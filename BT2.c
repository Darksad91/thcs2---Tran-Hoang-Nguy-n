#include <stdio.h>
#include <string.h>

struct Product {
    char id[50];
    char name[100];
    float price;
    int quantity;
};

void input_product(struct Product *p) {
    fgets(p->id, sizeof(p->id), stdin);
    p->id[strcspn(p->id, "\n")] = '\0';

    fgets(p->name, sizeof(p->name), stdin);
    p->name[strcspn(p->name, "\n")] = '\0';

    scanf("%f %d", &p->price, &p->quantity);
}

float total_price(struct Product p) {
    return p.price * p.quantity;
}

void display_product(struct Product p) {
    printf("ID: %s - Name: %s\n", p.id, p.name);
    printf("Price: %.2f - Quantity: %d\n", p.price, p.quantity);
    printf("Total: %.2f\n", total_price(p));
}

int main() {
    struct Product p;

    input_product(&p);
    display_product(p);

    return 0;
}

