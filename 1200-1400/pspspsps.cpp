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
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        //write code here
       int n;
       cin>>n;
       string s;
       cin>>s;
       int pc=0;
       int sc=0;
       int pi=-1;
       int si=0;
       int index=0;
       for(char ch:s){
            if(ch=='s'){
                  si=index;
                  sc++;
            }
            if(ch=='p'){
                  pc++;
                  if(pi==-1){
                        pi=index;
                  }
            }
            index++;
       }
       if(pc==0 || sc==0){
            cout<<"YES\n";
       }
       else if(si==0 || pi==n-1){
            cout<<"YES\n";
       }
       else cout<<"NO\n";


      
    }
}
  