#include <stdio.h>

#define MAX 100

int main() {
    int n, m;
    int adj[MAX][MAX] = {0};
    int indegree[MAX] = {0};
    int queue[MAX], front = 0, rear = -1;

    scanf("%d %d", &n, &m);

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // compute indegree
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j]) {
                indegree[j]++;
            }
        }
    }

    // enqueue nodes with indegree 0
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            queue[++rear] = i;
        }
    }

    int count = 0;

    // process queue
    while (front <= rear) {
        int v = queue[front++];
        printf("%d ", v);
        count++;

        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[++rear] = i;
                }
            }
        }
    }

    // if all vertices are not processed → cycle exists
    if (count != n) {
        printf("\nCycle detected. Topological sort not possible.\n");
    }

    return 0;
}