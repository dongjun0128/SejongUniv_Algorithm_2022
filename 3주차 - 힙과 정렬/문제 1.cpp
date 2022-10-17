#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 저장할 힙
int H[100];
int n = 0;



// 부모 힙 보다 크면 위로 보내는 함수
void upheap(int i) {
    int tmp;
    if (H[i] > H[i / 2]) {
        tmp = H[i];
        H[i] = H[i / 2];
        H[i / 2] = tmp;
        if (i / 2 != 1) {
            upheap(i / 2);
        }
    }
}

// 자식 노드보다 내가 더 작으면 내려가는 함수
// Left_Index = Index * 2 
// Right_Index = Index * 2 + 1
void downheap(int i) {
    int tmp;
    if (H[2 * i] > H[2 * i + 1]) {
        if (H[i] < H[2 * i]) {
            tmp = H[2 * i];
            H[2 * i] = H[i];
            H[i] = tmp;
            downheap(2 * i);
        }
    }
    else if (H[2 * i] < H[2 * i + 1]) {
        if (H[i] < H[2 * i + 1]) {
            tmp = H[2 * i + 1];
            H[2 * i + 1] = H[i];
            H[i] = tmp;
            downheap(2 * i + 1);
        }
    }
}

//삽입
int insertItem(int key) {
    if (n == 0) {
        n = n + 1;
        H[n] = key;
        return 0;
    }
    else if (n<100) {
        n = n + 1;
        H[n] = key;
        upheap(n);
        return 0;
    }

    else {
        return -1;
    }
    
}

// 삭제
int removeMax() {
    int k = H[1];
    H[1] = H[n];
    H[n] = 0;
    n--;
    downheap(1);
    return k;

    return 0;
}

//출력
void printHeap() {
    for (int i = 1;i <= n;i++) {
        printf(" %d", H[i]);
    }

}



int main()
{
    char command = NULL;

    while (command != 'q') {
        scanf("%c", &command);
        getchar();

        if (command == 'i') {
            int key;
            scanf("%d", &key);
            getchar();

            printf("%d", insertItem(key));
            printf("\n");
        }

        else if (command == 'd') {
            if (n != 0) {
                printf("%d\n", removeMax());
            }

            else {
                printf("지울 수 있는 heap이 없습니다!");
            }
        }

        else if (command == 'p') {
            printHeap();
            printf("\n");
        }
    }

    return 0;
}
