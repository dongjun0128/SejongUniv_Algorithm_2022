#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
	struct node* prev;
	char ch;
	struct node* next;

}Node;

void add_fuc(Node* header, Node* trailer, int r, char temp_ch) {
	Node* temp_node = (Node*)malloc(sizeof(Node));
	Node* p = header;

	r--;
	while (r--) {
		p = p->next;
		if (p == trailer) {
			printf("invalid position\n");
			return;
		}
	}

	temp_node->ch = temp_ch;

	temp_node->prev = p;
	temp_node->next = p->next;
	p->next->prev = temp_node;
	p->next = temp_node;

}

void delete_fuc(Node* header, Node* trailer, int r) {
	Node* p = header;

	while (r--) {
		p = p->next;
		if (p == trailer) {
			printf("invalid position\n");
			return;
		}
	}

	p->prev->next = p->next;
	p->next->prev = p->prev;
	free(p);
}

void print(Node* header) {

	for (Node* p = header->next;p->next != NULL;p = p->next) {
		printf("%c", p->ch);
	}
	printf("\n");
}

char get_fuc(Node* header, Node* trailer, int r) {
	Node* p = header;
	while (r--) {
		if (p->next == trailer) {
			printf("invalid position\n");
			return '\0';
		}
		p = p->next;
	}
	return p->ch;
}

void free_node(Node* header) {
	Node* p = header;

	while (p != NULL) {
		Node* temp_node = p;
		p = p->next;
		free(temp_node);
	}

}

int main()
{
	Node* header, * trailer;
	int N;
	char call_fuc;
	int order;
	char temp_ch;

	header = (Node*)malloc(sizeof(Node));
	trailer = (Node*)malloc(sizeof(Node));

	header->next = trailer;
	header->prev = NULL;
	trailer->prev = header;
	trailer->next = NULL;

	scanf("%d", &N);
	getchar();

	while (N--) {
		scanf("%c", &call_fuc);

		getchar();
		if (call_fuc == 'P') {
			print(header);
		}

		else if (call_fuc == 'G') {
			scanf("%d", &order);
			getchar();
			temp_ch = get_fuc(header, trailer, order);
			if (temp_ch != '\0')
				printf("%c", temp_ch);
		}

		else if (call_fuc == 'D') {
			scanf("%d", &order);
			getchar();
			delete_fuc(header, trailer, order);
		}

		else {
			scanf("%d %c", &order, &temp_ch);
			add_fuc(header, trailer, order, temp_ch);
			getchar();
		}
	}

	free_node(header);
	return 0;
}