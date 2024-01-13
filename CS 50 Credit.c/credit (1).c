#include <cs50.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int digit_count(long card_number);
int multiplication(int last_digit);
int number_digits(long card_number);
bool ValidAmex(long card_number, int numberdigits);
bool ValidMasterCard(long card_number, int numberdigits);
bool ValidVisa(long card_number, int numberdigits);

int main(void)

{
    // Ask the user to enter a credit card number
   long card_number = get_long("Enter your credit card number: ");

   int total_number_digit_count = digit_count(card_number);
   int numberdigits = number_digits(card_number);
   bool amex = ValidAmex( card_number, numberdigits);
   bool master = ValidMasterCard( card_number, numberdigits);
   bool visa = ValidVisa(card_number, numberdigits);


  //Check what kind of card it is
   if (total_number_digit_count % 10 !=0)
   {
    printf("INVALID\n");
    return 0;
   }
   else if (amex == true)
   {
    printf("AMEX\n");
   }

else if (master == true)
   {
    printf("MASTERCARD\n");
   }
   else if (visa == true)
   {
    printf("VISA\n");
   }
   else
   {
    printf("INVALID\n");

    return 0;
   }
}

bool ValidAmex(long card_number, int numberdigits)
{
    int frist_two_digits = card_number / pow (10, 13);
    if((numberdigits == 15) && (frist_two_digits == 34 || frist_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidVisa(long card_number, int numberdigits)
{
    if(numberdigits == 13)
    {
      int frist_digit = card_number / pow (10, 12);
      if(frist_digit == 4)
      {
        return true;
      }
    }

    else if (numberdigits == 16)
      {
      int frist_digit = card_number / pow (10, 15);
      if(frist_digit == 4)
      {
        return true;
      }
    }


        return false;



}


bool ValidMasterCard(long card_number, int numberdigits)
{
    int frist_two_digits = card_number / pow (10, 14);
    if((numberdigits == 16) && (frist_two_digits > 50 &&  frist_two_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int number_digits(long card_number)
{
    int count = 0;
    while(card_number > 0)
    {
        count = count + 1;
        card_number = card_number / 10;
    }

    return count;
}

int digit_count(long card_number)
{
    int total = 0;
    bool AlternateDigit = false;

    while(card_number > 0)
    {
        if(AlternateDigit == true)
        {
            int last_digit = card_number % 10;
            int product = multiplication(last_digit);
           total = total + product;
        }
        else
        {
            int last_digit = card_number % 10;
            total = total + last_digit;
        }

        AlternateDigit = !AlternateDigit;
        card_number = card_number / 10;
    }

    return total;

}



int multiplication (int last_digit)
{
   int multiplication = last_digit * 2;
   int total = 0;

   while(multiplication > 0)
   {
    int last_digit_multiplication = multiplication % 10;
    total = total + last_digit_multiplication;
    multiplication = multiplication / 10;

   }

   return total;

}
