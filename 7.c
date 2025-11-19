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
    int idDelete;
    int i;
    int foundIndex = -1;

    printf("Nhap id sinh vien muon xoa: ");
    scanf("%d", &idDelete);

    for (i = 0; i < n; i++) {
        if (students[i].id == idDelete) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Khong tim thay sinh vien co id = %d\n", idDelete);
    } else {
        for (i = foundIndex; i < n - 1; i++) {
            students[i] = students[i + 1];
        }
        n = n - 1;
    }

    printf("\nDanh sach sinh vien sau khi xoa:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n\n", students[i].phoneNumber);
    }

    return 0;
}
