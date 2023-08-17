#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
	FAST;
	int n,k ; 
	cin >> n >> k;
	vector<pi>item(n+1);
	int dp[n+1][k+1];
	REP(i,1,n+1){
		int weight,value;
		cin >> weight >> value;
		item[i] = make_pair(weight,value);
	}

	memset(dp,0,sizeof(dp));
	for(int i = 1; i <=  n; i++ ){
		for(int j = 0; j <= k ; j ++){
			if(j - item[i].first >= 0 ){
				dp[i][j] = max(dp[i-1][j],dp[i-1][j-item[i].first] + item[i].second);
			}
			else dp[i][j] = dp[i-1][j];
		}
	}

	cout << dp[n][k] << "\n";
	return 0;
}
