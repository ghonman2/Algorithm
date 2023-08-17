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

bitset<20>s;
int n = 0;

void init()
{
	cin >> n;
	s.reset();
}

vector<string> split(string input, char delimiter)
{
	vector<string>ret ;
	stringstream ss(input);
	string tmp;
	while(getline(ss,tmp,delimiter)){
		ret.push_back(tmp);
	}
	return ret;
}
void sol()
{
	while(n--){
		string line;
		int x = 0 ;
		cin >> line;
		if(!line.compare("add")){cin >> x; s.set(x-1,true);}
		else if(!line.compare("check")){ cin >> x; cout << s[x-1] << "\n";}
		else if(!line.compare("remove")) { cin >> x; s.set(x-1,false);}
		else if(!line.compare("toggle")) {cin  >> x; s.flip(x-1);}
		else if(!line.compare("all")) s.set();
		else if(!line.compare("empty")) s.reset();
		else cout << "fuck you" << "\n";
	}
}

int main(){
	FAST;
	init();
	sol();

	return 0;
}

