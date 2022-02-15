// Tik-Tac-Toe (1.0) by exosZoldyck
// Special thanks to PopeOfAtheism for giving me the idea of adding a scoreboard!!!

#include <iostream>
#include <iomanip>

using namespace std;

void draw(int pos[3][3]) {
    int i, j;

    cout << "--------------------" << endl;

    for (i = 0; i < 3; i++) {
        cout << endl;
        for (j = 0; j < 3; j++) {
            cout << setw(5) << pos[i][j];
        }
    }

    cout << endl << endl << "--------------------";

    return;
}

int player_input(int playerid, char player1_name[99], char player2_name[99]) {
    int input;

    reinput:
    input = 0;

    if (playerid == 1) {
        if (cout << player1_name << ": " && !(cin >> input)) {
            cout << endl;
            cout << "Invalid input!!!";
            cout << endl;
            cin.clear();
            cin.get();
            goto reinput;
        }

        cout << endl;
    }
    if (playerid == 2) {
        if (cout << player2_name << ": " && !(cin >> input)) {
            cout << endl;
            cout << "Invalid input!!!";
            cout << endl;
            cin.clear();
            cin.get();
            goto reinput;
        }

        cout << endl;
    }

    if (input < 1 || input > 9) { cout << "Invalid input!!!" << endl; goto reinput; };

    return input;
}

void input_set_ij(int *i, int *j, int input) {
    if (input == 1) { *i = 0; *j = 0; };
    if (input == 2) { *i = 0; *j = 1; };
    if (input == 3) { *i = 0; *j = 2; };
    if (input == 4) { *i = 1; *j = 0; };
    if (input == 5) { *i = 1; *j = 1; };
    if (input == 6) { *i = 1; *j = 2; };
    if (input == 7) { *i = 2; *j = 0; };
    if (input == 8) { *i = 2; *j = 1; };
    if (input == 9) { *i = 2; *j = 2; };

    return;
}

int field_check(int i, int j, int pos[3][3], int playerid, int *check_fail){
    if (pos[i][j] > 0) {
        *check_fail = 1;
        return pos[i][j];
    }

    return (playerid);
}

void win_check(int pos[3][3], int *winner, int playerid, char player1_name[99], char player2_name[99]){
    if (pos[0][0] == 1 && pos[0][1] == 1 && pos[0][2] == 1) { *winner = 1; }
    if (pos[1][0] == 1 && pos[1][1] == 1 && pos[1][2] == 1) { *winner = 1; }
    if (pos[2][0] == 1 && pos[2][1] == 1 && pos[2][2] == 1) { *winner = 1; }

    if (pos[0][0] == 1 && pos[1][0] == 1 && pos[2][0] == 1) { *winner = 1; }
    if (pos[0][1] == 1 && pos[1][1] == 1 && pos[2][1] == 1) { *winner = 1; }
    if (pos[0][2] == 1 && pos[1][2] == 1 && pos[2][2] == 1) { *winner = 1; }

    if (pos[0][0] == 1 && pos[1][1] == 1 && pos[2][2] == 1) { *winner = 1; }
    if (pos[0][2] == 1 && pos[1][1] == 1 && pos[2][0] == 1) { *winner = 1; }


    if (pos[0][0] == 2 && pos[0][1] == 2 && pos[0][2] == 2) { *winner = 2; }
    if (pos[1][0] == 2 && pos[1][1] == 2 && pos[1][2] == 2) { *winner = 2; }
    if (pos[2][0] == 2 && pos[2][1] == 2 && pos[2][2] == 2) { *winner = 2; }

    if (pos[0][0] == 2 && pos[1][0] == 2 && pos[2][0] == 2) { *winner = 2; }
    if (pos[0][1] == 2 && pos[1][1] == 2 && pos[2][1] == 2) { *winner = 2; }
    if (pos[0][2] == 2 && pos[1][2] == 2 && pos[2][2] == 2) { *winner = 2; }

    if (pos[0][0] == 2 && pos[1][1] == 2 && pos[2][2] == 2) { *winner = 2; }
    if (pos[0][2] == 2 && pos[1][1] == 2 && pos[2][0] == 2) { *winner = 2; }

    if (playerid == 1) { if (*winner != 0) { cout << endl << "The Winner is " << player1_name << "!" << endl << endl; } }
    if (playerid == 2) { if (*winner != 0) { cout << endl << "The Winner is " << player2_name << "!" << endl << endl; } }

    return;
}

int tie_check(int pos[3][3]) {
    int i, j, counter(0);

    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++) {
            if (pos[i][j] != 0) { counter++; }
        }
    }

    if (counter == 9) { cout << endl << "It's a tie!" << endl << endl; ; return 1; }
}

void scoreboard_draw(int *player1_score, int *player2_score, char player1_name[99], char player2_name[99]){
    cout << endl << endl << endl << "-----Scoreboard-----" << endl << endl;
    cout << player1_name << "'s Score: " << *player1_score << endl;
    cout << player2_name << "'s Score: " << *player2_score << endl << endl;
}



int main()
{
    int i, j, check_fail, *pi, *pj, *pcheck_fail, winner(0), *pwinner, player1_score, player2_score, *pplayer1_score, *pplayer2_score;
    int pos[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, playerid(1), input;
    char player1_name[99], player2_name[99];

    pi = &i;
    pj = &j;
    pcheck_fail = &check_fail;
    pwinner = &winner;
    pplayer1_score = &player1_score;
    pplayer2_score = &player2_score,

    cout << "Name of Player 1: "; cin >> player1_name;
    cout << "Name of Player 2: "; cin >> player2_name;


    newround: draw(pos);
    next_turn:cout << endl << endl << endl;

    check_fail = 0;

    input = player_input(playerid, player1_name, player2_name);

    input_set_ij(pi, pj, input);

    pos [i][j] = field_check(i, j, pos, playerid, pcheck_fail);

    if (check_fail == 1) { cout << "Invalid input!!!" << endl; draw(pos); goto next_turn; }

    win_check(pos, pwinner, playerid, player1_name, player2_name);
    if (tie_check(pos) == 1) { draw(pos); goto game_reset_tie; }
    if (winner != 0) { draw(pos); goto game_reset; }

    draw(pos);

    if (playerid == 1) { playerid = 2; }
    else if (playerid == 2) { playerid = 1; }
    goto next_turn;


    game_reset:
    if (winner == 1) { player1_score++; }
    else if (winner == 2) { player2_score++; }

    game_reset_tie:
    scoreboard_draw(pplayer1_score, pplayer2_score, player1_name, player2_name);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            pos[i][j] = 0;
        }
    }

    playerid = 1;
    winner = 0;

    goto newround;
}