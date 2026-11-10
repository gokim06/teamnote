// 다각형내부또는경계위에p가있으면true, O(N)
bool PointInPolygon(const vector<Point> &v, Point p){
int n = v.size(), cnt = 0;
Point p2(p.x+1, 1'000'000'000 + 1); // 좌표범위보다큰수
for(int i=0; i<n; i++){
int j = i + 1 < n ? i + 1 : 0;
if(min(v[i],v[j]) <= p && p <= max(v[i],v[j]) && CCW(v[i], v[j], p) == 0) return
true;
if(SegmentIntersection(v[i], v[j], p, p2)) cnt++;
}
return cnt % 2 == 1;
}
