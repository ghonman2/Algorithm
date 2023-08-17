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


int n = 0 ;

void init(){
	cin >> n ;
	return;
}

void sol(){
	vector<ll> dp(n+1,0);
	dp[0] = 1;
	for(int item = 1 ; item <= 3; item++){
		for(int i = 0 ; i <= n-item ; i ++){
			dp[i+item] += dp[i];
		}
	}
	cout << dp[n] << "\n";
}

int main(){
	int T = 0;
	cin >> T;
	while(T--){
		init();
		sol();
	}
	return 0;
}

