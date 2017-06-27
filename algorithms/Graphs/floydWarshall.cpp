#include <stdio.h>
using namespace std;

int graph[n][n];

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matriz[i][j] = min(matriz[i][k] + matriz[k][j], matriz[i][j]);
            }
        }
    }
}

int main() {

}
