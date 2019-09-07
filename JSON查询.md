# JSON查询

```c++


#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const LL N = 1e5 + 10;
const LL INF = 0x3f3f3f3f;

vector<string> v;
struct node{
	map<string, string > mp1;
	map<string, node*> mp2;
};

void reduce(string &s){
	s.erase(0,1);
	if(s[s.length()-1] == ',' || s[s.length()-1] == ':')
		s.erase(s.length()-2,2);
	else
		s.erase(s.length()-1,1);
	for(int i=0;i<s.length();i++){
		if(s[i] == '\\'){
			s.erase(i,1);
		}
	}
}

void store(node *root){

	while(1){
		string ta,tb,a,b;
		char ra, rb;
		scanf(" %c",&ra);
		while(ra == ',')
			scanf(" %c",&ra);
		
		if(ra == '}'){
			return ;
		}
		a += ra; 
		cin >> ta;
		a += ta;
		
		reduce(a);
		
		cout << " test " << a << endl;
		
		scanf(" %c",&rb);
		b += rb;
		if(rb == '{'){
			node* t = new node;
			root->mp2[a] = t;
			store(t);
		} else {
			cin >> tb;
			b += tb;
			reduce(b);
			root->mp1[a] = b;
		}	
	}
}


void split(string & sam, vector<string>& v, char c){
	v.clear();
	string temp;
	while(!sam.empty()){
		if(sam.find(c) == string::npos){
			v.push_back(sam);
			sam.clear();
			break;
		}
		int id = sam.find(c);
		temp = sam.substr(0,id);
		v.push_back(temp);
		sam.erase(0, id+1);
	}
}

void query(node* root,  int id){
	if(root->mp2.count(v[id])){
		if(id == v.size()-1){
			cout << "OBJECT" << endl;
		} else {
			query(root->mp2[v[id]], id+1);
		}
	} else if( root->mp1.count(v[id]) ){
		if(id == v.size()-1){
			cout << "STRING" << " " << root->mp1[v[id] ] << endl;
		} else {
			cout << "NOTEXIST" << endl;
		}
	} else {
		cout << "NOTEXIST" << endl;
	}
	return ;
}

int main(int argc, char **argv)
{
	string a,b,c;
	int i,j,n,m;
	char w;
	cin >> n >> m;
	scanf(" %c",&w);
	node* root = new node;
	store(root);
	for(i=0;i<m;i++){
		cin >> c;
		split(c, v, '.');
		query(root, 0);	
	}
	return 0; 
}

```