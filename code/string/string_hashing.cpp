// Time Complexity: build: O(N), get: O(1)
// 전처리O(N), 부분문자열의해시값을O(1)에구함
// Hashing<917, 998244353> H;
// H.build("ABCDABCD");
// assert(H.get(1, 4) == H.get(5, 8));
// 주의: get 함수의인자는1-based 닫힌구간
// 주의: M은10억근처의소수, P는M과서로소
// 1e5+3, 1e5+13, 131'071, 524'287, 1'299'709, 1'301'021
// 1e9-63, 1e9+7, 1e9+9, 1e9+103
template<long long P, long long M> struct Hashing {
vector<long long> h, p;
void build(const string &s){
int n = s.size();
h = p = vector<long long>(n+1); p[0] = 1;
for(int i=1; i<=n; i++) h[i] = (h[i-1] * P + s[i-1]) % M;
for(int i=1; i<=n; i++) p[i] = p[i-1] * P % M;
}
long long get(int s, int e) const {
long long res = (h[e] - h[s-1] * p[e-s+1]) % M;
return res >= 0 ? res : res + M;
}
};
