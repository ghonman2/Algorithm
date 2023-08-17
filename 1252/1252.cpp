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

string s1;
string s2;
void init()
{
	cin >> s1 >> s2;
	while(s1.length() < s2.length())
		s1.insert(0,"0");
	while(s1.length() > s2.length())
		s2.insert(0,"0");
}

void sol()
{
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	string ret;
	char z = 0, c = 0;
	int cnt = 0;
	while (cnt < (int)s1.length())
	{
		char x,y;
		x = s1[cnt] - '0';
		y = s2[cnt] - '0';
		c = (x ^ y ^ z) + '0';
		z = (x&y) | (x&z) | (y&z);
		ret += c;
		cnt ++;
	}
	if (z == 1)
		ret += '1';
	reverse(ret.begin(),ret.end());
	while(ret != "0" && ret[0] == '0')
		ret.erase(ret.begin(), ret.begin()+1);
	cout << ret << "\n";

}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

