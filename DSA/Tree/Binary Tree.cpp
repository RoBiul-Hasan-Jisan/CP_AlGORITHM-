struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};
//Preorder (Root → Left → Right)

void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

//Inorder (Left → Root → Right)

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
//Postorder (Left → Right → Root)

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}
//Level Order
void levelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

//Tree Height

int height(TreeNode* root) {
    if (root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}
//Count Total Nodes

int countNodes(TreeNode* root) {
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}
//Maximum & Minimum Value
int maxValue(TreeNode* root) {
    if (root == NULL)
        return INT_MIN;

    return max(root->val,
               max(maxValue(root->left), maxValue(root->right)));
}
//Level Order Sum
void levelOrderSum(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    int level = 1;

    while (!q.empty()) {
        int size = q.size();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout << "Level " << level << " sum = " << sum << endl;
        level++;
    }
}

//Invert Binary Tree Swap left & right child of every node

TreeNode* invertTree(TreeNode* root) {
    if (root == NULL)
        return NULL;

    swap(root->left, root->right);

    invertTree(root->left);
    invertTree(root->right);

    return root;
}
//Max Depth

int maxDepth(TreeNode* root) {
    if (root == NULL)
        return 0;

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}



#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    // Alternative constructor with initializer list (C++11+)
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// 1. TRAVERSALS


// Preorder (Root → Left → Right)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Preorder iterative (stack-based)
void preorderIterative(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        cout << node->val << " ";

        // Push right first so left is processed first (LIFO)
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}

// Inorder (Left → Root → Right)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Inorder iterative
void inorderIterative(TreeNode* root) {
    stack<TreeNode*> st;
    TreeNode* curr = root;

    while (curr || !st.empty()) {
        while (curr) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->val << " ";
        curr = curr->right;
    }
}

// Postorder (Left → Right → Root)
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// Postorder iterative (using two stacks)
void postorderIterative(TreeNode* root) {
    if (!root) return;

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);

        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }

    while (!st2.empty()) {
        cout << st2.top()->val << " ";
        st2.pop();
    }
}

// 2. BFS / LEVEL ORDER


// Basic level order
void levelOrder(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " ";

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

// Level order with levels separated
void levelOrderWithLevels(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            cout << node->val << " ";

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        cout << endl; // New line for each level
    }
}

// 3. TREE PROPERTIES


// Tree Height/Depth (Number of edges from root to deepest leaf)
int height(TreeNode* root) {
    if (!root) return -1; // or 0 if counting nodes
    return 1 + max(height(root->left), height(root->right));
}

// Tree Height (Number of nodes from root to deepest leaf)
int heightNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(heightNodes(root->left), heightNodes(root->right));
}

// Count Total Nodes
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Count Leaf Nodes
int countLeafNodes(TreeNode* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Maximum Value
int maxValue(TreeNode* root) {
    if (!root) return INT_MIN;
    return max(root->val,
               max(maxValue(root->left), maxValue(root->right)));
}

// Minimum Value
int minValue(TreeNode* root) {
    if (!root) return INT_MAX;
    return min(root->val,
               min(minValue(root->left), minValue(root->right)));
}

// 4. TREE OPERATIONS


// Invert Binary Tree (Mirror)
TreeNode* invertTree(TreeNode* root) {
    if (!root) return nullptr;

    // Swap children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

// Check if tree is symmetric
bool isSymmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;
    if (!left || !right) return false;
    if (left->val != right->val) return false;

    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isSymmetric(root->left, root->right);
}

// Check if tree is balanced (height difference <= 1)
int checkHeight(TreeNode* root) {
    if (!root) return 0;

    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) return -1;

    if (abs(leftHeight - rightHeight) > 1) return -1;

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

// 5. PATH & SUM OPERATIONS


// Level Order Sum (your version is good)
void levelOrderSum(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);
    int level = 0;

    while (!q.empty()) {
        int size = q.size();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            sum += node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        cout << "Level " << level << " sum = " << sum << endl;
        level++;
    }
}

// Check if path exists from root to leaf with given sum
bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;

    // If leaf node, check if value equals remaining sum
    if (!root->left && !root->right) {
        return root->val == targetSum;
    }

    // Check left and right subtrees
    return hasPathSum(root->left, targetSum - root->val) ||
           hasPathSum(root->right, targetSum - root->val);
}

// 6. SEARCH & FIND


// Find node with given value
TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;

    TreeNode* left = findNode(root->left, val);
    if (left) return left;

    return findNode(root->right, val);
}

// Get level/depth of a node
int getNodeLevel(TreeNode* root, int val, int level = 0) {
    if (!root) return -1;
    if (root->val == val) return level;

    int left = getNodeLevel(root->left, val, level + 1);
    if (left != -1) return left;

    return getNodeLevel(root->right, val, level + 1);
}

// 7. TREE CONSTRUCTION


// Build tree from inorder and preorder traversals
TreeNode* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder,
                             int preStart, int inStart, int inEnd) {
    if (preStart >= preorder.size() || inStart > inEnd)
        return nullptr;

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inIndex = 0;
    for (int i = inStart; i <= inEnd; i++) {
        if (inorder[i] == root->val) {
            inIndex = i;
            break;
        }
    }

    root->left = buildTreeFromPreIn(preorder, inorder,
                                   preStart + 1,
                                   inStart,
                                   inIndex - 1);
    root->right = buildTreeFromPreIn(preorder, inorder,
                                    preStart + 1 + (inIndex - inStart),
                                    inIndex + 1,
                                    inEnd);

    return root;
}

// 8. CLEANUP


// Delete entire tree (postorder traversal)
void deleteTree(TreeNode* root) {
    if (!root) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

// 9. UTILITY FUNCTIONS


// Print tree visually (simplified)
void printTree(TreeNode* root, string prefix = "", bool isLeft = true) {
    if (!root) return;

    cout << prefix;
    cout << (isLeft ? "├──" : "└──");
    cout << root->val << endl;

    printTree(root->left, prefix + (isLeft ? "│   " : "    "), true);
    printTree(root->right, prefix + (isLeft ? "│   " : "    "), false);
}

// Check if two trees are identical
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (!p && !q) return true;
    if (!p || !q) return false;
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}


int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Level Order: ";
    levelOrder(root);
    cout << endl;

    cout << "Height: " << height(root) << endl;
    cout << "Total Nodes: " << countNodes(root) << endl;
    cout << "Leaf Nodes: " << countLeafNodes(root) << endl;

    // Clean up
    deleteTree(root);

   
}
