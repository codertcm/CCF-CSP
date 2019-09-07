# crontab

```c++

#include <bits/stdc++.h>
using namespace std;

typedef long long int LL;
const int N = 1010;
const int INF = 0x3f3f3f3f;

int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string monthstr[13] = {"jan", "feb", "mar", "apr", "may", "jun", "jul","aug", "sep","oct","nov", "dec" };
string week[13] = {"sun", "mon", "tue", "wed", "thu", "fri", "sat"};

map<string, string> mp;

int isleap(int year){
	if( (year% 100 != 0 && year % 4 == 0) || year % 400 == 0 )
		return 1;
	return 0;
} 

int calday(int year, int month, int day){
	int to = 0;
	for(int i=1970;i<year;i++){
		if(isleap(i) )
			to += 366;
		else
			to += 365;
	}
	monthday[2] = isleap(year) ? 29 : 28; 
	for(int i=1;i<month;i++){
		to += monthday[i];
	}
	to += day;
	return to;
}

void tolower(string &sample){
	for(int i=0;i<(int)sample.length();i++){
		if(  sample[i] >= 'A' && sample[i] <= 'Z' ){
			sample[i] += 32;
		}
	}
	return ;
}

string myto_string(int a){
	string ans;
	while(a){
		string t;
		t = a % 10 + '0';
		ans = t + ans;
		a /= 10; 
	}
	if(ans.length() == 0)
		ans = "0";
	return ans;
}

void init(){
	for(int i=0;i<12;i++){
		mp[ monthstr[i] ] = myto_string(i+1);
		//cout << monthstr[i] << "  " << myto_string(i+1) << endl;
	}
	for(int i=0;i<7;i++){
		mp[ week[i] ] = myto_string(i);
		//cout << week[i]<< "  " << myto_string(i) << endl;
	}
	//cout << "here" << mp[ monthstr[i] ] << endl;
	return ;
}

void split(string& sample, vector<string>& v , char c){
	v.clear();
	while(!sample.empty()){
		if(sample.find(c) == string::npos){
			v.push_back(sample);
			sample.clear();
			break;
		}
		int id = sample.find(c);
		string temp = sample.substr(0, id);
		v.push_back(temp);
		sample.erase(0, id+1);
	}	
	return ;
}

void replace(string& str, string& from, string& to){
	if(from.empty())
		return ;
	size_t pos = 0;
	while( (pos = str.find(from, pos)) != string::npos){
		str.replace(pos, from.length(), to);
		pos += to.length();
	}
	return ;
}

void toReplace(string &sample){
	for(map<string, string>::iterator mit = mp.begin(); mit != mp.end(); mit++){
		string b = mit->first;
		string c = mit->second;
		replace(sample,b,c);
	}
	return ;
}

int toInt(string a){
	int ans = 0;
	for(int i=0;i<a.length();i++){
		ans = ans * 10 + a[i]-'0';
	}
	return ans;
}

struct Time{
	int year, month, day, hour, minute, week;
	int number[5];
	void to_number(){
		number[0] = minute;
		number[1] = hour;
		number[2] = day;
		number[3] = month;
		number[4] = week;
	} 
	void input(){
		scanf("%4d%2d%2d%2d%2d", &year, &month, &day, &hour, &minute);
		week = ( calday(year, month, day) + 3) % 7;
		to_number();
	}
	void add(){
		minute++;
		if(minute >= 60){
			minute -= 60;
			hour++;
		}
		if(hour >= 24){
			hour -= 24;
			day++;
			week = (week+1) % 7;
		}
		if(isleap(year) )
			monthday[2] = 29;
		else
			monthday[2] = 28;
		if(day > monthday[month]){
			day = 1;
			month++;
		}
		if(month > 12){
			month = 1;
			year++;
		}
		to_number();
	}
	void output(){
		printf("%4d%02d%02d%02d%02d", year, month, day, hour, minute);
	}	
};

struct item{
	vector<pair<int, int> > elem;
	void input(string inp, int id){		
		vector<string > deComma;
		split(inp, deComma, ',');
		for(int i=0; i<(int)deComma.size();i++){
			vector<string >  deMinus;
			split(deComma[i], deMinus, '-');
			if(deMinus.size() == 1){
				if(deMinus[0][0] == '*'){
					elem.push_back( { -1, INF} );
				} else {
					elem.push_back({ toInt(deMinus[0]), toInt(deMinus[0]) } );		
				}
			} else {
				if(toInt(deMinus[0]) > toInt(deMinus[1])) {
					if(id == 3){
						elem.push_back({toInt(deMinus[0]), 12} );
						elem.push_back({1, toInt(deMinus[1])} );	
					} 	
					else if(id == 4){
						elem.push_back({toInt(deMinus[0]), 6} );
						elem.push_back({0, toInt(deMinus[1])} );
					}
				} else{
					elem.push_back({toInt(deMinus[0]), toInt(deMinus[1]) }  );	
				}
			}
		}
	} 
};

struct command{
	string cmd;
	vector<item> options;
	void input(){
		string sample;
		getline(cin, sample);
		//cout << sample << endl;
		//getchar();
		vector<string> deSpace;
		split(sample, deSpace, ' ');
		for(int i=0;i<(int)deSpace.size()-1;i++){
			item t;
			tolower(deSpace[i]);
			toReplace(deSpace[i]);
			t.input(deSpace[i], i);
			//travel(t.elem);
			options.push_back(t);
		}
		cmd = deSpace[deSpace.size()-1 ];
	}
	void output(){
		cout << cmd;
	}
};

int isNotLower(Time a, Time b){
	LL formata = (LL)a.year * 100000000 + a.month * 1000000 + a.day * 10000 + a.hour * 100 + a.minute;
	LL formatb = (LL)b.year * 100000000 + b.month * 1000000 + b.day * 10000 + b.hour * 100 + b.minute;
	if(formata >= formatb)
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	int i,j,k,n;
	cin >> n;
	init();
	Time begin,end;
	command comm[N];
	begin.input();
	end.input();
	getchar();
	for(i=0;i<n;i++){
		comm[i].input();
	}
	while( !isNotLower(begin, end) ){
		
		//begin.output();
		//cout << begin.week << endl;
		for(i=0;i<n;i++){
			for(j=0;j<5;j++){
				for(k=0;k<comm[i].options[j].elem.size();k++){
					if(begin.number[j] >= comm[i].options[j].elem[k].first && begin.number[j] <= comm[i].options[j].elem[k].second){
						//cout << endl << endl << " test " << comm[i].options[j].elem[k].first << "   " << begin.number[j] << "   " <<  comm[i].options[j].elem[k].second << endl;
						break;
					}
				}
				if(k == comm[i].options[j].elem.size())
					break;
			}
			if(j == 5){
				begin.output();
				cout << " ";
				comm[i].output();
				cout << endl;
			}
		}
		begin.add();
	}
    return 0; 
}

```