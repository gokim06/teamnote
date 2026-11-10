// Time Complexity: O(V E)
// credit: https://gina65.tistory.com/23
struct EDGE {
int u, v;
ll c;
EDGE(int u, int v, ll c): u(u), v(v), c(c) {}
};
// set of all edges of a graph (vertices are zero-based)
vector<EDGE> ed;
// returns the weight of the directed minimum spanning tree rooted at vertex r (zero-based)
// N denotes the number of vertices
ll dmst(int N, int r) {
vector<int> mnu(N), lbl(N);
vector<ll> mnc(N);
ll ans = 0;
while(true) {
fill(mnc.begin(), mnc.end(), LLONG_MAX);
for(EDGE e : ed)
if(e.u != e.v && e.c < mnc[e.v]) {
mnc[e.v] = e.c;
mnu[e.v] = e.u;
}
mnc[r] = 0;
for(int i = 0; i < N; i++) ans += mnc[i];
fill(lbl.begin(), lbl.end(), -1);
int K = 0;
lbl[r] = K++;
for(int i = 0; i < N; i++) if(lbl[i] == -1) {
int x;
for(x = i; lbl[x] == -1; x = mnu[x]) lbl[x] = -2;
if(lbl[x] == -2) {
for(; lbl[x] == -2; x = mnu[x]) lbl[x] = K;
K++;
}
for(x = i; lbl[x] == -2; x = mnu[x]) lbl[x] = K++;
}
if(K == N) break;
N = K;
for(EDGE &e : ed) {
e.c -= mnc[e.v];
e.u = lbl[e.u];
e.v = lbl[e.v];
}
r = lbl[r];
}
return ans;
}
