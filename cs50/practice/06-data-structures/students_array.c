#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    int age;
}
student;

int main(void)
{
    student students[3];

    strcpy(students[0].name, "Nikita");
    students[0].age = 19;

    strcpy(students[1].name, "Alexandra");
    students[1].age = 20;

    strcpy(students[2].name, "Egor");
    students[2].age = 18;

    for (int i = 0; i < 3; i++)
    {
        printf("Name: %s\n", students[i].name);
        printf("Age: %i\n", students[i].age);
        printf("\n");
    }

    return 0;
}