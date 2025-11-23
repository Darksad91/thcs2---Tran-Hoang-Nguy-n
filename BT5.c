#include <stdio.h>
#include <string.h>

struct Student {
    char id[50];
    char name[100];
    float gpa;
};

void input_students(struct Student arr[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s", arr[i].id);
        scanf("%s", arr[i].name);
        scanf("%f", &arr[i].gpa);
    }
}

const char* classify(struct Student s) {
    if (s.gpa >= 8.0) return "Excellent";
    if (s.gpa >= 6.5) return "Good";
    if (s.gpa >= 5.0) return "Average";
    return "Weak";
}

void print_by_type(struct Student arr[], int n, const char* type) {
    for (int i = 0; i < n; i++) {
        if (strcmp(classify(arr[i]), type) == 0) {
            printf("%s - %s - %.2f - %s\n", arr[i].id, arr[i].name, arr[i].gpa, type);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    struct Student arr[n];
    input_students(arr, n);

    print_by_type(arr, n, "Excellent");
    print_by_type(arr, n, "Good");
    print_by_type(arr, n, "Average");
    print_by_type(arr, n, "Weak");

    return 0;
}

