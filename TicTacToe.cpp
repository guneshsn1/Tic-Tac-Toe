#include <iostream>
#include <ctime>
#include <string>

void drawBoard(char *spaces);
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);
int main(){
    char spaces[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char computer = 'O';
    char winner = ' ';
    bool running = true;

    std::cout << "Welcome to Tic Tac Toe!\n";
    std::cout << "***************************\n";
    drawBoard(spaces);
    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        if(checkWinner(spaces, player, computer) || checkTie(spaces)){
            running = false;
            break;
        }
        computerMove(spaces, computer);
        drawBoard(spaces);  
        if(checkWinner(spaces, player, computer) || checkTie(spaces)){
            running = false;
            break;
        }  
    }
    std::cout << "Thanks for playing!\n";
    return 0;
}
void drawBoard(char *spaces){
    std::cout << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
    std::cout << "_____|_____|_____" << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
    std::cout << "     |     |     " << '\n';
    std::cout << '\n';
}
void playerMove(char *spaces, char player){
    std::string input;
    int number;
    do{
        std::cout << "Enter a number (1-9): ";
        std::getline(std::cin, input);
        try{
            number = std::stoi(input);
        }
        catch(const std::exception& e){
            std::cout << "Invalid input. Please enter a number between 1 and 9.\n";
            number = -1;
        }
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
            break;
        }
    }while(!number > 0 || !number < 8);
}
void computerMove(char *spaces, char computer){
    int number;
    srand(time(NULL));
    while(true){
        number = rand() % 9;
        if(spaces[number] == ' '){
            spaces[number] = computer;
            break;
        }
    }
}
bool checkWinner(char *spaces, char player, char computer){
    for(int i = 0; i < 3; i++){
        if(spaces[i*3] == spaces[i*3 + 1] && spaces[i*3 + 1] == spaces[i*3 + 2] && spaces[i*3] != ' '){
            spaces[i] == player ? std::cout << "Player wins!\n" : std::cout << "Computer wins!\n";
            return true;
        }
        if(spaces[i] == spaces[i + 3] && spaces[i + 3] == spaces[i + 6] && spaces[i] != ' '){
            spaces[i] == player ? std::cout << "Player wins!\n" : std::cout << "Computer wins!\n";
            return true;
        }
    }
    if(spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' '){
        spaces[0] == player ? std::cout << "Player wins!\n" : std::cout << "Computer wins!\n";
        return true;
    }
    if(spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' '){
        spaces[2] == player ? std::cout << "Player wins!\n" : std::cout << "Computer wins!\n";
        return true;
    }

    return false;
}
bool checkTie(char *spaces){
    for(int i = 0; i < 9; i++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "It's a tie!\n";
    return true;
}