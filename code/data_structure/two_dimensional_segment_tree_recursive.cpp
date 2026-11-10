#define lseg(x) (x*2)
#define rseg(x) (x*2 + 1)
#define mid(x, y) ((x + y)/2)
int N;
int grid[1025][1025];
int seg[4097][4097];
void build_y(int cur_x, int begin_x, int end_x, int cur_y, int begin_y, int end_y)
{
int mid_y = mid(begin_y, end_y);
if (begin_y == end_y)
{
if (begin_x == end_x)
seg[cur_x][cur_y] = grid[begin_x][begin_y];
// else
seg[cur_x][cur_y] = seg[lseg(cur_x)][cur_y] + seg[rseg(cur_x)][cur_y];
}
// else
{
build_y(cur_x, begin_x, end_x, lseg(cur_y), begin_y, mid_y);
build_y(cur_x, begin_x, end_x, rseg(cur_y), mid_y+1, end_y);
seg[cur_x][cur_y] = seg[cur_x][lseg(cur_y)] + seg[cur_x][rseg(cur_y)];
}
}
void build_x(int cur_x, int begin_x, int end_x)
{
int mid_x = mid(begin_x, end_x);
if (begin_x != end_x)
{
build_x(lseg(cur_x), begin_x, mid_x);
build_x(rseg(cur_x), mid_x+1, end_x);
}
build_y(cur_x, begin_x, end_x, 1, 1, N);
}
void update_y(int cur_x, int begin_x, int end_x, int cur_y, int begin_y, int end_y, int x,
int y, int val)
{
if (begin_y == end_y)
{
if (begin_x == end_x)
seg[cur_x][cur_y] = val;
// else
seg[cur_x][cur_y] = seg[lseg(cur_x)][cur_y] + seg[rseg(cur_x)][cur_y];
return;
}
int mid_y = mid(begin_y, end_y);
if (y <= mid_y)
update_y(cur_x, begin_x, end_x, lseg(cur_y), begin_y, mid_y, x, y, val);
// else
update_y(cur_x, begin_x, end_x, rseg(cur_y), mid_y+1, end_y, x, y, val);
seg[cur_x][cur_y] = seg[cur_x][lseg(cur_y)] + seg[cur_x][rseg(cur_y)];
}
void update_x(int cur_x, int begin_x, int end_x, int x, int y, int val)
{
int mid_x = mid(begin_x, end_x);
if (begin_x != end_x)
{
if (x <= mid_x)
update_x(lseg(cur_x), begin_x, mid_x, x, y, val);
// else
update_x(rseg(cur_x), mid_x+1, end_x, x, y, val);
}
update_y(cur_x, begin_x, end_x, 1, 1, N, x, y, val);
}
int query_y(int cur_x, int cur_y, int begin_y, int end_y, int qbegin_y, int qend_y)
{
if (qend_y < begin_y || end_y < qbegin_y)
return 0;
if (qbegin_y <= begin_y && end_y <= qend_y)
return seg[cur_x][cur_y];
int mid_y = mid(begin_y, end_y);
int l = query_y(cur_x, lseg(cur_y), begin_y, mid_y, qbegin_y, qend_y);
int r = query_y(cur_x, rseg(cur_y), mid_y+1, end_y, qbegin_y, qend_y);
return l + r;
}
int query_x(int cur_x, int begin_x, int end_x, int qbegin_x, int qend_x, int qbegin_y, int
qend_y)
{
if (qend_x < begin_x || end_x < qbegin_x)
return 0;
if (qbegin_x <= begin_x && end_x <= qend_x)
return query_y(cur_x, 1, 1, N, qbegin_y, qend_y);
int mid_x = mid(begin_x, end_x);
int l = query_x(lseg(cur_x), begin_x, mid_x, qbegin_x, qend_x, qbegin_y, qend_y);
int r = query_x(rseg(cur_x), mid_x+1, end_x, qbegin_x, qend_x, qbegin_y, qend_y);
return l + r;
}
