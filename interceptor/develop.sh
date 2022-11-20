gcc server.c -o server.o -ljansson -lcurl
if [ $? -ne 0 ]; then
	exit
fi
docker build . -t aaronv70/dns-interceptor
clear
docker run -it -v /home/aaron/Desktop/dns/dns-interceptor/:/home/server gcc bash
