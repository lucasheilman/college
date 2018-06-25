#include <omp.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <tbb/concurrent_vector.h>

using std::cout;
using std::endl;
using std::vector;

void usage(void)
{
  cout << "sieve <prime max> <thread count>" << endl;
  cout << "<prime max> is upper bound on value of primes found." << endl;
  cout << "<thread count> is the number of threads to use." << endl;
}

void parse_args(int argc, char **argv, int *prime_maxp, int*num_threadsp) {
  if (argc != 3)
    {
      cout << "Invalid number of arguments!" << endl;
      usage();
      exit(0);
    }
  
  *prime_maxp = atoi(argv[1]);
  *num_threadsp = atoi(argv[2]);
  
  if (*prime_maxp < 2)
    {
      cout << "<range> Must be an integer greater than or equal to 2.";
      usage();
      exit(0);
    }
 
    if (*num_threadsp < 1)
    {
      cout << "<thread count> Must be an integer N where 1 <= N <= ";
      usage();
      exit(0);
    }
 
    if (*num_threadsp > omp_get_max_threads())
    {
        *num_threadsp = omp_get_max_threads();
    }
 
    /*
    // Make sure we haven't created too many threads.
    int temp = (*prime_maxp - 1) / *num_threadsp;
    if ((1 + temp) < (int)sqrt((double)*prime_maxp))
    {
        cout << "Too many threads requested!" << endl;
        cout << "The first thread must have a block size >= sqrt(n)." << endl;
        exit(1);
    }
    */
 
}

int main(int argc, char ** argv)
{
  // argv[1]: requested upper-bound on primes.
  // argv[2]: requested number of threads to create.

  int prime_max;  // upper bound on prime values
  int num_threads;  // number of threads to create

  parse_args(argc, argv, &prime_max, &num_threads);
  
  int count = 0;  // Global count of primes found so far
  tbb::concurrent_vector<int> pset0;
  for(int i = 0; i < ceil(sqrt(prime_max));i++){
    for(int a = ceil(sqrt(i)); a > 1; a--){
      if(i % a == 0 && i !=a) break;
      if(a == 2){
        pset0.push_back(i);
      }
    }
  }
    
  // Array marked[].  marked[i] assigned to 1 if i is not prime
  char * marked = (char *)malloc(prime_max + 1);
  marked[0] = 1;
  marked[1] = 1;
  for (int i = 2; i <= prime_max; ++i) 
    marked[i] = 0;
  unsigned a = 0;
  int p = 2;  // holds an integer known to be prime
  
  while(a < pset0.size())
    {
    p = pset0[a];
    int base = p*p;
    for(int m = base; m <= prime_max; m+=p){
      marked[m] = 1;
    }
    a++;
    } 
  
#ifdef KEEP_PRIMES
  tbb::concurrent_vector<int> pset;
#endif /* KEEP_PRIMES */
  for (int i = 2; i <= prime_max; ++i)
    {
      if (marked[i] == 0) {
#ifdef KEEP_PRIMES
	pset.push_back(i);
#endif /* KEEP_PRIMES */
	count++;
      }
    }
  
  free(marked);
      

  // Print the results 
  cout << count << " primes are less than or equal to " << prime_max << endl;

#ifdef KEEP_PRIMES
  cout << "First few:  "; // (up to 20 primes)
  int i = 0;
  while (i < 19 && i < count-1)
    cout << pset[i++] << ", ";
  cout << pset[i] << endl;
#endif /* KEEP_PRIMES */

  return 0;
}
