// 다각형의넓이의2배를반환, 항상정수, O(N)
ll PolygonArea(const vector<Point> &v){
ll res = 0;
for(int i=0; i<v.size(); i++) res += v[i] / v[(i+1)%v.size()];
return abs(res);
}
