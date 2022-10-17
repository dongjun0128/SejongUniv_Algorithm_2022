#include<stdio.h>
#include<stdlib.h>
int H[100] = { 0 };
int n = 0;

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

// 힙 설계
void buildheap() {
	int i;
	for (i = n / 2;i > 0;i--) {
		downheap(i);
	}
}

//출력
void printheap() {
	int i;
	for (i = 1;i <= n;i++) {
		printf(" %d", H[i]);
	}
}


int main() {
	int num, i;
	scanf("%d", &num);
	for (i = 1;i <= num;i++) {
		scanf("%d", &H[i]);
	}
	n = num;
	buildheap();
	printheap();
}