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



/// Using inOrder traverse
/// Store all elements in an vector
///
/// Time Complexity: O(n)
/// Space Complexity: O(n)


bool dfs(TreeNode* node, long mn, long mx);

bool isValidBST(TreeNode* root) {

  if(!root) return false;
  
  return dfs(root, LONG_MIN, LONG_MAX); 

}

bool dfs(TreeNode* node, long mn, long mx){

    if(!node) return true;
	if(node->val >= mx || node->val <= mn) return false;
	return dfs(node->left, mn, node->val) && dfs(node->right, node->val, mx); 

}

void preorder(TreeNode* root){

   if(root){
      printf("current node (%d) \n", root->val);
	  if(root->left) preorder(root->left);
	  if(root->right) preorder(root->right); 
   }

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
	
    return tree[0];
}



int main() {
    int b[]={4,2,6,1,7,5,7};
    TreeNode *root = createTree(b, sizeof(b)/sizeof(int));
//	preorder(root);
	if(isValidBST(root)) printf(" is Valide \n");
	else printf(" is NOT valid \n"); 

    return 0;
}
