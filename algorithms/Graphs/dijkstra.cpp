#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <pair <int, int> > graph[200];
int dist[201];

void dijkstra(int s, int n) {
    for (int i = 0; i < n; i++) { // check for nodes indexes
        dist[i] = 1000000000;
    }

    priority_queue<int> q;
    dist[s] = 0;
    q.push(make_pair(0, s));

    while (!q.empty()) {
        int v = -q.top();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            pair<int, int> u = graph[v][i];
            if (dist[u.first] > dist[v] + u.second) {
                dist[u.first] = dist[v] + u.second;
                q.push(make_pair(-dist[u.first], u.first));
            }
        }
    }
}

int main() {
    int n, m, u, v, w;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back(make_pair(v, w));
    }

    dijkstra(0, n); // check for indexes (starts with 0 or 1?)

    printf("%d", dist[2]);

    return 0;
}
