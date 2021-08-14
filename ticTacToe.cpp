// Simple Tic Tac Toe Program

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <time.h>

using namespace std;

void displayBoard(char b[3][3]){
    int x = 0;
    int y = 0;
    cout << endl;
    cout << "Current Board: " << endl;
    for(int i = 1; i < 12; i++){
        if(i % 4 == 0){
            cout << "-------|-------|-------" << endl;
        }
        else if(i % 2 == 0){
            y = 0;
            cout << "   " << b[x][y] << "   |   ";
            y++;
            cout << b[x][y] << "   |   ";
            y++;
            cout << b[x][y] << endl;
            x++;
        }
        else{
            cout << "       |       |" << endl;
        }
    }
    cout << endl;
}

void menu(){
    cout << endl;
    cout << "---------MENU--------" << endl;
    cout << "1: Top Left" << endl;
    cout << "2: Top Middle" << endl;
    cout << "3: Top Right" << endl;
    cout << "4: Middle Left" << endl;
    cout << "5: Center" << endl;
    cout << "6: Middle Right" << endl;
    cout << "7: Bottom Left" << endl;
    cout << "8: Bottom Middle" << endl;
    cout << "9: Bottom Right" << endl;
    cout << "Enter your choice: ";
}

bool winner(vector<int> v){
    if((find(v.begin(), v.end(), 1) != v.end() && 
        find(v.begin(), v.end(), 2) != v.end() && 
        find(v.begin(), v.end(), 3) != v.end()) ||
        (find(v.begin(), v.end(), 4) != v.end() && 
        find(v.begin(), v.end(), 5) != v.end() && 
        find(v.begin(), v.end(), 6) != v.end()) ||
        (find(v.begin(), v.end(), 7) != v.end() && 
        find(v.begin(), v.end(), 8) != v.end() && 
        find(v.begin(), v.end(), 9) != v.end()) ||
        (find(v.begin(), v.end(), 1) != v.end() && 
        find(v.begin(), v.end(), 4) != v.end() && 
        find(v.begin(), v.end(), 7) != v.end()) ||
        (find(v.begin(), v.end(), 2) != v.end() && 
        find(v.begin(), v.end(), 5) != v.end() && 
        find(v.begin(), v.end(), 8) != v.end()) ||
        (find(v.begin(), v.end(), 3) != v.end() && 
        find(v.begin(), v.end(), 6) != v.end() && 
        find(v.begin(), v.end(), 9) != v.end()) ||
        (find(v.begin(), v.end(), 1) != v.end() && 
        find(v.begin(), v.end(), 5) != v.end() && 
        find(v.begin(), v.end(), 9) != v.end()) ||
        (find(v.begin(), v.end(), 3) != v.end() && 
        find(v.begin(), v.end(), 5) != v.end() && 
        find(v.begin(), v.end(), 7) != v.end())){
            return true;
    }
    else{
        return false;
    }
}

pair<int, int> index(int pos){
    pair<int, int> i;
    switch (pos){
        case 1:
            return i = make_pair(0,0);
        case 2:
            return i = make_pair(0,1);;
        case 3:
            return i = make_pair(0,2);
        case 4:
            return i = make_pair(1,0);
        case 5:
            return i = make_pair(1,1);
        case 6:
            return i = make_pair(1,2);
        case 7:
            return i = make_pair(2,0);
        case 8:
            return i = make_pair(2,1);
        case 9:
            return i = make_pair(2,2);
        default:
            return i;
    }
}

int main(){
    //Variables
    int players;
    char xo;
    int position;
    bool xoFlag = true;
    bool locFlag = false;
    bool gameOver = false;
    vector<int> prevMoves;
    vector<int> xMoves;
    vector<int> oMoves;
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

    //Starting the game - Selecting amount of players 
    cout << "Welcome to Tic Tac Toe" << endl;
    cout << "-----------------------" << endl;
    cout << "Enter the amount of players(1 or 2): ";
    cin >> players;
    if(players == 1){
        //Beginning Single Player
        cout << "Player 1 vs Computer" << endl;
        do{
            //Selecting X or O 
            cout << "Pick 'X' or 'O': ";
            cin >> xo;
            if(xo == 'X'){
                xoFlag = false;
                cout << "You picked X" << endl;
                cout << "Your move first..." << endl;
            }
            else if(xo == 'O'){
                xoFlag = false;
                cout << "You picked O " << endl;
                cout << "You'll go second..." << endl;
                cout << endl;
            }
            else{
                cout << "Invalid choice, pick again..." << endl;
            }
        }while(xoFlag == true);
        
        //Player picked X
        if(xo == 'X'){
            //Displaying initial board
            displayBoard(board);

            //Read in and display the moves starting with X
            for(int i = 0; i < 9; i++){
                if(i % 2 != 0){
                    do{
                        srand(time(0));
                        position = (rand() % 9) + 1;
                        locFlag = false;
                        for(int i = 0; i < prevMoves.size(); i++){
                            if(position == prevMoves[i]){
                                locFlag = true;
                            }
                        }
                    }while(locFlag == true);
                    prevMoves.push_back(position);
                    oMoves.push_back(position);
                    cout << "Computer placed O at position: " << position << endl;
                    board[index(position).first][index(position).second] = 'O';
                    displayBoard(board);
                }
                else{
                    menu();
                    do{
                        cin >> position;
                        locFlag = false;
                        if(position < 1 || position > 9){
                            cout << "Invalid position..." << endl;
                            cout << "Please pick again" << endl;
                            locFlag = true;
                        }
                        for(int i = 0; i < prevMoves.size(); i++){
                            if(position == prevMoves[i]){
                                cout << "This position has already been taken..." << endl;
                                cout << "Please pick again" << endl;
                                locFlag = true;
                            }
                        }
                    }while(locFlag == true);
                    prevMoves.push_back(position);
                    xMoves.push_back(position);
                    cout << "Placed X at position: " << position << endl;
                    board[index(position).first][index(position).second] = 'X';
                    displayBoard(board);
                }
                //Check for winner
                if(winner(xMoves) == true){
                    cout << "Game Over... Player X wins!" << endl;
                    gameOver = true;
                    break;
                }
                else if(winner(oMoves) == true){
                    cout << "Game Over... Player O wins!" << endl;
                    gameOver = true;
                    break;
                }
            }

            //Game has no winner
            if(gameOver == false){
                cout << "Game Over... It is a draw!" << endl;
            }
        }
        //Player picked O
        else{
            //Read in and display the moves starting with O
            for(int i = 0; i < 9; i++){
                if(i % 2 == 0){
                    do{
                        srand(time(0));
                        position = (rand() % 9) + 1;
                        locFlag = false;
                        for(int i = 0; i < prevMoves.size(); i++){
                            if(position == prevMoves[i]){
                                locFlag = true;
                            }
                        }
                    }while(locFlag == true);
                    prevMoves.push_back(position);
                    xMoves.push_back(position);
                    cout << "Computer placed X at position: " << position << endl;
                    board[index(position).first][index(position).second] = 'X';
                    displayBoard(board);
                }
                else{
                    menu();
                    do{
                        cin >> position;
                        locFlag = false;
                        if(position < 1 || position > 9){
                            cout << "Invalid position..." << endl;
                            cout << "Please pick again" << endl;
                            locFlag = true;
                        }
                        for(int i = 0; i < prevMoves.size(); i++){
                            if(position == prevMoves[i]){
                                cout << "This position has already been taken..." << endl;
                                cout << "Please pick again" << endl;
                                locFlag = true;
                            }
                        }
                    }while(locFlag == true);
                    prevMoves.push_back(position);
                    oMoves.push_back(position);
                    cout << "Placed O at position: " << position << endl;
                    board[index(position).first][index(position).second] = 'O';
                    displayBoard(board);
                }
                //Check for winner
                if(winner(xMoves) == true){
                    cout << "Game Over... Player X wins!" << endl;
                    gameOver = true;
                    break;
                }
                else if(winner(oMoves) == true){
                    cout << "Game Over... Player O wins!" << endl;
                    gameOver = true;
                    break;
                }
            }

            //Game has no winner
            if(gameOver == false){
                cout << "Game Over... It is a draw!" << endl;
            }
        }
    }
    else{
        //Beginning multiplayer
        cout << "Player 1 vs Player 2" << endl;
        cout << "Player 1 is 'X'" << endl;
        cout << "Player 2 is '0'" << endl;
        cout << "Player 1 goes first..." << endl;

        //Displaying initial board
        displayBoard(board);

        //Read in and display the moves starting with X
        for(int i = 0; i < 9; i++){
            menu();
            if(i % 2 == 0){
                do{
                    cin >> position;
                    locFlag = false;
                    if(position < 1 || position > 9){
                        cout << "Invalid position..." << endl;
                        cout << "Please pick again" << endl;
                        locFlag = true;
                    }
                    for(int i = 0; i < prevMoves.size(); i++){
                        if(position == prevMoves[i]){
                            cout << "This position has already been taken..." << endl;
                            cout << "Please pick again" << endl;
                            locFlag = true;
                        }
                    }
                }while(locFlag == true);
                prevMoves.push_back(position);
                xMoves.push_back(position);
                cout << "Placed X at position: " << position << endl;
                board[index(position).first][index(position).second] = 'X';
                displayBoard(board);
            }
            else{
                do{
                    cin >> position;
                    locFlag = false;
                    if(position < 1 || position > 9){
                        cout << "Invalid position..." << endl;
                        cout << "Please pick again" << endl;
                        locFlag = true;
                    }
                    for(int i = 0; i < prevMoves.size(); i++){
                        if(position == prevMoves[i]){
                            cout << "This position has already been taken..." << endl;
                            cout << "Please pick again" << endl;
                            locFlag = true;
                        }
                    }
                }while(locFlag == true);
                prevMoves.push_back(position);
                oMoves.push_back(position);
                cout << "Placed O at position: " << position << endl;
                board[index(position).first][index(position).second] = 'O';
                displayBoard(board);
            }
            //Check for winner
            if(winner(xMoves) == true){
                cout << "Game Over... Player X wins!" << endl;
                gameOver = true;
                break;
            }
            else if(winner(oMoves) == true){
                cout << "Game Over... Player O wins!" << endl;
                gameOver = true;
                break;
            }
        }

        //Game has no winner
        if(gameOver == false){
            cout << "Game Over... It is a draw!" << endl;
        }
    }
    return 0;
}