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
	int w,k ;
	cin >> w >> k;
	vi build(k,0);
	REP(i,0,k) cin >> build[i];
	vector<pair<int,int>> pi;
	int answer= 0;

	REP(i,1,k){
		int left = *max_element(build.begin(),build.begin()+i);
		int right = *max_element(build.begin()+i,build.end());
		answer += max(0,min(left,right) - build[i]);
	}
	cout << answer << "\n";
	return 0;
}

