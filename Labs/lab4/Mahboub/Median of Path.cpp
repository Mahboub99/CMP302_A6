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

int Cnt_Calc_Median(TreeNode* root,  multiset<int>ms) {
    if (root == NULL) return 0;

    ms.insert(root->val);
    bool ans = 0;
    int level = ms.size();
    if (level & 1) {
    
        int l =  distance(ms.begin() ,  ms.lower_bound(root->val))+1;
        int r =  distance(ms.begin() , ms.upper_bound(root->val));
        int mid = (ms.size() + 1) / 2;
        
        if (mid >= l && mid <= r)
            ans = 1;
    }
    return Cnt_Calc_Median(root->left, ms ) + Cnt_Calc_Median(root->right, ms)+ans;
}


int32_t main() {
    int n, x , y, e;
    cin >> n;
    
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
    multiset<int>ms;
    //ms.insert(root->val);
    int ans = Cnt_Calc_Median(root, ms);
    cout << ans << endl;
    
    return 0;
}