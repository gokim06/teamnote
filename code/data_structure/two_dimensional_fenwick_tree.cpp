// credit: https://github.com/ncduy0303/Competitive-Programming/
// all indices are one-based.
#define MAX_N 5005
#define MAX_M 5005
int n, m, q;
ll ft[MAX_N][MAX_M], grid[MAX_N][MAX_M];
void update(int x, int y, int v) {
for (int tx = x; tx <= n; tx += tx&-tx)
for (int ty = y; ty <= m; ty += ty&-ty)
ft[tx][ty] += v;
}
ll sum(int x, int y) {
ll res = 0;
for (int tx = x; tx; tx -= tx&-tx)
for (int ty = y; ty; ty -= ty&-ty)
res += ft[tx][ty];
return res;
}
ll query(int x1, int y1, int x2, int y2) {
return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}
