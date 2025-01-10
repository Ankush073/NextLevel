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
struct node{
      ll a;
      ll b;
      ll c;
      ll d;
      ll e;
};
class SEGMENTTREE{
      vector<node>seg;
public:
      SEGMENTTREE(ll n){
            seg.resize(4*n);
      }
      void build(ll ind,ll low,ll high, ll arr[]){
            if(low==high){
                  seg[ind].a=arr[low]+(low+1);
                  seg[ind].b=arr[low]+(low+1);
                  seg[ind].c=arr[low]-(low+1);
                  seg[ind].d=arr[low]-(low+1);
                  seg[ind].e=0;
                  return;

            }
            ll mid =(low+high)/2;
            build(2*ind+1,low,mid,arr);
            build(2*ind+2,mid+1,high,arr);
            seg[ind].a=max(seg[2*ind+1].a,seg[2*ind+2].a);
            seg[ind].b=min(seg[2*ind+1].b,seg[2*ind+2].b);
            seg[ind].c=max(seg[2*ind+1].c,seg[2*ind+2].c);
            seg[ind].d=min(seg[2*ind+1].d,seg[2*ind+2].d);
            seg[ind].e=max(seg[2*ind+1].e,seg[2*ind+2].e);
            seg[ind].e=max(seg[ind].e,seg[2*ind+1].a-seg[2*ind+2].b);
            seg[ind].e=max(seg[ind].e,seg[2*ind+2].c-seg[2*ind+1].d);
      }
      void update(ll ind,ll low,ll high,ll i,ll val){
            if(low==high){
                  seg[ind].a=val+(low+1);
                  seg[ind].b=val+(low+1);
                  seg[ind].c=val-(low+1);
                  seg[ind].d=val-(low+1);
                  seg[ind].e=0;
                  return;
            }
            ll mid =(low+high)/2;
            if(i<=mid){
                  update(2*ind+1,low,mid,i,val);
            }
            else{
                  update(2*ind+2,mid+1,high,i,val);
            }
            seg[ind].a=max(seg[2*ind+1].a,seg[2*ind+2].a);
            seg[ind].b=min(seg[2*ind+1].b,seg[2*ind+2].b);
            seg[ind].c=max(seg[2*ind+1].c,seg[2*ind+2].c);
            seg[ind].d=min(seg[2*ind+1].d,seg[2*ind+2].d);
            seg[ind].e=max(seg[2*ind+1].e,seg[2*ind+2].e);
            seg[ind].e=max(seg[ind].e,seg[2*ind+1].a-seg[2*ind+2].b);
            seg[ind].e=max(seg[ind].e,seg[2*ind+2].c-seg[2*ind+1].d);
      }

      ll query(){
            return seg[0].e;
      }
};


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
        ll n,q;
        cin>>n>>q;
        ll arr[n];
        fo(i,n){
            cin>>arr[i];
        }
        SEGMENTTREE sg(n);
        sg.build(0,0,n-1,arr);
        cout<<sg.query()<<endl;
        while(q--){
            ll ind,val;
            cin>>ind>>val;
            ind--;
            sg.update(0,0,n-1,ind,val);
            cout<<sg.query()<<endl;
        }
    }
    return 0;
}