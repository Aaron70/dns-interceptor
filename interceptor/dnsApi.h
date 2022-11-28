// Prototypes
//#include "dns.h"

char* makePostRequest(char* url, char* json);
char* dnsToJSon(char *encoded);
char* makeGetKibana(char* url);
char * filterJsonKibana(char* json);
char * getUrlSearch(char *value);
char *searchInJson(char *json, char *value);
char * createStringJson(char *value);
char *createJsonPut(char *key, char *value);
