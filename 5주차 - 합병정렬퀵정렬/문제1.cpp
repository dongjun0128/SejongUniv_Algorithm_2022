#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int M[100] = { 0 };

void mergeSort(int* p, int l, int r);
void merge(int* p, int l, int m, int r);

int main() {
	int n, i;
	scanf("%d", &n);
	//동적 할당
	int* p = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++) {
		scanf("%d", &p[i]);
	}
	mergeSort(p, 0, n - 1);
	for (i = 0;i < n;i++) {
		printf(" %d", p[i]);
	}

	//해제
	free(p);
}

//합병
void merge(int* p, int l, int m, int r) {
	int i = l, k = l;
	int j = m + 1;
	while (i <= m && j <= r) {
		if (p[i] <= p[j]) {
			M[k++] = p[i++];
		}
		else {
			M[k++] = p[j++];
		}
	}
	while (i <= m) {
		M[k++] = p[i++];
	}
	while (j <= r) {
		M[k++] = p[j++];
	}
	for (k = l;k <= r;k++) {
		p[k] = M[k];
	}
}

//합병 정렬
void mergeSort(int* p, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(p, l, m);
		mergeSort(p, m + 1, r);
		merge(p, l, m, r);
	}
}

