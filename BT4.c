#include <stdio.h>
#include <string.h>

struct Address {
    int number;
    char street[100];
    char district[100];
};

struct Employee {
    char id[50];
    char name[100];
    struct Address home;
};

int main() {
    struct Employee e;

    scanf("%s %s", e.id, e.name);
    scanf("%d %s", &e.home.number, e.home.street);
    getchar();
    fgets(e.home.district, sizeof(e.home.district), stdin);
    e.home.district[strcspn(e.home.district, "\n")] = '\0';

    printf("ID: %s - Name: %s\n", e.id, e.name);
    printf("Address: %d %s, %s\n", e.home.number, e.home.street, e.home.district);

    return 0;
}

