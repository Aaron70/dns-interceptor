gcc server.c -o server.o -ljansson -lcurl -lb64
if [ $? -ne 0 ]; then
	exit
fi
docker build . -t arrokoth20/dns-interceptor
clear
docker run -it -v /home/danie20/Documents/DNSPY2/dns-interceptor/:/home/server gcc bash
