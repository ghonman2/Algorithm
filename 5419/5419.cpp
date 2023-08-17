#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef pair<ll,ll> pi;

bool cmp(pi a, pi b){
	if(a.first == b.first) return a.second > b.second;
	else return a.first < b.first;
}

void sol(){
	int n = 0;
	cin >> n ;
	pi winds[n];
	REP(i,0,n){
		ll x,y;
		cin >> x >> y;
		winds[i].first = x ;
		winds[i].second = y;
	}
	cout  << "\n";
	sort(winds,winds+n,cmp);
	REP(i,0,n){
		cout << winds[i].first << " " << winds[i].second << "\n";
	}

}



int main(){
	FAST;

	int t = 0 ,T = 0;
	cin >> T ;
	while (t++ < T){
		sol();
	}
	return 0;
}
