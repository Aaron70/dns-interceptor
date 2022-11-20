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

char* createJSON(char *encoded) {
  
  char* s = NULL;
  
  json_t *root = json_object();
  
  json_object_set_new( root, "data", json_string( encoded ) );
  
  s = json_dumps(root, 0);
  puts(s);
  json_decref(root);
  
 return s;
}
