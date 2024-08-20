#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function prototypes
void drawBoard(const vector<vector<char>> &board);
bool isBoardFull(const vector<vector<char>> &board);
bool checkWin(const vector<vector<char>> &board, char player);
bool isValidMove(const vector<vector<char>> &board, int row, int col);
void makeMove(vector<vector<char>> &board, int row, int col, char player);

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize 3x3 board with spaces

    bool player1Turn = true; // Player 1 starts the game
    bool gameEnd = false;

    cout << "Welcome to Tic-Tac-Toe!" << endl;

    while (!gameEnd)
    {
        // Draw the board
        drawBoard(board);

        // Determine current player
        char currentPlayer = (player1Turn) ? 'X' : 'O';
        cout << "Player " << currentPlayer << ", enter your move (row[1-3] col[1-3]): ";

        // Get player input
        int row, col;
        cin >> row >> col;

        // Convert input to zero-indexed
        row--; // Decrement by 1 to adjust for zero-indexing
        col--; // Decrement by 1 to adjust for zero-indexing

        // Check if the move is valid
        if (isValidMove(board, row, col))
        {
            // Make the move
            makeMove(board, row, col, currentPlayer);

            // Check for win
            if (checkWin(board, currentPlayer))
            {
                drawBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameEnd = true;
            }
            else if (isBoardFull(board))
            {
                drawBoard(board);
                cout << "It's a tie!" << endl;
                gameEnd = true;
            }
            else
            {
                // Switch turns
                player1Turn = !player1Turn;
            }
        }
        else
        {
            cout << "Invalid move! Please try again." << endl;
        }
    }

    cout << "Thanks for playing Tic-Tac-Toe!" << endl;

    return 0;
}

// Function to draw the Tic-Tac-Toe board
void drawBoard(const vector<vector<char>> &board)
{
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i)
    {
        cout << "| ";
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j] << " | ";
        }
        cout << endl;
        cout << "-------------" << endl;
    }
}

// Function to check if the board is full
bool isBoardFull(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>> &board, char player)
{
    // Check rows and columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
        {
            return true; // Row win
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
        {
            return true; // Column win
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
    {
        return true; // Main diagonal win
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
    {
        return true; // Anti-diagonal win
    }

    return false; // No win
}

// Function to check if a move is valid
bool isValidMove(const vector<vector<char>> &board, int row, int col)
{
    // Check if the position is within bounds and the cell is empty
    return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ');
}

// Function to make a move on the board
void makeMove(vector<vector<char>> &board, int row, int col, char player)
{
    board[row][col] = player;
}
