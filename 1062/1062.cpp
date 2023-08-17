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

int n,k ;
vector<string> words;
bool alpha[26];
void init()
{
	cin >> n >> k ;
	REP(i,0,n){
		string word;
		cin >> word;
		words.push_back(word);
	}
	memset(alpha,0,sizeof(alpha));
}

int canRead()
{
	int ret = 0 ; 
	for(auto word : words){
		bool isRead = true;
		for (char ch : word){
			if(alpha[ch-'a'] == false){
				isRead = false;
				break;
			}
		}
		if(isRead) {ret ++;}
	}
	return ret;
}
int answer  = 0; 
void dfs(int idx ,int cnt)
{
	if(cnt == k ){
		answer = max(answer,canRead());
		return;
	}

	for(int i= idx; i < 26; i++){
		if(alpha[i] == true) continue;
		alpha[i] = true;
		dfs(i, cnt+1);
		alpha[i] = false;
	}
}

void sol()
{
	alpha['a' - 'a'] = true;
	alpha['n'-'a'] = true;
	alpha['t'- 'a'] = true;
	alpha['i' - 'a'] = true;
	alpha['c' - 'a'] = true;
	k -= 5;
	if(k >= 0)
		dfs(0,0);
}

int main(){
	FAST;
	init();
	sol();
	cout << answer << "\n";
	return 0;
}

