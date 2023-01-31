#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Given a list of numbers and a number k, return whether any two numbers from the list add up to k.
// For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.

int get_existence(int* input, int length, int k)
{
    /// Create a dynamic array to hold all the possible values
    for(int i = 0; i < length; i++)
    {
        for(int j = i; j < length; j++)
        {
            if( (input[i] + input[j]) == k) return 1;
        }
    }
    return 0;
}

// Bonus: Can you do this in one pass?
int get_existence_single_path(int* input, int length, int k)
{
    /// Here we are mimicking a pseudo map
    /// The space taken is really bad thought
    int buffer[3000] = {0};

    for(int i = 0; i < length; i++)
    {
        if(buffer[k - input[i]] != 0) 
        {
            return 1;
        }
        else 
        {
            buffer[input[i]] = input[i];
        }
    }
    
    return 0;
}

int main(int argc, char const *argv[])
{
    int tab[] = {10, 15, 3, 7};
    int k = 17;

    printf("%d", get_existence(tab, 4, k));
    
    return 0;
}
