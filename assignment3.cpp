#include <iostream>
using namespace std;
class tictactoe{
    public:
void board_pattern(char board[][3]) {
    for (int i=0; i<3;i++) {
            for (int j=0;j<3;j++) {
                cout<<board[i][j];
                if (j<2)cout<<" | ";
            }cout<<endl;
            if(i<2)cout<<"---------"<<endl;
        }
}
bool Win_check(char board[][3], char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||(board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0]==player && board[1][1]==player && board[2][2]==player) ||
        (board[0][2]==player && board[1][1]==player && board[2][0]==player)) {
        return true;
    }
    return false;
}
bool check_board(char board[][3]) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
};
int main() {
    tictactoe obj1;
    char board[3][3];
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }
    char currentPlayer = 'X';
    do {
        obj1.board_pattern(board);
         int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {  
            board[row][col] = currentPlayer;
 if (obj1.Win_check(board, currentPlayer)) {
                obj1.board_pattern(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (obj1.check_board(board)) {
                obj1.board_pattern(board);
                cout << "It's a tie!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
        }

    } while (true);

    return 0;
}
