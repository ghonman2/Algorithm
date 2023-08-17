#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;



int valid(vi enters, ll idx)
{
	ll ret = 0 ;
	for (ll i = 0 ; i < enters.size(); i ++){
		ret += idx / enters[i];
	}
	return ret ;
}

int main(){
	FAST;
	ll n , m = 0 ;
	cin >> n >> m;
	vi enters;
	for(ll i = 0 ; i < n; i ++){
		ll ent;
		cin >> ent;
		enters.push_back(ent);
	}

	ll answer = -1;
	ll b = *max_element(enters.begin(),enters.end())*m;
	for(; b >= 1 ; b /= 2){
		while(valid(enters,answer+b) < m) answer+=b;
	}
	cout <<( answer + 1) <<"\n";
	return 0;
}
