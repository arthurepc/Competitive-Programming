#include <stdio.h>
#include <vector>
#define N 100000
using namespace std;

// SIMPLE ONE

vector < int > graph[N];
bool visited[N];

void dfs(int v) {
    if (visited[v]) return;

    visited[v] = true;
    printf("%d\n", v);

    for (int i = 0; i < graph[v].size(); i++) {
        dfs(graph[v][i]);
    }
}

int main() {
    int n, m, v, u;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);

    return 0;
}
