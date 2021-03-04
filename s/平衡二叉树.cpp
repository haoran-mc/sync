#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
struct Node {
    int data;
    int height;
    Node* left;
    Node* right;
};
struct Tree {
    Node* root;
};
#define bug printf("<------>\n");

/*得到当前结点的高度*/
int getHeight(Node* node) {
    bug
        cout >> bool(node->left);
    if (node -> left) {
        bug
    }
    bug
    return 1;
    // return node ? max(getHeight(node -> left), getHeight(node -> right)) + 1 : 0;
}

/*得到结点的平衡因子*/
int balanceFactor(Node* node) {
    int R = 0;
    int L = 0;
    if (node -> left)
        L = node->left->height;
    if (node -> right)
        R = node->right->height;

    return node ? L - R : 0;
}


/*
 *     4           4          2
 *    / \          |\        / \
 *   2   5       2 | 5      1   4
 *  / \         / \|           / \
 * 1   3       1   3          3   5
 */

/*右旋操作*/
Node* rotateRight(Node* node) {
    Node* left  = node -> left;
    Node* right = node -> right;

    node->left  = left->right;
    left->right = node;

    left->height  = max(getHeight(left->left), getHeight(left->right)) + 1;
    right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

    return left;
}


/*
 *   2          2            4
 *  / \        /|           / \
 * 1   4      1 | 4        2   5
 *    / \       |/ \      / \
 *   3   5      3   5    1   4
 */

/*左旋操作*/
Node* rotateLeft(Node* node) {
    Node* left  = node->left;
    Node* right = node->right;

    node->right = right->left;
    right->left = node;

    left->height  = max(getHeight(left->left), getHeight(left->right)) + 1;
    right->height = max(getHeight(right->left), getHeight(right->right)) + 1;

    return right;
}

/*平衡化操作*/
Node* rebalance(Node* &node) {
    while (balanceFactor(node) > 1 && balanceFactor(node -> left) <= 1 && balanceFactor(node -> right) <= 1) {
        if (balanceFactor(node -> left) > 1)
            node = node -> left;
        if (balanceFactor(node -> right) > 1)
            node = node -> right;
    }
    int factor = balanceFactor(node);
    if (factor > 1 && balanceFactor(node->left) > 0)           // LL
        return rotateRight(node);
    else if (factor < -1 && balanceFactor(node->right) <= 0)   // RR
        return rotateLeft(node);
    else if (factor >  1 && balanceFactor(node->left) <= 0) {  // LR
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    else if (factor < -1 && balanceFactor(node->right) > 0) {  // RL
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    else  // Nothing happened.
        return node;
}

/*使用了递归，二叉搜索树那里使用的是迭代，结果相同，只是这里使用了rebalance进行平衡化*/
void treeInsert(Node* &root, int value) {
    root -> height = getHeight(root);
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        root = newNode;
    }
    else if (root->data == value)
        return;
    else {
        if (root->data < value)
            treeInsert(root->right, value);
        else
            treeInsert(root->left, value);
    }
    rebalance(root);
}

/*删除操作很难，这部分代码错误*/
/*如果当前结点需要删除，而它又有两个子结点，那么就无法删除当前结点*/
void treeDelete(Node* root, int value) {
    Node* toFree;
    if (root) {
        if (root->data == value) {
            if (root->right)
                treeDelete(root->right, value);
            else {
                toFree = root;
                root = toFree->left;
                free(toFree);
            }
        }
        else {
            if(root->data < value)
                treeDelete(root->right, value);
            else
                treeDelete(root->left, value);
        }
        rebalance(root);
    }
}

void preorder(Node* node) {
    if (node != NULL) {
        printf("%d ", /* node.data */ node -> data);
        printf("%d\n", /* node.data */ node -> height);
        preorder(node -> left );
        preorder(node -> right);
    }
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node -> left );
        printf("%d ", node -> data);
        inorder(node -> right);
    }
}

void postorder(Node* node) {
    if (node != NULL) {
        postorder(node -> left );
        postorder(node -> right);
        printf("%d ", node -> data);
    }
}

int main() {
    Tree tree;
    tree.root = NULL;
    int arr[] = {8, 3, 5, 1, 0, 2, 9, 4, 7, 6};
    for (int i = 0; i < 10; ++i)
        treeInsert(tree.root, arr[i]);
    preorder(tree.root);  printf("\n");
    // inorder(tree.root);   printf("\n");
    // postorder(tree.root); printf("\n");
    return 0;
}
