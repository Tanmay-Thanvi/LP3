// N Queen Problem

#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> ans_when_queen_placed, ans_when_queen_not_placed;

int placed_row = -1, placed_col = -1;

void print_board(vector<string> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board.size(); j++)
        {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

void n_queen(int col, vector<string> &board, vector<bool> &leftrow, vector<bool> &upperdiagonal, vector<bool> &lowerdiagonal)
{
    int n = board.size();
    if (col == n)
    {
        if (board[placed_row][placed_col] == 'Q')
        {
            ans_when_queen_placed.push_back(board);
        }
        ans_when_queen_not_placed.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftrow[row] == 0 and upperdiagonal[n - 1 - (row - col)] == 0 and lowerdiagonal[row + col] == 0)
        {
            leftrow[row] = 1;
            upperdiagonal[n - 1 - row + col] = 1;
            lowerdiagonal[col + row] = 1;

            board[row][col] = 'Q';
            n_queen(col + 1, board, leftrow, upperdiagonal, lowerdiagonal);
            board[row][col] = '.';

            leftrow[row] = 0;
            upperdiagonal[n - 1 - row + col] = 0;
            lowerdiagonal[col + row] = 0;
        }
    }
}

int main()
{
    int n;
    vector<bool> leftrow(n, 0), upperdiagonal(2 * n - 1, 0), lowerdiagonal(2 * n - 1, 0);

    cout << "Enter size of ChessBoard : ";
    cin >> n;
    cout << endl;

    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    cout << "# Note : Indexing starts from 0,0" << endl;
    cout << "Enter Queen's position (x,y) to be placed : ";
    cin >> placed_row >> placed_col;

    cout << "Board looks like : \n";
    board[placed_row][placed_col] = 'Q';
    print_board(board);
    board[placed_row][placed_col] = '.';
    cout << endl;

    n_queen(0, board, leftrow, upperdiagonal, lowerdiagonal);

    cout << "Total Solutions When Queen Is Placed ( " << ans_when_queen_placed.size()
         << " Out of " << ans_when_queen_not_placed.size() << " ) : \n"
         << endl;

    for (int i = 0; i < ans_when_queen_placed.size(); i++)
    {
        print_board(ans_when_queen_placed[i]);
    }

    char choice;
    cout << "Do You Want to Print N-Queen Result (Y/N) ? : ";
    cin >> choice;
    cout << endl;

    if (toupper(choice) == 'Y')
    {
        cout << "\nTotal Solutions When Queen Is Not Placed ( "
             << ans_when_queen_not_placed.size() << " ) : \n"
             << endl;

        for (int i = 0; i < ans_when_queen_not_placed.size(); i++)
        {
            print_board(ans_when_queen_not_placed[i]);
        }
    }
    else if (toupper(choice) != 'N')
    {
        cout << "You Provided Invalid Input " << endl;
    }

    cout << "\nProgram End!" << endl;
    return 0;
}

/*
    Time Complexity: O(N!)
    Auxiliary Space: O(N^2)
*/