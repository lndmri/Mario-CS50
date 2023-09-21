#include <stdio.h>
#define N 26

int main(void)
{
    char ch;
    int alphabet[N];
    int is_anagram = 1;

    for (int i = 0; i < N; i++)
    {
        alphabet[i] = 0;
    }

    printf("Enter first word: ");
    while((ch = getchar()) != '\n')
    {
        ch -= 'a';
        alphabet[(int) ch]++;
    }

    printf("Enter second word: ");
    while((ch = getchar()) != '\n')
    {
        ch -= 'a';
        alphabet[(int) ch]--;
    }

    for (int i = 0; i < N; i++)
    {
        if (alphabet[i] != 0)
        {
            is_anagram = 0;
            break;
        }
    }

    if (is_anagram)
        printf("Words are anagrams!\n");
    else
        printf("Words are not anagrams\n");

    return 0;

}