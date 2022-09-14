#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node {
    struct node* left;
    int data;
    struct node* right;
}Node;

Node* get_node(int e) {
    Node* p;
    p = (Node*)malloc(sizeof(Node));
    p->left = NULL;
    p->right = NULL;
    p->data = e;

    return p;
}

Node* find_node(Node* root, int e) {
    if (root == NULL) return NULL;

    if (root->data == e) return root;

    Node* L = NULL, * R = NULL;

    L = find_node(root->left, e);
    if (L != NULL) return L;
    R = find_node(root->right, e);
    return R;
}

void pre_order(Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    pre_order(root->left);
    pre_order(root->right);
}

void make_tree(Node* root, int x, int y, int z) {
    if (y != 0) {
        root->left = get_node(y);
    }

    if (z != 0) {
        root->right = get_node(z);
    }
}

void print_Node(Node* root, char str[]) {
    Node* p = root;
    printf(" %d", p->data);

    for (int i = 0;i < strlen(str);i++) {
        if (str[i] == 'R') {
            p = p->right;
            printf(" %d", p->data);
        }

        if (str[i] == 'L') {
            p = p->left;
            printf(" %d", p->data);
        }
    }
    printf("\n");
}

int main()
{
    int n;
    Node* root = NULL;

    scanf("%d", &n);

    while (n--) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        if (root == NULL) {
            root = get_node(x);
            root->left = get_node(y);
            root->right = get_node(z);
        }

        else {
            Node* p = find_node(root, x);
            make_tree(p, x, y, z);
        }

    }

    scanf("%d", &n);
    getchar();
    while (n--) {
        char str[101];
        scanf("%s", str);
        getchar();

        print_Node(root, str);
    }


    return 0;
}
