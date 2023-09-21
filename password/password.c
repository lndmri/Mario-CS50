// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    string pswd = password;
    int len = strlen(password);
    bool lower = false;
    bool upper = false;
    bool digit = false;
    bool symbol = false;
    // THERE IS A WAY TO OPTIMIZE THIS INTO ONLYBONE LOOP
    for (int i = 0; i < len; i++)
    {
        if (islower(pswd[i]))
        {
            lower = true;
        }
        if (isupper(pswd[i]))
        {
            upper =  true;
        }
        if (isdigit(pswd[i]))
        {
            digit = true;
        }
        if (!isalnum(pswd[i]))
        {
            symbol = true;
        }
    }

    if (lower && upper && digit && symbol)
    {
        return true;
    }
    else
    {
        return false;
    }
}
