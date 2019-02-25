/// Source : https://leetcode.com/problems/validate-binary-search-tree/description/
/// Author : Bin Zhao
/// Time   : 2019-02-21
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>


struct TreeNode;
typedef struct TreeNode TreeNode;

/// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};




bool hasPathSum(TreeNode* root, int sum) {
    if(!root) return false;    
    if (root->val == sum && root->left == NULL && root->right == NULL) return true;    
    return  hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val); 
}

TreeNode* createTree(int a[], int n)
{
    if (n<=0) return NULL;

	TreeNode **tree = (TreeNode **)malloc(n*sizeof(TreeNode*));

    for(int i=0; i<n; i++) {
        if (a[i]==0 ){
            tree[i] = NULL;
            continue;
        }
        tree[i] = (TreeNode*)malloc(sizeof(TreeNode));
		tree[i]->val = a[i];
		tree[i]->left = NULL;
		tree[i]->right = NULL;
    }
    int pos=1;
    for(int i=0; i<n && pos<n; i++) {
        if (tree[i]){
            tree[i]->left = tree[pos++];
            if (pos<n){
                tree[i]->right = tree[pos++];
            }
        }
    }
    for(int i=0; i<n; i++) {
        if(tree[i]) {
            printf("      val, %d \n ", tree[i]->val);
            if(tree[i]->left) printf(" left, %d \n ", tree[i]->left->val);
            if(tree[i]->right) printf("             right, %d \n ", tree[i]->right->val);
        }                
    }
	
    return tree[0];
}



int main() {
    int b[]={5,4,8,11,0,13,4,7,2,0,0,0,1};
    TreeNode *root = createTree(b, sizeof(b)/sizeof(int));
//	preorder(root);
	if(hasPathSum(root, 32)) printf(" has sum \n");
	else printf(" has no sum \n"); 

    return 0;
}
