// Time Complexity: O(N log N)
typedef complex<double> cpx;
void FFT(vector<cpx> &a, bool inv_fft=false){
int N = a.size(); vector<cpx> root(N/2);
for(int i=1, j=0; i<N; i++){
int bit = N / 2;
while(j >= bit) j -= bit, bit >>= 1;
if(i < (j += bit)) swap(a[i], a[j]);
}
double ang = 2 * acos(-1) / N * (inv_fft ? -1 : 1);
for(int i=0; i<N/2; i++) root[i] = cpx(cos(ang*i), sin(ang*i));
for(int i=2; i<=N; i<<=1){
int step = N / i;
for(int j=0; j<N; j+=i) for(int k=0; k<i/2; k++){
cpx u = a[j+k], v = a[j+k+i/2] * root[step * k];
a[j+k] = u+v; a[j+k+i/2] = u-v;
}
}
if(inv_fft) for(int i=0; i<N; i++) a[i] /= N;
}
// [버전1] 일반곱셈: 결과값이10^14 이하일때사용(빠름)
vector<ll> multiply(const vector<ll> &_a, const vector<ll> &_b){
vector<cpx> a(all(_a)), b(all(_b));
int N = 2; while(N < a.size() + b.size()) N <<= 1;
a.resize(N); b.resize(N); FFT(a); FFT(b);
for(int i=0; i<N; i++) a[i] *= b[i];
vector<ll> ret(N); FFT(a, 1);
for(int i=0; i<N; i++) ret[i] = llround(a[i].real());
while(ret.size() > 1 && ret.back() == 0) ret.pop_back();
return ret;
}
// [버전2] 모듈러곱셈: 결과값이아주크거나모듈러연산이필요할때사용(안전함) 상수가커서조금
느릴수있음(약3~4배)
vector<ll> multiply_mod(const vector<ll> &a, const vector<ll> &b, const ull mod){
int N = 2; while(N < a.size() + b.size()) N <<= 1;
vector<cpx> v1(N), v2(N), r1(N), r2(N);
for(int i=0; i<a.size(); i++) v1[i] = cpx(a[i] >> 15, a[i] & 32767);
for(int i=0; i<b.size(); i++) v2[i] = cpx(b[i] >> 15, b[i] & 32767);
FFT(v1); FFT(v2);
for(int i=0; i<N; i++){
int j = i ? N-i : i;
cpx ans1 = (v1[i] + conj(v1[j])) * cpx(0.5, 0);
cpx ans2 = (v1[i] - conj(v1[j])) * cpx(0, -0.5);
cpx ans3 = (v2[i] + conj(v2[j])) * cpx(0.5, 0);
cpx ans4 = (v2[i] - conj(v2[j])) * cpx(0, -0.5);
r1[i] = (ans1 * ans3) + (ans1 * ans4) * cpx(0, 1);
r2[i] = (ans2 * ans3) + (ans2 * ans4) * cpx(0, 1);
}
vector<ll> ret(N); FFT(r1, true); FFT(r2, true);
for(int i=0; i<N; i++){
ll av = llround(r1[i].real()) % mod;
ll bv = ( llround(r1[i].imag()) + llround(r2[i].real()) ) % mod;
ll cv = llround(r2[i].imag()) % mod;
ret[i] = (av << 30) + (bv << 15) + cv;
ret[i] %= mod; ret[i] += mod; ret[i] %= mod;
}
while(ret.size() > 1 && ret.back() == 0) ret.pop_back();
return ret;
}
// ================= FFT 템플릿끝=================
[사용방법가이드]
vector<ll> A,B = {1, 2, 3}; // x^0, x^1, x^2 순서다항식의계수를담는다.
vector<ll> res = multiply(A, B); // A랑B곱한계수를담는다.
vector<ll> res_mod = multiply_mod(C, D, MOD); // 곱한결과를MOD로나눈나머지를요구할때. (ull
MOD)
for(int i=0; i<res.size(); i++) cout << res[i] << " "; // i번째인덱스= x^i의계수
for(int i=0; i<raw_res.size(); i++) { // 큰수곱셈자릿수올림처리
if(raw_res[i] >= 10) {
if(i == raw_res.size() - 1) raw_res.push_back(0); // 자리늘리기
raw_res[i+1] += raw_res[i] / 10;
raw_res[i] %= 10;}}
