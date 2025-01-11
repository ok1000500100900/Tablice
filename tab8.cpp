
#include <iostream>
#define MAX 50
#define MAXLINE 10
#define X 2

void je();
void initTab(int t[], int nSize);
void printTab(int t[], int nSize);
void bubbleSort(int t[], int nSize);
void simpleSelectionSort(int t[], int nSize);
void simpleInsertionSort(int t[], int nSize);
int halfFind(int x, int t[], int nSize);

int main()
{
  int t[MAX];
  initTab(t, MAX);
  printTab(t, MAX);
  je();
  simpleInsertionSort(t, MAX);
  printTab(t, MAX);
  je();
  int result = halfFind(X, t, MAX);
  printf("%d", result);
  return 0;
}

void je()
{
  printf("\n");
}

void initTab(int t[], int nSize)
{
  srand((unsigned int)time(NULL));
  for(int i = 0;i < nSize;i++)
  {
    t[i] = rand() % nSize;
  }
}

void printTab(int t[], int nSize)
{
  for(int i = 0;i < nSize;i++)
  {
    printf("%d ", t[i]);
    if((i + 1) % MAXLINE==0) printf("\n");
  }
}

void bubbleSort(int t[], int nSize)
{
  for(int i = 0;i < nSize;i++)
  {
    for(int j = nSize - 1;j >= i;j--)
    {
      if(t[j] < t[j - 1])
      {
        int temp = t[j];
        t[j] = t[j - 1];
        t[j - 1] = temp;
      }
    }
  }
}

void simpleSelectionSort(int t[], int nSize)
{
  for(int i = 0;i < nSize - 1;i++)
  {
    int min = t[i];
    int ix_min = i;

    for(int j = i + 1;j < nSize;j++)
    {
      if(t[j] < min)
      {
        min = t[j];
        ix_min = j;
      }
    }
    t[ix_min] = t[i];
    t[i] = min;
  }
}

void simpleInsertionSort(int t[], int nSize)
{
  for(int i = 0;i < nSize;i++)
  {
    int x = t[i];
    int j = i - 1;

    while(j >= 0 && t[j] > x)
    {
      t[j + 1] = t[j--];
    }

    t[j + 1] = x;
  }
}

int halfFind(int x, int t[], int nSize)
{
  int p = 0;
  int k = nSize - 1;
  int m;
  do {
    m = (p + k) / 2;
    if(x > t[m])p = m + 1;
    else if(x < t[m])k = m - 1;
    else break;
  } while(p <= k);

  if(p <= k)return m;
  return -1;
}