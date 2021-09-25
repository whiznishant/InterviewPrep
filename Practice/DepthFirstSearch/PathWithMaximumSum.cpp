#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

class TreeNode {
 public:
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) {
    val = x;
    left = right = nullptr;
  }
};

class MaximumPathSum {
 public:
  static int maxSumPath(TreeNode *root, vector<int> &currPath,int &maxSum )
  {
    if( root == nullptr )
      return 0;

    currPath.push_back(root->val);
    int leftSum = maxSumPath(root->left,currPath,maxSum);
    int rightSum = maxSumPath(root->right,currPath,maxSum);
    int currMaxSum = leftSum + root->val + rightSum;
    int currLeftSum = leftSum + root->val;
    int currRightSum = rightSum + root->val;
    int maxOnePathSum = max( currLeftSum, currRightSum );
    currMaxSum = max( currMaxSum, maxOnePathSum);
    currMaxSum = max( currMaxSum, root->val );
    
    if(currMaxSum > maxSum)
    {
        maxSum = currMaxSum;        
    }
    currPath.pop_back();
    return (max(leftSum,rightSum) + root->val );
  }
  static int findMaximumPathSum(TreeNode *root) {
    // TODO: Write your code here
    vector<int> currPath;
    int maxSum = INT_MIN;
    maxSumPath(root,currPath,maxSum);
    return maxSum;
  }
};

int main(int argc, char *argv[]) {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl; // Ans -- 
  
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(3);
  root->right->left = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->right->left->left = new TreeNode(7);
  root->right->left->right = new TreeNode(8);
  root->right->right->left = new TreeNode(9);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
  
  root = new TreeNode(-1);
  root->left = new TreeNode(-3);
  cout << "Maximum Path Sum: " << MaximumPathSum::findMaximumPathSum(root) << endl;
}
