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

vector<int>sum;
int hight(TreeNode* root) {
    if (root == NULL) return 0;
    int l = hight(root->left) + 1;
    int r = hight(root->right) + 1;
    return max(l, r);
}
vector<vector<int>> bfs(TreeNode* root , int h) {

    vector<vector<int>>ans;
    map<TreeNode*, int>level;

    if (root != NULL) {
        queue<TreeNode*>q;
        q.push(root);
        level[root] = 0;
        ans.resize(h);
        sum.resize(h);
        sum[0] += root->val;
        ans[0].push_back(root->val);
        while (!q.empty()) {
            TreeNode* cur = q.front(); q.pop();
            if (cur->left != NULL) {
                q.push(cur->left);
                level[cur->left] = level[cur] + 1;
                ans[level[cur->left]].push_back(cur->left->val);
                sum[level[cur->left]] += cur->left->val;
            };

            if (cur->right != NULL) {
                q.push(cur->right);
                level[cur->right] = level[cur] + 1;
                ans[level[cur->right]].push_back(cur->right->val);
                sum[level[cur->right]] += cur->right->val;
            };

        }

    }
    return ans;
}

int32_t main() {
    int n, x, y, e;
    cin >> n;

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
    int h = hight(root);
    vector<vector<int>>vec = bfs(root , h);

    int L = root->val % h;
    int K = 1e9;
    int L_sz = vec[L].size();
    for (int i = 0; i < L_sz ; i++) K = min(vec[L][i], K);
    K %= h;
    if (K == 0) K = 1;
    for (int i = 0; i < h; i += K) {
        cout<<sum[i];
    }
    cout << endl;
    return 0;
}