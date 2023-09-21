#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int starting_population;
    const int least_population = 9;
    int endsize;
    int n = 0;
    int added_population;

    do
    {
        starting_population = get_int("Initial llamas population: ");
        added_population = starting_population;
        if (starting_population < least_population){
            printf("Minimum population can not be less than 9 llamas\n");
        }
    }while(starting_population < least_population);

    //printf("%i/n",starting_population);

    // TODO: Prompt for end size
    do{
        endsize = get_int("Endsize of llamas: ");
        if(endsize < starting_population){
            printf("Endsize cannot be less than initial size\n");
        }
    }while(endsize < starting_population);

    // TODO: Calculate number of years until we reach threshold
    while(added_population < endsize){
        added_population = added_population + (int)(added_population/3) - (int)(added_population/4);
        n++;
    }

    // TODO: Print number of years
    printf("Years: %i\n",n);
}
