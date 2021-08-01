#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t="";
	ifstream fin("info.txt");
	getline(fin,s);
	fin.close();
	cout<<s<<endl;
	for(int i=0;i<s.size();i++){
		if(s[i]=='\\') t+="\\\\";
		else t+=s[i];
	} 
	ofstream fout("ipacdir.h");
	fout<<"string ipacdir=\""<<t<<"\";"<<endl;
	fout.close();
	return 0;
}

