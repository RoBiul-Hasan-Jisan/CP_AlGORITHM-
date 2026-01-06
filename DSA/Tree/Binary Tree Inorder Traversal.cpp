#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* l;
    TreeNode* r;

    TreeNode(int x) {
        val = x;
        l = r = nullptr;
    }
};

vector<int> iot(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr != nullptr || !st.empty()) {

        while (curr != nullptr) {
            st.push(curr);
            curr = curr->l;
        }

        curr = st.top();
        st.pop();
        ans.push_back(curr->val);

        curr = curr->r;
    }

    return ans;
}

int main() {
    /*
        Example Tree:
              1
               \
                2
               /
              3
        Inorder Output: 1 3 2
    */

    TreeNode* root = new TreeNode(1);
    root->r = new TreeNode(2);
    root->r->l = new TreeNode(3);

    vector<int> res = iot(root);

    for (int x : res)
        cout << x << " ";

    return 0;
}
