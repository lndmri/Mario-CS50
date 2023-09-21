#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Using typedef
typedef struct
{
    string name;
    string number;
}
person;

int main(void)
{


    person people[2];

    people[0].name = "Carter";
    people[0].number = "+1 213-236-8754";

    people[1].name = "John";
    people[1].number = "+1 634-536-8121";

    string name = get_string("Name: ");

    for (int i = 0; i < 2; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Found. Phone number is %s\n",people[i].number);

        }
}


}