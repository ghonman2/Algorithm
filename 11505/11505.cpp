#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;

int n,k,m;
vector<ll>tree;

void modify(ll idx, ll num)
{
    idx += n;
    tree[idx] = num;

    for(idx /= 2 ; idx >= 1 ; idx /= 2)
        tree[idx] = (tree[2*idx+1] * tree[2*idx]) %1000000007;

}

ll add(ll a, ll b)
{
    ll ans = 1;
    a += n, b += n;
    while(a <= b){
        if(a % 2 == 1) ans *= tree[a++];
        if(b % 2 == 0) ans *= tree[b--];
        a /= 2, b/= 2;
    }

    return ans % 1000000007;
}

int main(){
    FAST;
    cin >> n >> m>>k;
    tree = vector<ll>(2*n+1,1);
    REP(i,1,n+1){
		ll num;
		cin >> num;
		modify(i,num);
    }
	REP(i,0,m+k){
        ll cmd,idx,num;
        cin >> cmd >> idx >> num;
        if(cmd == 1){
            modify(idx,num);
        }
        else {
            ll b = min(idx,num), c = max(idx,num);
            print(add(b,c)%1000000007);
        }
    }
    return 0;
}
