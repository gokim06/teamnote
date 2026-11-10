// 다각형내부또는경계위에p가있으면true, O(log N)
// 주의: v는반시계방향으로정렬된볼록다각형이어야함
bool PointInConvexPolygon(const vector<Point> &v, const Point &pt){
if(CCW(v[0], v[1], pt) < 0) return false; int l = 1, r = v.size() - 1;
while(l < r){
int m = l + r + 1 >> 1;
if(CCW(v[0], v[m], pt) >= 0) l = m; else r = m - 1;
}
if(l == v.size() - 1) return CCW(v[0], v.back(), pt) == 0 && v[0] <= pt && pt <=
v.back();
return CCW(v[0], v[l], pt) >= 0 && CCW(v[l], v[l+1], pt) >= 0 && CCW(v[l+1], v[0], pt)
>= 0;
}
