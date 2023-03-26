#include <stdio.h>

void printHashesAndSpaces(int n);
int getQuantity(void);

int main(void)
{
  int quantity = getQuantity();
  printHashesAndSpaces(quantity);
}

void printHashesAndSpaces(int n)
{
  for(int i = 1; i <= n; i++)
  {
    for(int j = (n - i); j >= 0; j--)
    {
      printf(" ");
    }
    for(int k = 0; k < i; k++)
    {
      printf("#");
    }

    printf(" ");

    for(int k = 0; k < i; k++)
    {
      printf("#");
    }
    for(int j = (n - i); j >= 0; j--)
    {
      printf(" ");
    }
    printf("\n");
  }
}

int getQuantity(void)
{
  int x;
  printf("Insira a quantidade de blocos entre 1 a 8\n");

  do
  {
    printf("Quantidade: ");
    scanf("%i", &x);
  }
  while(x <= 0 || x > 8);

  return x;
}
