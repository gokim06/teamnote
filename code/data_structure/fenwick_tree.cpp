// Time Complexity: O(log N)
// author: https://github.com/ncduy0303
int n, q;
ll ft1[MAX_N], ft2[MAX_N];
void update(ll *ft, int x, ll v) {
for (; x <= n; x += LSOne(x))
ft[x] += v;
}
void range_update(int l, int r, ll v) {
update(ft1, l, v);
update(ft1, r + 1, -v);
update(ft2, l, v * (l - 1));
update(ft2, r + 1, -v * r);
}
ll sum(ll *ft, int x) {
ll res = 0;
for (; x; x -= LSOne(x))
res += ft[x];
return res;
}
// sum of all elements in [1, x]
ll ps(int x) {
return sum(ft1, x) * x - sum(ft2, x);
}
// range sum query of [l, r]
ll rsq(int l, int r) {
return ps(r) - ps(l - 1);
}
