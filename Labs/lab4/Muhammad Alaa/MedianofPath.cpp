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

void countValid(Node *root, long long level, multiset<ll> level_nodes, ll &count)
{
    if (!root)
        return;
    level_nodes.insert(root->data);
    if (level % 2 == 1)
    {
        auto iter = level_nodes.cbegin();
        std::advance(iter, level / 2);
        unsigned long long median = *iter;
        if (median == root->data)
            count++;
    }

    countValid(root->l, level + 1, level_nodes, count);
    countValid(root->r, level + 1, level_nodes, count);
}

ll height(Node *root)
{
    if (!root)
        return 0;
    else
    {
        int left_height = height(root->l);
        int right_height = height(root->r);
        if (left_height >= right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }
}

int main(void)
{
    ll N;
    cin >> N;
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
    ll h = height(r);
    ll count = 0;
    multiset<ll> level_nodes;
    countValid(r, 1, level_nodes, count);

    cout << count;
    return 0;
}