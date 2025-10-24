Longest Common Prefix Optimization in Selected Strings
struct TrieNode {
    TrieNode* children[26] = {nullptr};
    int count = 0;
};

void insert(TrieNode* root, const string &s) {
    TrieNode* node = root;
    for (char c : s) {
        int idx = c - 'a';
        if (!node->children[idx])
            node->children[idx] = new TrieNode();
        node = node->children[idx];
        node->count++;
    }
}

// DFS to find longest prefix appearing in at least 2 strings
void dfs(TrieNode* node, string &path, string &res) {
    if (!node) return;
    if (node->count >= 2 && path.size() > res.size())
        res = path;
    for (int i = 25; i >= 0; --i) { // descending for lexicographically largest
        if (node->children[i]) {
            path.push_back('a' + i);
            dfs(node->children[i], path, res);
            path.pop_back();
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> strings(n);
    for (int i = 0; i < n; i++) cin >> strings[i];

    // Sort lexicographically to pick first k strings for minimal lex order
    sort(strings.begin(), strings.end());
    
    TrieNode* root = new TrieNode();
    for (int i = 0; i < k; i++)
        insert(root, strings[i]);

    string path = "", result = "";
    dfs(root, path, result);

    if (result.empty()) cout << "EMPTY\n";
    else cout << result << "\n";
}



