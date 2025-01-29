#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (long long i = 0; i < n; i++)
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
typedef pair<long long, long long> pii;
typedef pair<ll, ll> pl;
typedef vector<long long> vi;
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
        long long n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<vector<long long>>a(n,vector<long long>(m));
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                  cin>>a[i][j];
            }   
        }

        vector<long long >rs(n);
        vector<long long>cs(m);
        for(long long i=0;i<n;i++){
            long long sum=0;
            for(long long j=0;j<m;j++){
                  sum+=a[i][j];
            }
            rs[i]=sum;
        }
        for(long long j=0;j<m;j++){
            long long sum=0;
            for(long long i=0;i<n;i++){
                  sum+=a[i][j];
            }
            cs[j]=sum;
        }

        long long cnt=0;
        long long x=0;
        long long y=0;
        while(cnt<n+m-1){
            if(s[cnt]=='D'){
                  a[x][y]= -rs[x];
                  rs[x]+=a[x][y];
                  cs[y]+=a[x][y];
                  x++;


            }
            else{
                  a[x][y]= -cs[y];
                  rs[x]+=a[x][y];
                  cs[y]+=a[x][y];
                  y++;

            }
            cnt++;
        }
        for(long long i=0;i<n;i++){
            for(long long j=0;j<m;j++){
                  cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
        
    
  
    }
}
  