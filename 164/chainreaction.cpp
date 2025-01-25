#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, false, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define mod 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
int divup(int a,int b){
      return (a+b-1)/b;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    int mx=*max_element(a.begin(),a.end());
    vector<long long >ans(mx+1);
    for(int i=0;i<n;i++){
      int coef=0;
      if(i==0 || a[i]>a[i-1]) ++coef;
      if(i+1<n && a[i]<a[i+1]) --coef;
      int r =a[i];
      ans[r]+=coef;
      while(r>0){
            int val=divup(a[i],r);
            int l=divup(a[i],val);
            ans[l-1]+=coef*val;
            ans[r]-=coef*val;
            r=l-1;
      }
    }
    for(int i=0;i<mx;i++) ans[i+1]+=ans[i];
    for(int i=0;i<mx;i++) cout<<ans[i]<< " ";
    cout<<endl;

    return 0;
}