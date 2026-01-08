class Solution {
public:
    long long totalSum = 0;
    long long ans = 0;
    static const int MOD = 1e9 + 7;


    long long bt(TreeNode* root) {
        if (!root) return 0;

        long long left = bt(root->left);
        long long right = bt(root->right);

        return left + right + root->val;
    }

 
    long long traverse(TreeNode* root) {
        if (!root) return 0;

        long long left = traverse(root->left);
        long long right = traverse(root->right);

        if (root->left) {
            ans = max(ans, left * (totalSum - left));
        }

        if (root->right) {
            ans = max(ans, right * (totalSum - right));
        }

        return left + right + root->val;
    }

    int maxProduct(TreeNode* root) {
        totalSum = bt(root);
        traverse(root);
        return ans % MOD;
    }
};