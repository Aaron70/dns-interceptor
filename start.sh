docker build ./interceptor -t aaronv70/dns-interceptor 
interceptor=$1

docker build ./api -t aaronv70/dns-api
api=$1

docker build ./client -t aaronv70/dns-client
client=$1

# This command was get from: https://stackoverflow.com/questions/29326721/is-there-a-way-to-get-the-docker-hub-username-of-the-current-user
username=$(docker info | sed '/Username:/!d;s/.* //'); 
user="aaronv70"

if [[ interceptor -eq 0 && $username == $user ]]; then
   docker push aaronv70/dns-interceptor
fi

if [[ api -eq 0 && $username == $user ]]; then
   docker push aaronv70/dns-api
fi

if [[ client -eq 0 && $username == $user ]]; then
   docker push aaronv70/dns-client
fi

helm uninstall dns-interceptor
helm install dns-interceptor deploy/
