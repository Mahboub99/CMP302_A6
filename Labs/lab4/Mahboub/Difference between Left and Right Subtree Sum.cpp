#include<bits/stdc++.h>

#define int long long int

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
};



int hight(TreeNode* root) {
    if (root == NULL) return 0;
    int l = hight(root->left) + 1;
    int r = hight(root->right) + 1;
    return max(l, r);
}

int sum_tree(TreeNode* root) {
    if (root == NULL) return 0;
    return root->val =  sum_tree(root->left) + sum_tree(root->right) + root->val;
}

int cnt_abs_diff(TreeNode* root ,int d) {
    if (root == NULL) return 0;
    bool ans = 0;
    if (root->left != NULL && root->right != NULL) ans = abs(root->left->val - root->right->val) <= d;
    else if (root->right == NULL && root->left != NULL) ans = root->left->val <= d;
    else if (root->left == NULL && root->right != NULL) ans = root->right->val <= d;
    else if (root->left == NULL && root->right == NULL) ans = 1;

    return  cnt_abs_diff(root->right, d) + cnt_abs_diff(root->left, d) + ans;
}


int32_t main() {
    int n, d  ,x , y, e;
    cin >> n >> d;
    
    vector<TreeNode*>tree(n);
    
    for (int i = 0; i < n; i++) {
        cin >> x;
        tree[i] = new TreeNode(x);
    }
    char c;
    cin >> e;
    for (int i = 0; i < e; i++) {
        cin >> c >> x >>y;
        if (c == 'L') tree[x]->left = tree[y];
        else tree[x]->right = tree[y];
    }
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }

    TreeNode* root = tree[0];
    sum_tree(root);
    int ans = cnt_abs_diff(root, d);
    cout << ans << endl;
    return 0;
}