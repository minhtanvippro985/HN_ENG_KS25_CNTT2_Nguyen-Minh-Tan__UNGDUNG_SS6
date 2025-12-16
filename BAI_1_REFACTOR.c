#include <stdio.h>
#include <math.h>

#define MAX 100

// -------- Function Prototypes ----------
void inputArray(int a[], int *n);
void printArray(int a[], int n);
int sumArray(int a[], int n);
void deleteAt(int a[], int *n);
void insertAt(int a[], int *n);
void reverseArray(int a[], int n);
void bubbleSort(int a[], int n);
void linearSearch(int a[], int n);
int isPrime(int x);
void printPrimes(int a[], int n);
void menu();

// -------- Main ----------
int main() {
    int arr[MAX];
    int size;
    int choice;

    inputArray(arr, &size);

    do {
        menu();
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Tong cac phan tu = %d\n", sumArray(arr, size));
                break;

            case 2:
                printf("Dang thoat chuong trinh...\n");
                break;

            case 3:
                deleteAt(arr, &size);
                printArray(arr, size);
                break;

            case 4:
                insertAt(arr, &size);
                printArray(arr, size);
                break;

            case 5:
                reverseArray(arr, size);
                printArray(arr, size);
                break;

            case 6:
                bubbleSort(arr, size);
                printArray(arr, size);
                break;

            case 7:
                linearSearch(arr, size);
                break;

            case 8:
                printPrimes(arr, size);
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 2);

    return 0;
}

// -------- Functions ----------

void menu() {
    printf("\n-------- MENU --------\n");
    printf("1. Tong cac so trong mang\n");
    printf("2. Thoat chuong trinh\n");
    printf("3. Xoa phan tu\n");
    printf("4. Them phan tu\n");
    printf("5. Dao nguoc mang\n");
    printf("6. Sap xep bubble sort\n");
    printf("7. Linear search\n");
    printf("8. In cac so nguyen to\n");
}

void inputArray(int a[], int *n) {
    printf("Nhap size mang: ");
    scanf("%d", n);

    for (int i = 0; i < *n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}

void printArray(int a[], int n) {
    printf("Mang: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int sumArray(int a[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum;
}

void deleteAt(int a[], int *n) {
    int pos;
    printf("Nhap vi tri can xoa (0 -> %d): ", *n - 1);
    scanf("%d", &pos);

    if (pos < 0 || pos >= *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        a[i] = a[i + 1];
    }
    (*n)--;
}

void insertAt(int a[], int *n) {
    int pos, value;
    printf("Nhap vi tri can chen (0 -> %d): ", *n);
    scanf("%d", &pos);

    if (pos < 0 || pos > *n) {
        printf("Vi tri khong hop le!\n");
        return;
    }

    printf("Nhap gia tri can chen: ");
    scanf("%d", &value);

    for (int i = *n; i > pos; i--) {
        a[i] = a[i - 1];
    }
    a[pos] = value;
    (*n)++;
}

void reverseArray(int a[], int n) {
    int i = 0, j = n - 1, temp;
    while (i < j) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}

void bubbleSort(int a[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void linearSearch(int a[], int n) {
    int x, found = 0;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            printf("Tim thay %d tai vi tri %d\n", x, i);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay!\n");
    }
}

int isPrime(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0)
            return 0;
    }
    return 1;
}

void printPrimes(int a[], int n) {
    printf("Cac so nguyen to: ");
    for (int i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            printf("%d ", a[i]);
        }
    }
    printf("\n");
}
