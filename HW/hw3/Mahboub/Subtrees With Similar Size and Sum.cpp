#include<bits/stdc++.h>
#include<unordered_map>

#define int long long int

using namespace std;

struct TreeNode {
    int val;
    int size;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), size(1), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), size(1), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), size(1), left(left), right(right) {}
};
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int hight(TreeNode* root) {
    if (root == NULL) return 0;
    int l = hight(root->left) + 1;
    int r = hight(root->right) + 1;
    return max(l, r);
}

int sum_tree(TreeNode* root) {
    if (root == NULL) return 0;
    return root->val = sum_tree(root->left) + sum_tree(root->right) + root->val;
}

int sum_size(TreeNode* root) {
    if (root == NULL) return 0;
    return root->size = sum_size(root->left) + sum_size(root->right) + root->size;
}
unordered_map<pair<int ,int>, int ,hash_pair >ans;

void is_similer(TreeNode* root) {
    if (root == NULL) return;
    ans[{root->size, root->val}]++;
    is_similer(root->left );
    is_similer(root->right);
}

int32_t main() {
    int n, x, y,m, e;
    cin >> n>>m;

    vector<TreeNode*>tree(n);

    for (int i = 0; i < n; i++) {
        cin >> x;
        tree[i] = new TreeNode(x);
    }
    char c;
    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> c >> x >> y;
        if (c == 'L') tree[x]->left = tree[y];
        else tree[x]->right = tree[y];
    }
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    TreeNode* root = tree[0];
    sum_tree(root);
    sum_size(root);
    is_similer(root);
    for (auto c : ans) {
        if (c.second > 1 && c.first.first > m) {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    
    return 0;
}