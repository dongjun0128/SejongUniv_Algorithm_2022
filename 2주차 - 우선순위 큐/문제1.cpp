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

    for (int arr_num = 0; arr_num < size; arr_num++ ) {
        scanf("%d", &arr[arr_num]);
        getchar();
    }

    for (int arr_num = 0; arr_num < size; arr_num++) {
        printf("%d", arr[arr_num]);
    }

    //동적할당 해제
    free(arr);

    return 0;
}
