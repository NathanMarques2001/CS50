#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int TOTAL = 1000;

char *getText(char message[]);
int compute_score(char word[]);

int main(void)
{
  char *word1 = getText("Player 1: ");
  char *word2 = getText("Player 2: ");

  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  if (score1 > score2)
  {
    printf("\nPlayer 1 wins!\n");
  }
  else if (score1 < score2)
  {
    printf("\nPlayer 1 wins!\n");
  }
  else
  {
    printf("\nTie!\n");
  }

  free(word1);
  free(word2);
}

char *getText(char message[])
{
  char *input = malloc(sizeof(char) * TOTAL);
  if (input == NULL)
  {
    printf("Erro: não foi possível alocar memória.\n");
    exit(1);
  }
  char character;
  int i = 0;

  printf("\nEnter a word:\n");
  printf("%s\n", message);

  do
  {
    character = getchar();
    input[i] = character;
    i++;
  } while (character != '\n' && i < TOTAL);

  input[i - 1] = '\0';

  return input;
}

int compute_score(char word[])
{
  int points = 0;
  int length = strlen(word);

  for (int i = 0; i < length; i++)
  {
    if (isalpha(word[i]))
    {
      if (islower(word[i]))
      {
        points += word[i] - 'a';
      }
      else
      {
        points += word[i] - 'A';
      }
    }
  }

  return points;
}