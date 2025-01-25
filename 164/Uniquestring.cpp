#include<bits/stdc++.h>
using namespace std;
#define fore(i,l,r) for(int i=int(l);i<int(r);i++)
#define sz(a) int((a).size())

typedef long long li;
typedef pair<int,int>pt;

template<class A ,class B> ostream& operator <<(ostream& out, const pair<A,B>&p) 
{
      return out<<"(" << p.x<< "," <<p.y<<")";
}

template<class A> ostream& operator << (ostream& out, const vector<A>&v)
{
      fore(i,0,sz(v))
      {
            if(i) out<<" ";
            out <<v[i];
      }
      return out;
}


const int MOD= int(1e9)+7;
int add (int a,int b)
{
      a+=b;
      while(a>=MOD)
            a-=MOD;
      while(a<0)
            a+=MOD;
      return a;
}

void upd(int &ans,int val)
{
      ans=add(ans,val);
}

int mul(int a,int b)
{
      return int (a*1ll*b%MOD);
}

int binPow(int a,int k)
{
      int ans=1;
      while(k>0)
      {
            if(k&1)
                  ans=mul(ans,a);
            a=mul(a,a);
            k>>=1;
      }
      return ans;
}
int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

const int N=3055;
int f[N] ,invf[N];
void precalcFact()
{
      f[0]=invf[0]=1;
      fore(i,1,N)
      {
            f[i]=mul(f[i-1],i);
            invf[i]=binPow(f[i],MOD-2);
      }
}

int C(int n,int k)
{
      if(k<0 || k>n)
      {
            return 0;
      }
      return mul(f[n],mul(invf[k],invf[n-k]));
}

int n,c,k;
inline bool read()
{
      if(!(cin>>n>>c>>k))
            return false;
      return true;
}

int d[N][N], sum[N][N];


void precalcShort(int mx)
{
      memset(d,0,sizeof d);
      d[0][0]=1;
      fore(z,0,n)
      {
            fore(l,0,n)
            {
                  if(d[z][l]==0)
                        continue;
                  upd(d[z+1][l+1],+d[z][l]);
                  upd(d[z+1][min(n,l+mx)+1],-d[z][l]);
            }
            fore(l,0,n+1)
                  upd(d[z+1][l+1],d[z+1][l]);
      }
      memset(sum,0,sizeof sum);
      fore(z,0,n+1) fore(l,0,n+1)
            sum[z][l+1]=add(sum[z][l],d[z][l]);    
}

int getSum(int z,int lf,int rg)
{
      if(z<0 || z>n || lf>=rg)
            return 0;
      return add(sum[z][rg],-sum[z][lf]);
}
vector<int> precalcCnt(int n)
{
      vector<int>cnt(n+1,0);
      fore(x,1,n+1)
            cnt[gcd(x,n)]++;
      return cnt;
}

int calcFixedPoints(int g)
{
      if(c>=g)
            return c+k>=n;
      int cntOnes=(c+k)/(n/g);
      int cntZeros=g-cntOnes;
      int all =0;
      fore(ones,0,cntOnes+1)
            upd(all,C(g,ones));
      int bad=0;
      fore(pref,0,c)
      {
            int minZeros=max(0,cntZeros-1);
            int minMid=g-c;
            int sufLen=g-pref-1;
            fore(z,minZeros,sufLen+1)
                  upd(bad,getSum(z,minMid,sufLen+1));
      }
      return add(all,-bad);

}
inline void solve()
{
      precalcFact();
      precalcShort(c);
      auto cnt = precalcCnt(n);

      int ans=0;
      fore(g,1,n+1)
      {
            if(n%g!=0)
                  continue;
            int cntFP=calcFixedPoints(g);
            upd(ans,mul(cnt[g],cntFP));
      }
      cout<<mul(ans,binPow(n,MOD-2))<<endl;
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
      if(read())
      {
            solve();
      

      }
      return 0;
       
}