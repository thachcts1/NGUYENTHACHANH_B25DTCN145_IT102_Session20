#include <stdio.h>

struct Student {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student sv;

    printf("Nhap ten sinh vien: ");
    scanf("%49s", sv.name);

    printf("Nhap tuoi: ");
    scanf("%d", &sv.age);

    printf("Nhap so dien thoai: ");
    scanf("%14s", sv.phoneNumber);

    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("So dien thoai: %s\n", sv.phoneNumber);

    return 0;
}
