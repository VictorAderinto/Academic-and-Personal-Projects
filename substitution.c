#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void encrypt(string argv[1]);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (isblank(argv[1][i]) || isdigit(argv[1][i]))
        {
            printf("Key must be an alphabetic character\n");
            return 1;
        }
    }    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Key must not contain repeated characters\n");
                return 1; 
            }
        }
    }
    if (strlen(argv[1]) != 26 )
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    string plaintext =  get_string("Plaintext:");
    string alphabet = "ABCDEFGHIJKLMONPQRSTUVWXYZ";
    string alphabet2 = "abcdefghijklmnopqrstuvwxyz";
    for (long k = 0, m = strlen(plaintext); k < m; k++)
    {
    for (long i = 0, n = strlen(alphabet);i < n; i++)
    {
        if (isalpha(plaintext[k]) && islower(plaintext[k]) && plaintext[k] == alphabet2[i])
        {
            plaintext[k] = tolower(argv[1][i]);
            k++;
        }
        if (isalpha(plaintext[k]) && isupper(plaintext[k]) && plaintext[k] == alphabet[i])
        {
            plaintext[k] = toupper(argv[1][i]);
            k++;
        }
    }
    }
    printf("ciphertext: %s\n", plaintext);
    return 0;
}

