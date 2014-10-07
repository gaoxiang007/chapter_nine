// http://www.geeksforgeeks.org/print-bst-keys-in-the-given-range/

/*
Given two values k1 and k2 (where k1 < k2) and a root pointer to a Binary Search Tree. 
Print all the keys of tree in range k1 to k2. i.e. print all x such that k1<=x<=k2 and 
x is a key of given BST. Print all the keys in increasing order.
*/

/*
           20
          /  \
         8   22
        / \
       4  12

intput: k1 = 10 , k2 = 22
output: 8 20 22
*/
    
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(x) : val(x), left(NULL), right(NULL) {}
};

void printRange(TreeNode* root, int k1, int k2) {
    if(root == NULL) {
        return;
    }
    if(root->val > k1) {
        printRange(root->left, k1, k2);
    } 
    if(root->val >= k1 && root->val <= k2) {
        cout << root->val << " ";    
    }
    if(root->val < k2) {
        printRange(root->right, k2, k2);
    }
}


