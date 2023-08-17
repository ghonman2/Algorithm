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


int main(){
	FAST;
	string word;
	cin >> word;
	ll dp[word.length()+1];	
	memset(dp,0,word.length()+1);
	dp[1] = 1;
	for(int i = 2 ; i <= word.length(); i++){
		dp[i] = dp[i-1] + 1;
		char num[2];
		num[0] = word[i-1];
		num[1] = word[i];
		if(atoi(num) < 27) dp[i] += 1;
		dp[i] %= 1000000;
	}
	REP(i,0,word.size()+1) cout << dp[i] << " ";
	cout << "\n";
	cout << dp[word.length()] << "\n";
	return 0;
}

