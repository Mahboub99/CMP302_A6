#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
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
    Node *l, *r;
};
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
vector<vector<Node *>> res;
void levels(struct Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        ll count = q.size();
        vector<Node *> l;
        while (count--)
        {
            Node *temp = q.front();
            q.pop();
            l.push_back(temp);
            if (temp->l)
                q.push(temp->l);
            if (temp->r)
                q.push(temp->r);
        }
        res.push_back(l);
    }
}
void getLevelsWithoutQueue(Node *root, long long level, vector<Node *> &level_nodes)
{
    if (!root)
        return;
    if (level == 1)
        level_nodes.push_back(root);
    else if (level > 1)
    {
        getLevelsWithoutQueue(root->l, level - 1, level_nodes);
        getLevelsWithoutQueue(root->r, level - 1, level_nodes);
    }
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
    }
    ll h = height(data[0]);
    REP(d, h)
    {
        vector<Node *> levelnodes;
        getLevelsWithoutQueue(data[0], d + 1, levelnodes);
        res.push_back(levelnodes);
    }
    //levels(data[0]);
    ll l = data[0]->data % h;
    ll min = res[l][0]->data;
    for (ll i = 1; i < SZ(res[l]); i++)
        if (res[l][i]->data < min)
            min = res[l][i]->data;
    ll k = min % h;
    if (!k)
        k = 1;
    vector<ll> sums;
    for (ll i = 0; i < SZ(res); i++)
    {
        ll sum = 0;
        for (ll j = 0; j < SZ(res[i]); j++)
        {
            sum += res[i][j]->data;
        }
        sums.push_back(sum);
    }
    vector<ll> result;
    for (ll i = 0; i < SZ(sums); i += k)
    {
        result.push_back(sums[i]);
    }

    REP(m, SZ(result))
    cout << result[m];
    cout << endl;
    return 0;
}