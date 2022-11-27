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

kubectl create -f https://download.elastic.co/downloads/eck/2.5.0/crds.yaml

kubectl apply -f https://download.elastic.co/downloads/eck/2.5.0/operator.yaml

cat <<EOF | kubectl apply -f -
apiVersion: elasticsearch.k8s.elastic.co/v1
kind: Elasticsearch
metadata:
  name: quickstart
spec:
  version: 8.5.2
  nodeSets:
  - name: default
    count: 1
    config:
      node.store.allow_mmap: false
EOF

cat <<EOF | kubectl apply -f -
apiVersion: kibana.k8s.elastic.co/v1
kind: Kibana
metadata:
  name: quickstart
spec:
  version: 8.5.2
  count: 1
  elasticsearchRef:
    name: quickstart
EOF

PASSWORD=$(kubectl get secret quickstart-es-elastic-user -o go-template='{{.data.elastic | base64decode}}')



helm uninstall dns-interceptor
helm install --set password=$PASSWORD dns-interceptor deploy/
