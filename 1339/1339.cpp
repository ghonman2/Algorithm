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

vector<string> words;
int n;

void init()
{
	cin  >> n;
	words= vector<string>(n);
	REP(i,0,n)cin >>words[i];
}

int cmp(pair<char,int> &a, pair<char,int>&b)
{
	return a.second > b.second;
}

void sol()
{
	map<char,int>dict;
	
	for(int i = 0 ; i < n; i ++){
		string word = words[i];
		int power = word.length()-1;
		for(int k = 0 ; k < word.size() ; k++){
			if(dict.find(word[k]) == dict.end()){
				dict[word[k]] = (int)pow(10,power);
			}else {
				dict[word[k]] += (int)pow(10,power);
			}
			power -= 1;
		}
	}

	vector<pair<char,int>>v(dict.begin(),dict.end());
	sort(v.begin(),v.end(),cmp);
	int mul = 9;
	int answer= 0 ;
	for(auto i : v){
		answer += mul*i.second;
		mul -=1;
	}
	cout << answer <<"\n";
}



int main(){
	FAST;
	init();
	sol();
	return 0;
}

