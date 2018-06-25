# include <iostream>
#include <fstream>
# include <vector>
# include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <bits/stdc++.h>
#include <map>
using namespace std;


string code="x";

struct Tuple{
	pair<char,int> tup;
	Tuple(char a, int b){
		tup=make_pair(a,b);
	}
	bool operator==(const Tuple &other){
		if(this->tup.first==other.tup.first && this->tup.second==other.tup.second) return true;
		return false;
	}
	char first(){
		return tup.first;
	}
	int second(){
		return tup.second;

	}

	

};



class Compare{
	public: 
		bool operator()(const Tuple a, const Tuple b) const{
			return (a.tup.second>b.tup.second);
		}
};

ostream &operator<<(ostream & os, Tuple t){
	os<<t.tup.first<<" "<<t.tup.second;
}


Tuple combine(Tuple a, Tuple b){
	Tuple c('!',a.tup.second+b.tup.second);
	return c;
}


int countfreq(char c, string s){
	int count=0;
	for(int i=0;i<s.size();i++){
		if(s[i]==c) count++;
	}
	return count;
}


vector<Tuple> createtuples(string s){
	vector<Tuple> newvec;
	for(int i=0;i<s.size();i++){
		Tuple t(s[i], countfreq(s[i], s));
		if(find(newvec.begin(), newvec.end(),t)!=newvec.end()){
			continue;
		}else if(t.first()==' '){
			continue;
		}else{
			newvec.push_back(t);
		}
	}
	return newvec;
}


int leftchild(int lindex){
	return 2*lindex;

}

int rightchild(int rindex){
	return 2*rindex+1;
}
vector<Tuple> huffman(vector<Tuple> t){
	vector<Tuple> arranged;
	int counter=t.size();
	priority_queue<Tuple, vector<Tuple>, Compare> pq;
	for(int i=0;i<t.size();i++){
		pq.push(t[i]);
	}
	while(!pq.empty() && counter>1){
		Tuple top1=pq.top();
		pq.pop();
		Tuple top2=pq.top();
		pq.pop();
		Tuple combined=combine(top1,top2);
		pq.push(combined);
		arranged.insert(arranged.begin(),top1);
		arranged.insert(arranged.begin(),top2);
		counter--;

	}
	
	Tuple root =combine(arranged[0], arranged[1]);
	cout<<"Tree is"<<endl;
	arranged.insert(arranged.begin(),root);
	Tuple null('/',0);
	arranged.insert(arranged.begin(),null);
	for(int i=0;i<arranged.size();i++){
		cout<<arranged[i]<<endl;
	}
	return arranged;
}

vector<Tuple> encode(vector<Tuple> v){
	vector<Tuple> encoded;
	int i=1;

	cout<<"----------------------------------------------"<<endl;
	while(leftchild(i)<v.size() && rightchild(i)<v.size()){
		cout<<v[leftchild(i)]<<endl;
		cout<<v[rightchild(i)]<<endl;
		cout<<v[leftchild(leftchild(i))]<<endl;
		i++;

	}
	cout<<"----------------------------------------------"<<endl;
	
	return encoded;

}
bool isrange(char c){
	if (c>='a' and c<='z') return true;
	return false;
}
//string leftstr="0";
//string rightstr="1";

void printall(int val, vector<Tuple> t, string val2){

	
	Tuple left=t[leftchild(val)];
	Tuple right=t[rightchild(val)];
	cout<<"Left child is"<<left<<"Right Child is"<<right<<endl;
	if (leftchild(val)<=t.size() && rightchild(val)<=t.size() ){
		
		if (isrange(t[leftchild(val)].first())){
			val2.erase(val2.end()-1, val2.end());
			val2=val2+"0";
			cout<<"Code of "<<t[leftchild(val)]<<"is "<<val2<<endl;

		}else{
			cout<<"Left child called"<<endl;
			printall(leftchild(val), t, val2+"0");	
		}
		
		if (isrange(t[rightchild(val)].first())){
			val2.erase(val2.end()-1, val2.end());
			val2=val2+"1";
			cout<<"Code of "<<t[rightchild(val)]<<"is "<<val2<<endl;
		}else{
			cout<<"Right child called"<<endl;
			printall(rightchild(val),t, val2+"1");
		}		
	}
}




int main(){
	Tuple t(2,3);
	
	cout<<t;
	string phrase;
	cout<<"Enter the phrase to be encoded"<<endl;
	getline(cin, phrase);
	vector<Tuple> v;
	v=createtuples(phrase);
	vector<Tuple> arranged=huffman(v);
	//encode(arranged);
	string s1="1001";
	s1.erase(s1.end()-1, s1.end());
	cout<<s1<<endl;
	

	
	printall(1,arranged,"0");
	
	
	
}