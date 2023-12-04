#include<stdio.h>
struct sinhVien {
	char name[50];
	int age;
	int number;
	char email[100];
};
void nhap_thong_tin(int size){
	struct sinhVien dsSinhVien[size];
	for(int i=0;i<size;i++){
		printf("Nhap vao ten sinh vien: ");
		scanf("%s",&dsSinhVien[i].name);
		printf("Nhap vao tuoi sinh vien: ");
		scanf("%d",&dsSinhVien[i].age);
		printf("Nhap vao so dien thoai: ");
		scanf("%d",&dsSinhVien[i].number);
		printf("Nhap vao email: ");
		scanf("%s",&dsSinhVien[i].email);
	}
}
void in_thong_tin(int size){
	struct sinhVien dsSinhVien[size];
	printf("Danh sach sinh vien\n");
	for(int i=0;i<size;i++){
		printf("Ten sinh vien: %s\n",dsSinhVien[i].name);
		printf("Tuoi: %d\n",dsSinhVien[i].age);
		printf("So dien thoai: %d\n",dsSinhVien[i].number);
		printf("Email: %s\n",dsSinhVien[i].email);
	}
}
int main(){
	int n;
	printf("Nhap vao so sinh vien: ");
	scanf("%d",&n);
	getchar();
	nhap_thong_tin(n);
	in_thong_tin(n);
}
