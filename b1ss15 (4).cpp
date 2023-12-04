#include<stdio.h>
struct sinhVien {
	char name[50];
	int age;
	int number;
	char email[100];
};
int main(){
	int n;
	struct sinhVien dsSinhVien[n];
	printf("Nhap vao so sinh vien muon nhap: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Nhap vao ten sinh vien: ");
		scanf("%s",&dsSinhVien[i].name);
		printf("Nhap vao tuoi sinh vien: ");
		scanf("%d",&dsSinhVien[i].age);
		printf("Nhap vao so dien thoai: ");
		scanf("%d",&dsSinhVien[i].number);	
		printf("Nhap vao email: ");
		scanf("%s",&dsSinhVien[i].email);
	}
	printf("Danh sach sinh vien\n");
	for(int i=0;i<n;i++){
		printf("Ten sinh vien: %s\n",dsSinhVien[i].name);
		printf("Tuoi: %d\n",dsSinhVien[i].age);
		printf("So dien thoai: %d\n",dsSinhVien[i].number);
		printf("Email: %s\n",dsSinhVien[i].email);
	}
}
