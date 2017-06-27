#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

vector < pair<int, int> > graph[201];
int dist[201];

bool bellmanFord(int s, int n) {

    for (int i = 0; i < n; i++) {
        dist[i] = 1000000000;
    }

    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (int j = 0; j < graph[u].size(); j++) {
                pair<int, int> v = graph[u][j];

                if (dist[v.first] > dist[u] + v.second) {
                    dist[v.first] = dist[u] + v.second;
                }
            }
        }
    }

    bool hasNegativeCycle = false;
    for (int u = 0; u < n; u++) {
        for (int j = 0; j < graph[u].size(); j++) {
            pair<int, int> v = graph[u][j];
            if (dist[v.first] > dist[u] + v.second)
                hasNegativeCycle = true;
        }
    }

    return hasNegativeCycle;
}


int main() {
    int n, m, u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back(make_pair(v, w));
    }

    printf("%d\n", bellmanFord(0, n)? 1 : 0);

    printf("%d", dist[2]);

    return 0;
}
