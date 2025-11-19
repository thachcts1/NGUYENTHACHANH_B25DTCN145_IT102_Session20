#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student students[50];
    int i;

    for (i = 0; i < 5; i++) {
        students[i].id = i + 1;

        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);

        printf("Nhap ten: ");
        scanf("%49s", students[i].name);

        printf("Nhap tuoi: ");
        scanf("%d", &students[i].age);

        printf("Nhap so dien thoai: ");
        scanf("%14s", students[i].phoneNumber);
    }

    printf("\nDanh sach sinh vien:\n");

    for (i = 0; i < 5; i++) {
        printf("Sinh vien thu %d:\n", i + 1);
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
    }

    return 0;
}
