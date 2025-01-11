#include <iostream>
#include <stdio.h>
#include <time.h>

#define ROWS 4
#define COLS 5

void initTab2D(int t[][COLS], int nRows, int nCols);
void printTab2D(int t[][COLS], int nRows, int nCols);

int main()
{
  int t[ROWS][COLS];
  initTab2D(t, ROWS, COLS);
  printTab2D(t, ROWS, COLS);
  return 0;
}

void initTab2D(int t[][COLS], int nRows, int nCols)
{
  srand((unsigned)time(NULL));
  for(int i = 0;i < nRows;i++)
    for(int j = 0;j < nCols;j++)
      t[i][j] = rand() % (nRows * nCols);

}

void printTab2D(int t[][COLS], int nRows, int nCols)
{
  for(int i = 0;i < nRows;i++)
    for(int j = 0;j < nCols;j++) {
      printf("%2d ", t[i][j]);
      if((j + 1) % COLS == 0) printf("\n");
    }
}