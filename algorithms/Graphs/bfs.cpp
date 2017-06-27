#include <stdio.h>
#include <vector>
#include <queue>
#define N 100000
using namespace std;

// SIMPLE ONE

vector < int > graph[N];
bool visited[N];

void bfs(int v) {
    queue<int> q;

    q.push(v);
    visited[v] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int p = graph[u][i];
            if (!visited[p]) {
                visited[p] = true;
                q.push(p);
            }
        }
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

    bfs(1);

    return 0;
}
