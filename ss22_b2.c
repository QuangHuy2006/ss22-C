#include <stdio.h>
#include <stdlib.h>
struct regis{
	char username[50];
	char password[50];
};
struct regis acc[50];
struct login{
	char usernamelogin[50];
	char passwordlogin[50];
};
struct login log[50];
void saveacc(){
	FILE *file;
	file = fopen("Student1.bin","wb");
	fwrite(acc,sizeof(struct regis), 2, file);
	fclose(file);
}

void registered(){
	struct regis acc1;
	fflush(stdin);
	printf("username : ");
	fgets(acc1.username,sizeof(acc1.username),stdin); 
	fflush(stdin);
	printf("password : ");
	fgets(acc1.password,sizeof(acc1.password),stdin); 
	saveacc();
}

void login(){
	int cnt;
	struct login log1;
	struct regis acc1;
	fflush(stdin);
	printf("username : ");
	fgets(log1.usernamelogin,sizeof(log1.usernamelogin),stdin); 
	if(strcmp(log1.usernamelogin,acc1.username)==0){
		cnt++;
	}
	fflush(stdin);
	printf("password : ");
	fgets(log1.passwordlogin,sizeof(log1.passwordlogin),stdin); 
	if(strcmp(log1.passwordlogin,acc1.password)==0){
		cnt++;
	}
	if(cnt%2==0){
		printf("thong tin dung !");
	}
}
int main(){
	int choice;
	do{
	printf("\nMenu\n");
	printf("1 : Dang nhap\n");
	printf("2 : Dang ky\n");
	printf("\nnhap lua chon cua ban : ");
	scanf("%d", &choice);
	if(choice==1){
		login();
	}
	if(choice==2){
		registered();
	}
	}while(choice!=3);
	exit(0);
}