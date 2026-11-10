// credit: https://infossm.github.io/blog/2019/11/15/2D-segment-tree/
// all indices here are zero-based.
class Seg2D{
// public:
int n, m;
vector<vector<int>> a;
Seg2D(int n, int m) : n(n), m(m), a(2*n,vector<int>(2*m)){}
void init(vector<vector<int>>& val){
for(int i = 0; i < n; i++){
for(int j = 0; j < m; j++)
a[i+n][j+m] = val[i][j];
}
for(int i = n; i < 2*n; i++){
for(int j = m-1; j > 0; j--) a[i][j] = a[i][j<<1]+a[i][j<<1|1];
}
for(int i = n-1; i > 0; i--){
for(int j = 1; j < 2*m; j++){
a[i][j] = a[i<<1][j] + a[i<<1|1][j];
}
}
}
void upd(int x, int y, int val) {
a[x+n][y+m] = val;
for(int i = y+m; i > 1; i >>= 1)
a[x+n][i>>1] = a[x+n][i] + a[x+n][i^1];
for(x = x+n; x > 1; x >>= 1){
for(int i = y+m; i >= 1; i >>= 1){
a[x>>1][i] = a[x][i]+a[x^1][i];
}
}
}
int query1D(int x, int y1, int y2){
int ret = 0;
for(y1 += m, y2 += m+1; y1 < y2; y1 >>= 1, y2 >>= 1){
if(y1 & 1) ret += a[x][y1++];
if(y2 & 1) ret += a[x][--y2];
}
return ret;
}
int query(int x1, int y1, int x2, int y2) {
int ret = 0;
for(x1 += n, x2 += n+1; x1 < x2; x1 >>= 1, x2 >>= 1){
if(x1&1) ret += query1D(x1++, y1, y2);
if(x2&1) ret += query1D(--x2, y1, y2);
}
return ret;
}
};
