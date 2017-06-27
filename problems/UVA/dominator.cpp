#include <stdio.h>
#include <vector>
using namespace std;

vector <int> graph[101];
bool visited[101];

void dfs(int v, int reach) {
    if (visited[v]) return;

    visited[v] = true;



    for (int i = 0; i < graph[v].size(); i++) {
        int u = graph[v][i];
        dfs(u);
    }
}

int main() {
    int t, n, e;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        scanf("%d", &n);

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                scanf("%d", &e);

                if (e) {
                    graph[j].push_back(k);
                }
            }
        }


    }

    return 0;
}
