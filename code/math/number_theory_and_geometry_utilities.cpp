// • 카탈란수
// 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012,742900
// Cn = binomial(n ∗2, n)/(n + 1);
// - 길이가2n인올바른괄호수식의수
// - n + 1개의리프를가진풀바이너리트리의수
// - n + 2각형을n개의삼각형으로나누는방법의수
// 3 [f(x0) + f(xn) + 4 P f(x2i+1) + 2 P f(x2i)]
// • Simpson 공식(적분) : Simpson 공식, Sn(f) = h
// - M = max |f4(x)|이라고하면오차범위는최대En ≤M(b−a)
// h4
// • 알고리즘게임
// - Nim Game의해법: 각더미의돌의개수를모두XOR했을때0 이아니면첫번째, 0 이면두번째플레이어가
// 승리.
// - Grundy Number : 어떤상황의Grundy Number는, 가능한다음상황들의Grundy Number를모두모은
// 다음, 그집합에포함되지않는가장작은수가현재state의Grundy Number가된다. 만약다음state가
// 독립된여러개의state들로나뉠경우, 각각의state의Grundy Number의XOR 합을생각한다.
// - Subtraction Game : 한번에k 개까지의돌만가져갈수있는경우, 각더미의돌의개수를k + 1로나눈
// 나머지를XOR 합하여판단한다.
// - Index-k Nim : 한번에최대k개의더미를골라각각의더미에서아무렇게나돌을제거할수있을때, 각
// binary digit에대하여합을k + 1로나눈나머지를계산한다. 만약이나머지가모든digit에대하여0이라면
// 두번째, 하나라도0이아니라면첫번째플레이어가승리.
// - Misere Nim : 모든돌무더기가1이면N이홀수일때후공승, 그렇지않은경우XOR 합0이면후공승
// • Pick’s Theorem
// 격자점으로구성된simple polygon이주어짐. I 는polygon 내부의격자점수, B 는polygon 선분위격자점
// 수, A는polygon의넓이라고할때, 다음과같은식이성립한다. A = I + B/2 −1
// number of (x, y) : (0 <= x < n && 0 < y <= k/d x + b/d)
ll count_solve(ll n, ll k, ll b, ll d) { // argument should be positive
if (k == 0) {
return (b / d) * n;
}
if (k >= d || b >= d) {
return ((k / d) * (n - 1) + 2 * (b / d)) * n / 2 + count_solve(n, k % d, b % d, d);
}
return count_solve((k * n + b) / d, d, (k * n + b) % d, k);
}
// • 페르마포인트: 삼각형의세꼭짓점으로부터거리의합이최소가되는점
// 2π/3 보다큰각이있으면그점이페르마포인트, 그렇지않으면각변마다정삼각형그린다음, 정삼각형의
// 끝점에서반대쪽삼각형의꼭짓점으로연결한선분의교점
// (a2 + b2 + c2 + 4
// √
// 2π/3 보다큰각이없으면거리의합은
// q
// 3S)/2, S는넓이
// • 오일러정리: 서로소인두정수a, n에대해aϕ(n) ≡1 (mod n)
// 모든정수에대해an ≡an−ϕ(n) (mod n)
// m ≥log2n이면am ≡am%ϕ(n)+ϕ(n) (mod n)
// • g0 + g1 + g2 + · · · gp−2 ≡−1 (mod p) iff g = 1, otherwise 0.
