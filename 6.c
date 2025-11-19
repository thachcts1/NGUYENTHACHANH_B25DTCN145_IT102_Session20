#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student students[50] = {
        {1, "An",   18, "0123456789"},
        {2, "Binh", 19, "0223456789"},
        {3, "Cuong",20, "0323456789"},
        {4, "Dung", 21, "0423456789"},
        {5, "Huy",  19, "0523456789"}
    };

    int n = 5;
    struct Student newStudent;
    int i;

    printf("Nhap thong tin sinh vien muon them:\n");

    printf("Nhap id: ");
    scanf("%d", &newStudent.id);

    printf("Nhap ten: ");
    scanf("%49s", newStudent.name);

    printf("Nhap tuoi: ");
    scanf("%d", &newStudent.age);

    printf("Nhap so dien thoai: ");
    scanf("%14s", newStudent.phoneNumber);

    students[n] = newStudent;
    n = n + 1;

    printf("\nDanh sach sinh vien sau khi them moi:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
        printf("\n");
    }

    return 0;
}
