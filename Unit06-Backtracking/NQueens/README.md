# N-Queens
**Divya Sharma - IC-2K23-29**
## Problem Statement
Place N queens on an N×N board so that no two attack each other.
## Algorithm
Place queens column by column. For each column, try every row and check if the position is safe against the queens already placed in earlier columns. If safe, move to the next column. If no row works, return to the previous column and try the next row there.
The board is stored as a 1D array where index is column and value is row. This makes the safety check three lines - same row, same main diagonal, same anti-diagonal - because the column check is automatic.
## Pseudocode
```
SolveNQueens(n):
    board[0..n-1] = -1
    count = 0
    Place(col):
        if col == n:
            count = count + 1
            print board
            return
        for row from 0 to n-1:
            if IsSafe(board, row, col):
                board[col] = row
                Place(col + 1)
                board[col] = -1
    Place(0)
    return count
IsSafe(board, row, col):
    for i from 0 to col-1:
        if board[i] == row: return false
        if abs(board[i] - row) == abs(i - col): return false
    return true
```
## Complexity
Worst case is O(N!) because the algorithm could explore all row permutations. In practice the safe check prunes most branches and the number of nodes actually visited is much smaller. Space is O(N) for the board and the recursion stack.
## Sample Input / Output
```
N=4
Solution 1: 1 3 0 2
Solution 2: 2 0 3 1
Total: 2
N=8
Total: 92
```
