#include <stdio.h>
#define maxSize 100

void inputArray(int *arr, int *size);
void findEven(int *arr, int size);
int isPrime(int n);
void findPrimes(int *arr, int size);
void flipArray(int *arr, int size);
void sortArray(int *arr, int size, int sortMNC);
int findArray(int *arr, int size, int findNum);

int main(){
    int arr[maxSize] = {0}, size = 0, choice;

    do{
        printf("%*s========MENU=======\n", 10, "");
        printf("1. Nhap vao so phan tu va tung phan tu\n");
        printf("2. In ra cac phan tu la so chan\n");
        printf("3. In ra cac phan tu la so nguyen to\n");
        printf("4. Dao nguoc mang\n");
        printf("5. Menu sap xep mang\n");
        printf("6. Tim kiem phan tu trong mang\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                {
                    inputArray(arr, &size);
                }
                break;
            case 2:
                {
                    if(size){
                        findEven(arr, size);
                    }
                }
                break;
            case 3:
                {
                    if(size){
                        findPrimes(arr, size);
                    }
                }
                break;
            case 4:
                {
                    if(size){
                        flipArray(arr, size);
                    }
                }
                break;
            case 5:
                {
                    if(size){
                        int menuChoice = 0;
                        printf("1. Tang dan\n");
                        printf("2. Giam dan\n");
                        printf("Lua chon cua ban: ");
                        scanf("%d", &menuChoice);
                        if(menuChoice == 1 || menuChoice == 2){
                            sortArray(arr, size, menuChoice);
                        }
                    }
                }
                break;
            case 6:
                {
                    if(size){
                        int findNum;
                        printf("Nhap vao gia tri can tim kiem trong mang: ");
                        scanf("%d", &findNum);
                        if(findArray(arr, size, findNum)){
                            printf("Gia tri ban tim co trong mang!\n");
                        } else {
                            printf("Gia tri ban tim khong co trong mang!\n");
                        }
                    }
                }
                break;
            case 7:
                {
                    printf("Ket thuc chuong trinh!\n");
                }
                break;
            default:
                printf("Lua chon khong hop le hay nhap lai!\n");
        }

        if(!size && choice != 7){
            printf("Mang trong hay nhap mang truoc khi thuc hien thao tac!\n");
        }

        printf("\n\n");
    } while(choice != 7);
}

void inputArray(int *arr, int *size){
    printf("Nhap vao so phan tu ban muon nhap: ");
    scanf("%d", size);
    
    while(*size < 1 || *size > 100){
        printf("So phan tu khong hop le hay nhap lai: ");
        scanf("%d", size);
    }
    
    for(int i = 0; i < *size; i++){
        printf("Array[%d]: ", i);
        scanf("%d", arr + i);
    }
}

void findEven(int *arr, int size){
    printf("Tat ca cac so chan trong mang: ");
    for(int i = 0; i < size; i++){
        if(*(arr + i) % 2 == 0){
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

int isPrime(int n){
    if(n < 2) return 0;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

void findPrimes(int *arr, int size){
    printf("Tat ca so nguyen to co trong mang: ");
    for(int i = 0; i < size; i++){
        if(isPrime(*(arr + i))){
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}

void flipArray(int *arr, int size){
    for(int i = 0; i < size / 2; i++){
        int tmp = *(arr + i);
        *(arr + i) = *(arr + size - i - 1);
        *(arr + size - i - 1) = tmp;
    }
}

void sortArray(int *arr, int size, int sortMNC){
    for(int i = 1; i < size; i++){
        int Index = i - 1, Value = *(arr + i);
        while(Index >= 0 && (sortMNC == 1 ? *(arr + Index) < Value : *(arr + Index) > Value)){
            *(arr + Index + 1) = *(arr + Index);
            Index--;
        }
        *(arr + Index + 1) = Value;
    }
}

int findArray(int *arr, int size, int findNum){
    for(int i = 0; i < size; i++){
        if(*(arr + i) == findNum) return 1;
    }
    return 0;
}
