#include "dnsApi.h"
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <jansson.h>

struct MemoryStruct {
  char *memory;
  size_t size;
};
 
static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
  size_t realsize = size * nmemb;
  struct MemoryStruct *mem = (struct MemoryStruct *)userp;
 
  char *ptr = realloc(mem->memory, mem->size + realsize + 1);
  if(!ptr) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
  }
 
  mem->memory = ptr;
  memcpy(&(mem->memory[mem->size]), contents, realsize);
  mem->size += realsize;
  mem->memory[mem->size] = 0;
 
  return realsize;
}

char* makePostRequest(char* url, char* json) {
  CURL *curl;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */
  curl = curl_easy_init();
  struct curl_slist *list = NULL;
  struct MemoryStruct chunk;
 
  chunk.memory = malloc(1);  /* will be grown as needed by realloc above */
  chunk.size = 0;   
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be an https:// URL if that is what should receive the
       data. */
    list = curl_slist_append(list, "Accept: application/json");
    list = curl_slist_append(list, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, list);
    curl_easy_setopt(curl, CURLOPT_URL, url);
    /* Now specify the POST data */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  return chunk.memory;
}

char* makeGetKibana(char* url)
{
  CURL *curl;
  CURLcode res;

  curl = curl_easy_init();
  struct curl_slist *list = NULL;
  struct MemoryStruct chunk;

  chunk.memory = malloc(1);  /* will be grown as needed by realloc above */
  chunk.size = 0; 
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url);
    /* example.com is redirected, so we tell libcurl to follow redirection */
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
 
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  
  return chunk.memory;
}

char * filterJsonKibana(char* json) {
  char *jsonAux = malloc(strlen(json) + 1);
  strcpy(jsonAux, json);
  char * token = strtok(jsonAux, ",:\n{}");
  int objective = 0;
  int countSource = 0;
  char destination[1000] = "";
  char *newJson = malloc(strlen(json));
  while( token != NULL ) {
      if (strcmp(token, "\"_source\"") == 0 || strcmp(token, "\"_source\":") == 0 ) {
        strcat(destination, (countSource >= 1 ? "}," : ""));
        countSource += 1;
        objective = 1;
        token = strtok(NULL, "}");
      }
      if (objective) {
        strcat(destination, token);
        token = strtok(NULL, ":"); //}
        objective = 0;
      }
      else {
        token = strtok(NULL, ",:\n{}");
      }
   }
  if (strlen(destination) == 0) {
     return NULL;
  }
  strcat(destination, "}");
  strcpy(newJson, destination);
  return newJson;
}

char * getUrlSearch(char *value) {
  char url[55] = "http://localhost:9200/zones/_search?q=";
  strcat(url,value);
  char *answer = malloc(strlen(url) + 1);
  strcpy(answer, url);
  memset(url, 0, 55);
  return answer;

}

char *searchInJson(char *json, char *paramValue) {
  char *value = createStringJson(paramValue);
  char *jsonAux = (char*) malloc(strlen(json) + 1);
  strcpy(jsonAux, json);
  char * token = strtok(jsonAux, ":,{}");
  while( token != NULL ) {
      if (strcmp(token, value) == 0) {
        token = strtok(NULL, ",:{} " "");
        break;
      }
      else {
        token = strtok(NULL, ", " " :{}");
      }
  }
  free(jsonAux);
  char resAux[100] = "";
  char * res = (char*) malloc(100);
  strncpy(resAux, token + 1, strlen(token) - 2);
  strcpy(res, resAux);
  memset(resAux,0, 100);
  return res;
  

}

char * createStringJson(char *value) {
  char * answuer = malloc(strlen(value));
  strcpy(answuer, "\"");
  strcat(answuer, value);
  strcat(answuer, "\"");

  return answuer;

}
char * getUrlPut(char *id) {
  char *answer = (char*) malloc(100);
  char url[100] = "http://localhost:9200/zones/_update/";
  strcat(url,id);
  strcpy(answer, url);
  memset(url,0,100);
  return answer;

}
char *createJsonPut(char *key, char *value) {
  char* s = NULL;
  char* res = NULL;
  char *newRes = malloc(100);
  char cutJson[100];
  
  json_t *root = json_object();
  json_t *json = json_object();
  
  json_object_set_new( json, key, json_string(value ));
  s = json_dumps(json, 0);

  json_object_set_new(root, "doc", json_string("a"));
  res = json_dumps(root, 0);

  free(json);
  free(root);
  
  strncpy(cutJson, res + 0, 7);
  strcpy(newRes, cutJson);
  strcat(newRes, s);
  strcat(newRes,"}");
  memset(cutJson,0,100);

  return newRes;


}

char* createJSON(char *encoded) {
  
  char* s = NULL;
  
  json_t *root = json_object();
  
  json_object_set_new( root, "data", json_string( encoded ) );
  
  s = json_dumps(root, 0);
  json_decref(root);
  
 return s;
}


char* kibana(char* host, char* jsonEncoded) {
  char* JSON = makeGetKibana(getUrlSearch(host));
  char* filterJson = filterJsonKibana(JSON);

  if (filterJson == NULL) {
      char* answer = makePostRequest("http://dns-api-svc/api/dns_resolver",jsonEncoded);
      return answer;
  }

 return filterJson;
}
