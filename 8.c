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
    int pos;
    int i;
    struct Student newStudent;

    printf("Nhap vi tri muon chen (0 den %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Vi tri khong hop le\n");
    } else {
        printf("Nhap thong tin sinh vien muon chen:\n");

        printf("Nhap id: ");
        scanf("%d", &newStudent.id);

        printf("Nhap ten: ");
        scanf("%49s", newStudent.name);

        printf("Nhap tuoi: ");
        scanf("%d", &newStudent.age);

        printf("Nhap so dien thoai: ");
        scanf("%14s", newStudent.phoneNumber);

        for (i = n; i > pos; i--) {
            students[i] = students[i - 1];
        }

        students[pos] = newStudent;
        n = n + 1;
    }

    printf("\nDanh sach sinh vien sau khi chen:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n\n", students[i].phoneNumber);
    }

    return 0;
}
