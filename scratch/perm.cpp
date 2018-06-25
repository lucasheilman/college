#include <iostream>
#include <string>
using namespace std;

bool perm(string str1, string str2){
	if(str1.length() != str2.length()){
		return false;
	}
	size_t found;
	int count = 0;
	for(int i = 0;i < str1.length(); i++){
		found = str2.find(str1[i]);
		if(found != string::npos){
			str2.erase(found,1);
			count = count + 1;
		}
	}
	if(count == str1.length()){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	string str1 = "banana";
	string str2 = "nnaaab";
	cout << perm(str1,str2) << endl;
	str1 = "taco";
	str2 = "taco";
	cout << perm(str1,str2) << endl;
	str1 = "fan";
	str2 = "no";
	cout << perm(str1,str2) << endl;
}
