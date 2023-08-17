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

int l,c ;
string s;
string check = "aeiou";
int cmp(char a, char b){return a < b;}
void init()
{
	cin >> l >> c;
	s = string(c,0);
	REP(i,0,c) cin >> s[i];
	sort(s.begin(),s.end(),cmp);
}

void search(string subs, int idx,int nr_za, int nr_mo)
{
	if (subs.length() == l){
		if(nr_za >= 2 && nr_mo >= 1) cout << subs << "\n";
		return;
	}
	for(int i = idx ; i < c; i ++){
		if(subs.find(s[i]) != string :: npos)continue;
		int d_za = 0 ;
		int d_mo = 0;
		if(check.find(s[i]) != string :: npos) d_mo = 1;
		else d_za = 1;
		search(subs + s.substr(i,1), i+1,nr_za + d_za,nr_mo +d_mo);
	}

}

void sol()
{
	string subs;
	search(subs,0,0,0);
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

