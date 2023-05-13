#include <stdio.h>
#include <string.h>

int validateFlag(long number);
long calculateDivider(int divider);
int validateCard(long number);

int main(void)
{
  // MASTERCARD AND VISA HAS 16 NUMBERS
  // AMERICAN EXPRESS HAS 15 NUMBERS
  // DON'T FORGET TO ADD AN L TO THE END OF THE NUMBER TO REPRESENT A LONG TYPE
  if (validateCard(ENTER NUMBER HERE) == 1)
  {
    if (validateFlag(ENTER NUMBER HERE) == 1)
    {
      printf("Your card is MASTERCARD\n");
    }
    else if (validateFlag(ENTER NUMBER HERE) == 2)
    {
      printf("Your card is AMERICAN EXPRESS\n");
    }
    else if (validateFlag(ENTER NUMBER HERE) == 3)
    {
      printf("Your card is VISA\n");
    }
    else
    {
      printf("We only accept the following flags: MASTERCARD, AMERICAN EXPRESS AND VISA!\n");
    }
  }
  else
  {
    printf("Número do cartão INVÁLIDO\n");
  }
  return 0;
}

int validateFlag(long number)
{
  int numberLength = 0;
  int flagID = 0;
  long divider = 0L;
  long quantityOfNumbers = number;

  do
  {
    quantityOfNumbers /= 10;
    numberLength++;
  } while (quantityOfNumbers > 0);

  if (numberLength == 16)
  {
    divider = calculateDivider(numberLength);
    if (divider != -1)
    {
      if (number / divider == 51 || number / divider == 52 || number / divider == 53 ||
          number / divider == 54 || number / divider == 55)
      {
        // MASTERCARD
        return flagID = 1;
      }
    }
  }
  if (numberLength == 15)
  {
    divider = calculateDivider(numberLength);
    if (divider != -1)
    {
      if ((number / divider) == 34 || (number / divider) == 37)
      {
        // AMERICAN EXPRESS
        return flagID = 2;
      }
    }
  }
  if (numberLength >= 13 && numberLength <= 16)
  {
    divider = 0;
    divider = calculateDivider(numberLength);
    if (divider != -1)
    {
      if (((number / 10) / divider) == 4)
      {
        // VISA
        return flagID = 3;
      }
    }
  }

  return flagID;
}

long calculateDivider(int divider)
{
  long x = 0;
  if (divider == 13)
  {
    x = 100000000000L;
  }
  else if (divider == 14)
  {
    x = 1000000000000L;
  }
  else if (divider == 15)
  {
    x = 10000000000000L;
  }
  else if (divider == 16)
  {
    x = 100000000000000L;
  }
  else
  {
    x = -1;
  }

  return x;
}

// LUHN ALGORITHM
int validateCard(long number)
{
  if (number > 0)
  {
    long quantityOfNumbers = number;
    int numberLength = 0;
    long divider = 0;
    long remainder = 10;
    int digit = 0;
    int result = 0;
    int otherResult = 0;
    int finalResult = 0;

    do
    {
      quantityOfNumbers /= 10;
      numberLength++;
    } while (quantityOfNumbers > 0);

    for (int i = numberLength; i >= 0; i--)
    {
      if (i % 2 != 0)
      {
        if (divider == 0)
        {
          digit = number % remainder * 2;
        }
        else
        {
          digit = number % remainder / divider * 2;
        }
        if (digit >= 10)
        {
          result += digit / 10;
          result += digit % 10;
        }
        else
        {
          result += digit;
        }
      }
      else
      {
        if (divider == 0)
        {
          otherResult += number % remainder;
        }
        else
        {
          otherResult += number % remainder / divider;
        }
      }
      if (divider == 0)
      {
        divider += 10;
      }
      else
      {
        divider *= 10;
      }
      remainder *= 10;
    }
    finalResult = (result + otherResult) % 10;

    if (finalResult == 0)
    {
      // CREDIT CARD VALID
      return 1;
    }
  }
  // CREDIT CARD INVALID
  return 0;
}