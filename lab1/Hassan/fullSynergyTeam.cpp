#include <bits/stdc++.h>
using namespace std;

int n, e;

void createGroups(vector<vector<int> >& groups, const vector<vector<int> >& v, int& mx, vector<int> lastGroup = vector<int>(), int index = 0)
{
  int lastGroupSize = lastGroup.size();
  if(lastGroupSize >= n)
  {
    return;
  }
  for(int i = index; i < n; i++)
  {
      bool validGroup = true;
      for(int j = 0; j < lastGroupSize; j++) {
        if(!v[lastGroup[j]][i])
        {
            validGroup = false;
            break;
        }
      }
      if(validGroup)
      {
        vector<int> tmpGroup = lastGroup;
        tmpGroup.push_back(i);
        mx = max(int(tmpGroup.size()), mx);
        groups.push_back(tmpGroup);
        createGroups(groups, v, mx, tmpGroup, i + 1);
      }
  }

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
  vector<vector<int> > groups;
  int mx = 1;
  createGroups(groups, v, mx);
  cout<<mx<<endl;
}
