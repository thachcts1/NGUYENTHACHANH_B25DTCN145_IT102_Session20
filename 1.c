#include <stdio.h>

struct Student {
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student sv = {"Luong Gia Huy", 18, "0123456789"};

    printf("Thong tin sinh vien:\n");
    printf("Ten: %s\n", sv.name);
    printf("Tuoi: %d\n", sv.age);
    printf("So dien thoai: %s\n", sv.phoneNumber);

    return 0;
}
