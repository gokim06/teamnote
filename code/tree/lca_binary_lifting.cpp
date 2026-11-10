// preprocessing: O(NlogN)
// query: O(logN)
int N, H;
vector<int> adj[100001];
int dep[100001] = {-1};
int st[18][100001];
void dfs(int cur, int prev, int h) {
H = max(H, __lg(h+1));
dep[cur] = h;
st[0][cur] = prev;
for (int i = 1; (1<<i)<=h; i++)
st[i][cur] = st[i-1][st[i-1][cur]];
for (int next : adj[cur]) {
if (next != prev)
dfs(next, cur, h+1);
}
}
int lca(int u, int v) {
if (dep[u] < dep[v])
swap(u, v);
for (int i = H; i >= 0; i--) {
if (dep[st[i][u]] >= dep[v])
u = st[i][u];
}
for (int i = H; i >= 0; i--) {
if (st[i][u] != st[i][v]) {
u = st[0][st[i][u]];
v = st[0][st[i][v]];
}
}
return u == v ? u : st[0][u];
}
