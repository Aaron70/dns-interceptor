docker build . -t aaronv70/dns-interceptor
clear
docker run -it -v /home/aaron/Desktop/dns/dns-interceptor/:/home/server gcc bash
