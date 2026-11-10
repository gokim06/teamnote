// Time Complexity: O(log max(a, b))
// 정수a, b 주어지면ax + by = gcd(a, b) = g
// 를만족하는정수{g, x, y} 반환
tuple<ll,ll,ll> ext_gcd(ll a, ll b){
if(b == 0) return {a, 1, 0};
auto [g,x,y] = ext_gcd(b, a % b);
return {g, y, x - a/b * y};
}
