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
    }
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
    if (dp[p][i] != dp[q][i])
      p = dp[p][i], q = dp[q][i];
  }

  return dp[p][0];
}

int main() {

}
