#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct SinhVien{
	char id[50];
	char name[50];
	int age;
};
struct SinhVien sv[100];
int numberstudent=0;

void saveStudent(){
	FILE *file;
	file = fopen("student.bin","wb");
	fwrite(sv,sizeof(struct SinhVien), 1, file);
	fclose(file);
}
void printstudent(){
	if(numberstudent==0){
		printf("\ndanh sach sinh vien trong!\n");
		return;
	}else{
		for(int i=0;i<numberstudent-1;i++){
			printf("\nthong tin sinh vien thu %d", i+1);
			printf("\nid : %s",sv[i].id);
			printf("\nname : %s",sv[i].name);
			printf("\nage : %d",sv[i].age);
			
		}
	}
}

void fixinfor(){
	struct SinhVien sv1;
	fflush(stdin);
	printf("\nnhap id : ");
	fgets(sv1.id,sizeof(sv1.id),stdin);
	sv1.id[strcspn(sv1.id,"\n")]=' ';
	fflush(stdin);
	printf("\nnhap ten hoc sinh : ");
	fgets(sv1.name,sizeof(sv1.name),stdin);
	sv1.name[strcspn(sv1.name,"\n")]=' ';
	printf("\nnhap tuoi : ");
	scanf("%d", &sv1.age);
	sv[numberstudent-2] = sv1;
	saveStudent();
}

void loadFileSinhvien(){
	FILE *file;
	file=fopen("Student.bin","rb");
	if(file==NULL){
		printf("loi khong mo duoc file !\n");
		return;
	}
	numberstudent = fread(&sv,sizeof(struct SinhVien),100,file);
	//dong file
	fclose(file);
}

void addstudent(){
	if(numberstudent>=100){
		printf("danh sach day !");
		return;
	}
	struct SinhVien sv1;
	fflush(stdin);
	printf("\nnhap id : ");
	fgets(sv1.id,sizeof(sv1.id),stdin);
	sv1.id[strcspn(sv1.id,"\n")]=' ';
	fflush(stdin);
	printf("\nnhap ten hoc sinh : ");
	fgets(sv1.name,sizeof(sv1.name),stdin);
	sv1.name[strcspn(sv1.name,"\n")]=' ';
	printf("\nnhap tuoi : ");
	scanf("%d", &sv1.age);
	sv[numberstudent-1] = sv1;
	numberstudent++;
	saveStudent();
}

void deletestudent(){
	int xpos;
	char x[50];
	fflush(stdin);
	printf("nhap ten hoc sinh ban muon xoa : ");
	gets(x);
	for(int i=0;i<numberstudent-1;i++){
		if(strcmp(sv[i].name,x)==0){
			xpos=i;
		}else{
			printf("khong co hoc sinh nay !");
			return;
		}
	}
	for(int i=xpos;i<numberstudent;i++){
		strcpy(sv[i].name,sv[i+1].name);
		strcpy(sv[i].id,sv[i+1].id);
		sv[i].age=sv[i+1].age;
	}
	for(int i=0;i<numberstudent-2;i++){
			printf("\nthong tin sinh vien thu %d", i+1);
			printf("\nid : %s",sv[i].id);
			printf("\nname : %s",sv[i].name);
			printf("\nage : %d",sv[i].age);
			
	}
}

void find(){
	int xpos;
	char x[50];
	fflush(stdin);
	printf("nhap ten hoc sinh ban muon tim : ");
	gets(x);
	for(int i=0;i<numberstudent-1;i++){
		if(strcmp(sv[i].name,x)==0){
			xpos=i;
		}
	}
	if(xpos){
		printf("tim thay %s o vi tri %d", x,xpos);
	}
	
}

int max(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}


void arrange(){
	for(int i=0;i<numberstudent-2;i++){
		int minpos=i;
		for(int j=i+1;j<=numberstudent-1;j++){
			if(sv[minpos].age<sv[j].age){
				minpos=j;
			}
		}
		if(minpos!=i){
			int temp=sv[i].age;
			sv[i].age=sv[minpos].age;
			sv[minpos].age=temp;
		}		
	}	
		for(int i=0;i<numberstudent-1;i++){
			printf("\nthong tin sinh vien thu %d", i+1);
			printf("\nid : %s",sv[i].id);
			printf("\nname : %s",sv[i].name);
			printf("\nage : %d",sv[i].age);
			
		}
}

int main(){
	int numberstudent=0;
	int choose;
	loadFileSinhvien();
	do{
		printf("\nMENU\n");
		printf("1 : in danh sach sinh vien\n");
		printf("2 : them sinh vien\n");
		printf("3 : sua thong tin sinh vien\n");
		printf("4 : xoa sinh vien\n");
		printf("5 : tim kiem sinh vien\n");
		printf("6 : sap xep danh sach sinh vien\n");
		printf("7 : thoat\n");
		printf("\nnhap lua chon cua ban : ");
		scanf("%d", &choose);
		switch(choose){
			case 1:
				printstudent();
			break;
			case 2:	
				addstudent();
			break;
			case 3:
				fixinfor();
			break;
			case 4:
				deletestudent();
			break;
			case 5:
				find();
			break;
			case 6:
				arrange();	
			break;
		}
	}while(choose!=7);
	exit(0);	
	return 0;
}
//trien khai ham
