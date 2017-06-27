#include <stdio.h>
#include <vector>

#define N 100000
#define LOG 21

using namespace std;


int dp[N][LOG];
int level[N];
int cost[N];
vector<int> graph[N];

void dfs(int v, int l, int p, int costv) {
  if (level[v] != -1) return;

  level[v] = l + 1;
  dp[v][0] = p;
  costv = costv + cost[v];

  for (int i = 0; i < graph[v].size(); i++)
    dfs(graph[v][i], level[v], v, costv);
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
    int n, a, l, q, s, t;

    while (scanf("%d", &n) && n != 0) {

    }



    return 0;
}
