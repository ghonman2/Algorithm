#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)
#define FAST cin.tie(NULL);cout.tie(NULL); ios::sync_with_stdio(false)
#define print(a) cout << a << "\n";
#define vprint(a) REP(i,0,a.size()) cout << a[i] << " "; cout << "\n";

#define MAX 502

using namespace std;

typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;


int main(){
	FAST;
	string dna;
	cin >> dna;
	vi(dna.size()+1,0);
	int dp[502][502];
	memset(dp,0,sizeof(dp));

	return 0;
}

