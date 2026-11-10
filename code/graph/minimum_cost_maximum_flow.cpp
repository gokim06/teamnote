// 최소비용유량(Min-Cost Max-Flow), O(Flow * E)
// 사용법)
//
// MinCostFlow<int,long long> mcf(n);
//
// mcf.add_edge(u, v, cap, cost);
//
// auto [flow, cost] = mcf.run(src, sink);
// 가능한만큼흘림
//
// auto [flow, cost] = mcf.run(src, sink, need);
// need 만큼만흘림
template<typename flow_t=int, typename cost_t=long long, flow_t MAX_U=(1<<30), cost_t
MAX_C=(1LL<<60)>
struct MinCostFlow{ // 0-based
struct edge_t{ int v, r; flow_t c; cost_t d; };
int n;
vector<vector<edge_t>> g;
vector<int> prv, idx, chk;
vector<cost_t> dst;
MinCostFlow(int n) : n(n) { clear(); }
void clear(){
g = vector<vector<edge_t>>(n);
prv = idx = chk = vector<int>(n);
dst = vector<cost_t>(n);
}
// add_edge: 용량c, 비용d (역간선자동추가)
void add_edge(int s, int e, flow_t c, cost_t d){
g[s].push_back({e, (int)g[e].size(), c, d});
g[e].push_back({s, (int)g[s].size()-1, 0, -d});
}
// SPFA 기반최단경로탐색(음수비용허용)
bool find_path(int s, int t){
fill(chk.begin(), chk.end(), 0);
fill(dst.begin(), dst.end(), MAX_C);
queue<int> que; que.push(s); dst[s] = 0; chk[s] = 1;
while(!que.empty()){
int v = que.front(); que.pop(); chk[v] = 0;
for(int i=0; i<g[v].size(); i++){
const auto &e = g[v][i];
if(e.c > 0 && dst[e.v] > dst[v] + e.d){
dst[e.v] = dst[v] + e.d; prv[e.v] = v; idx[e.v] = i;
if(!chk[e.v]) que.push(e.v), chk[e.v] = 1;
}
}
}
return dst[t] < MAX_C;
}
// augment: 단일경로로가능한만큼혹은k 제한만큼유량흘리기
pair<flow_t, cost_t> augment(int s, int t, flow_t k=-1){
if(!find_path(s, t)) return {0, 0};
flow_t fl = MAX_U;
for(int i=t; i!=s; i=prv[i]) fl = min(fl, g[prv[i]][idx[i]].c);
if(k != -1) fl = min(fl, k);
for(int i=t; i!=s; i=prv[i]){
g[prv[i]][idx[i]].c -= fl;
g[i][g[prv[i]][idx[i]].r].c += fl;
}
return {fl, fl * dst[t]};
}
// run: 전체루프돌며누적유량/비용반환
pair<flow_t, cost_t> run(int s, int t, flow_t k=-1){
flow_t flow = 0; cost_t cost = 0;
while(true){
auto [fl,cst] = augment(s, t, k);
if(fl == 0) break;
flow += fl; cost += cst;
if(k != -1) k -= fl;
}
return {flow, cost};
}
};
