#include <cs50.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>


// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // TODO
    // for each candidate check if name matches
    for (int i = 0; i < candidate_count; i++)
    {

        // if it matches store the number of the candidate that matches
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;

}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO get the first non eliminated vote
    // for each voter
    for (int i = 0; i < voter_count; i++)
    {

        for (int j = 0; j < 3; j++)
        {
            if (preferences[i][j] <= candidate_count  && (!candidates[preferences[i][j]].eliminated))
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // TODO
    // figuring out the half of the votes, the max votes that a candidate received, and the index of that candidate
    int total_votes = 0;
    int max = 0;
    int index;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max)
        {
            max = candidates[i].votes;
            index = i;
        }
        total_votes += candidates[i].votes;
    }

    int half_votes = (total_votes % 2 == 0) ? (total_votes / 2) : ((total_votes + 1) / 2);

    if (max > half_votes)
    {
        printf("%s\n", candidates[index].name);
        return true;
    }


    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // TODO
    // Assuming that max number of votes that a candidate might have is a 100 declare min
    int min = 100;
    for (int i = 0; i < candidate_count; i++)
    {
        // if it is not eliminated and votes is less than min
        if (!(candidates[i].eliminated) && candidates[i].votes <= min)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    // Check if number of active candidates equals the number of candidates that have the min
    int still_in_election = 0;
    int tied_on_min = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            still_in_election++;
        }

        if (candidates[i].votes == min)
        {
            tied_on_min++;
        }
    }

    if (tied_on_min == still_in_election)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO


    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}