#include"BoardGame_Classes.hpp"
int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'X');
    cout << "Welcome to FCAI tic_tac_toe Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'O');
    else
        players[1] = new RandomPlayer ('O', 3);
    int x;
    cout<<"choose game you want to play"<<endl;
    cout<<"1.for pyramid tic tac toe "<<endl;
    cout<<"2.for four in a row "<<endl;
    cout<<"3.for 5x5 tic tac toe "<<endl;
    cout<<"4.for x_o "<<endl;
    cin>>x;
    if(x==1) {
        GameManager tic_tac_toe_game(new tic_tac_toe_Board(), players);
        tic_tac_toe_game.run();
    }
    else if(x==2){
        GameManager connect_four_game (new connect_four(), players);
        connect_four_game.run();
    }
    else if(x==3){
        GameManager tic_tac_toe_5x5_game(new tic_tac_toe_5x5(), players);
        tic_tac_toe_5x5_game.run();
    }
    else if(x==4){
        GameManager x_o_game (new X_O_Board(), players);
        x_o_game.run();
    }
}