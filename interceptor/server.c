#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "dns.c"
#include "dnsApi.c"
#include "base64.c"
	
#define PORT	 53
#define MAXLINE 65536
	
char* intToIpv4( int ip){
	char* ipv4[4];
	int byte[4];
	for( int i = 0; i < 4; i++ ){
		byte[i] = ip & 255;
		ip = ip >> 8;
	}
	char* ipAddress = malloc(15);
	sprintf(ipAddress, "%i.%i.%i.%i", byte[3], byte[2], byte[1], byte[0]);
	return ipAddress;
}

void handler(struct DNS_HEADER *dns) {
	if (isQueryStandart(dns)) {
		printf("PYTHON");
		
	} else {
		printf("kibana");
	}
}

char* receiveDNSPacket(int sockfd, struct sockaddr_in *cliaddr, int* packetSize) {

	char* buffer = malloc(MAXLINE);
	int len, n;
	len = sizeof(cliaddr); //len is value/result
	
	*packetSize = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, ( struct sockaddr *) cliaddr, &len);
	//sendto(sockfd, (const char *)buffer,*packetSize,
	//	MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
	//		sizeof(cliaddr));


	return buffer;
}

char* getHostName(char* packet, int packetSize) {

	int headerSize = sizeof(struct DNS_HEADER) + 1;
	int len = strlen(&packet[headerSize]);
	char* host = malloc(len+1);
	for( int i = 0; i <= len; i++){
		if ( packet[headerSize + i] > 30) {
			host[i] = packet[headerSize + i];
		}else{
			host[i] = '.';
		}
	}
	host[len] = '\0';
	return host;
}

char* getHostName(char* packet, int packetSize) {

	int headerSize = sizeof(struct DNS_HEADER);
	int len = packet[headerSize];
	printf("Num: %i\n",len);	
	printf("Host: ");
	for( int i = headerSize; i < packetSize; i++){
		if ( packet[i] < 30) {
			printf("%i", packet[i]);
		}else{
			printf("%c", packet[i]);
		}
	}
	printf("\n");
	return "";
}

void listenClient(int sockfd){
		
	struct sockaddr_in servaddr, cliaddr;
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
		
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
		
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		return;
	}
	while(1)
	{
		int packetSize = 0;
		char* packet = receiveDNSPacket(sockfd, &cliaddr, &packetSize);

		//char* hostName = getHostName(packet, packetSize);
		//int hostLen = strlen(hostName);
		//char*	trash =   ".default.svc.cluster.local";
		//memset(&packet[sizeof(struct DNS_HEADER) + 1 + (strlen(hostName) - strlen(trash) )],0,strlen(trash));
		//hostName = getHostName(packet, packetSize);

		//struct DNS_HEADER *header = (struct DNS_HEADER*)packet;
		size_t encodedLenght = 0;
		char* encoded = base64_encode(packet, packetSize, &encodedLenght);
		char* json = createJSON(encoded);
		//printf("encode: %s\n", json);
	
		//printf("HostName: %s\n", hostName);

		//unsigned short int id = header->id;
		//printf("ID: %hu\n", (id >> 8 ) + ((id & 255) << 8));


		encoded = makePostRequest("http://dns-api-svc/api/dns_resolver",json);
		//printf("Response: %s\n",encoded);

		size_t decodedLen = 0;
		char* decoded = base64_decode(encoded, strlen(encoded), &decodedLen); 
		printf("DecodedLen: %i\n", (int)decodedLen);

		sendto(sockfd, (const char *)decoded, (int)decodedLen,
			MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
				sizeof(cliaddr));
	}

}

// Driver code
int main() {
	int sockfd;
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	listenClient(sockfd);

	return 0;
}

