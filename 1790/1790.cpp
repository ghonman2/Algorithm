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

ll n,k;


void init()
{
	cin >> n >> k;
}

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16


ll valid(ll x)
{
	ll ret = 0 ; 
	ll k = 1;
	ll i = 10 ;
	for(; i <= x;  k++, i*= 10)ret += (i-i/10)*k;
	ret += k*(1+x-i/10);
	return ret;
}

void sol()
{
	ll h = (n + 1)/ 2;
	ll x = 0 ;
	for(; h >= 1; h /=2){
		while(valid(x+h) <= k) x += h;
	}
	if (x > n )cout << "-1\n";
	else cout << to_string(x).back() << "\n";
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}
