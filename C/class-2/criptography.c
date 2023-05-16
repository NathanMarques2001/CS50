#include <stdio.h>
#include <stdlib.h>

const int TOTAL = 1000;

char *getText(void);
char *criptography(char text[], int strength);

int main(void)
{
  char *text = getText();
  char *cryptographyText = criptography(text, 6);
  printf("%s\n", cryptographyText);

  free(cryptographyText);
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

char *criptography(char text[], int strength) {
  int min = 0;
  int max = 0;
  int estouro = 0;
  int sub = 0;
  int i = 0;
  
  char *newText = malloc(sizeof(char) * TOTAL);
  if (newText == NULL)
  {
    printf("Erro: não foi possível alocar memória.\n");
    exit(1);
  }

  do{
    newText[i] = text[i];
    i++;
  }while(text[i] != '\0');

  for(int i = 0; i < TOTAL; i++)
    {
      if(newText[i] >= 'a' && newText[i] <= 'z'){
        min = 97;
        max = 122;
        if(newText[i] + strength > max){
          estouro = newText[i] + strength;
          sub = estouro - max;
          newText[i] = min + sub;
        } else {
          newText[i] += strength;
        }
      } else if(newText[i] >= 'A' && newText[i] <= 'Z'){
        min = 64;
        max = 90;
        if(newText[i] + strength > max){
          estouro = newText[i] + strength;
          sub = estouro - max;
          newText[i] = min + sub;
        } else {
          newText[i] += strength;
        }
      }
    }
  return newText;
}
