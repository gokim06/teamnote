// Time Complexity: O(V E)
int N, M; ll D[555]; // 주의: 웬만하면long long으로잡는게좋음
vector<tuple<int,int,ll>> E; // {from, to, weight}
void AddEdge(int s, int e, int w){
E.emplace_back(s, e, w);
}
// s에서도달가능한음수사이클있으면false 반환
bool Run(int s){
memset(D, 0x3f, sizeof D);
ll INF = D[0];
D[s] = 0;
for(int iter=1; iter<=N; iter++){
bool changed = false;
for(auto [u,v,w] : E){
if(D[u] == INF) continue;
if(D[v] > D[u] + w) D[v] = D[u] + w, changed = true;
}
if(iter == N && changed) return false;
}
return true;
}
