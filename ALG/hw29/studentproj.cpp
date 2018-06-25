#include <iostream>
#include <algorithm>
#include <vector>
#include "math.h"
using namespace std;

vector < vector <int> > visited;
vector <int> maxVec (5,1);
long double maxTotal;

void checkMax(vector <int> curVec){
  long double total = 0;
  bool overOne = false;
  total += curVec[0]/21.0;
  if(curVec[0]/21.0 > 1.0){
    overOne = true;
  }
  total += pow(curVec[1], 2)/450.0;
  if(pow(curVec[1], 2)/450.0 > 1.0){
    overOne = true;
  }
  total += sqrt(curVec[2])/sqrt(21);
  if(sqrt(curVec[2])/sqrt(21) > 1.0){
    overOne = true;
  }
  total += .5*log2(curVec[3]);
  if(.5*log2(curVec[3]) > 1.0){
    overOne = true;
  }
  total += pow(1.2,curVec[4])/50.0;
  if(pow(1.2,curVec[4])/50.0 > 1.0){
    overOne = true;
  }
  if(total > maxTotal && ! overOne){
    cout << maxTotal/5.0 << endl;
    maxTotal = total;
    for(int i = 0; i < 5; ++i){
      maxVec[i] = curVec[i];
    }
  }
}

bool isVisited(vector <int> curVec){
  for(int x = 0; x < visited.size(); ++x){
    if(std::equal(curVec.begin(),curVec.end(),visited[x].begin())){
      return true;
    }
  }
  return false;

}

void probs(vector <int> curVec){
  int count = 0;
  for(int i = 0; i < 5; ++i){
    count += curVec[i];
  }
  if(count == 21){
    checkMax(curVec);
  }
  else{
    curVec[0] += 1;
    if(! isVisited(curVec)){
      visited.push_back(curVec);
      probs(curVec);
    }
    curVec[0] -= 1;
    curVec[1] += 1;
    if(! isVisited(curVec)){
      visited.push_back(curVec);
      probs(curVec);
    }
    curVec[1] -= 1;
    curVec[2] += 1;
    if(! isVisited(curVec)){
      visited.push_back(curVec);
      probs(curVec);
    }
    curVec[2] -= 1;
    curVec[3] += 1;
    if(! isVisited(curVec)){
      visited.push_back(curVec);
      probs(curVec);
    }
    curVec[3] -= 1;
    curVec[4] += 1;
    if(! isVisited(curVec)){
      visited.push_back(curVec);
      probs(curVec);
    }
    curVec[4] -= 1;
  }
}


int main(){
  vector <int> curVec (5,1);
  visited.push_back(curVec);
  cout << "Loading..." << endl;
  probs(curVec);
  cout <<endl;
  float prob = maxTotal/5.0;
  cout << "Combined probability of the problems: " 
       << maxTotal << ", probability of completing every problem: " << prob << endl;
	
  cout << "Number of students for Alg1: " <<  maxVec[0] << endl;
  cout << "Probability for Alg1: ";	
  cout << (maxVec[0]/21.0) << endl << endl;
  cout << "Number of students for Alg2: " <<  maxVec[1] << endl;
  cout << "Probability for Alg2: ";	
  cout << pow(maxVec[1], 2)/450.0 << endl << endl;
  cout << "Number of students for Alg3: " <<  maxVec[2] << endl;
  cout << "Probability for Alg3: ";	
  cout << sqrt(maxVec[2])/sqrt(21.0) << endl << endl;
  cout << "Number of students for Alg4: " <<  maxVec[3] << endl;
  cout << "Probability for Alg4: ";	
  cout << .5*log2(maxVec[3]) << endl << endl;
  cout << "Number of students for Alg5: " <<  maxVec[4] << endl;
  cout << "Probability for Alg5: ";	
  cout << pow(1.2,maxVec[4])/50.0 << endl << endl;
  cout << endl;
  return 0;
}
