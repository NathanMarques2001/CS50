#include <stdio.h>

int getStartSize(void);
int getFinalSize(int initialPopulation);
int calculateYearsOfGrowth(int initial, int final);

int main(void)
{
  int startSize = getStartSize();
  int finalSize = getFinalSize(startSize);
  int years = calculateYearsOfGrowth(startSize, finalSize);

  printf("Years: %i\n", years);

  return 0;
}

int getStartSize(void)
{
  int x = 0;
  printf("Enter the starting population\n");

  do
  {
    printf("Quantity: ");
    scanf("%i", &x);
  } while (x < 9);

  return x;
}

int getFinalSize(int initialPopulation)
{
  int x = 0;
  printf("Enter the final population\n");

  do
  {
    printf("Quantity: ");
    scanf("%i", &x);
  } while (x < initialPopulation);

  return x;
}

int calculateYearsOfGrowth(int initial, int final)
{
  int x = initial;
  int born = 0;
  int died = 0;
  int count = 0;

  do
  {
    born = x / 3;
    died = x / 4;
    x += born - died;
    count++;
  } while (x < final);

  return count;
}