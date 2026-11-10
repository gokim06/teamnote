// Time Complexity: O(V 3)
int N, G[111][111];
void Init(){ // 시작전에호출해야함
memset(G, 0x3f, sizeof G);
for(int i=1; i<=N; i++) G[i][i] = 0;
}
// s에서e로가는가중치w 간선추가
void AddEdge(int s, int e, int w){
G[s][e] = min(G[s][e], w);
}
void Run(){
for(int k=1; k<=N; k++)
for(int i=1; i<=N; i++)
for(int j=1; j<=N; j++)
G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}
