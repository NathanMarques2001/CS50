#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <myLibrary.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
const int TOTAL = 1000;

int compute_score(char word[]);

int main(void)
{
  printf("Player 1: ");
  char *word1 = get_string();
  printf("Player 2: ");
  char *word2 = get_string();

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