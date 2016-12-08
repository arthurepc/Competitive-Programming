#include <stdio.h>
#include <vector>

#define N 1000000
#define LOG 21

using namespace std;


int dp[N][LOG];
int level[N];
vector<int> graph[N];

void dfs(int v, int l, int p) {
  if (level[v] != -1) return;

  level[v] = l + 1;
  dp[v][0] = p;

  for (int i = 0; i < graph[v].size(); i++)
    dfs(graph[v][i], level[v], v);
}

void build(int n) {
  for (int k = 1; k < LOG; k++) {
    for (int j = 1; j <= n; j++) {
        dp[j][k] = dp[dp[j][k - 1]][k - 1];
        //printf("%d", dp[j][k]);
    }
    //printf("\n");
  }
}

int lca(int p, int q) {
  if (level[p] < level[q]) swap(p, q);

  for (int i = LOG; i >= 0; i--) {
    if (level[p] - (1 << i) >= level[q])
      p = dp[p][i];
  }

  if (p == q) return p;

  for (int i = LOG - 1; i >= 0; i--) {
    //printf("i = %d, p == %d, q == %d\n", i, dp[p][i], dp[q][i]);
    if (dp[p][i] != dp[q][i])
      p = dp[p][i], q = dp[q][i];
  }

  return dp[p][0];
}

int main() {
    int t, n, m, u, q, v, w;

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {

        printf("Case %d:\n", i+1);

        scanf("%d", &n);


        for (int j = 0; j <= n; j++) {
            level[j] = -1;
        }

        for (int j = 0; j <= n; j++)
            graph[j].clear();

        for (int j = 0; j < n; j++) {
            scanf("%d", &m);

            for (int k = 0; k < m; k++) {
                scanf("%d", &u);

                graph[j+1].push_back(u);
                graph[u].push_back(j+1);
            }
        }

        dfs(1, -1, 1);
        build(n);
/*
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < graph[i].size(); j++)
                printf("n = %d, g = %d\n", i, graph[i][j]);
        }
*/
        scanf("%d", &q);

        for (int j = 0; j < q; j++) {
            scanf("%d %d", &v, &w);

            printf("%d\n", lca(v, w));
        }
    }


    return 0;
}
