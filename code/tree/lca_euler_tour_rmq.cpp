// preprocessing: O(NlogN)
// query: O(1)
int N;
vector<int> adj[100001];
int enter[100001];
pair<int, int> st[18][200001];
void dfs(int cur, int prev) {
static int t;
enter[cur] = ++t;
st[0][t] = {enter[cur], cur};
for (int next : adj[cur]) {
if (next != prev) {
dfs(next, cur);
st[0][++t] = {enter[cur], cur};
}
}
}
void pre() {
for (int i = 1; (1<<i) <= 2*N; i++) {
for (int j = 1; j+(1<<i)-1 <= 2*N; j++) {
st[i][j] = min(st[i-1][j], st[i-1][j+(1<<(i-1))]);
}
}
}
int lca(int u, int v) {
if ((u = enter[u]) > (v = enter[v]))
swap(u, v);
int l = __lg(v-u+1);
return min(st[l][u], st[l][v-(1<<l)+1]).second;
}
