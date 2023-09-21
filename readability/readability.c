#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
int main (void)
{
    string s = "Hello";

    for (int i = 0, l = strlen(s); i <= l; i++)
    {
        printf("%i\n", s[i]);
    }

}
*/

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int computeGrade(int letters, int words, int sentences);

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    // Count letters
    int letters = count_letters(text);
    // printf("Letters %i\n", letters);


    // Count Words
    int words = count_words(text);
    // printf("Words: %i\n",words);


    // Count Sentences
    int sentences = count_sentences(text);
    // printf("Sentences: %i\n",sentences);

    // Compute the index passing letters, words and sentences

    int index = computeGrade(letters, words, sentences);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }


}

int count_letters(string text)
{
    int len = strlen(text);
    int letter_count = 0;
    for (int i = 0; i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter_count++;
        }
    }

    return letter_count;
}

int count_words(string text)
{
    int len = strlen(text);
    int word_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == ' ' && text[i + 1] != ' ')
        {
            word_count++;
        }

    }

    return word_count + 1;
}

int count_sentences(string text)
{
    int len = strlen(text);
    int sentence_count = 0;

    for (int i = 0; i < len; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count++;
        }
    }

    return sentence_count;
}

int computeGrade(int letters, int words, int sentences)
{
    double L = ((double)letters / words) * 100;
    double S = ((double)sentences / words) * 100;

    return (int) round(0.0588 * L - 0.296 * S - 15.8);
}