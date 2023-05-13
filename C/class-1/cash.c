#include <stdio.h>

int calculateChangeAmount(float value);
float getValue(void);
int changeCoin(int value);

int main(void)
{
  float change = getValue();
  printf("%i\n", calculateChangeAmount(change));

  return 0;
}

int calculateChangeAmount(float value)
{
  int coinsValue = value * 100;
  coinsValue %= 100;

  int quantityOfCoins = 0;

  do
  {
    int x = changeCoin(coinsValue);
    coinsValue -= x;
    quantityOfCoins++;
  } while (coinsValue > 0);

  return quantityOfCoins;
}

float getValue(void)
{
  float x;
  printf("Insira o valor do troco: \n");

  do
  {
    printf("-> ");
    scanf("%f", &x);
  } while (x <= 0);

  return x;
}

int changeCoin(int value)
{
  int x;
  if (value >= 25)
  {
    x = 25;
  }
  else if (value >= 10)
  {
    x = 10;
  }
  else if (value >= 5)
  {
    x = 5;
  }
  else
  {
    x = 1;
  }
  return x;
}
