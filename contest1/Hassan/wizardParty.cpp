#include <bits/stdc++.h>
using namespace std;
int n, e;
bool isSolved(const vector<bool>& used)
{
  int usedSize = used.size();
  for(int i = 0; i < usedSize; i++)
  {
    if(!used[i]) return false;
  }
  return true;
}
bool isPossible(const vector<vector<int> >& v, vector<bool> used = vector<bool>(n, false), int index = 0)
{
    if(n == 1) return true;
    if(index == 0 && used[0]) return isSolved(used);
    bool ans = false;
    for(int i = 0; i < n; i++)
    {
      if(v[index][i] && !used[i])
      {
        used[i] = true;
        ans = ans || isPossible(v, used, i);
        used[i] = false;
      }
    }
    return ans;
}
int main()
{
  cin>>n>>e;
  vector<vector<int> > v(n, vector<int>(n, 0));
  int a, b;
  for(int i = 0; i < e; i++)
  {
    cin>>a>>b;
    v[a][b] = v[b][a] = 1;
  }
  cout<<isPossible(v)<<endl;
}
