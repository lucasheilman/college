
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
#include"../elapsed_time.h"
#define HASH_DOMAIN_SIZE 257000017

struct Dictionary {
  vector<string> wordArray;   // store the data
  vector<vector<string>* > hashTable;

  Dictionary(const char *filename);  // constructor

  bool inWordArray(string &s);       // single query
  void check(const char *filename);  // multiple queries
  int hash(string& word);

  double timeSuccesses, timeFailures;
};

int Dictionary::hash(string &s) {
  size_t n = s.size();
  int h = 0;
  for(size_t i=0; i < n; i++) {
    h += (int)s[i] << i%8;
  }
  h %= HASH_DOMAIN_SIZE;
  return h;
}

void getWords( const char *filename, vector<string> &vec )
{
  ifstream f(filename);
  if ( ! f.good() ) {
    cerr << "Error:  unable to open " << filename << endl;
    exit(-1);
  }
  string s;
  while ( f >> s ) vec.push_back(s);
}

Dictionary::Dictionary( const char *filename )
{
  getWords(filename, wordArray);
  hashTable.resize(HASH_DOMAIN_SIZE, 0);
  for(auto it = wordArray.begin(); it != wordArray.end(); it++) {
    int h = hash(*it);
    if (hashTable[h] == 0) hashTable[h] = new vector<string>();
    hashTable[hash(*it)]->push_back(*it);
  }

  vector<size_t> stats;
  for(auto it = hashTable.begin(); it != hashTable.end(); it++) {
    vector<string>* row = *it;
    size_t rs;
    if (row == 0) {
      rs = 0;
    } else {
      rs = row->size();
    }
    if (stats.size() < rs+1) {
      stats.resize(rs+1, 0);
    }
    stats[rs]++;
  }

  double sum = 0;
  cout << "Hash table statistics:" << endl;
  cout << "bucket length\t| # of buckets" << endl;
  cout << "-------------\t| ------------" << endl;
  for(size_t i=0; i < stats.size(); i++) {
    cout << i << "\t\t| " << stats[i] << endl;
    sum += stats[i]*i;
  }
  cout << "Average bucket length: " << sum/hashTable.size() << endl << endl;
}

bool Dictionary::inWordArray(string &s)
{
  double et = elapsed_time();
  vector<string>* row = hashTable[hash(s)];
  if (row != 0) {
    int n = row->size();
    for ( int i = 0; i < n; ++i ) {
      if ( s == (*row)[i] ) {
        timeSuccesses += elapsed_time() - et;
        return true;
      }
    }
  }
  timeFailures += elapsed_time() - et;
  return false;
}


void Dictionary::check( const char *filename )
{
  vector<string> query;
  getWords(filename, query);

  start_timer();  // from elapsed_time.h

  int counter = 0, n = query.size();
  for ( int i = 0; i < n; ++i ) {
    if ( ! inWordArray(query[i]) ) {
      // cout << query[i] << " ";
      ++counter;
    }
  }
  cout << "Misspelled " << counter << " words." << endl;

  double cycles = elapsed_time();
  cout << " Total cycles: " << cycles << endl;
  cout << " Words checked: " << n << endl;
  cout << " Cycles/success: " << timeSuccesses/(n-counter) << endl;
  cout << " Cycles/failure: " << timeFailures/counter << endl;
  cout << " Extra time/word: " << (cycles - timeSuccesses - timeFailures)/n << endl;
}

int main(int argc, char **argv)
{
  if ( argc != 3 ) {
    cerr << "Usage: spellCheck dictionaryFile inputFile" << endl;
    exit(0);
  }
  Dictionary d(argv[1]);
  d.check(argv[2]);
}

