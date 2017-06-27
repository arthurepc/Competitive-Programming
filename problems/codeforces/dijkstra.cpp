#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define N 100010

vector <pair <int, int> > graph[N];
int dist[N];
int parent[N];

void dijkstra(int s, int n) {
    priority_queue<int> q;
    dist[s] = 0;
    q.push(-s);
    parent[s] = -1;

    while (!q.empty()) {
        int v = -q.top();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            pair<int, int> u = graph[v][i];
            if (dist[u.first] > dist[v] + u.second) {
                dist[u.first] = dist[v] + u.second;
                q.push(-u.first);
                parent[u.first] = v;
            }
        }
    }
}

int main() {
    int n, m, u, v, w;
    vector<int> ans;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) { // check for nodes indexes
        dist[i] = 1000000000;
        parent[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);

        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }

    dijkstra(1, n);

    if (dist[n] == 1000000000) {
        printf("-1");
        return 0;
    }

    int i = n;
    ans.push_back(n);
    while (parent[i] != -1) {
        ans.push_back(parent[i]);
        i = parent[i];
    }

    for (int i = ans.size() - 1; i >= 0; i--) {
        printf("%d ", ans[i]);
    }

    return 0;
}
