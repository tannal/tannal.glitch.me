
# k3s prometheus


kubectl get services
kubectl get pods

sudo systemctl stop k3s
sudo k3s server --write-kubeconfig-mode 644

curl -sfL https://get.k3s.io | sh

sudo k3s kubectl get nodes

curl https://raw.githubusercontent.com/helm/helm/master/scripts/get-helm-3 | bash

helm repo add prometheus-community https://prometheus-community.github.io/helm-charts
helm repo update

kubectl create namespace prometheus
sudo helm install prometheus prometheus-community/kube-prometheus-stack -n prometheus

kubectl port-forward -n prometheus svc/prometheus-kube-prometheus-prometheus 9090:9090

# dev

kubectl apply -f hello-world.yaml
kubectl get deployments
kubectl get pods
kubectl get services

minikube  kubectl rollout restart deployment -- -n nextcloud nextcloud
minikube  kubectl rollout restart deployment -- -n nextcloud nextcloud-db
minikube  kubectl rollout restart deployment -- -n nextcloud nextcloud-redis

minikube kubectl apply -- -f nextcloud-config.yaml
minikube kubectl apply -- -f nextcloud-secrets.yaml
minikube kubectl apply -- -f nextcloud-pvc.yaml
minikube kubectl apply -- -f nextcloud-deployment.yaml
minikube kubectl apply -- -f nextcloud-db-deployment.yaml
minikube kubectl apply -- -f nextcloud-redis-deployment.yaml
minikube kubectl apply -- -f nextcloud-services.yaml


```bash
minikube kubectl get pods -- -n nextcloud
```

```bash
export NO_PROXY=$NO_PROXY,192.168.49.2
```
Configure proxy settings for minikube:
Set the following environment variables before starting minikube:
routeros

```bash
export HTTP_PROXY=http://127.0.0.1:8890/
export HTTPS_PROXY=http://127.0.0.1:8890/
export NO_PROXY=localhost,127.0.0.1,10.96.0.0/12,192.168.59.0/24,192.168.49.0/24,192.168.39.0/24

export HTTP_PROXY=http://10.90.243.70:8890/
export HTTPS_PROXY=http://10.90.243.70:8890/
export NO_PROXY=localhost,127.0.0.1,10.96.0.0/12,192.168.59.0/24,192.168.49.0/24,192.168.39.0/24
```
Start minikube with proxy settings:
Use the following command to start minikube with the proxy settings:

```bash
minikube start --docker-env HTTP_PROXY=$HTTP_PROXY --docker-env HTTPS_PROXY=$HTTPS_PROXY --docker-env NO_PROXY=$NO_PROXY
```
If you're still having issues pulling images, you might need to configure minikube to use a different image repository. You can do this by adding the --image-repository flag:

```bash
kubectl create namespace nextcloud
```

复制
minikube start --docker-env HTTP_PROXY=$HTTP_PROXY --docker-env HTTPS_PROXY=$HTTPS_PROXY --docker-env NO_PROXY=$NO_PROXY --image-repository=auto
If problems persist, you might want to delete the existing minikube cluster and start fresh:

复制
minikube delete
minikube start --docker-env HTTP_PROXY=$HTTP_PROXY --docker-env HTTPS_PROXY=$HTTPS_PROXY --docker-env NO_PROXY=$NO_PROXY --image-repository=auto
Make sure your proxy allows connections to the necessary Kubernetes repositories and domains.

# inbox


# people

involves:k8s-ci-robot
involves:pohly
involves:thockin
involves:danwinship
involves:dims
involves:aojea
involves:alexzielenski
involves:liggitt
involves:SataQiu
involves:pacoxu
involves:neolit123
involves:p0lyn0mial
involves:sttts
involves:humblec
involves:wojtek-t
involves:jpbetz
involves:jsafrane
involves:tkashem
involves:soltysh
involves:chendave
involves:seans3
involves:BenTheElder
involves:tallclair
involves:alculquicondor
involves:logicalhan
involves:MikeSpreitzer
involves:gnufied
involves:andrewsykim
involves:claudiubelu
involves:Huang-Wei
involves:deads2k
involves:klueska
involves:msau42
involves:andyzhangx
involves:smarterclayton
involves:cblecker
involves:jayunit100
involves:nikhita
involves:dashpole
involves:mtaufen
involves:justinsb
involves:lavalamp

# setup