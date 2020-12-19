#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
typedef long long int ll;
#define SZ(c) ((ll)((c).size()))
#define REP(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define FOR(i, b, e) for (ll i = (ll)(b); i <= (ll)(e); ++i)
#define ALL(c) (c).begin(), (c).end()
#define MP(c, b) make_pair(c, b)
using namespace std;

struct Node
{
    ll data;
    ll size;
    Node *l, *r, *p;
};
vector<pair<ll, ll>> results;
ll sumSubtrees(Node *root)
{
    if (!root)
        return 0;
    ll l = sumSubtrees(root->l);
    ll r = sumSubtrees(root->r);
    ll sum = l + r + root->data;
    results.push_back(MP(sum, root->size));
    return sum;
}
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};
ll treeSize(Node *root)
{
    if (!root)
        return 0;
    ll left = treeSize(root->l);
    ll right = treeSize(root->r);
    root->size = left + right + (ll)1;
    return root->size;
}

int main(void)
{
    ll N, M;
    cin >> N >> M;
    vector<Node *> data(N);
    REP(i, N)
    {
        ll d;
        cin >> d;
        Node *n = new Node;
        n->data = d;
        n->l = NULL;
        n->r = NULL;
        n->p = NULL;
        data[i] = n;
    }
    ll E;
    cin >> E;
    REP(j, E)
    {
        char pos;
        ll p, c;
        cin >> pos >> p >> c;
        if (pos == 'L')
            data[p]->l = data[c];
        else
            data[p]->r = data[c];
        data[c]->p = data[p];
    }
    Node *r = NULL;
    REP(m, N)
    if (!data[m]->p)
        r = data[m];
    treeSize(r);
    sumSubtrees(r);
    unordered_map<pair<ll, ll>, ll, hash_pair> mp;
    REP(k, SZ(results))
    if (results[k].second > M)
        mp[MP(results[k].first, results[k].second)]++;
    for (auto element : mp)
    {
        if (element.second > 1)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}