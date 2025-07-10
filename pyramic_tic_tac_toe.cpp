#include "pyramic_tic_tac_toe.h"
tic_tac_toe_Board::tic_tac_toe_Board(){
    n_rows =3, n_cols = 5;
    board = new char *[n_rows];
    for (int k = 0; k < n_rows; k++) {
        board[k] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[k][j] = 0;
    }
}
bool tic_tac_toe_Board::update_board (int x, int y, char mark) {
    if (!(x < 0 || x > 2 || y < 0 || y > 4) && ( board[x][y]==0)) {
        if (x == 0 && board[0][0]==0) {
            y = 0;
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        else if (x == 1 && y <= 2 ) {
            if(board[1][0]==0||board[1][1]==0||board[1][2]==0) {
                board[x][y] = toupper(mark);
                n_moves++;
                return true;
            }
            else{
                cout<<"false position"<<endl;
                return false;}
        }
        else if (x == 2) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
        else{
            cout<<"false position"<<endl;
            return false;}
    }
    else{
        cout<<"false position"<<endl;
        return false;}
}
void tic_tac_toe_Board::display_board(){
    cout << "\n                          ------                   "<<endl;
    cout << "                     ";
    cout << "  | (" << '0' << ',' << '0' << ")(" << board [0][0]<<") |";
    cout << "\n                     ---------------                     " << endl;
    cout << "           ";
    for (int k: {0, 1, 2}) {
        cout << " | (" << '1' << ',' << k << ")("<< board [1][k]<<")";
    }
    cout << "\n           ----------------------------------           " << endl;
    for (int k: {0, 1, 2, 3, 4}) {
        cout << " | (" << '2' << ',' << k << ")("<<board [2][k]<<")";
    }
    cout << "\n----------------------------------------------------------" << endl;
}
bool tic_tac_toe_Board::is_winner() {
    if(board[0][0] !=0){
        if(board[1][1] == board[0][0]) {
            if (board[2][2] == board[0][0]) { return true; }
        }
        else if(board[1][2] == board[0][0]){
            if(board[2][4] ==board[0][0]){return true;}
        }
        else  if(board[1][0] == board[0][0] && board[2][0] ==board[0][0]){return true;}
    }
    if((board[2][0] !=0 &&board[2][1] == board[2][0] && board[2][2] ==board[2][0] )){return true;}
    if((board[2][1] !=0 &&board[2][2] == board[2][1] && board[2][3] ==board[2][1] )){return true;}
    if((board[2][2] !=0 &&board[2][3] == board[2][2] && board[2][4] ==board[2][2] )){return true;}
    else{
        return false;
    }
}
bool tic_tac_toe_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}
bool tic_tac_toe_Board::game_is_over () {
    return n_moves >= 9;
}


