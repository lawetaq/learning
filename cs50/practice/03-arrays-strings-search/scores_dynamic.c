#include <stdio.h>

int main(void)
{
    int n;
    float average;
    int sum = 0;

    do 
    {
        printf("How many scores? ");
        scanf("%i", &n); 
    }
    while (n < 1);

    int scores[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter score %i: ", i + 1);
        scanf("%i", &scores[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sum += scores[i];
    }

    average = sum / (float) n;
    printf("Average: %f\n", average);

    return 0;
}