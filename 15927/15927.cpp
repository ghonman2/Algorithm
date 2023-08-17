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

string s;
vector<vi>dp;
void init()
{
	cin >> s;
	return;
}

int answer = 1;

void sol()
{
	stack<pair<int,int>>q;
	int left = 0 ,right = s.length()-1 ;
	q.push({left,right});
	while(!q.empty()){
		tie(left,right) = q.top(); q.pop();
		if(s[left] != s[right]) {answer = right-left + 1; break;}
		else {q.push({left,right-1}); q.push({left+1,right});}
	}
	if(answer <= 1){
		cout << -1 << "\n";
	}else cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();

	return 0;
}

