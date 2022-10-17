#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

//제자리 퀵 정렬
void inPlaceQuickSort(int* p, int l, int r) {
	if (l >= r) {
		return;
	}
	int pivot = r;
	int i = l;
	int j = r - 1;
	int tmp;
	while (i <= j) {
		while (i <= j && p[i] <= p[pivot]) { i++; }
		while (j >= i && p[j] >= p[pivot]) { j--; }
		if (i > j) {
			tmp = p[pivot];
			p[pivot] = p[i];
			p[i] = tmp;
		}
		else {
			tmp = p[i];
			p[i] = p[j];
			p[j] = tmp;
		}
	}
	inPlaceQuickSort(p, l, i - 1);
	inPlaceQuickSort(p, i + 1, r);
}

int main() {
	int n, i;
	scanf("%d", &n);
	//동적할당
	int* p = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++) {
		scanf("%d", &p[i]);
	}
	inPlaceQuickSort(p, 0, n - 1);
	for (i = 0;i < n;i++) {
		printf(" %d", p[i]);
	}

	//해제
	free(p);
}