#include <stdio.h>
#include <string.h>
#include "s.h"

void abc(Person p)
{
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
}

void main()
{
    Person person = {
        .name = "John Doe",
        .age = 30};

int x=sizeof(person);

printf("Size of person: %d\n", x);
}