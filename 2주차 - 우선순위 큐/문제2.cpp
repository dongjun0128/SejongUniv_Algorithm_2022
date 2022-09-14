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

    //제자리 삽입 정렬
    for (int arr_num1 = 1; arr_num1 < size; arr_num1++) {
        int arr_num2;
        // 현재 삽입 될 숫자인 arr_num1의 정수를 key로 복사
        int key = arr[arr_num1];

        // key가 더 큰 값일 때 까지 자리 옮기기
        for (arr_num2 = arr_num1 - 1; arr_num2 >= 0 && arr[arr_num2] > key; arr_num2--) {
            arr[arr_num2 + 1] = arr[arr_num2];
        }

        // 자리에 삽입
        arr[arr_num2 + 1] = key;
    }


    for (int arr_num = 0; arr_num < size; arr_num++) {
        printf(" %d", arr[arr_num]);
    }

    //동적할당 해제
    free(arr);

    return 0;
}
