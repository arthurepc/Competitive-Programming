#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

vector < pair<int, int> > graph[200];
int costs[200];
int parent[200];

int prim(int s, int n) {
  for (int i = 0; i < n; i++) {
    costs[i] = 1000000000;
    parent[i] = -1;
  }

  priority_queue<pair<int, int> > q;

  costs[s] = 0;
  parent[s] = -1;

  int result = 0;

  while (!q.empty()) {
    pair<int, int> u = q.top();
    q.pop();

    for (int i = 0; i < graph[u].size(); i++) {
      pair<int, int> v = graph[u][i];

      if (costs[v.second] > v.first) {
        costs[v] = v.first;
        parent[v] = u.seconf;
        q.push(v);
        result += costs[v];
      }
    }
  }
}


int main() {
  int n, m, u, v, w;

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &u, &v, &w);

    graph[u].push_back(make_pair(w, v));
    graph[v].push_back(make_pair(w, u));
  }
}


