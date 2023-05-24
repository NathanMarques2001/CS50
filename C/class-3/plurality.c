#include <stdio.h>

int main(void)
{
  struct candidate
  {
    char name[100];
    int votes;
  };

  struct candidate candidate1 = {"Nathan", 0};
  printf("%s %i",candidate1.name, candidate1.votes);
  return 0;
}

void getCandidateData(int quantity)
{
}