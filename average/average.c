# include <stdio.h>
# include <cs50.h>

const int N = 3;

float average(int length, float array[]);

int main(void)
{
    float array[N];

    for (int i = 0; i < N; i++){
        array[i] = get_float("Score: ");
    }

    printf("The sum is %.2f\n", average(N, array));

}

float average(int length, float array[])
{
    float sum = 0;

    for(int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
