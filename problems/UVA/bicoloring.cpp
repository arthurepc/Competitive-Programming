#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[201];
int colors[201];

bool isBipartite(int v) {
    queue<int> q;
    colors[v] = 0;
    q.push(v);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int p = graph[u][i];

            if (colors[p] == -1) {
                colors[p] = 1 - colors[u];
                q.push(p);
            }else if (colors[p] == colors[u]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int n, m, u, v;

    while (scanf("%d", &n) && n != 0) {

        for (int i = 0; i < n; i++) {
            colors[i] = -1;
        }

        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }

        scanf("%d", &m);

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        if (isBipartite(0)) {
            printf("BICOLORABLE.\n");
        } else {
            printf("NOT BICOLORABLE.\n");
        }
    }

    return 0;
}
