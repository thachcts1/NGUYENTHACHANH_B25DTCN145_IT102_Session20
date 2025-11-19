#include <stdio.h>
#include <string.h>

struct Dish {
    int id;
    char name[50];
    int price;
};

void printAll(struct Dish menu[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d. id: %d, name: %s, price: %d\n",
               i + 1, menu[i].id, menu[i].name, menu[i].price);
    }
}

void insertAt(struct Dish menu[], int *n, int pos) {
    int i;
    struct Dish x;

    if (*n >= 100) {
        printf("Menu da day\n");
        return;
    }

    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le\n");
        return;
    }

    printf("Nhap id: ");
    scanf("%d", &x.id);
    printf("Nhap name: ");
    scanf("%49s", x.name);
    printf("Nhap price: ");
    scanf("%d", &x.price);

    for (i = *n; i > pos; i--) {
        menu[i] = menu[i - 1];
    }
    menu[pos] = x;
    *n = *n + 1;
}

void updateAt(struct Dish menu[], int n, int pos) {
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le\n");
        return;
    }

    printf("Nhap id moi: ");
    scanf("%d", &menu[pos].id);
    printf("Nhap name moi: ");
    scanf("%49s", menu[pos].name);
    printf("Nhap price moi: ");
    scanf("%d", &menu[pos].price);
}

void deleteAt(struct Dish menu[], int *n, int pos) {
    int i;
    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le\n");
        return;
    }

    for (i = pos; i < *n - 1; i++) {
        menu[i] = menu[i + 1];
    }
    *n = *n - 1;
}

void sortPriceDesc(struct Dish menu[], int n) {
    int i, j;
    struct Dish temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (menu[i].price < menu[j].price) {
                temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}

void sortPriceAsc(struct Dish menu[], int n) {
    int i, j;
    struct Dish temp;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (menu[i].price > menu[j].price) {
                temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}

int linearSearchByName(struct Dish menu[], int n, char key[]) {
    int i;
    for (i = 0; i < n; i++) {
        if (strcmp(menu[i].name, key) == 0) {
            return i;
        }
    }
    return -1;
}

int binarySearchByName(struct Dish menu[], int n, char key[]) {
    int i, j;
    struct Dish temp;
    int left, right, mid;

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(menu[i].name, menu[j].name) > 0) {
                temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }

    left = 0;
    right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (strcmp(menu[mid].name, key) == 0) {
            return mid;
        } else if (strcmp(menu[mid].name, key) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    struct Dish menu[100] = {
        {1, "Pho", 30000},
        {2, "Com", 25000},
        {3, "Bun", 28000},
        {4, "Mi", 26000},
        {5, "Lau", 120000}
    };

    int n = 5;
    int choice;
    int pos;
    int subChoice;
    char key[50];
    int index;

    do {
        printf("\nMENU\n");
        printf("1. In ra cac phan tu trong menu\n");
        printf("2. Them mot phan tu vao vi tri chi dinh\n");
        printf("3. Sua mot phan tu o vi tri chi dinh\n");
        printf("4. Xoa mot phan tu o vi tri chi dinh\n");
        printf("5. Sap xep cac phan tu theo price\n");
        printf("6. Tim kiem phan tu theo name\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printAll(menu, n);
            break;

        case 2:
            printf("Nhap vi tri muon them (0 den %d): ", n);
            scanf("%d", &pos);
            insertAt(menu, &n, pos);
            break;

        case 3:
            printf("Nhap vi tri muon sua (0 den %d): ", n - 1);
            scanf("%d", &pos);
            updateAt(menu, n, pos);
            break;

        case 4:
            printf("Nhap vi tri muon xoa (0 den %d): ", n - 1);
            scanf("%d", &pos);
            deleteAt(menu, &n, pos);
            break;

        case 5:
            printf("1. Giam dan theo price\n");
            printf("2. Tang dan theo price\n");
            printf("Lua chon: ");
            scanf("%d", &subChoice);
            if (subChoice == 1) {
                sortPriceDesc(menu, n);
            } else if (subChoice == 2) {
                sortPriceAsc(menu, n);
            }
            printAll(menu, n);
            break;

        case 6:
            printf("1. Tim kiem tuyen tinh\n");
            printf("2. Tim kiem nhi phan\n");
            printf("Lua chon: ");
            scanf("%d", &subChoice);

            printf("Nhap name can tim: ");
            scanf("%49s", key);

            if (subChoice == 1) {
                index = linearSearchByName(menu, n, key);
            } else {
                index = binarySearchByName(menu, n, key);
            }

            if (index == -1) {
                printf("Khong tim thay mon an\n");
            } else {
                printf("Tim thay: id: %d, name: %s, price: %d\n",
                       menu[index].id, menu[index].name, menu[index].price);
            }
            break;

        case 7:
            break;

        default:
            printf("Lua chon khong hop le\n");
        }
    } while (choice != 7);

    return 0;
}
