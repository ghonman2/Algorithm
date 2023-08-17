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

vector<pair<int,int>>lines;
int n= 0 ;
vi dp(501,0);
int cmp(pair<int,int>a, pair<int,int>b)
{
	if(a.first == b.first) return a.second > b.second;
	else return a.first > b.first;
}

void init()
{
	cin >> n;
	REP(i,0,n){
		int a = 0, b = 0 ;
		cin >> a >> b;
		lines.push_back({a,b});
	}
	sort(lines.begin(),lines.end());
}

void sol()
{
	vi list;
	for(auto line : lines){
		int dst = line.second;
		if(list.empty() || list.back() < dst) list.push_back(dst);
		else{ 
			int idx  = lower_bound(list.begin(),list.end(),dst) - list.begin();
			list[idx] = dst;
		}
	}
	cout << n-list.size() << "\n";
}


int main(){
	FAST;
	init();
	sol();
	//REP(i,0,n)cout << lines[i].first <<" " << lines[i].second << "| ";
	//cout << "\n";

	return 0;
}

