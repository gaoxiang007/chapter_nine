void printPath(TreeNode* root, vector<int>& path) {
    if(root == NULL) {
        return;
    }
    path.push_back(root->val);
    if(root->left == NULL && root->right == NULL) {
        printArray(path);
    } else {
        printPath(root->left, path);
        printPath(root->right, path);
    }
}


///////////// referred from http://ideone.com/fork/NyqYyS
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>

using namespace std;



struct TreeNode {
  TreeNode *left, *right;
  int data;
  TreeNode(int val) : left(NULL), right(NULL), data(val) { }
};



TreeNode* createTree(){
  TreeNode* root=new TreeNode(45);
  //level 2
  root->left=new TreeNode(22);
  root->right=new TreeNode(70);
  //level 3
  root->left->left=new TreeNode(15);
  root->left->right=new TreeNode(27);
  root->right->left=new TreeNode(60);
  root->right->right=new TreeNode(80);
  
  return root;
}



void printPath(const vector<int>& v){
    cout<<"path "; 
    for (auto& item : v){
      cout<<item<<" ";
    }
    cout<<endl;
}

bool isLeaf(const TreeNode* root){
    return NULL==root->left && NULL ==root->right;
}

void printAllPathRecursive(const TreeNode* root, vector<int> v){
    if(isLeaf(root)) {
        v.push_back(root->data);
        printPath(v);
        return;
    }
    
  
    v.push_back(root->data);

    printAllPathRecursive(root->left,v);
    printAllPathRecursive(root->right,v);

}



void printAllPathNonRecursive(TreeNode* root){
    if(NULL==root)
        return;

    stack<TreeNode*> s;
    stack<string> path;

    s.push(root);

    path.push(to_string(root->data)+" ");

    while(!s.empty()){
        TreeNode* current=s.top();
        s.pop();

        string currentPath=path.top();
        path.pop();

        if(isLeaf(current)){
            cout<<"path  "<< currentPath<<endl;
            continue;
        }

        if(current->left){
           string leftString=currentPath+" "+to_string(current->left->data);
           s.push(current->left);
           path.push(leftString);
        } 

        if(current->right){
           string rightString=currentPath+" "+to_string(current->right->data);
           s.push(current->right);
           path.push(rightString);
        }

    }
        
}



int main() {
  TreeNode* fullBinaryTree=createTree();
  vector<int> v;
  //printAllPathRecursive(fullBinaryTree,v);
  printAllPathNonRecursive(fullBinaryTree);

  return 0;
}
