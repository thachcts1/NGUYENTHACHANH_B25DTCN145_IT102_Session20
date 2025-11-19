#include <stdio.h>

struct Student {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
};

int main() {
    struct Student students[50] = {
        {1, "An", 18, "0123456789"},
        {2, "Binh", 19, "0223456789"},
        {3, "Cuong", 20, "0323456789"},
        {4, "Dung", 21, "0423456789"},
        {5, "Huy", 19, "0523456789"}
    };

    int n = 5;
    int idSearch;
    int i;
    int foundIndex = -1;

    printf("Nhap id sinh vien muon sua: ");
    scanf("%d", &idSearch);

    for (i = 0; i < n; i++) {
        if (students[i].id == idSearch) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1) {
        printf("Khong tim thay sinh vien co id = %d\n", idSearch);
    } else {
        printf("Nhap ten moi: ");
        scanf("%49s", students[foundIndex].name);

        printf("Nhap tuoi moi: ");
        scanf("%d", &students[foundIndex].age);
    }

    printf("\nDanh sach sinh vien sau khi chinh sua:\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", students[i].id);
        printf("Ten: %s\n", students[i].name);
        printf("Tuoi: %d\n", students[i].age);
        printf("So dien thoai: %s\n", students[i].phoneNumber);
        printf("\n");
    }

    return 0;
}
