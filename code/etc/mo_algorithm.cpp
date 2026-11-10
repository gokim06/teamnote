// Time Complexity: O(Q log Q + (N + Q)
// √
N)
// program to find the number of distinct elements in [l, r].
// struct query
{
static int block_sz;
int i, j, idx;
bool operator<(const query& a) const
{
return make_pair(i/block_sz, j) < make_pair(a.i/block_sz, a.j);
}
};
// this should be set to sqrt(N) upon reading the input.
int query::block_sz = 0;
int N, M;
int A[100001];
query Q[100000];
int R[100000]; // result vector.
void collect()
{
static int freq[1000001];
int cnt = 0;
auto insert = [&](int idx)
{
if (!freq[A[idx]]++)
cnt++;
};
auto remove = [&](int idx)
{
if (!--freq[A[idx]])
cnt--;
};
sort(Q, Q+M);
int i = 1;
int j = 0;
for (int k = 0; k < M; k++)
{
query q = Q[k];
while (j < q.j)
insert(++j);
while (j > q.j)
remove(j--);
while (i > q.i)
insert(--i);
while (i < q.i)
remove(i++);
R[q.idx] = cnt;
}
}
