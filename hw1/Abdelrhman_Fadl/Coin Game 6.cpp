#include <iostream>
#include <set>
#include <queue>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <stdio.h>
#include <cstring>                    
#include <sstream>
#include <numeric>
#include <assert.h>

using namespace std;

#define lop(i,n) for(int i=0 ;i<n ;i++)
#define VI    vector<int>
#define VLL    vector<ll>
#define VPI    vector<pair<int,int>>
#define VII    vector<VI>
#define all(v)    v.begin() , v.end()
#define SORT(v)    sort(all(v))
#define ll    long long
#define ull unsigned long long
#define scni(x)    scanf("%d",&x)           
#define scnll(x)    scanf("%lld",&x)        
#define scnd(x)    scanf("%lf",&x)          
#define prnti(x)    printf("%d\n",x)        
#define prntll(x)    printf("%lld",x)       
#define prntd(x)    printf("%.9lf",x)        
#define sz(x)  x.size()
#define pp push_back
#define P pair<int , int>
#define mp make_pair

const double EPS = 1e-9;
const double PI = 3.14159265359;

//  O( n * log(log(n)) )
vector<ll> primes;
void GeneratingPrimes(int top){
    vector<bool> p (top+1 , 1);
//    vector<ll> primes;
    p[0] = p[1] = 0;

    for(int i = 2; i <= sqrt(top) ; i++){
        if(p[i]){
            for(int j = i*i ; j <= top ; j+=i){
                p[j]=0;
            }
        }
    }
    lop(i , top+1)
        if(p[i])primes.push_back(i);
//    return primes;
}

ll gcd(ll a ,ll b){return (b==0)?a : gcd(b , a%b);}
ll lcm(ll a, ll b){return (a * b) / gcd(a , b);}
void EXTgcd(ll a , ll b , ll & x0 , ll & y0){
    if(b==0){ x0 =1 , y0 = 0; return; }
    EXTgcd( b , a%b , x0 , y0 );
    ll x1 = y0;
    ll y1 = x0 - (a/b) * (y0);

    y1 = y1;
    x0 = x1;
    y0 = y1;
}

long long power(long long n, long long p , ll mod) {
    if (!p)
        return 1;
    long long ans = 1;
    while (p > 1) {
        if (p & 1)
            ans = (ans * n) % mod;
        n = (n * n) % mod;
        p /= 2;
    }
    return (ans * n) % mod;
}

double dist(double a , double b , double x, double y){ return sqrt( pow( a-x ,2) + pow( b-y ,2) ); }
double dist3(double a , double b , double c , double x , double y ,double z ){ return sqrt( pow( a-x ,2) + pow( b-y ,2) + pow( c-z ,2)); }

int xadd[9]= { 1 , -1 , 0 , 1 , -1 , 0 , 1 , -1 , 0 };
int yadd[9]= { 1 , -1 , 0 ,-1 ,  0 , 1 , 0 ,  1, -1 };

int xx[4]={0 , 1 , 0 , -1};
int yy[4]={1 , 0 , -1 , 0};

// string digits[]= {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

#define no  { cout<<"NO\n";  }
#define yes { cout<<"YES\n"; }
#define _1  { cout<<"-1\n";  }

ll const N = 1e5 + 10;
ll const INF = 1e18;
ll const mod = 1000000009;

///////////////////////////////////////////////////////////////////

int t, n, a[30], ok=0;

void solve(int idx = 0, int rem = t){
    if(rem == 0){
        ok=1;
        return;
    }
    if(idx == n || rem < 0)return;

    solve(idx+1, rem-a[idx]);
    solve(idx+1, rem);

    return;
}

int main(){

    cin >> t >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    solve();
    cout << ok;

return 0;}