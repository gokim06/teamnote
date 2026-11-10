// ans contains the final euler circult
// In case of an Eulerian trail, add a temporary edge between two odd vertices,
// and remove it later.
vector<set<int>> graph;
vector<int> ans;
void dfs(int v) {
while (!graph[v].empty()) {
int u = *graph[v].begin();
graph[u].erase(v);
graph[v].erase(u);
dfs(u);
}
ans.push_back(v);
}
// • Eulerian cycle (undirected): all vertices must have even degree.
// • Eulerian cycle (directed): every vertex has equal indegree and outdegree.
// • Eulerian path (undirected): exactly zero or two vertices must have odd degree.
// • Eulerian path (directed): at most one vertex has out−in = 1 and at most one vertex has in−out = 1.
// all other vertices must have equal indegree and outdegree.
