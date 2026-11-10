#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool is_safe(int board[], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[i] == row) return false;
        if (abs(board[i] - row) == abs(i - col)) return false;
    }
    return true;
}
void place(int col, int n, int board[], int *count) {
    if (col == n) {
        (*count)++;
        printf("Solution %d: ", *count);
        for (int i = 0; i < n; i++) printf("%d ", board[i]);
        printf("\n");
        return;
    }
    for (int row = 0; row < n; row++) {
        if (is_safe(board, row, col)) {
            board[col] = row;
            place(col + 1, n, board, count);
            board[col] = -1;
        }
    }
}
void solve(int n) {
    int *board = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) board[i] = -1;
    int count = 0;
    printf("N=%d\n", n);
    place(0, n, board, &count);
    printf("Total: %d\n\n", count);
    free(board);
}
int main(void) {
    solve(4);
    solve(8);
    return 0;
}
