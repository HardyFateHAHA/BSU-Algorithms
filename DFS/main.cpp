#include <bits/stdc++.h>

using namespace std;


/*
//список ребер
int vertexCount , edgeCount;
cin >> vertexCount >> edgeCount;//вершины и ребра
vector<pair<int , int>> edges(edgeCount);
for(auto &[a , b] : edges){
    cin >> a >> b;
    a--;
    b--;
}
*/

/*
//матрица смежности
int vertexCount , edgeCount;
cin >> vertexCount >> edgeCount;//вершины и ребра
vector<vector<int>> graph(vertexCount , vector<int>(vertexCount));
for(int i = 0 ; i < edgeCount ; i++){
    int a , b;
    cin >> a >> b;
    a--;
    b--;
    graph[a][b] = 1;
    graph[b][a] = 1; //для неориентированного  графа
}
*/

/*
int vertexCount , edgeCount;
cin >> vertexCount >> edgeCount;//вершины и ребра
vector<vector<int>> graph(vertexCount);
for(int i = 0 ; i < edgeCount ; i++){
    int a , b;
    cin >> a >> b;
    a--;
    b--;
    graph[a].push_back(b);
    graph[b].push_back(a); //для неориентированного графа
void dfs(vector<vector<int>> &graph , int v){
    visited[v] = 1;
    for(int to = 0 ; to < graph.size() ; to++){
        if(!visited[to] && graph[v][to])dfs(graph , to , visited);
    }
}
}
*/

vector<int> visited(101 , 0);
int n , k(0) , a[101][101];
void dfs(int v){
    k++;
    visited[v] = k;
    for(int t = 1 ; t <= n ; t++)if(visited[t] == 0 && a[v][t])dfs(t);
}
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    bool flag = true;
    for(int i = 1 ; i <= n ; i++)
        for(int j = 1 ; j <= n ; j++)
            cin >> a[i][j];

    for(int i = 1 ; i <= n ; i++)if(visited[i] == 0)dfs(i);
    for(int i = 1 ; i <= n ; i++)cout << visited[i] << ' ';
    cout << '\n';
    return 0;
}