#include <stdio.h>
#define maxSize 100

void inputArray(int arr[],int *size);
void outputArray(int arr[],int size);
void sumArray(int arr[],int size,int *sum);
void findMax(int arr[],int size,int *max);

int main(){
	int choice,arr[maxSize]={0},size=0;
	do{
		printf("%*s======MENU=======\n",10,"");
		printf("1.Nhap vao so phan tu va tung phan tu\n");
		printf("2.Hien thi cac phan tu trong mang\n");
		printf("3.Tinh do dai mang\n");
		printf("4.Tinh tong cac phan tu trong mang\n");
		printf("5.Hien thi phan tu lon nhat\n");
		printf("6.Thoat\n");
		printf("Lua chon cua ban: ");	
		scanf("%d",&choice);
		switch(choice){
			case 1:
				{
					inputArray(arr,&size);
				}
				break;
			case 2:
				{
					if(size){
						outputArray(arr,size);
					}
				}
				break;
			case 3:
				{
					if(size){
						printf("Chieu dai cua mang la: %d",size);
					}
				}
				break;
			case 4:
				{
					if(size){
						int sum=0;
						sumArray(arr,size,&sum);
						printf("Tong cua tat ca cac phan tu trong mang la: %d",sum);
					}
				}
				break;
			case 5:
				{
					if(size){
						int max=arr[0];
						findMax(arr,size,&max);
						printf("Phan tu lon nhat trong mang la: %d",max);
					}
				}
				break;
			case 6:
				{
					printf("Ket thuc chuong trinh!");
				}
				break;
			default:
				printf("Lua chon khong hop le!");
		}
		if(!size && choice != 6){
			printf("Mang trong vui long nhap mang truoc khi thao tac!");
		}
		printf("\n\n");
	}while(choice !=6);
}

void inputArray(int arr[],int *size){
	printf("Nhap vao chieu dai cua mang: ");	
	scanf("%d",size);
	while(*size < 1 || *size >= maxSize){
		printf("Chieu dai mang nhap vao khong hop le hay nhap lai: ");	
		scanf("%d",size);
	}
	
	for(int i=0;i<*size;i++){
		printf("Array[%d]: ",i);
		scanf("%d",arr+i);
	}
}

void outputArray(int arr[],int size){
	printf("Mang cua ban:\n");
	for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}

void sumArray(int arr[],int size,int *sum){
	for(int i=0;i<size;i++){
		*sum+=*(arr+i);
	}
}

void findMax(int arr[],int size,int *max){
	for(int i=1;i<size;i++){
		if(*max < *(arr+i))	
			*max=*(arr+i);
	}
}

