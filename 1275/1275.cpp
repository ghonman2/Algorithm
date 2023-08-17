#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef vector<ll> vl;
vl tree;
int n,q;

ll query(int idx)
{
	ll ans = 0 ;
	while(idx){
		ans += tree[idx];
		idx -= idx & -idx;
	}
	return ans;
}

void update(int idx, ll diff)
{
	while(idx <= n){
		tree[idx] += diff;
		idx += idx & -idx;
	}
}

int main(){
	FAST;
	cin >> n >> q;
	vl numbers(n+1,0);
	tree = vl(n+1,0);
	REP(i,1,n+1) {
		cin >> numbers[i];
		update(i,numbers[i]);
	}
	REP(i,0,q){
		int x,y,a;
		ll b;
		cin >> x >> y >>a >> b;
		ll diff = b - numbers[a];
		numbers[a] = b;
		print(query(y)-query(x-1));
		update(a,diff);
	}
	return 0;
}
