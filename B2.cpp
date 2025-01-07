#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maxSize 100

void inputString(char *str);
void outputString(char *str);
void countString(char *str, int length, int choice, int *count);

int main(){
    int choice = 0, length = 0, count = 0;
    char *str = (char *)malloc(maxSize * sizeof(char));
    
    if (str == NULL) {
        printf("Khong the cap phat bo nho!\n");
        return 1;
    }

    do {
        printf("%*s=======MENU========\n", 10, "");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                inputString(str);
                length = strlen(str);
                break;
            }
            case 2: {
                if (length) {
                    outputString(str);
                }
                break;
            }
            case 3: {
                if (length) {
                    countString(str, length, choice, &count);
                    printf("So luong chu cai trong chuoi cua ban la: %d\n", count);
                }
                break;
            }
            case 4: {
                if (length) {
                    countString(str, length, choice, &count);
                    printf("So luong chu so trong chuoi cua ban la: %d\n", count);
                }
                break;
            }
            case 5: {
                if (length) {
                    countString(str, length, choice, &count);
                    printf("So luong ky tu dac biet trong chuoi cua ban la: %d\n", count);
                }
                break;
            }
            case 6: {
                printf("Ket thuc chuong trinh!\n");
                break;
            }
            default:
                printf("Lua chon cua ban khong hop le hay chon lai!\n");
        }
        if (!length && choice != 6) {
            printf("Chuoi trong hay nhap chuoi truoc khi thuc hien thao tac!\n");
        }
        printf("\n\n");
    } while (choice != 6);

    free(str);
    return 0;
}

void inputString(char *str) {
    while (getchar() != '\n');

    printf("Moi nhap vao mot chuoi bat ki: ");
    fgets(str, maxSize, stdin);
    
    str[strcspn(str, "\n")] = '\0';
}

void outputString(char *str) {
    printf("Day la chuoi ma ban da nhap vao: %s\n", str);
}

void countString(char *str, int length, int choice, int *count) {
    *count = 0;
    for (int i = 0; i < length; i++) {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')) {
            if (choice == 3) {
                ++*count;
            }
        } else if (str[i] >= '0' && str[i] <= '9') {
            if (choice == 4) {
                ++*count;
            }
        } else {
            if (choice == 5) {
                ++*count;
            }
        }
    }
}
