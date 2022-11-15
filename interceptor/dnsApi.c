#include "dnsApi.h"
#include <curl/curl.h>
#include <stdio.h>
#include <string.h>
#include <jansson.h>
void makePostRequest(char* url, char* json) {
  CURL *curl;
  CURLcode res;
 
  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);
 
  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be an https:// URL if that is what should receive the
       data. */
    curl_easy_setopt(curl, CURLOPT_URL, url);
    /* Now specify the POST data */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
 
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
