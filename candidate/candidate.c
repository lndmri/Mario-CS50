#include <cs50.h>
#include <stdio.h>
#include <string.h>


typedef struct
{
    string name;
    int votes;

}candidate;


candidate get_candidate(string prompt);


int main(void)
{
    candidate sample = get_candidate("Enter Candidate info.");
    printf("Name is %s.\nAmount of votes is %i\n",sample.name, sample.votes);

}

candidate get_candidate(string prompt)
{
    printf("%s\n",prompt);
    candidate generic;
    generic.name = get_string("Name: ");
    generic.votes = get_int("Votes: ");

    return generic;
}