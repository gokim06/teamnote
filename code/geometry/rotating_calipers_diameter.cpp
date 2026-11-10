// 가장먼두점을구하는함수, O(N)
// 주의: hull은반시계방향으로정렬된볼록다각형이어야함
pair<Point, Point> Calipers(vector<Point> hull){
int n = hull.size(); ll mx = 0; Point a, b;
for(int i=0, j=0; i<n; i++){
while(j + 1 < n && (hull[i+1] - hull[i]) / (hull[j+1] - hull[j]) >= 0){
ll now = Dist(hull[i], hull[j]);
if(now > mx) mx = now, a = hull[i], b = hull[j];
j++;
}
ll now = Dist(hull[i], hull[j]);
if(now > mx) mx = now, a = hull[i], b = hull[j];
}
return {a, b};
}
