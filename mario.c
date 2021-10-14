#include <cs50.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    // gets int between 0 and 9 from user
    while (n > 8 || n <= 0);
    for (int i = 0; i < n; i++) // iterates through 0 to height for columns
    {
        for (int j = 0; j < n ; j++) //iterates through 0 to height for rows
        {
            if (j < n - i - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}