#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int H[99] = { 0 };
int heap_sort[99] = { 0 };
int n = 0;
int size = 0;

// 자식 노드보다 내가 더 작으면 내려가는 함수
// Left_Index = Index * 2 
// Right_Index = Index * 2 + 1
void downheap(int i) {
	int tmp;

	if (H[2 * i] > H[2 * i + 1]) {
		if (H[2 * i] > H[i]) {
			tmp = H[i * 2];
			H[i * 2] = H[i];
			H[i] = tmp;
			downheap(i * 2);
		}
	}
	else {
		if (H[2 * i + 1] > H[i]) {
			tmp = H[i * 2 + 1];
			H[i * 2 + 1] = H[i];
			H[i] = tmp;
			downheap(i * 2 + 1);
		}
	}
}

//힙 설계
void rbuild(int i) {
	if (i > n) {
		return;
	}
	rbuild(2 * i);
	rbuild(2 * i + 1);
	downheap(i);
	return;
}

//제자리 힙 정렬
void inPlaceHeapSort() {
	int i;
	for (i = size;i > 1;i--) {
		int tmp;
		tmp = H[1];
		H[1] = H[i];
		H[i] = 0;
		heap_sort[i] = tmp;
		n--;
		downheap(1);
	}
	heap_sort[1] = H[1];
}

//힙 출력
void printArray() {
	int i;
	for (i = 1;i <= size;i++) {
		printf(" %d", heap_sort[i]);
	}
}


int main() {
	int k, i;
	scanf("%d", &k);
	for (i = 1;i <= k;i++) {
		scanf("%d", &H[i]);
		n++;
		size++;
	}
	rbuild(1);
	inPlaceHeapSort();
	printArray();
}