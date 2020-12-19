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
    ll sum;
    Node *l, *r, *p;
};
ll sumSubtrees(Node *root)
{
    if (!root)
        return 0;
    ll l = sumSubtrees(root->l);
    ll r = sumSubtrees(root->r);
    ll sum = l + r + root->data;
    root->sum = sum;
    return sum;
}

ll R;
void countValid(Node *root, ll &count)
{
    if (!root)
        return;

    countValid(root->l, count);
    countValid(root->r, count);
    if (!root->l && root->r)
    {
        if (root->r->sum - 0 <= R)
            count++;
    }
    else if (root->l && !root->r)
    {
        if (root->l->sum - 0 <= R)
            count++;
    }
    else if (!root->l && !root->r)
    {
        count++;
    }
    else
    {
        if (abs(root->l->sum - root->r->sum) <= R)
            count++;
    }
}

int main(void)
{
    ll N;
    cin >> N >> R;
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
    sumSubtrees(r);
    ll count = 0;
    countValid(r, count);
    cout << count << endl;
    return 0;
}