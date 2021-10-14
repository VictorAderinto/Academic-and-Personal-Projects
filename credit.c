#include <cs50.h>
#include <stdio.h>
#include <math.h>

long get_credit_card(void);
int card_counting(long n);

int main(void)
{
    long card =  get_credit_card();
    int card_length = card_counting(card);
    if (card_length == 13 || card_length == 15 || card_length == 16)
    {
        int add = 0 ;
        long number;
        for (int i = 1 ; i < card_length; i = i + 2) // iterates from 1 to card length in increments of 2
        {
            number =  card / pow(10, i); 
            number = number % 10;
            number =  number * 2;  // gets digits at a particular position and multiplies by 2
            int sum = 0;
            if (number >= 10) // checks to see if digit is more than ten
            {
                int digit = number % 10;
                sum = digit + 1;
                add = add + sum;   //  variable that stores sum of the product digits
            }
            else
            {
                add = add + number;
            }
        }
        long sums;
        int total = 0;
        for (int j = 0; j < card_length; j = j + 2)  // iterates from 0 to card length in increments of 2
        {
            sums = card / pow(10, j);  
            sums = sums % 10;   // gets digit at a particular position
            total = total + sums;  // variable that sums up digits in the card number
        }
        int total_sum = total + add;
        long num1 = card  / pow(10, card_length - 1);
        num1 = num1 % 10;
        long num2 = card / pow(10, card_length - 2);
        num2 = num2 % 10;
        if (total_sum % 10 == 0 && num1 == 4)  // checks to see if card meets requirements to be a VISA card
        {
            printf("VISA\n");
        }
        else if (total_sum % 10 == 0 && num1 == 5 && num2 > 0 && num2 < 6)  // checks to see if card meets requirements to be a MASTERCARD
        {
            printf("MASTERCARD\n");
        }
        else if (total_sum % 10 == 0 && num1 == 3 && (num2 == 4 || num2 == 7))   // checks to see if card meets requirements to be AMEX  card
        {
            printf("AMEX\n");
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

}

//function that gets card number from the user
long get_credit_card(void)
{
    long n;
    do
    {
        n =  get_long("What is your credit card number?\n");
    }
    while (n < 1);
    return n;
}

//counts number of digits in card number
int card_counting(long n)
{
    int card_counter = 0;
    while (n != 0)
    {
        n = n / 10;
        card_counter++;
    }
    return card_counter;
}