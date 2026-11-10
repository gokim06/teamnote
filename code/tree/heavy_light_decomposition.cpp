// Time Complexity: 전처리O(N), 쿼리O(T(N) log N)
// sz:서브트리크기, dep:깊이, par:부모, top:체인헤드, in:DFS방문순서(SegTree의인덱스)
vector<int> adj[SZ]; //pv: 방문순서카운터
int sz[SZ], dep[SZ], par[SZ], top[SZ], in[SZ], pv;
// 1. DFS 1: 서브트리크기계산및Heavy Edge를0번으로보냄
void dfs_sz(int v, int p = 0) {
sz[v] = 1;
par[v] = p;
dep[v] = dep[p] + 1;
for (auto &next : adj[v]) {
if (next == p) continue;
dfs_sz(next, v);
sz[v] += sz[next];
// 가장무거운자식을adj[v][0]으로스왑(Heavy Edge)
if (sz[next] > sz[adj[v][0]] || adj[v][0] == p) {
swap(next, adj[v][0]);
}}}
// 2. DFS 2: DFS 순서(in) 부여및Top 설정
void dfs_hld(int v) {
in[v] = ++pv;
for (auto next : adj[v]) {
if (next == par[v]) continue;
// Heavy Edge(0번)면Top 유지, 아니면자신이새로운Top
top[next] = (next == adj[v][0]) ? top[v] : next;
dfs_hld(next);
}}
// 3. 경로쿼리(u, v 경로의합/최대값등)
long long query_path(int u, int v) {
long long ret = 0;
while (top[u] != top[v]) {
if (dep[top[u]] < dep[top[v]]) swap(u, v);
int st = top[u];
ret += seg_query(in[st], in[u]); // 체인구간쿼리
u = par[st];
}
if (dep[u] > dep[v]) swap(u, v);
// [Type A] 정점가중치(Vertex Weight)
ret += seg_query(in[u], in[v]);
// [Type B] 간선가중치(Edge Weight)
// LCA(u)는경로에포함되지않으므로in[u] + 1 부터시작
// if (u != v) ret += seg_query(in[u] + 1, in[v]);
return ret;
}
// 4-1. 정점업데이트(u의값을val로)
void update_vertex(int u, int val) { seg_update(in[u], val); }
// 4-2. 간선업데이트(u-v 간선값을val로)
void update_edge(int u, int v, int val) {
// 둘중깊이가더깊은쪽이자식노드이며, 간선값을들고있음
if (dep[u] < dep[v]) seg_update(in[v], val);
else seg_update(in[u], val); }
// 5. 초기화및실행예시
void init_hld(int root = 1) {
pv = 0; dfs_sz(root);
top[root] = root;
dfs_hld(root);
// 1. 정점가중치인경우:
//
for(int i=1; i<=N; i++) seg_update(in[i], Cost[i]);
// 2. 간선가중치인경우(입력이u, v, w): 트리에는일단간선만넣음
//
// dfs가다끝난뒤에수행해야dep 비교가능
//
if(dep[u] < dep[v]) seg_update(in[v], w); //자식에게가중치박아넣음
//
else seg_update(in[u], w);
}
