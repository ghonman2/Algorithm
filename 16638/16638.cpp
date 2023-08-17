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

int answer = INT_MIN ;
int  n = 0;
string opers;
vi numbers;
string str;

void init()
{
	cin >> n ;
	cin >> str;
	for(int i = 0 ; i < n; i++)
	{
		if (i % 2)
			opers.push_back(str[i]);
		else 
			numbers.push_back(str[i] - '0');
	}
}

int cal(int a, int b, char op)
{
	int ret = 0;
	if (op == '+')
		ret = a + b;
	else if (op == '-')
		ret = a - b;
	else if (op == '*')
		ret = a*b;
	return ret;
}

void make_postfix()
{
	stack<char>s;
	deque<char>buffer;
	
	for(int i = 0 ; i < n ; i ++)
	{
		if ( i % 2 ==0)
			buffer.push_back(str[i]);
		else
		{
			if(s.empty())
				s.push(str[i]);
			else{
				while(!s.empty() &&s.top() == '*' && str[i] != '*'){
					buffer.push_back(s.top()); s.pop();}
				s.push(str[i]);
			}
		}
	}
	while (!s.empty())
	{
		buffer.push_back(s.top());s.pop();
	}
	stack<int>stack;
	while(!buffer.empty())
	{
		char ch = buffer.front(); buffer.pop_front();
		if (ch == '*' || ch == '+' || ch == '-')
		{
			int s = stack.top(); stack.pop();
			int f = stack.top(); stack.pop();
			stack.push(cal(f,s,ch));
		}
		else
			stack.push(ch - '0');
	}
	cout <<  stack.top() << "\n";
}

void sol()
{
	make_postfix();
	cout << answer << "\n";
}

int main(){
	FAST;
	init();
	sol();
	return 0;
}
