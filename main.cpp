#include "main.h"
using namespace std;




void consoleInit(void){
   SetConsoleOutputCP(CP_UTF8);
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
   consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;  // Set the cursor visibility to false
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

void visualizerInit(void){
   for(int i = 0; i<consoleWidth; i++){
      cout << "=";
   }
   string welcomeText = "WELCOME TO N-queen Visualizer ♛";
   cout << "\n\n";
   cout << changeColor(onCenter(welcomeText, consoleWidth), 'Y') << endl;
   cout << changeColor(onCenter("↓ Enter value of N to get Started ↓", consoleWidth), 'B') << endl;

   cout << onCenter("",consoleWidth);
   cin >> N;
}

bool isSafe(const vector<vector<char>>& board, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j] == 'Q') return false;
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j] == 'Q') return false;
    return true;
}

void solveNQueensUtil(vector<vector<char>>& board, int row) {
    if (row >= N){
        clearBoard();
        drawEmptyBoard();
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 'Q';
            updateBoard(row, col, " Q", false);
            Sleep(delay);

            solveNQueensUtil(board, row + 1);

            board[row][col] = '.';
            updateBoard(row, col, "  ", false);
            // Sleep(delay);
        }
        else{
         board[row][col] = 'Q';
         updateBoard(row, col, " Q", true);
         Sleep(delay);
         board[row][col] = '.';
         updateBoard(row, col, "  ", false);
        }
    }

    return;
}

void solveNQueens() {
   if(N<4){
      cout << changeColor(onCenter("Solution Doesn't exist!!!", consoleWidth),'R');
   }
   vector<vector<char>> board(N, vector<char>(N, '.'));
    clearBoard();
    drawEmptyBoard();
    solveNQueensUtil(board, 0);
}


int main()
{
   consoleInit();
   visualizerInit();

   solveNQueens();
   while(1);
   // cout << endl;
   // for (int i = 0; i < N; i++)  cout <<" ---";
   // cout << endl;

   // for (int i = 0; i < N; i++)
   // {
   //    for (int j = 0; j < N; j++){
   //       if (!j)
   //             cout  << "| "  <<  changeColor("Q",'R') <<" |";
   //       else
   //             cout << " Q |";
   //    }

   //    cout << endl;

   //    for (int i = 0; i < N; i++)  cout <<" ---";
   //    cout << endl;
   // }


   // for(int i=0;i<=100;++i){
   //    printf("\r[%3d%%]",i);
   //    Sleep(1000);
   // }


   return 0;
}