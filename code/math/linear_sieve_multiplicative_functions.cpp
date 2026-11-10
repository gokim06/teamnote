// sigma 계산하는부분제외하면O(n), sigma 계산은O(n log log n)
// pw(j, e[i*j]) 모두전처리하면O(n)에계산할수있음
// prime: n 이하소수목록
// sp : 최소소인수, 소수라면0
// tau : 약수개수, sigma : 약수합
// phi : n 이하자연수중n과서로소인개수
// mu : 2번이상곱해진소인수가있으면0, 그렇지않으면(-1)^(소인수개수)
// e[i] : i에sp[i]가곱해진횟수
vector<int> prime;
int sp[sz], e[sz], phi[sz], mu[sz], tau[sz], sigma[sz];
phi[1] = mu[1] = tau[1] = sigma[1] = 1;
for(int i=2; i<=n; i++){
if(!sp[i]){
prime.push_back(i);
e[i] = 1; phi[i] = i-1; mu[i] = -1; tau[i] = 2; sigma[i] = i+1;
}
for(auto j : prime){
if(i*j >= sz) break;
sp[i*j] = j;
if(i % j == 0){
e[i*j] = e[i]+1; phi[i*j] = phi[i]*j; mu[i*j] = 0;
tau[i*j] = tau[i]/e[i*j]*(e[i*j]+1);
sigma[i*j] = sigma[i]*(j-1)/(pw(j, e[i*j])-1)*(pw(j, e[i*j]+1)-1)/(j-1);//overflow
break;
}
e[i*j] = 1; phi[i*j] = phi[i] * phi[j]; mu[i*j] = mu[i] * mu[j];
tau[i*j] = tau[i] * tau[j]; sigma[i*j] = sigma[i] * sigma[j];
}
}
