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


char* dnsToJSon(struct DNS_HEADER *dns) {
  
  char* s = NULL;
  
  json_t *root = json_object();
  json_t *json_arr = json_array(); 
  
  json_object_set_new( root, "id", json_integer( dns->id ) );
  json_object_set_new( root, "rd", json_integer(dns->rd));
  json_object_set_new( root, "tc", json_integer(dns->tc));
  json_object_set_new( root, "aa", json_integer(dns->aa));
  json_object_set_new( root, "opcode", json_integer(dns->opcode));
  json_object_set_new( root, "qr", json_integer(dns->qr));

  json_object_set_new( root, "rcode", json_integer(dns->rcode));
  json_object_set_new( root, "cd", json_integer(dns->cd));
  json_object_set_new( root, "ad", json_integer(dns->ad));
  json_object_set_new( root, "z", json_integer(dns->z));
  json_object_set_new( root, "ra", json_integer(dns->ra));

  json_object_set_new( root, "q_count", json_integer(dns->q_count));
  json_object_set_new( root, "ans_count", json_integer(dns->ans_count));
  json_object_set_new( root, "auth_count", json_integer(dns->auth_count));
  json_object_set_new( root, "add_count", json_integer(dns->add_count));
  
  s = json_dumps(root, 0);
  puts(s);
  json_decref(root);
  
 return s;
}
