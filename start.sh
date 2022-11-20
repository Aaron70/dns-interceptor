docker build ./interceptor -t aaronv70/dns-interceptor

if [ $? -eq 0 ]; then
   docker push aaronv70/dns-interceptor
fi

docker build ./api -t aaronv70/dns-api

if [ $? -eq 0 ]; then
   docker push aaronv70/dns-api
fi

helm uninstall dns-interceptor
helm install dns-interceptor deploy/
