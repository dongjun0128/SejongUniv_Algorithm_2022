#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>


void insertionSort(int* arr, int size) {
    //제자리 삽입 정렬
    for (int arr_num1 = 1; arr_num1 < size; arr_num1++) {
        int arr_num2;
        // 현재 삽입될 숫자인 i번째 정수를 key 변수로 복사
        int key = arr[arr_num1];

        // key가 더 큰 값일 때까지 
        for (arr_num2 = arr_num1 - 1; arr_num2 >= 0 && arr[arr_num2] > key; arr_num2--) {
            arr[arr_num2 + 1] = arr[arr_num2];
        }

        // 자리에 삽입
        arr[arr_num2 + 1] = key;
    }
}

void selectionSort(int* arr, int size) {
    //제자리 선택 정렬
    for (int arr_num1 = 0; arr_num1 < size; arr_num1++) {
        int min = arr[arr_num1];
        int key = -1;

        // arr[arr_num1]보다 작은값이 있는지 확인
        for (int arr_num2 = arr_num1 + 1; arr_num2 < size; arr_num2++) {
            if (min > arr[arr_num2]) {
                min = arr[arr_num2];
                key = arr_num2;
            }
        }

        // arr[arr_num1] 보다 작은값이 존재하면 자리 바꾸기
        if (key != -1) {
            int temp = arr[arr_num1];
            arr[arr_num1] = arr[key];
            arr[key] = temp;
        }
    }
}

void swap(int arr[], int a, int b) {
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left], low = left + 1, high = right, temp;
    while (low <= high) {
        while (low <= right && pivot >= arr[low]) low++;
        while (high >= (left + 1) && pivot <= arr[high]) high--;
        if (low <= high) swap(arr, low, high);
    }
    swap(arr, left, high);
    return high;
}

void quickSort(int arr[], int left, int right) {
    if (left <= right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int main()
{

    int size;

    //크기가 n인 배열을 동적 할당
    scanf("%d", &size);
    getchar();

    int* arr1 = (int*)malloc(sizeof(int) * size);
    int* arr2 = (int*)malloc(sizeof(int) * size);

    //할당에 오류가 생기면 강제종료
    if (arr1 == NULL) return-1;
    if (arr2 == NULL) return-1;

    //리스트 초기화
    for (int arr_num = 0; arr_num < size; arr_num++) {
        int num = rand() % 10000;
        
        arr1[arr_num] = num;
        arr2[arr_num] = num;
    }


    //시간 측정 시작
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    insertionSort(arr1, size);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart -  start.QuadPart;
    printf("삽입정렬 시간: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));


    QueryPerformanceFrequency(&ticksPerSec);
    QueryPerformanceCounter(&start);
    selectionSort(arr1, size);
    QueryPerformanceCounter(&end);
    // 측정값으로부터 실행시간 계산
    diff.QuadPart = end.QuadPart - start.QuadPart;
    printf("선택정렬 시간: %.12f sec\n\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));



    //동적할당 해제
    free(arr2);
    free(arr1);

    return 0;
}
