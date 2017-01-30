/**
 *  437. Path Sum III
 *
 *  You are given a binary tree in which each node contains an integer value.
 *
 *  Find the number of paths that sum to a given value.
 *
 *  The path does not need to start or end at the root or a leaf, but it must go
 *  downwards (traveling only from parent nodes to child nodes).
 *
 *  The tree has no more than 1,000 nodes and the values are in the range
 *  -1,000,000 to 1,000,000.
 *
 *  Example:
 *
 *  root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
 *
 *         10
 *        /  \
 *       5   -3
 *      / \    \
 *     3   2   11
 *    / \   \
 *   3  -2   1
 *
 *  Return 3. The paths that sum to 8 are:
 *
 *  1.  5 -> 3
 *  2.  5 -> 2 -> 1
 *  3. -3 -> 11
 */

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int pathSum(struct TreeNode *root, int sum);
void init_treenode(struct TreeNode *root);
void print_treenode(struct TreeNode *node);
int visit_treenode(struct TreeNode *node, int s, int sum);

int
main(int argc, const char *argv[])
{
    int n = 8;
    struct TreeNode *root = NULL;

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    init_treenode(root);
    print_treenode(root);
    fputs("\n", stdout);
    printf("%d\n", pathSum(root, n));

    return 0;
}

void
init_treenode(struct TreeNode *root)
{
    root->val = 10;
    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 5;
    root->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->left->val = 3;
    root->left->left->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->left->left->val = 3;
    root->left->left->left->left = NULL;
    root->left->left->left->right = NULL;
    root->left->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->left->right->val = -2;
    root->left->left->right->left = NULL;
    root->left->left->right->right = NULL;
    root->left->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->right->val = 2;
    root->left->right->left = NULL;
    root->left->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->right->right->val = 1;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = -3;
    root->right->left = NULL;
    root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->right->val = 11;
    root->right->right->left = NULL;
    root->right->right->right = NULL;
}

void
print_treenode(struct TreeNode *node)
{
    if (node == NULL) return;

    // Pre-order traversal
    printf("%d ", node->val);
    if (node->left != NULL) print_treenode(node->left);
    if (node->right != NULL) print_treenode(node->right);
}

/* === solution === */

int
pathSum(struct TreeNode *root, int sum)
{
    int s, count;
    s = count = 0;

    if (root == NULL) return 0;
    count += visit_treenode(root, s, sum);

    return count;
}

int
visit_treenode(struct TreeNode *node, int s, int sum)
{
    if (s + node->val == sum) return 1;
    else if (s + node->val > sum) return 0;
    else {
        if (node->left != NULL)
            return visit_treenode(node->left, s + node->val, sum);
        if (node->right != NULL)
            return visit_treenode(node->right, s + node->val, sum);
        return 0;
    }
}

/* === EOS === */
