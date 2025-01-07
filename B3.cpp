#include <stdio.h>
#include <string.h>
#define maxSize 100

void inputString(char *str, int *length);
void outputMirrorString(char *str, int length);
void countWords(char *str, int length, int *count);
void compareString(int length1, int length2);
void upperString(char *str, int length);
void addString(char *str1, char *str2, int *length1, int length2);

int main(){
    char str1[maxSize] = "\0", str2[maxSize] = "\0";
    int length1 = 0, length2 = 0, choice;

    do{
        printf("%*s=======MENU=======\n", 10, "");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap vao chuoi khac, so sanh do dai voi chuoi ban dau\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap vao chuoi khac va them chuoi do vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                {
                    inputString(str1, &length1);
                }
                break;
            case 2:
                {
                    if(length1){
                        outputMirrorString(str1, length1);
                    }
                }
                break;
            case 3:
                {
                    if(length1){
                        int Words = 0;
                        countWords(str1, length1, &Words);
                        printf("Chuoi co %d tu\n", Words);
                    }
                }
                break;
            case 4:
                {
                    if(length1){
                        inputString(str2, &length2);
                        compareString(length1, length2);
                    }
                }
                break;
            case 5:
                {
                    if(length1){
                        upperString(str1, length1);
                    }
                }
                break;
            case 6:
                {
                    if(length1){
                        inputString(str2, &length2);
                        addString(str1, str2, &length1, length2);
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

        if(!length1 && choice != 7){
            printf("Chuoi trong hay chuoi vao truoc khi thuc hien thao tac!\n");
        }

        printf("\n\n");
    } while(choice != 7);
}

void inputString(char *str, int *length){
    while(getchar() != '\n');
    
    printf("Nhap vao chuoi cua ban: ");
    
    fgets(str, maxSize, stdin);
    str[strcspn(str, "\n")] = '\0';
    
    *length = strlen(str);
}

void outputMirrorString(char *str, int length){
    printf("Chuoi dao nguoc cua ban la:\n");
    for(int i = length - 1; i >= 0; i--){
        printf("%c", *(str + i));
    }
    printf("\n");
}

void countWords(char *str, int length, int *count){
    *count = 0;
    for(int i = 0; i < length; i++){
        if(*(str + i) == ' ' && *(str + i + 1) != ' ' && i != length - 1 || (i == 0 && *(str + i) != ' ')) {
            ++(*count);
        }
    }
}

void compareString(int length1, int length2){
    if(length1 > length2){
        printf("Mang ban dau dai hon mang luc sau!\n");
    }
    else if(length1 < length2){
        printf("Mang ban dau ngan hon mang luc sau!\n");
    }
    else{
        printf("Hai mang bang nhau!\n");
    }
}

void upperString(char *str, int length){
    for(int i = 0; i < length; i++){
        if(*(str + i) >= 'a' && *(str + i) <= 'z'){
            *(str + i) -= 32;
        }
    }
    printf("Cac ki tu trong chuoi da duoc in hoa!\n");
}

void addString(char *str1, char *str2, int *length1, int length2){
    for(int i = 0; i < length2; i++){
        *(str1 + (*length1)++) = *(str2 + i);
    }
    printf("Da them chuoi 2 vao chuoi 1 xong!\n");
}
