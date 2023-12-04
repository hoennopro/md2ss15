#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int maSach;
    char name[50];
    char tac_gia[50];
    int price;
    char theloai[50];
} bk;

void printfMenu() {
    printf("\n");
	printf("1. Nhap thong tin sach.\n");
	printf("2. Hien thi danh sach sach.\n");
	printf("3. Them sach moi.\n");
	printf("4. Xoa sach.\n");
	printf("5. Cap nhat thong tin sach.\n");
	printf("6. Sap xep sach theo gia.\n");
	printf("7. Tim kiem sach theo ten.\n");
	printf("8. Tim kiem sach trong khoang gia.\n");
	printf("9. Thoat.\n");
	printf("Nhap lua chon cua ban: ");
}

void nhap_thong_tin(bk *books, int *n) {
    int i;
    printf("Nhap so luong sach: ");
    scanf("%d", n);
    for (i = 0; i < *n; i++) {
        printf("Nhap thong tin cho sach thu %d:\n", i + 1);
        printf("Nhap ma sach: ");
        scanf("%d", &books[i].maSach);
        printf("Nhap ten sach: ");
        scanf("%s", books[i].name);
        printf("Nhap tac gia sach: ");
        scanf("%s", books[i].tac_gia);
        printf("Nhap gia tien sach: ");
        scanf("%d", &books[i].price);
        printf("Nhap the loai sach: ");
        scanf("%s", books[i].theloai);
    }
    printf("Da nhap thong tin cho %d quyen sach.\n", *n);
}

void hien_thi(bk *books, int n) {
    int i;
    printf("Danh sach sach:\n");
    for (i = 0; i < n; i++) {
        printf("Thong tin sach thu %d:\n", i + 1);
        printf("Ma sach: %d\n", books[i].maSach);
        printf("Ten sach: %s\n", books[i].name);
        printf("Tac gia sach: %s\n", books[i].tac_gia);
        printf("Gia tien sach: %d\n", books[i].price);
        printf("The loai sach: %s\n", books[i].theloai);
    }
}

void them_sach_moi(bk *books, int *n, int m) {
    if (*n >= 100) {
        printf("Danh sach day.\n");
        return;
    }
    int i;
    for (i = *n - 1; i >= m; i--) {
        books[i + 1] = books[i];
    }
    printf("Nhap thong tin sach:\n");
    printf("Nhap ma sach: ");
    scanf("%d", &books[m].maSach);
    printf("Nhap ten sach: ");
    scanf("%s", books[m].name);
    printf("Nhap tac gia sach: ");
    scanf("%s", books[m].tac_gia);
    printf("Nhap gia tien sach: ");
    scanf("%d", &books[m].price);
    printf("Nhap the loai sach: ");
    scanf("%s", books[m].theloai);
    (*n)++;
    printf("Da them sach moi.\n");
}

void xoa_sach(bk *books, int *n, int ma) {
    int i, j;
    for (i = 0; i < *n; i++) {
        if (books[i].maSach == ma) {
            for (j = i; j < (*n - 1); j++) {
                books[j] = books[j + 1];
            }
            (*n)--;
            printf("Da xoa sach co ma %d.\n", ma);
            return;
        }
    }
    printf("Khong tim thay sach co ma %d.\n", ma);
}

void cap_nhat_sach(bk *books, int n, int ma) {
    int i;
    for (i = 0; i < n; i++) {
        if (books[i].maSach == ma) {
            printf("Nhap thong tin moi cho sach:\n");
            printf("Nhap ten sach: ");
            scanf("%s", books[i].name);
            printf("Nhap tac gia sach: ");
            scanf("%s", books[i].tac_gia);
            printf("Nhap gia tien sach: ");
            scanf("%d", &books[i].price);
            printf("Nhap the loai sach: ");
            scanf("%s", books[i].theloai);
            printf("Da cap nhat thong tin cho sach co ma %d.\n", ma);
            return;
        }
    }
    printf("Khong tim thay sach co ma %d.\n", ma);
}

void sap_xep_gia(bk *books, int n) {
    int i, j;
    bk temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (books[j].price > books[j + 1].price) {
                temp = books[j];
                books[j] = books[j + 1];
                books[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep sach theo gia tang dan.\n");
}

void tim_kiem_ten(bk *books, int n, char *ten) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (strcmp(books[i].name, ten) == 0) {
            printf("Thong tin sach co ten %s:\n", ten);
            printf("Ma sach: %d\n", books[i].maSach);
            printf("Ten sach: %s\n", books[i].name);
            printf("Tac gia sach: %s\n", books[i].tac_gia);
            printf("Gia tien sach: %d\n", books[i].price);
            printf("The loai sach: %s\n", books[i].theloai);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach co ten %s.\n", ten);
    }
}

void tim_kiem_gia(bk *books, int n, int gia_min, int gia_max) {
    int i, found = 0;
    for (i = 0; i < n; i++) {
        if (books[i].price >= gia_min && books[i].price <= gia_max) {
            if (!found) {
                printf("Danh sach sach trong khoang gia %d - %d:\n", gia_min, gia_max);
            }
            printf("Thong tin sach thu %d:\n", i + 1);
            printf("Ma sach: %d\n", books[i].maSach);
            printf("Ten sach: %s\n", books[i].name);
            printf("Tac gia sach: %s\n", books[i].tac_gia);
            printf("Gia tien sach: %d\n", books[i].price);
            printf("The loai sach: %s\n", books[i].theloai);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sach trong khoang gia %d - %d.\n", gia_min, gia_max);
    }
}

int main() {
    bk books[100];
    int n = 0;
    int choice, ma;
    char ten[50];
    int gia_min, gia_max;

    do {
        printfMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                nhap_thong_tin(books, &n);
                break;
            case 2:
                hien_thi(books, n);
                break;
            case 3:
                them_sach_moi(books, &n, n);
                break;
            case 4:
                printf("Nhap ma sach can xoa: ");
                scanf("%d", &ma);
                xoa_sach(books, &n, ma);
                break;
            case 5:
                printf("Nhap ma sach can cap nhat: ");
                scanf("%d", &ma);
                cap_nhat_sach(books, n, ma);
                break;
            case 6:
                sap_xep_gia(books, n);
                break;
            case 7:
                printf("Nhap ten sach can tim: ");
                scanf("%s", ten);
                tim_kiem_ten(books, n, ten);
                break;
            case 8:
                printf("Nhap gia thap nhat: ");
                scanf("%d", &gia_min);
                printf("Nhap gia cao nhat: ");
                scanf("%d", &gia_max);
                tim_kiem_gia(books, n, gia_min, gia_max);
                break;
            case 9:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le");
                break;
        	}
        }while(1);
    }
