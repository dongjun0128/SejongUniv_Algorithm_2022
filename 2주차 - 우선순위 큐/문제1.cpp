#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main()
{

    int size;

    //크기가 n인 배열을 동적 할당
    scanf("%d", &size);
    getchar();

    int* arr = (int*)malloc(sizeof(int) * size);

    //할당에 오류가 생기면 강제종료
    if (arr == NULL) return-1;

    //입력값 저장
    for (int arr_num = 0; arr_num < size; arr_num++) {
        scanf("%d", &arr[arr_num]);
        getchar();
    }

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


    for (int arr_num = 0; arr_num < size; arr_num++) {
        printf(" %d", arr[arr_num]);
    }

    //동적할당 해제
    free(arr);

    return 0;
}
