#include <stdio.h>

/*
Author: Mario A Landa Pulido
U_Number: U63987600
Purpose: This program calculates the time an escalator is active, given the number of people that use it and the time when they
enter it (in seconds).
*/

// Function prototype
int active_seconds(int arrival[], int n);

int main(void)
{
    int num_people;

    // Get input for number of people
    printf("Enter number of people: ");
    scanf("%d", &num_people);

    int arrival[num_people];

    printf("Enter arrival times: ");

    // Get input for number of people
    for (int i = 0; i < num_people; i++)
    {
        scanf("%d", &arrival[i]);
    }

    // print the time that the escalator is active
    printf("Active seconds: %d\n", active_seconds(arrival, num_people));
}

// this function calculates the time the escalator is active

int active_seconds(int arrival[], int n)
{
    int time = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (arrival[i + 1] - arrival[i] < 10)
        {
            time += arrival[i + 1] - arrival[i];
        }
        else
        {
            time += 10;
        }
    }

    // Validate in case the user enters no person

    if (n != 0)
    {
        return time + 10;
    }
    else
    {
        return 0;
    }
}
