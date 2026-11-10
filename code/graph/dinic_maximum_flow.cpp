// Time Complexity: O(V 2E), 모든간선의용량이1이면O(min(V 2/3, E1/2)E)
// 디닉알고리즘(Dinic) 최대유량, O(E * sqrt(V)) ~ O(V^2 E)
// 사용법)
//
// Dinic<int> mf(n);
//
// mf.add_edge(u, v, cap); // 유향, 무향은왕복용량추가
//
// auto flow = mf.maximum_flow(src, sink);
//
// 최소컷은minimum_cut 호출(유량재활용)
// Directed Graph이면add_edge(s, e, c)
// Undirected Graph이면add_edge(s, e, c, c)
template<typename flow_t, flow_t MAX_U=(1<<30)>
struct Dinic{ // 0-based
struct edge_t{ int v, r; flow_t c, f; };
int n;
vector<vector<edge_t>> g;
vector<int> lv, idx;
Dinic(int n) : n(n) { clear(); }
void clear(){
g = vector<vector<edge_t>>(n);
lv = vector<int>(n, 0);
idx = vector<int>(n, 0);
}
// add_edge: s→e 용량c1, e→s 역간선용량c2 (기본0)
void add_edge(int s, int e, flow_t c1, flow_t c2=flow_t(0)){
g[s].push_back({e, (int)g[e].size(), c1, 0});
g[e].push_back({s, (int)g[s].size()-1, c2, 0});
}
// bfs: 레벨그래프구성(limit 사용하면Scaling Dinic)
bool bfs(int s, int t, flow_t limit=1){
fill(lv.begin(), lv.end(), 0);
queue<int> que; que.push(s); lv[s] = 1;
while(!que.empty()){
int v = que.front(); que.pop();
for(const auto &e : g[v]) if(!lv[e.v] && e.c - e.f >= limit) que.push(e.v), lv[e.v] =
lv[v] + 1;
}
return lv[t] != 0;
}
// dfs: Blocking flow 탐색
flow_t dfs(int v, int t, flow_t fl=MAX_U){
if(v == t || fl == flow_t(0)) return fl;
for(int &i=idx[v]; i<g[v].size(); i++){
auto &e = g[v][i];
if(lv[e.v] != lv[v] + 1 || e.c - e.f == flow_t(0)) continue;
flow_t now = dfs(e.v, t, min(fl, e.c - e.f));
if(now == flow_t(0)) continue;
e.f += now; g[e.v][e.r].f -= now;
return now;
}
return 0;
}
// maximum_flow: s→t 최대유량반환
flow_t maximum_flow(int s, int t){
flow_t flow = 0, augment = 0;
while(bfs(s, t)){
fill(idx.begin(), idx.end(), 0);
while((augment=dfs(s, t)) != flow_t(0)) flow += augment;
}
return flow;
}
// {최소컷비용, s와같은집합, t와같은집합, 절단간선}
// minimum_cut: (최소컷값, S집합, T집합, 절단간선) 반환
tuple<flow_t, vector<int>, vector<int>, vector<pair<int,int>>> minimum_cut(int s, int t){
flow_t flow = maximum_flow(s, t);
vector<int> a, b;
vector<pair<int,int>> edges;
bfs(s, t, 1);
for(int i=0; i<n; i++) (lv[i] ? a : b).push_back(i);
for(auto i : a) for(auto e : g[i]) if(e.c != flow_t(0) && !lv[e.v])
edges.emplace_back(i, e.v);
return {flow, a, b, edges};
}
};
