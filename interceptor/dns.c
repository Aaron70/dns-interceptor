#include "dns.h"

int isQueryStandart(struct DNS_HEADER *dns){
    if ( dns->opcode != 0 ){
        return 0;
    }
    return dns->qr;
}
