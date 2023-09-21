#include <cs50.h>
#include <stdio.h>
#include <math.h>


long get_card(void);
int get_card_length(long n);
bool checksum(long card, int length);
string check_issuer(long card, int length);

int main(void)
{
    // Get Credit Card Number
    long card_number = get_card();

    //printf("%li\n",card_number);

    // Get Card Length
    int card_length =  get_card_length(card_number);

    // printf("The card lenght is: %i\n", card_length);

    // Check Sum and
    bool validity = checksum(card_number, card_length);

    //Check Card issuer
    string issuer = check_issuer(card_number, card_length);
    // printf("%s",issuer);

    if (validity)
    {
        printf("%s\n", issuer);
    }
    else
    {
        printf("INVALID\n");

    }

}

long get_card(void)
{
    long card_number = 0;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    return card_number;
}

int get_card_length(long n)
{
    long card_number = n;
    int count = 0;
    while (card_number >= 1)
    {
        card_number /= 10;
        count++;
    }
    return count;
}

bool checksum(long card, int length)
{
    long card_number = card;
    int card_length = length;
    long sum1 = 0;
    long sum2 = 0;
    long mult = 0;

    // Get sum 1
    int i = card_length;
    while (i > 0)
    {
        sum1 += card_number % 10;
        card_number /= 100;
        i -= 2;
    }

    //printf("Sum1 is %li\n", card_number);

    // Re-assing value of card number but starting with second from last (getting rid of last number)
    card_number = card / 10;

    // Get sum2
    int j = card_length - 1;
    while (j > 0)
    {
        mult = (card_number % 10) * 2;

        if (mult >= 10)
        {
            sum2 += (mult % 10) + 1;
        }
        else
        {
            sum2 += mult;
        }
        card_number /= 100;
        j -= 2;
    }

    // printf("Sum 2 is %i\n", sum2);

    if ((sum1 + sum2) % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }

}

string check_issuer(long card, int length)
{
    long card_number = card;
    long card_length = length;
    long first = 1;
    long first_two = 1; //(long) pow (10, (card_length-2));
    string card_issuer = "";

    for (int i = 1; i < card_length; i++)
    {
        first *= 10;
    }
    first = card_number / first;


    for (int i = 2; i < card_length; i++)
    {
        first_two *= 10;
    }
    first_two = card_number / first_two;


    if (card_length == 15 && (first_two == 34 || first_two == 37))
    {
        card_issuer = "AMEX";
    }
    else if (card_length == 16 && (first_two == 51 || first_two == 52 || first_two == 53 || first_two == 54 || first_two == 55))
    {
        card_issuer = "MASTERCARD";
    }
    else if (card_length == 16 && first == 4)
    {
        card_issuer = "VISA";
    }
    else if (card_length == 13 && first == 4)
    {
        card_issuer = "VISA";
    }
    else
    {
        card_issuer = "INVALID";
    }

    return card_issuer;

}