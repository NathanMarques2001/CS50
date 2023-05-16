#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int TOTAL = 1000;

char *getText(void);
int getStrength(void);
char *criptography(char text[], int strength);

int main(void)
{
  char *text = getText();
  int strength = getStrength();
  *text = *criptography(text, strength);
  printf("%s\n", text);

  free(text);

  return 0;
}

char *getText(void)
{
  char *input = malloc(sizeof(char) * TOTAL);
  if (input == NULL)
  {
    printf("Erro: não foi possível alocar memória.\n");
    exit(1);
  }
  char character;
  int i = 0;

  printf("Enter the text here: ");

  do
  {
    character = getchar();
    input[i] = character;
    i++;
  } while (character != '\n' && i < TOTAL);

  input[i - 1] = '\0';

  return input;
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
