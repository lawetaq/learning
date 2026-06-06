#include <stdio.h>

int main(void)
{
    int scores[3];
    int count;
    float average;

    for (count = 0; count < 3; count++)
    {
        printf("Enter a number: ");
        scanf("%i", &scores[count]);
    }

    int sum = 0;

    for (count = 0; count < 3; count++)
    {
        sum = sum + scores[count];
    }

    average = sum / 3.0;
    printf("Average: %f\n", average);

    return 0;
}