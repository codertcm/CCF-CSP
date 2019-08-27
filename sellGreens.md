# SellGreens

## code

```c++

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;

const int N = 11000;
const int M = 100000;

char sam[M];
int T,n;

struct Elem {
    char tp;
    int id;
};

int toInt(string a)
{
    int num = 0;
    for(int i=1; i<(int)a.length(); i++) {
        num = num * 10 + a[i]-'0';
    }
    return num;
}

void reduce(char *p, vector<string > &v)
{
    string temp;
    for(int i=0; p[i]; i++) {
        if(p[i] == ' ') {
            v.push_back(temp);
            temp.clear();
        } else {
            temp += p[i];
        }
    }
    v.push_back(temp);
}

int main()
{
    int i,j;
    cin >> T >> n;
    getchar();
    while(T--) {
        queue<Elem> q[N];
        Elem elem[N];
        for(i=0; i<n; i++) {
            vector<string> v;
            cin.getline(sam, M);
            reduce(sam, v);
            for(j=0; j<(int)v.size(); j++) {
                elem[j].tp = v[j][0];
                elem[j].id = toInt(v[j]);
                q[i].push(elem[j]);
            }
        }
        int flag = 0;
        queue<int> need;
        for(i=0; i<n; i++) {
            if(q[i].front().tp == 'S') {
                need.push(i);
            }
        }
        int lim = 0;
        while(!need.empty()) {
            if(lim > (int)need.size())
                break;
            int id_a = need.front();
            need.pop();
            int id_b = q[id_a].front().id;
            if(id_b < 0 || id_b >= n || q[id_b].empty() )
                break;
            if(q[id_b].front().tp != 'R' || q[id_b].front().id != id_a ) {
                need.push(id_a);
                lim++;
            } else {
                q[id_b].pop();
                q[id_a].pop();
                if( !q[id_a].empty() && q[id_a].front().tp == 'S') {
                    need.push(id_a);
                }
                if( !q[id_b].empty() && q[id_b].front().tp == 'S') {
                    need.push(id_b);
                }
                lim-=2;
                if(lim < 0)
                    lim = 0;
            }
        }
        for(i=0; i<n; i++) {
            if(!q[i].empty()) {
                flag = 1;
                break;
            }
        }
        if(flag)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}

```
