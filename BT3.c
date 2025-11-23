#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

int is_valid(struct Date d) {
    if (d.month < 1 || d.month > 12) return 0;

    int maxDay;

    if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7 ||
        d.month == 8 || d.month == 10 || d.month == 12)
        maxDay = 31;
    else if (d.month == 4 || d.month == 6 || d.month == 9 || d.month == 11)
        maxDay = 30;
    else {
        if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0))
            maxDay = 29;
        else
            maxDay = 28;
    }

    return d.day >= 1 && d.day <= maxDay;
}

int main() {
    int n;
    scanf("%d", &n);

    struct Date arr[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &arr[i].day, &arr[i].month, &arr[i].year);
    }

    for (int i = 0; i < n; i++) {
        if (is_valid(arr[i])) {
            printf("%d/%d/%d\n", arr[i].day, arr[i].month, arr[i].year);
        }
    }

    return 0;
}

