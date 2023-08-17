#include <bits/stdc++.h>
#define REP(i,a,b) for ( int i = a ; i < b ; i ++)

using namespace std;
typedef long long ll;
typedef unsigned long long u64;
typedef unsigned int u32;
typedef vector<int> vi;
int INF = INT_MAX;



int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n = 0 ; 
	cin >> n ;
	pair<int,int>lines[100000];
	REP(i,0,n){
		int x,y;
		cin >> x >> y ;
		lines[i].first = x; lines[i].second = y;
	}
	sort(lines,lines+n);
	int answer = 0 ;
	int r = -INF, l = -INF; 
	
	REP(i,0,n){
		if(lines[i].first < r){
			r = max(lines[i].second,r);
		}
		else {
			answer += r-l;
			l = lines[i].first;
			r = lines[i].second;
		}
	}
	answer += r-l;
	cout << answer << "\n";

	return 0;
}
