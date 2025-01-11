#include <iostream>
#define MAX 50
#define MAXLINE 5

int main()
{
  int t[MAX];
  for(int i = 0;i < MAX;i++) t[i] = i + 1;

  int last = (int)sqrt((double)MAX);
  for(int i = 1;i <= last;i++)
  {
    int k = i + 1;
    if(t[i] != 0)
      for(int j = 2 * i + 1;j < MAX;j += k)
        t[j] = 0;
  }

  for(int i = 0;i < MAX;i++) {
    if(t[i])printf("%d ", t[i]);
    printf("\n");

  }

}