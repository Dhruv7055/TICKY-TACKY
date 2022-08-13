#include<bits/stdc++.h>
using namespace std;
char arr[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char turn = '1';
bool draw = false;
int row,col,ch;

bool running();
void display();
void myturn();

bool running(){
    for(int i = 0; i < 3; i++){
        if(arr[i][0] == arr[i][1] && arr[i][0] == arr[i][2]) // row wise winning
        return false;

        if(arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i]) // column wise winning
        return false;
    }
    if(arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2]) // diagonal 1 winning
    return false;

    if(arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0]) // diagonal 2 winning
    return false;

    for(int i = 0; i < 3; i++)
    for(int j = 0; j < 3; j++)
    if(arr[i][j] != 'X' && arr[i][j] != 'O')
    return true;

    draw = true;
    return false;
}

void myturn(){
    if(turn == '1'){
        cout<<"\t\tPLAYER 1 ENTER YOUR CHOICE \n";
    }
    if(turn == '2'){
        cout<<"\t\tPLAYER 2 ENTER YOUR CHOICE \n";
    }
    cin >> ch;
    if(ch == 1){
        row = 0;
        col = 0;
    }
    else if(ch == 2){
        row = 0; 
        col = 1;
    }
    else if(ch == 3){
        row = 0; 
        col = 2;
    }
    else if(ch == 4){
        row = 1;
        col = 0;
    }
    else if(ch == 5){
        row = 1;
        col = 1;
    }
    else if(ch == 6){
        row = 1;
        col = 2;
    }
    else if(ch == 7){
        row = 2;
        col = 0;
    }
    else if(ch == 8){
        row = 2;
        col = 1;
    }
    else if(ch == 9){
        row = 2;
        col = 2;
    }
    else{
        cout<<"\t\tITS AN INVALID CHOICE .... PLEASE ENTER AGAIN";
    }

    if(turn == '1' && arr[row][col] != 'X' && arr[row][col] != 'O'){
        arr[row][col] = 'X';
        turn = '2';
    }
    else if(turn == '2' && arr[row][col] != 'X' && arr[row][col] != 'O'){
        arr[row][col] = 'O';
        turn = '1';
    }
    else{
        cout<<"\tALREADY FILLED\n";
        myturn();
    }
}

void display(){
    cout<<"\t\t     |      |    \n";
    cout<<"\t\t    "<<arr[0][0]<<"  |   "<<arr[0][1]<<"   |    "<<arr[0][2]<<" \n";
    cout<<"\t\t_____|______|_____\n";
    cout<<"\t\t     |      |     \n";
    cout<<"\t\t    "<<arr[1][0]<<"  |   "<<arr[1][1]<<"   |    "<<arr[1][2]<<" \n";
    cout<<"\t\t_____|______|_____\n";
    cout<<"\t\t     |      |     \n";
    cout<<"\t\t    "<<arr[2][0]<<"  |   "<<arr[2][1]<<"   |    "<<arr[2][2]<<" \n";
    cout<<"\t\t     |      |    \n";
}

int main(){
    cout<<"\n\n\t\tWLECOME TO THE GAME OF TIC TAC TOE";
    cout<<"\n\t\tTHIS GAME IS TO BE PLAYED BETWEEN TWO PLAYERS \n";
    cout<<"\t\tFOR PLAYER 1 , 'x' IS THE SYMBOL \n";
    cout<<"\t\tFOR PLAYER 2 , 'O' IS THE SYMBOL \n";
    cout<<"\t\tHERE WE START WITH THE GAME, AND HERE YOU HAVE THE BLOCK \n";
    cout<<"\t\tBOTH PLAYERS HAVE TO CHOOSE THE BLOCK NUMBER FOR ASSIGNING THEIR SYMBOLS TO WIN \n";
    cout<<"\n \n";
    while(running()){
        display();
        myturn();
        running();
    }
    if(draw == false){
        if(turn == '2' ){
            cout<<"\t\tCONGRATULATIONS!!! PLAYER 1 WON THE MATCH";
        }
        if(turn == '1' ){
            cout<<"\t\tCONGRATULATIONS!!! PLAYER 1 WON THE MATCH";
        }
    }
    else{
        cout<<"\t\tITS A DRAW, CONGRATULATIONS TO BOTH PLAYERS";
    }
}
