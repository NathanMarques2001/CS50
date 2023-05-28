#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <myLibrary.h>

const int TOTAL = 1000;

int getStrength(void);
char *criptography(char text[], int strength);

int main(void)
{
  char *text = get_string();
  int strength = getStrength();
  *text = *criptography(text, strength);
  printf("%s\n", text);

  free(text);

  return 0;
}

int getStrength(void)
{
  int x = 0;

  printf("\nAgora, insira força da encriptação: ");

  do
  {
    scanf("%i", &x);
  } while (x <= 0);

  return x;
}

char *criptography(char text[], int strength)
{
  int length = strlen(text);

  for (int i = 0; i < length; i++)
  {
    if (isalpha(text[i]))
    {
      char base = islower(text[i]) ? 'a' : 'A';
      text[i] = ((text[i] - base + strength) % 26) + base;
    }
  }

  return text;
}
