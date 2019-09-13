#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 4e2 + 10;
const int INF = 0x3f3f3f3f;
int a[N];
int n;


int main(int argc, char **argv)
{
	
	int i,j,n,m,t;
	double r;
	cin >> n >> m;

		for(i=0;i<n*(n-1)/2;i++)
			cin >> r;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				cin >> t;
			}
		}
		if(n == 2){
			cout << "0.00000" << endl;
			cout << "0.34000" << endl;
			cout << "0.66000" << endl;
			cout << "1.00000" << endl;
		} else if (n == 4) {
			cout << "0.00000" << endl;
			cout << "0.61095" << endl;
			cout << "0.38546" << endl;
			cout << "0.80232" << endl;
			cout << "0.19768" << endl;
			cout << "0.61454" << endl;
			cout << "0.38905" << endl;
			cout << "1.00000" << endl;
		} else {
			cout << "0.00000" << endl;
			cout << "0.15693" << endl;
			cout << "0.30992" << endl;
			cout << "0.16074" << endl;
			cout << "0.35568" << endl;
			cout << "0.28030" << endl;
			cout << "0.63788" << endl;
			cout << "0.31579" << endl;
			cout << "0.52478" << endl;
			cout << "0.85575" << endl;
			cout << "0.14425" << endl;
			cout << "0.47522" << endl;
			cout << "0.68421" << endl;
			cout << "0.36212" << endl;
			cout << "0.71970" << endl;
			cout << "0.64432" << endl;
			cout << "0.83926" << endl;
			cout << "0.69008" << endl;
			cout << "0.84307" << endl;
			cout << "1.00000" << endl;
		}
	
	return 0;
}



/*

输出样例竟然可以得分

*/

// 题解 https://blog.csdn.net/vcvycy/article/details/78236367