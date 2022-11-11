// Server side implementation of UDP client-server model
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
	
#define PORT	 53
#define MAXLINE 1024
	
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
		char* test = dnsToJSon(dns);
		printf("PYTHON");
		
	} else {
		printf("kibana");
	}
}


// Driver code
int main() {
	int sockfd;
	int buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
		
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
		
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
		exit(EXIT_FAILURE);
	}
		
	int len, n;
	
	len = sizeof(cliaddr); //len is value/result
	
	n = recvfrom(sockfd, (int *)buffer, MAXLINE,
				MSG_WAITALL, ( struct sockaddr *) &cliaddr,
				&len);
	//buffer[n] = '\0';
	struct DNS_HEADER *dns = (struct DNS_HEADER*)&buffer; 
	unsigned short int id = dns->id;
	printf("Number of bytes readed: %d/n",n);
	printf("ID: %s\n", intToIpv4(dns->id));
	printf("ID: %hu\n", dns->id);
	printf("ID: %hu\n", (id >> 8 ) + ((id & 255) << 8));
	printf("Qr: %i\n", 0+dns->qr);
	printf("Opcode: %i\n", 0+dns->opcode);
	printf("Query Count: %i\n", 0+dns->q_count);
	printf("Client : %s\n", buffer);
	dns->qr = 1;
	sendto(sockfd, (const char *)dns, sizeof(buffer),
		MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
			len);
	printf("Hello message sent.\n");
	handler(dns);
	return 0;
}
