#include <stdio.h>
#include <stdlib.h>

const int TOTAL = 1000;

char *getText(void);
int wordsQuantity(char text[]);
float lettersAverage(char text[], int words);
float sentencesAverage(char text[], int words);
int ColemanLiauIndex(float letterAvg, float sentenceAvg);

int main(void)
{
  char *text = getText();
  int words = wordsQuantity(text);
  float letters = lettersAverage(text, words);
  float sentences = sentencesAverage(text, words);
  int grade = ColemanLiauIndex(letters, sentences);

  if (grade >= 16)
  {
    printf("Grade 16+\n");
  }
  else if (grade < 1)
  {
    printf("Before Grade 1\n");
  }
  else
  {
    printf("Grade: %i\n", grade);
  }

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

int wordsQuantity(char text[])
{
  int wordCounter = 1;

  for (int i = 0; i < TOTAL; i++)
  {
    if (text[i] == ' ' && text[i] != '\n' && text[i] != '\0')
    {
      wordCounter++;
    }
  }

  return wordCounter;
}

float lettersAverage(char text[], int words)
{
  int letterCounter = 0;

  for (int i = 0; i < TOTAL; i++)
  {
    if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
    {
      letterCounter++;
    }
  }

  float letterAvg = (letterCounter / (float)words) * 100;

  return letterAvg;
}

float sentencesAverage(char text[], int words)
{
  int sentenceCounter = 0;

  for (int i = 0; i < TOTAL; i++)
  {
    if (text[i] == '!' || text[i] == '.' || text[i] == '?')
    {
      sentenceCounter++;
    }
  }

  float sentenceAvg = (sentenceCounter / (float)words) * 100;

  return sentenceAvg;
}

int ColemanLiauIndex(float letterAvg, float sentenceAvg)
{
  float calculateIndex = 0.0588 * letterAvg - 0.296 * sentenceAvg - 15.8;
  int index = (int)(calculateIndex + 0.5);

  return index;
}