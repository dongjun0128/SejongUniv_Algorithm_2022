#include<stdio.h>
int heap[99] = { 0 };
int heap_sort[99] = { 0 };
int n = 0;
int size = 0;

// 자식 노드보다 내가 더 작으면 내려가는 함수
// Left_Index = Index * 2 
// Right_Index = Index * 2 + 1
void downheap(int i) {
	int tmp;
	if (heap[2 * i] > heap[2 * i + 1]) {
		if (heap[2 * i] > heap[i]) {
			tmp = heap[i * 2];
			heap[i * 2] = heap[i];
			heap[i] = tmp;
			downheap(i * 2);
		}
	}
	else {
		if (heap[2 * i + 1] > heap[i]) {
			tmp = heap[i * 2 + 1];
			heap[i * 2 + 1] = heap[i];
			heap[i] = tmp;
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

//힙 출력
void printArray() {
	int i;
	for (i = 1;i <= size;i++) {
		printf(" %d", heap_sort[i]);
	}
}

//힙 정렬
void inPlaceHeapSort() {
	int i;
	for (i = size;i > 1;i--) {
		int tmp;
		tmp = heap[1];
		heap[1] = heap[i];
		heap[i] = 0;
		heap_sort[i] = tmp;
		n--;
		downheap(1);
	}
	heap_sort[1] = heap[1];
}
int main() {
	int k, i;
	scanf("%d", &k);
	for (i = 1;i <= k;i++) {
		scanf("%d", &heap[i]);
		n++;
		size++;
	}
	rbuild(1);
	inPlaceHeapSort();
	printArray();
}