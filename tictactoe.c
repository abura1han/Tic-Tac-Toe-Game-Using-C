#include <stdio.h>
#include <stdlib.h>

// gameboard
char gameBoard[3][3];

// function prototype
void drawBoard();
int showResult(char ch);
int validateInput(int cell);
void getRowCol(int cell, int *x, int *y);
void playerX(int *pCell);
void playerO(int *pCell);

int main()
{
    int row = 0,
        col = 0,
        selectedCell = 0,
        availableCell = 9,
        startChar = '1';

    // fill up all data of the game board
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            gameBoard[row][col] = startChar++;
        }
    }

    // loop untill match running
    while (availableCell >= 0)
    {

        // set color & clear screen
        system("color 0a");
        system("cls");

        // draw the game board
        drawBoard();

        // assume the first player is X
        playerX(&selectedCell);
        // get row & column
        getRowCol(selectedCell, &row, &col);
        // update data array & decrease availabe cell
        gameBoard[row][col] = 'X';
        availableCell--;

        // clear screen & redraw the board
        system("cls");
        drawBoard();

        // check if player X is wine or not
        if (showResult('X') == 1)
        {
            printf("\nPlayer X Won!");
            break;
        }
        else if (availableCell == 0)
        {
            printf("\nMatch Drawn.....!");
            break;
        }

        // assume last player is O
        playerO(&selectedCell);
        // get row & column
        getRowCol(selectedCell, &row, &col);
        // update data array & decrease availabe cell
        gameBoard[row][col] = 'O';
        availableCell--;

        // clear & redraw the screen
        system("cls");
        drawBoard();

        // check if player O is wine or not
        if (showResult('O') == 1)
        {
            printf("\nPlayer O Won!");
            break;
        }
        else if (availableCell == 0)
        {
            printf("\nMatch Drawn.....!");
            break;
        }
    }

    return 0;
}

// draw the game board
void drawBoard()
{
    printf("--- Tic Tac Toe ---\n");
    printf("..................\n");
    printf("     %c | %c | %c \n", gameBoard[0][0], gameBoard[0][1], gameBoard[0][2]);
    printf("    ---|---|---\n");
    printf("     %c | %c | %c \n", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("    ---|---|---\n");
    printf("     %c | %c | %c \n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
}

// get row & column
void getRowCol(int cell, int *x, int *y)
{
    *x = (cell - 1) / 3;
    *y = (cell - 1) % 3;
}

// validate input
int validateInput(int cell)
{
    int row, col;

    // check if inputed value is less than 0 & greather than 9
    if (cell < 0 || cell > 9)
    {
        printf("Invalid Input. Try Again : ");
        return 0;
    }

    // check if inputed value is already occupied
    getRowCol(cell, &row, &col);
    if (gameBoard[row][col] == 'X' || gameBoard[row][col] == 'O')
    {
        printf("Already Occupied. Try Another : ");
        return 0;
    }

    return 1;
}

// turn player X
void playerX(int *pCell)
{
    int cell;
    do
    {
        printf("Player X : ");
        scanf("%d", &cell);
    } while (0 == validateInput(cell));
    *pCell = cell;
}

// turn player O
void playerO(int *pCell)
{
    int cell;
    do
    {
        printf("Player O : ");
        scanf("%d", &cell);
    } while (validateInput(cell) == 0);
    *pCell = cell;
}

// show result
int showResult(char ch)
{
    int status = 0;

    // check diagonal \ /
    if (gameBoard[0][0] == ch && gameBoard[1][1] == ch && gameBoard[2][2] == ch)
    {
        status = 1;
    }
    // check diagonal /
    else if (gameBoard[0][2] == ch && gameBoard[1][1] == ch && gameBoard[2][0] == ch)
    {
        status = 1;
    }
    // check first row
    else if (gameBoard[0][0] == ch && gameBoard[0][1] == ch && gameBoard[0][2] == ch)
    {
        printf("Player %c Won!", ch);
        status = 1;
    }
    // check second row
    else if (gameBoard[1][0] == ch && gameBoard[1][1] == ch && gameBoard[1][2] == ch)
    {
        status = 1;
    }
    // check third row
    else if (gameBoard[2][0] == ch && gameBoard[2][1] == ch && gameBoard[2][2] == ch)
    {
        status = 1;
    }
    // check first column
    else if (gameBoard[0][0] == ch && gameBoard[1][0] == ch && gameBoard[2][0] == ch)
    {
        status = 1;
    }
    // check second column
    else if (gameBoard[0][1] == ch && gameBoard[1][1] == ch && gameBoard[2][1] == ch)
    {
        status = 1;
    }
    // check first column
    else if (gameBoard[0][2] == ch && gameBoard[1][2] == ch && gameBoard[2][2] == ch)
    {
        status = 1;
    }

    return status;
}