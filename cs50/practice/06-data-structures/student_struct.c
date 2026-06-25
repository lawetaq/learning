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
    student s;

    strcpy(s.name, "Nikita");
    s.age = 19;

    printf("Name: %s\n", s.name);
    printf("Age: %i\n", s.age);

    return 0;
}