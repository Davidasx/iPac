#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#include <ipacdir.h>
int form;
void init() {
	cout << "-----Configuration-----" << endl;
	cout << "Which format do you like?" << endl;
	cout << "1)Plain format" << endl;
	cout << "  iPac>>" << endl;
	cout << "2)Double line format" << endl;
	cout << "  [iPac]" << endl;
	cout << "  ©¸---->>" << endl;
	cout << "Choice(1/2)" << endl;
	int var = getch();
	if (var == '1')
		form = 1;
	else
		form = 2;
	ofstream fout((ipacdir+"\\ipac.ini").data());
	fout << form << endl;
	fout.close();
	return;
}
int execute(string command) {
	int rval = system(command.data());
	if (!rval)
		return 0;
	else {
		cout << "One or more operations failed." << endl;
		cout << "Press R to retry." << endl;
		cout << "Press any other key to quit." << endl;
		int press = getch();
		if (press == 'R' || press == 'r') {
			cout << "Retrying..." << endl;
			return 2;
		}
		return 1;
	}
}
vector<string> words;
int plug(){
	ifstream fin((ipacdir+"\\ipacplug.ini").data());
	string function,command;
	while(fin>>function){
		fin>>command;
		if(words[0]==function){
			while (execute(command) == 2)
				;
			return 1;
		}
	}
	return 0;
}
void interact() {
	while (1) {
		if (form == 1)
			cout << "  iPac>>";
		else {
			cout << "  [iPac]" << endl;
			cout << "  ©¸---->>";
		}
		words.clear();
		string s;
		getline(cin, s);
		s += " ";
		int lst = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] == ' ') {
				if (i != lst)
					words.push_back(s.substr(lst, i - lst));
				lst = i + 1;
			}
		}
		if (!words.size())
			continue;
		int ok = 1;
		if (words[0] == "install") {
			string command = "cinst";
			for (int j = 1; j < words.size(); j++) {
				command += " ";
				command += words[j];
			}
			while (execute(command) == 2)
				;
			ok = 0;
		}
		if (words[0] == "uninstall") {
			string command = "cuninst";
			for (int j = 1; j < words.size(); j++) {
				command += " ";
				command += words[j];
			}
			while (execute(command) == 2)
				;
			ok = 0;
		}
		if (words[0] == "search") {
			string command = "choco search";
			for (int j = 1; j < words.size(); j++) {
				command += " ";
				command += words[j];
			}
			while (execute(command) == 2)
				;
			ok = 0;
		}
		if (words[0] == "info") {
			string command = "choco info";
			for (int j = 1; j < words.size(); j++) {
				command += " ";
				command += words[j];
			}
			while (execute(command) == 2)
				;
			ok = 0;
		}
		if (words[0] == "list") {
			string command = "clist";
			for (int j = 1; j < words.size(); j++) {
				command += " ";
				command += words[j];
			}
			while (execute(command) == 2)
				;
			ok = 0;
		}
		if (words[0] == "clear" || words[0] == "cls") {
			system("cls");
			ok = 0;
		}
		if (words[0] == "config") {
			init();
			ok = 0;
		}
		if (words[0] == "exit" || words[0] == "quit") {
			exit(0);
		}
		if(plug()) ok=0;
		if (ok)
			cout << "Sorry,command not supported.Please try again." << endl;
	}
}
int main() {
	ifstream fin((ipacdir+"\\ipac.ini").data());
	if (!fin) {
		fin.close();
		cout << "It seems like you're running iPac the first time." << endl;
		cout << "Please configure it first." << endl;
		init();
	} else {
		fin >> form;
		fin.close();
	}
	interact();
	return 0;
}
