#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// This code is used for guidance (you can change it if you want).

struct Node
{
  int index;
  int rating;
  Node *parent; // this is optional
  vector<Node *> children;
};

long long maximumSum(Node *root, vector<vector<long long>> &memo, bool par = 0)
{
  if (!root)
    return 0LL;

  long long &ret = memo[root->index][par];

  if (ret != -1)
    return ret;

  ret = 0;

  long long ans1 = 0, ans2 = 0;

  for (auto b : root->children)
  {
    ans1 += maximumSum(b, memo, 0);
  }

  if (!par)
  {
    for (auto b : root->children)
    {
      ans2 += maximumSum(b, memo, 1);
    }

    ans2 += root->rating;
  }

  ret = max(ans1, ans2);

  return ret;
}

int main()
{

  // Number of nodes in the tree
  int N;
  cin >> N;

  vector<Node *> nodes(N);
  for (int i = 0; i < N; i++)
  {
    nodes[i] = new Node;
    nodes[i]->index = i;
    cin >> nodes[i]->rating;
  }

  // Iterating over all edges
  int parent, child;
  for (int i = 0; i < N - 1; i++)
  {
    cin >> parent >> child;
    nodes[child]->parent = nodes[parent];
    nodes[parent]->children.push_back(nodes[child]);
  }

  // TODO: Create a vector called 'memo' used for memoization (What is the dimensions of that vector?)
  // then uncomment the following line.
  vector<vector<long long>> memo(N, vector<long long>(2, -1));
  cout << maximumSum(nodes[0], memo) << '\n';

  return 0;
}