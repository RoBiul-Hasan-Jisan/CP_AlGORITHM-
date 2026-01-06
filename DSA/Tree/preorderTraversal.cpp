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

//Preorder	ROOT → LEFT → RIGHT
//Inorder	LEFT → ROOT → RIGHT
//Postorder	LEFT → RIGHT → ROOT


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (!root) return ans;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        ans.push_back(curr->val);   // ROOT

        if (curr->r) st.push(curr->r); // RIGHT first
        if (curr->l) st.push(curr->l); // LEFT second
    }

    return ans;
}


int main() {
    /*
                10
              /    \
             5      15
            / \       \
           2   7       20
              /
             6
    Inorder 2 5 6 7 10 15 20
    Preorder 10 5 2 7 6 15 20
    POSTORDER 2  6 7 5 20 15 10


    */

    TreeNode* root = new TreeNode(10);
    root->l = new TreeNode(5);
    root->r = new TreeNode(15);

    root->l->l = new TreeNode(2);
    root->l->r = new TreeNode(7);

    root->l->r->l = new TreeNode(6);
    root->r->r = new TreeNode(20);

   
      vector<int> res1 = preorderTraversal(root);
     

 

         for (int x : res1)
        cout << x << " ";
    

    return 0;
}
