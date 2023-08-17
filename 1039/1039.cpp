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

void swap(char *a, char *b){
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

char n[1000001];
int  k = 0;

void init()
{
	cin >> n >> k;
	n[strlen(n)] = '\0';
}
int answer = -1;
set<string> check[11];
void dfs(char *str, int idx)
{
	if(idx == k){
		answer = max(answer,atoi(str));
		return;
	}
	for(int i = 0 ; i < strlen(str); i++){
		for(int j = i + 1; j < strlen(str); j++){
			if(i == 0 && str[j] == '0') continue;
			swap(str+i,str+j);
			if(!check[idx].count(str)){
				check[idx].insert(str);
				dfs(str,idx+1);
			}
			swap(str+i,str+j);
		}
	}
}

void sol()
{
	dfs(n,0);
	if(answer < 0) cout <<  answer << "\n";
	else cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

