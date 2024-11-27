
def isSafe(board, row, col, n):
    # Check the column
    for i in range(row):
        if board[i] == col or \
           board[i] - i == col - row or \
           board[i] + i == col + row:
            return False
    return True

def solveNQueen(board, row, n):
    if row == n:
        # Print the board solution
        for i in range(n):
            print('.' * board[i] + 'Q' + '.' * (n - board[i] - 1))
        print()
        return True

    res = False
    for col in range(n):
        if isSafe(board, row, col, n):
            board[row] = col
            res = solveNQueen(board, row + 1, n) or res

    return res

def nQueens(n):
    board = [-1] * n  # Initialize the board with -1 (no queens placed)
    solveNQueen(board, 0, n)

n = 4  
nQueens(n)
