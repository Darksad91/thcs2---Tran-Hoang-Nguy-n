#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CONTACTS 100

typedef struct {
    int id;
    char name[30];
    char email[50];
    char phone[11];
    bool sex;
    char address[50];
} Contact;

void displayContact(Contact c) {
    printf("ID: %d\n", c.id);
    printf("Name: %s\n", c.name);
    printf("Email: %s\n", c.email);
    printf("Phone: %s\n", c.phone);
    printf("Sex: %s\n", c.sex ? "Nam" : "Nu");
    printf("Address: %s\n", c.address);
    printf("--------------------------\n");
}

void displayAllContacts(Contact contacts[], int n) {
    if(n == 0) {
        printf("Danh sach lien he trong.\n");
        return;
    }
    for(int i = 0; i < n; i++) {
        displayContact(contacts[i]);
    }
}

void addContact(Contact contacts[], int *n) {
    if(*n >= MAX_CONTACTS) {
        printf("Danh sach da day.\n");
        return;
    }
    Contact c;
    c.id = (*n) + 1;
    
    printf("Nhap ten: ");
    getchar();
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = 0;

    printf("Nhap email: ");
    fgets(c.email, sizeof(c.email), stdin);
    c.email[strcspn(c.email, "\n")] = 0;


    printf("Nhap so dien thoai: ");
    fgets(c.phone, sizeof(c.phone), stdin);
    c.phone[strcspn(c.phone, "\n")] = 0;

    char sexInput;
    printf("Nhap gioi tinh (M/N): ");
    scanf(" %c", &sexInput);
    c.sex = (sexInput == 'M' || sexInput == 'm') ? true : false;

    printf("Nhap dia chi: ");
    getchar();
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address, "\n")] = 0;

    contacts[*n] = c;
    (*n)++;
    printf("Them lien he thanh cong!\n");
}

void searchContact(Contact contacts[], int n) {
    char keyword[30];
    printf("Nhap ten can tim: ");
    getchar();
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    for(int i = 0; i < n; i++) {
        if(strstr(contacts[i].name, keyword)) {
            displayContact(contacts[i]);
        }
    }
}

void deleteContact(Contact contacts[], int *n) {
    int id;
    printf("Nhap ID can xoa: ");
    scanf("%d", &id);

    int found = 0;
    for(int i = 0; i < *n; i++) {
        if(contacts[i].id == id) {
            found = 1;
            for(int j = i; j < *n - 1; j++) {
                contacts[j] = contacts[j + 1];
            }
            (*n)--;
            printf("Xoa lien he thanh cong!\n");
            break;
        }
    }
    if(!found) printf("Khong tim thay ID.\n");
}

void editContact(Contact contacts[], int n) {
    int id;
    printf("Nhap ID can chinh sua: ");
    scanf("%d", &id);
    getchar();

    for(int i = 0; i < n; i++) {
        if(contacts[i].id == id) {
            printf("Nhap ten moi: ");
            fgets(contacts[i].name, sizeof(contacts[i].name), stdin);
            contacts[i].name[strcspn(contacts[i].name, "\n")] = 0;

            printf("Nhap email moi: ");
            fgets(contacts[i].email, sizeof(contacts[i].email), stdin);
            contacts[i].email[strcspn(contacts[i].email, "\n")] = 0;

            printf("Nhap so dien thoai moi: ");
            fgets(contacts[i].phone, sizeof(contacts[i].phone), stdin);
            contacts[i].phone[strcspn(contacts[i].phone, "\n")] = 0;

            char sexInput;
            printf("Nhap gioi tinh moi (M/N): ");
            scanf(" %c", &sexInput);
            contacts[i].sex = (sexInput == 'M' || sexInput == 'm') ? true : false;

            printf("Nhap dia chi moi: ");
            getchar();
            fgets(contacts[i].address, sizeof(contacts[i].address), stdin);
            contacts[i].address[strcspn(contacts[i].address, "\n")] = 0;

            printf("Chinh sua thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay ID.\n");
}

void sortContacts(Contact contacts[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp(contacts[i].name, contacts[j].name) > 0) {
                Contact temp = contacts[i];
                contacts[i] = contacts[j];
                contacts[j] = temp;
            }
        }
    }
    printf("Sap xep danh sach theo ten thanh cong!\n");
}

int main() {
    Contact contacts[MAX_CONTACTS];
    int n = 0;
    int choice;

    do {
        printf("\n----------------------- Contact Menu --------------------\n");
        printf("1. Hien thi danh sach lien he\n");
        printf("2. Them cac lien he moi\n");
        printf("3. Chinh sua thong tin lien he\n");
        printf("4. Xoa lien he\n");
        printf("5. Tim kiem lien he\n");
        printf("6. Sap xep\n");
        printf("0. Thoat chuong trinh\n");
        printf("---------------------------------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: displayAllContacts(contacts, n); break;
            case 2: addContact(contacts, &n); break;
            case 3: editContact(contacts, n); break;
            case 4: deleteContact(contacts, &n); break;
            case 5: searchContact(contacts, n); break;
            case 6: sortContacts(contacts, n); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le.\n");
        }

    } while(choice != 0);

    return 0;
}
