#include <cs50.h>
#include <stdio.h>

int main(void)


{
   // Get the card number from the user
    long long card_number;
    do
    {
        card_number = get_long_long(" Provide a credit card number: ");
    }
    while (card_number < 0);

   // Check the correctness of the card number using the Luhn algorithm
    int sum = 0;
    int digit_count = 0;
    long long temp_number = card_number;

    while (temp_number > 0)
    {
      // Get the last digit
        int digit = temp_number % 10;

        // If even number, add to total
        if (digit_count % 2 == 0)
        {
            sum += digit;
        }
        else
        {
          // If an odd digit, multiply by 2 and add the digits of the result to the sum
            int doubled_digit = digit * 2;
            sum += doubled_digit / 10 + doubled_digit % 10;
        }
// Go to next digit
        temp_number /= 10;
        digit_count++;
    }

    // Check that the final sum is divisible by 10
    if (sum % 10 == 0)
    {
      // Check card type
        int first_digit = card_number / 1000000000000000; // Get the first digit

        if ((digit_count == 15) && (first_digit == 3))
        {
            printf("AMEX\n");
        }
        else if ((digit_count == 16) && (first_digit == 5))
        {
            printf("MASTERCARD\n");
        }
        else if ((digit_count == 16) && (first_digit == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
