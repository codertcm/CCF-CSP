
#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 4e2 + 10;
const int INF = 0x3f3f3f3f;

struct auth{
	string a;
	int level;
};

map<string, int> ath;

map<string, vector<auth> > role;

map<string, vector<string> > user;

void input(auth& a, string t){
	size_t id;
	if( (id = t.find(':') )!= string::npos){
		a.a = t.substr(0, id);
		a.level = t[ t.length()-1 ] - '0';
	} else {
		a.a = t;
		a.level = -1;
	}
}

int main(int argc, char **argv)
{
	int i,j,n,m,k,q;
	string ta,tb;
	auth temp;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> ta;
		input(temp, ta);
		ath[temp.a] = temp.level;
	}
	cin >> m;
	for(i=0;i<m;i++){
		cin >> ta;
		cin >> q;
		for(j=0;j<q;j++){
			cin >> tb;
			input(temp,tb);
			role[ta].push_back(temp);	
		}
	}
	cin >> k;
	for(i=0;i<k;i++){
		cin >> ta;
		cin >> q;
		for(j=0;j<q;j++){
			cin >> tb;
			user[ta].push_back(tb);
		}
	}
	cin >> q;
	while(q--){
		cin >> ta >> tb;
		input(temp, tb);
		
		if(user.count(ta) == 0 ){
			cout << "false" << endl;
		} else if(ath.count(temp.a) == 0 ){
			cout << "false" << endl;
		} else {
			
			string flag = "false";
			int ans = -1;
			for(i=0;i<user[ta].size();i++){
				
				tb = user[ta][i];
				//if(role.count(tb) == 0) 多余判断
				//	break;
				for(j=0;j<role[tb].size();j++){
					if(temp.a == role[tb][j].a && temp.level <= role[tb][j].level){
						flag = "true";
						ans = max(ans, role[tb][j].level);
					}
				}
			}
			if(temp.level == -1){
				if(ans != -1)
					cout << ans << endl;
				else
					cout << flag << endl;
			} else {
				cout << flag << endl;
			}
		}
	}
	return 0;
}

/*

我TM多写了个判断

*/