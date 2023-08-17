#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << ( a ) << "\n";
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef vector<ll> vl;

vl number;
int n,m,k;
ll *tree = NULL;
vector<vl>change;
int MAX = 0;

void update(int idx, ll diff)
{
	while(idx <= MAX){
		tree[idx] += diff;
		idx += idx & - idx;
	}
}

ll query(int idx)
{
	ll ans = 0 ;
	while(idx){
		ans += tree[idx];
		idx -= -idx & idx;
	}
	return ans;
}

void init(){
	cin >> n >> m >> k;
	MAX = n+1;
	tree = (ll*)malloc(sizeof(ll)*(MAX));

	memset(tree,0,sizeof(ll)*(MAX));
	number.push_back(0);
	REP(i,1,n+1){
		ll num;
		cin >> num;
		number.push_back(num);
		update(i,num);
	}

	REP(i,0,m+k){
		int a,b;
		ll c = 0;
		cin >> a >> b >> c;
		if(a == 1){
			ll diff = c - number[b];
			update(b,diff);
			number[b] = c;
		}
		else {
			print(query(c)-query(b-1));
		}
	}

}


int main(){
	FAST;
	init();
	return 0;
}
