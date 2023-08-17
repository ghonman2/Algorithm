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

vector<string>puzzle(6);
map<string,int>dict;
char result = 0;
void init()
{
	REP(i,0,6) cin >> puzzle[i];
	REP(i,0,6){
		if(dict.find(puzzle[i]) == dict.end()) 
			dict[puzzle[i]] = 1;
		else dict[puzzle[i]] += 1;
	}
	sort(puzzle.begin(),puzzle.end());
}

int check(vector<string> list)
{
	map<string,int>set = dict;
	for(int i = 0 ; i < 3; i++){
		string tmp;
		for(int  j = 0 ; j < 3 ; j ++)
			tmp.push_back(list[j][i]);
		int idx = find(puzzle.begin(),puzzle.end(),tmp) - puzzle.begin();
		if(idx == 6) return 0;
		else set[puzzle[idx]] -=1;
		if(set[puzzle[idx]] < 0) return 0;
	}
	return 1;
}

void search(vector<string>list,vector<int>idxs,int idx)
{
	if(idx > 6)return;
	if(result) return;
	if(list.size() == 3)
	{
		if(check(list)){
			REP(i,0,3)cout << list[i] << "\n";
			result = 1;
		}
		return;
	}
	for(int i = 0; i < 6; i++){
		if(i == idx )continue;
		if(find(idxs.begin(),idxs.end(),i) != idxs.end()) continue;
		list.push_back(puzzle[i]);
		idxs.push_back(i);
		search(list,idxs,i+1);
		idxs.pop_back();
		list.pop_back();
	}
}

void sol()
{
	vector<string>list;
	vector<int>idxs;
	for(int i = 0 ; i < 6; i ++){
		list.push_back(puzzle[i]);
		search(list,idxs,i+1);
		list.pop_back();
	}
	if(!result) cout << 0 << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}

