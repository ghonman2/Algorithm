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
typedef vector<ll> vl;

int t = 0;
int n,m;
vl Anumbers;
vl Bnumbers;
vl Anums;
vl Bnums;

void init()
{
	cin >> t;
	cin >> n;
	Anumbers = vl(n,0);
	REP(i,0,n) cin >> Anumbers[i];
	cin >> m;
	Bnumbers = vl(m,0);
	REP(i,0,m) cin >> Bnumbers[i];
}

void search(ll number,int idx)
{
	Anums.push_back(number);
	for(int i = idx + 1;i < n ; i++)
		search(number+Anumbers[i],i);
}


void search2(ll number,int idx)
{
	Bnums.push_back(number);
	for(int i = idx + 1;i < m ; i++)
		search2(number+Bnumbers[i],i);

}


void sol()
{

	map<ll,ll>Adict;
	map<ll,ll>Bdict;

	ll answer = 0 ;
	
	for(int i = 0 ; i < Anumbers.size(); i++){
		ll tmp = 0 ;
		for(int j = i ; j < Anumbers.size();j++){
			tmp += Anumbers[j];
			if(Adict.find(tmp) == Adict.end()) Adict[tmp] = 1;
			else Adict[tmp] += 1;
		}
	}

	for(int i = 0 ; i < Bnumbers.size(); i++){
		ll tmp = 0 ;
		for(int j = i ; j < Bnumbers.size(); j++){
			tmp += Bnumbers[j];
			if(Bdict.find(tmp) == Bdict.end()) Bdict[tmp] = 1;
			else Bdict[tmp] += 1;
		}
	}

	for(auto iter = Adict.begin(); iter != Adict.end(); iter ++){
		if(Bdict.find(t-iter->first) != Bdict.end()){
			answer += Bdict[t-iter->first]*(iter->second);
		}
	}
	cout << answer << "\n";
}


int main(){
	FAST;
	init();
	sol();
	return 0;
}

