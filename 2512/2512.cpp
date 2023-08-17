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

int n;
ll m;
vector<ll> budgets;
vector<ll>dp;
ll max_budget;
void init()
{
	cin >> n ;
	budgets = vector<ll>(n,0);
	REP(i,0,n)cin >> budgets[i];
	cin >> m;
}

ll sum(ll lower)
{
	ll ret = 0;
	if(lower > max_budget)return LLONG_MAX;
	for(auto budget : budgets){
		if(budget > lower)
			ret += lower;
		else 
			ret += budget;
	}
	return ret;
}

void sol()
{
	max_budget = *max_element(budgets.begin(),budgets.end());
	ll x = 0;
	for(ll h = max_budget/ 2; h > 0 ; h /= 2){
		while(sum(x+h) <=  m) x += h;
	}
	cout << x<< "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

