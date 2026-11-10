#include <stdio.h>
#include <stdbool.h>
#define N 5
int adj[N][N] = {
    {0, 1, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {1, 0, 0, 1, 0},
    {0, 1, 1, 0, 1},
    {0, 0, 0, 1, 0}
};
char label[N] = {'A', 'B', 'C', 'D', 'E'};
void bfs(int start) {
    bool visited[N] = {false};
    int queue[N], front = 0, rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    printf("BFS: ");
    while (front < rear) {
        int node = queue[front++];
        printf("%c ", label[node]);
        for (int i = 0; i < N; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void dfs(int start) {
    bool visited[N] = {false};
    int stack[N], top = -1;
    stack[++top] = start;
    printf("DFS: ");
    while (top >= 0) {
        int node = stack[top--];
        if (visited[node]) continue;
        visited[node] = true;
        printf("%c ", label[node]);
        for (int i = N - 1; i >= 0; i--) {
            if (adj[node][i] && !visited[i]) stack[++top] = i;
        }
    }
    printf("\n");
}
int main(void) {
    bfs(0);
    dfs(0);
    return 0;
}
