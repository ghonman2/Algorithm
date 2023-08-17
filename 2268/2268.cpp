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

int n,m;
vector<ll>tree;

void modify(ll idx, ll num)
{
    idx += n;
    tree[idx] = num;

    for(idx /= 2 ; idx >= 1 ; idx /= 2)
        tree[idx] = tree[2*idx+1] + tree[2*idx];

}

ll add(ll a, ll b)
{
    ll ans = 0;
    a += n, b += n;
    while(a <= b){
        if(a % 2 == 1) ans += tree[a++];
        if(b % 2 == 0) ans += tree[b--];
        a /= 2, b/= 2;
    }

    return ans;
}

/*
ll query(ll idx)
{
	ll ans = 0 ; 
	while(idx){
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void mod(ll idx, ll diff)
{
	while(idx <= n ){
		tree[idx] += diff;
		idx += idx & -idx;
	}
}
*/
int main(){
    FAST;
    cin >> n >> m;
    tree = vector<ll>(2*n,0);
	for(ll i = 0 ; i < m ; i++){
        ll cmd,idx,num;
        cin >> cmd >> idx >> num;
		if(cmd){
			modify(idx,num);
		}
		else {
			ll a = idx ,b = num;
			if(a>b){
				ll tmp = a;
				a = b;
				b = tmp;
			}
			print(add(a,b));
		}
	}
    return 0;
}

