#include"BoardGame_Classes.hpp"
Player::Player(char symbol) {
    this->symbol = symbol;
}
Player::Player (int order, char symbol) {
    cout << "Welcome player " << order << endl;
    cout << "Please enter your name: ";
    cin >> name;
    this->symbol = symbol;
}
void Player::get_move (int& x, int& y) {
    cout << "\nPlease enter your move x and y (0 to 2) separated by spaces: ";
    cin >> x >> y;
}
string Player::to_string(){
    return "Player: " + name ;
}
char Player::get_symbol() {
    return symbol;
}
