#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <myLibrary.h>

const int MAX = 9;
const int NAME_MAX = 100;

typedef struct
{
  char *name;
  int votes;
} Candidate;

int vote(char name);
void print_winner(void);

int main(int argc, char argv[])
{
  Candidate candidateArray[MAX];
  int voter_count;

  if (argc != 1)
  {
    for (int i = 0; i < argc - 1; i++)
    {
      candidateArray[i].name = argv[i + 1];
      candidateArray[i].votes = 0;
    }
  }
  printf("Number of voters: ");
  scanf("%i", &voter_count);

  for (int i = 0; i < voter_count; i++)
  {
    char name = get_string();

    // Check for invalid vote
    if (!vote(name))
    {
      printf("Invalid vote.\n");
    }

    vote(name);
  }

  return 0;
}

int vote(char name)
{
  for (int i = 0; i < 2; i++)
  {
    /* code */
  }

  return 0;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
  // TODO
  return;
}