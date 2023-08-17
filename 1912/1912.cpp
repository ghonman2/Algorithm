
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

vi numbers;
int n = 0 ;

void init()
{
	cin >> n;
	numbers = vi(n,0);
	REP(i,0,n) cin >> numbers[i];
	
}

void sol()
{
	vi dp = vi(n+1,0);
	dp[0] = numbers[0];
	int maxSum = dp[0];
	
	for(int i = 1 ; i < n; i++){
		dp[i] = max(dp[i-1]+numbers[i],numbers[i]);
		if(dp[i] > maxSum)  maxSum = dp[i] ;
	}	
	cout << maxSum << "\n";
}


int main(){
	FAST;
	init();
	sol();

	return 0;
}

