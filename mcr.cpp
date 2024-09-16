
bool isWin(char game[3][3]) {
    bool win = false;
    if (game[0][0] == game[0][1] && game[0][1] == game[0][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[1][0] == game[1][1] && game[1][1] == game[1][2] && (game[1][0] == 'X' || game[1][0] == 'O')) win = true;
    if (game[2][0] == game[2][1] && game[2][1] == game[2][2] && (game[2][0] == 'X' || game[2][0] == 'O')) win = true;
    
    if (game[0][0] == game[1][0] && game[1][0] == game[2][0] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][1] == game[1][1] && game[1][1] == game[2][1] && (game[0][1] == 'X' || game[0][1] == 'O')) win = true;
    if (game[0][2] == game[1][2] && game[1][2] == game[2][2] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    
    if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && (game[0][0] == 'X' || game[0][0] == 'O')) win = true;
    if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && (game[0][2] == 'X' || game[0][2] == 'O')) win = true;
    
    return win;
}

int main() {
    int i, j;
    char game[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}}; 
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; 
    cout << "X = Player 1" << endl << "O = Player 2" << endl;
    
    for (int n = 0; n < 9; n++) {
        turn = !turn; 
        if (!turn)
            cout << "Player 1: ";
        else
            cout << "Player 2: ";
        
        cout << "Which cell to mark? i:[1..3], j:[1..3]: ";
        cin >> i >> j;
        
        i--;         j--;
        
        if (game[i][j] != ' ') { 
            cout << "please try another cell" << endl;
            n--; 
            continue;
        }

        if (!turn)
            game[i][j] = player1;
        else
            game[i][j] = player2;

        cout << game[0][0] << game[0][1] << game[0][2] << endl;
        cout << game[1][0] << game[1][1] << game[1][2] << endl;
        cout << game[2][0] << game[2][1]  << game[2][2] << endl;

        if (isWin(game)) {
            if (!turn)
                cout << "Player 1 wins!" << endl;
            else
                cout << "Player 2 wins!" << endl;
            break; 
        }

        if (n == 8) { 
            cout << "Tie!" << endl;
        }
    }

    return 0;
}
