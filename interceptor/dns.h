// Structure taken from: https://gist.github.com/fffaraz/9d9170b57791c28ccda9255b48315168
struct DNS_HEADER
{
    unsigned short int id; // identification number

    unsigned char rd :1; // recursion desired
    unsigned char tc :1; // truncated message
    unsigned char aa :1; // authoritive answer
    unsigned char opcode :4; // purpose of message
    unsigned char qr :1; // query/response flag

    unsigned char rcode :4; // response code
    unsigned char cd :1; // checking disabled
    unsigned char ad :1; // authenticated data
    unsigned char z :1; // its z! reserved
    unsigned char ra :1; // recursion available

    unsigned short q_count; // number of question entries
    unsigned short ans_count; // number of answer entries
    unsigned short auth_count; // number of authority entries
    unsigned short add_count; // number of resource entries
};

//    unsigned  char name[8];
//    unsigned  char type[2];
//    unsigned  char class_[2];
//    unsigned  char ttl[4];
//    unsigned  char rdlength[2];
//    unsigned  char rdata[4];

// Function prototypes

int isQueryStandart(struct DNS_HEADER *dns);

