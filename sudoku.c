#include <stdio.h>
void printsudo(int sudo[9][9]) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (sudo[row][col] == 0) {
                printf(" .");
            } else {
                printf(" %d", sudo[row][col]);
            }
            if ((col + 1) % 3 == 0 && col < 9 - 1) {
                printf(" |");
            }
        }
        printf("\n");
        if ((row + 1) % 3 == 0 && row < 9 - 1) {
            printf("-------+-------+-------\n");
        }
    }
}

int isSafe(int sudo[9][9], int row, int col, int num) {
    for (int x = 0; x < 9; x++) {
        if (sudo[row][x] == num || sudo[x][col] == num) {
            return 0;
        } 
    }//TO check wheather the number entered by the student is not same to other numbers of same row and column

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (sudo[i + startRow][j + startCol] == num) {
                return 0;
            }
        }
    }//TO check wheather the number entered by the student is not same to other numbers of same row and column of a 3x3 block

    return 1;
}

int play(int sudo[9][9]) {
    int row, col, num;

    int isComplete = 1;
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (sudo[row][col] == 0) {
                isComplete = 0;
                break;
            }
        }
        if (!isComplete) {
            break;
        }  
    }  //Checking if sudoku is complete or not

    if (isComplete) {
        printf("Congratulations! You've solved the Sudoku.\n");
        return 1;
    }

    printf("\nSudoku Grid:\n");
    printsudo(sudo);

    printf("Enter row, column, and number (e.g., 1 2 3): ");
    scanf("%d %d %d", &row, &col, &num);

    if (row < 1 || row > 9 || col < 1 || col > 9 || num < 1 || num > 9 || sudo[row - 1][col - 1] != 0) {
        printf("Invalid input. Please try again.\n");
        return play(sudo);
    }

    if (isSafe(sudo, row - 1, col - 1, num)) {
        sudo[row - 1][col - 1] = num;
        return play(sudo);
    } else {
        printf("Invalid move. Please try again.\n");
        return play(sudo);
    }
}

int main() {
    int sudo[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Welcome to Sudoku! Fill in the empty cells(.) to solve the puzzle\n");
    printf("Rule for sudoku\n1.Sudoku Rule № 1: Use Numbers 1-9\n2.Sudoku Rule № 2: Don’t Repeat Any Numbers\n3.Sudoku Rule № 3: Don’t Guess\n4.Sudoku Rule № 4: Use Process of Elimination");
    if (play(sudo)) {
        printf("Sudoku solved!\n");
        
    }
return 0;
}
