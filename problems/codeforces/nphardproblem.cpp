#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[100200];
int colorArr[100200];


bool isBipartite(int src) {
    // Create a color array to store colors assigned to all veritces. Vertex
    // number is used as index in this array. The value '-1' of  colorArr[i]
    // is used to indicate that no color is assigned to vertex 'i'.  The value
    // 1 is used to indicate first color is assigned and value 0 indicates
    // second color is assigned.
    for (int i = 0; i < 100200; ++i)
        colorArr[i] = -1;

    // Assign first color to source
    colorArr[src] = 1;

    // Create a queue (FIFO) of vertex numbers and enqueue source vertex
    // for BFS traversal
    queue <int> q;
    q.push(src);

    // Run while there are vertices in queue (Similar to BFS)
    while (!q.empty())
    {
        // Dequeue a vertex from queue ( Refer http://goo.gl/35oz8 )
        int u = q.front();
        q.pop();

         // Find all non-colored adjacent vertices
        for (int v = 0; v < graph[u].size(); ++v)
        {
            // An edge from u to v exists and destination v is not colored
            if (graph[u][v] && colorArr[v] == -1)
            {
                // Assign alternate color to this adjacent v of u
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }

            //  An edge from u to v exists and destination v is colored with
            // same color as u
            else if (graph[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }

    // If we reach here, then all adjacent vertices can be colored with
    // alternate color
    return true;
}


int main() {
    int n, m, u, v;

    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    //printf("%s", isBipartite(1)? "sim" : "nao");

    if (isBipartite(1)) {
        vector <int> a, b;
        for (int i = 1; i <= n; i++) {
            printf("%d ", colorArr[i]);
            if (colorArr[i] == 1) a.push_back(i);
            else if (colorArr[i] == 0) b.push_back(i);
        }
/*
        printf("%d", a.size());
        for (int i = 0; i < a.size(); i++) {
            if (i == a.size() - 1) printf("%d\n", a[i]);
            else printf("%d ", a[i]);
        }


        printf("%d", b.size());
        for (int i = 0; i < b.size(); i++) {
            if (i == b.size() - 1) printf("%d\n", b[i]);
            else printf("%d ", b[i]);
        }*/
//    } else printf("-1");

    return 0;
}
