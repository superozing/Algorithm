/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) 
    {
        // 노드 개수를 새는거구나!
        int count = 0;

        if (root == nullptr)
            return 0;

        list<TreeNode*> q;

        q.push_back(root);

        while (!q.empty())
        {
            TreeNode* pNode = q.front();
            q.pop_front();
            ++count;

            if (pNode->left)
                q.push_back(pNode->left);
            if (pNode->right)
                q.push_back(pNode->right);
        }

        return count;
    }
};