// segment tree for finding the maximum continuous sum in [l, r].
// struct seg
{
// left, right, max, total.
ll l, r, m, t;
};
seg seg_merge(seg a, seg b)
{
seg s;
s.l = max(a.l, a.t + b.l);
s.r = max(b.r, b.t + a.r);
s.m = max(max(a.m, b.m), a.r + b.l);
s.t = a.t + b.t;
return s;
}
int A[100001];
seg segtree[400001];
void build(int cur, int begin, int end)
{
if (begin == end)
{
segtree[cur] = (seg) {A[begin], A[begin], A[begin], A[begin]};
return;
}
int mid = (begin + end)/2;
build(cur*2, begin, mid);
build(cur*2+1, mid+1, end);
segtree[cur] = seg_merge(segtree[cur*2], segtree[cur*2+1]);
}
seg query(int cur, int begin, int end, int qbegin, int qend)
{
if (qend < begin || end < qbegin)
return (seg) {INT_MIN, INT_MIN, INT_MIN, 0};
if (qbegin <= begin && end <= qend)
return segtree[cur];
int mid = (begin + end)/2;
seg l = query(cur*2, begin, mid, qbegin, qend);
seg r = query(cur*2+1, mid+1, end, qbegin, qend);
return seg_merge(l, r);
}
