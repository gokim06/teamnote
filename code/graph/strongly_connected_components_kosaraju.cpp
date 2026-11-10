// Time Complexity: O(V + E)
constexpr int SZ = 101010;
int N, M;
vector<int> G[SZ], R[SZ]; // G: 원래 그래프, R: 역방향 그래프
vector<int> V; // DFS1 종료 순서
vector<vector<int>> S; // SCC별 정점 리스트
int C[SZ];
// C[i]: i번정점이속한SCC 번호(0:미방문, -1:DFS1방문, 1이상:SCC ID)
// 1. 간선추가(양방향저장)
void AddEdge(int s, int e){
G[s].push_back(e); R[e].push_back(s); }
// 2. 첫번째DFS: 종료순서대로V에담기(위상정렬순서파악)
void DFS1(int v){
C[v] = -1; // 방문표시(임시)
for(auto i : G[v]) if(!C[i]) DFS1(i);
V.push_back(v); // 끝나는순서대로넣음
}
// 3. 두번째DFS: 역방향그래프에서묶기(SCC 형성)
void DFS2(int v, int c){
C[v] = c; // SCC 번호부여
S.back().push_back(v); // 현재SCC 그룹에추가
for(auto i : R[v]) if(C[i] == -1) DFS2(i, c);
}
int GetSCC(){
// 초기화(여러테스트케이스일경우필요)
// S.clear(); V.clear(); memset(C, 0, sizeof(C));
// Step 1: 정방향DFS로스택(V) 채우기
for(int i=1; i<=N; i++) if(!C[i]) DFS1(i);
// Step 2: 스택을뒤집어서역방향DFS 수행
reverse(V.begin(), V.end());
int cnt = 0;
for(auto i : V) {
if(C[i] == -1) { // DFS1에서방문했지만아직SCC 그룹이없는경우
S.emplace_back(); // 새로운SCC 그룹생성
DFS2(i, ++cnt);
// SCC 번호는1번부터시작
}
} return cnt; // 총SCC 개수반환}
