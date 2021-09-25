/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void BuildSearchNodes(TreeNode *root, unordered_map<TreeNode *, vector<int>> &searchNodes)
    {
        queue<TreeNode *> q;

        // If the tree is empty, assign new node address to root
        if (root == NULL)
        {
            return;
        }

        // Else, do level order traversal until we find an empty
        // place, i.e. either left child or right child of some
        // node is pointing to NULL.
        q.push(root);

        while (!q.empty())
        {
            TreeNode *temp = q.front();
            q.pop();

            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }

            if (temp->left == NULL && temp->right == NULL)
            {
                // Do nothing
            }
            else
            {
                vector<int> searchVal;
                searchVal.clear();
                PostOrder(temp, searchVal);
                searchNodes[temp] = searchVal;
            }
        }
    }
    
    void PostOrder(TreeNode *temp, vector<int> &values)
    {
        if (temp == NULL)
            return;

        PostOrder(temp->left, values);
        PostOrder(temp->right, values);
        values.push_back(temp->val);
        cout << temp->val << ' ';
    }
    
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode* p, TreeNode* q)
    {

        unordered_map<TreeNode *, vector<int>> searchNodes;
        int numElementsInSearch = 65565;
        TreeNode *lowestNode = NULL;

        // Build search nodes: This will build all connected components per node.
        BuildSearchNodes(root, searchNodes);

        for(unordered_map<TreeNode *, vector<int>>::iterator nodeItr = searchNodes.begin();
        nodeItr != searchNodes.end();
        nodeItr++)
        {
            TreeNode* valAt = nodeItr->first;
            vector<int> eachSearchNode = nodeItr->second;

            // Find nodes that contain both p and q in common
            if(std::find(eachSearchNode.begin(), eachSearchNode.end(), p->val) != eachSearchNode.end()
            && std::find(eachSearchNode.begin(), eachSearchNode.end(), q->val) != eachSearchNode.end())
            {
                if(numElementsInSearch > eachSearchNode.size())
                {
                    numElementsInSearch = eachSearchNode.size();
                    lowestNode = valAt;
                }
            }
        }

        return lowestNode;
    }
};
