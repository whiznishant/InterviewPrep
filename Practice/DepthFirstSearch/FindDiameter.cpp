/*

Tree Diameter (medium) #
Given a binary tree, find the length of its diameter. The diameter of a tree is the number of nodes on the longest path between any two leaf nodes. The diameter of a tree may or may not pass through the root.

Note: You can always assume that there are at least two leaf nodes in the given tree.

Example 1:
            1
            /\
           2  3
          /  / \
         4  5   6

Output: 5

Explanation: The diameter of the tree is: [4, 2, 1, 3, 6]
Example 2:
1
2
3
5
6
7
8
10
9
11

*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeNode {
 public:
  int val = 0;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class TreeDiameter {
 public:
  static int findDiaHelper( TreeNode *root, int currDepth , int &longest )
  {
    if(root == nullptr)
      return currDepth;
    currDepth++;
    int leftDepth = findDiaHelper(root->left,currDepth,longest);
    int rightDepth = findDiaHelper(root->right,currDepth,longest);   
    if(leftDepth > 0  && rightDepth > 0 )
    {
      int longestPath = leftDepth + rightDepth + 1 - (2 * currDepth);
      if(longestPath > longest)
        longest = longestPath;
    }
    return max(leftDepth,rightDepth);
  }

  static int findDiameter(TreeNode *root) {
    int treeDiameter = 0;
    // TODO: Write your code here
    findDiaHelper(root,0,treeDiameter);
    return treeDiameter;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
  root->left->left = nullptr;
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  root->right->left->right->left = new TreeNode(10);
  root->right->right->left->left = new TreeNode(11);
  cout << "Tree Diameter: " << TreeDiameter::findDiameter(root) << endl;
}
