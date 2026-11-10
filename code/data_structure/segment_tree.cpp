// Time Complexity: O(log N)
// SZ: N보다크거나같은2^k 꼴의수
// 13만-> 1 << 17 (131072), 26만-> 1 << 18 (262144)
// 52만-> 1 << 19 (524288), 100만-> 1 << 20 (1048576)
constexpr int SZ = 1 << 20;
ll T[SZ<<1];
void Set(int x, ll v){ // x번째수를v로지정, x는0 이상SZ 미만
x += SZ; T[x] = v;
while(x /= 2) T[x] = T[x*2] + T[x*2+1];
}
ll Sum(int l, int r){ // [l, r] 구간의합
ll res = 0;
for(l+=SZ, r+=SZ; l<=r; l/=2, r/=2){
if(l % 2 == 1) res += T[l++];
if(r % 2 == 0) res += T[r--];
}
return res;
}
