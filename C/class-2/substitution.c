#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <myLibrary.h>>

const int TOTAL = 1000;

char *getKey(void);
char *criptography(char text[], char key[]);

int main(void)
{
  char *text = get_string();
  char *key = get_string();
  *text = *criptography(text, key);
  printf("%s\n", text);

  free(text);
  free(key);

  return 0;
}

char *getKey(void)
{
  char *key = malloc(sizeof(char) * TOTAL);
  if (key == NULL)
  {
    printf("Erro: não foi possível alocar memória.\n");
    exit(1);
  }
  char character;
  int i = 0;

  printf("Enter the key here: ");

  do
  {
    character = getchar();
    key[i] = character;
    i++;
  } while (i < 26);

  key[i - 1] = '\0';

  return key;
}

char *criptography(char text[], char key[])
{
  int length = strlen(text);
  int keyLength = strlen(key);
  int weight = 0;

  for (int i = 0; i < length; i++)
  {
    if (isalpha(text[i]))
    {
      char base = islower(text[i]) ? 'a' : 'A';
      weight = text[i] - base;
      text[i] = key[weight];
    }
  }

  return text;
}
