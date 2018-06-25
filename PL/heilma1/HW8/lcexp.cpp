#include <iostream>
#include <string>
using namespace std;

struct lcexp{
  string identifier;
  lcexp* lcexp1;
  lcexp* lcexp2;
  lcexp(string id)
  {
    identifier = id;
    lcexp1 = NULL;
    lcexp2 = NULL;
  }
  lcexp(string id, lcexp* lc1)
  {
    identifier = id;
    lcexp1 = lc1;
    lcexp2 = NULL;
  }
  lcexp(lcexp* lc1, lcexp* lc2)
  {
    identifier = "";
    lcexp1 = lc1;
    lcexp2 = lc2;
  }
  bool isvar()
  {
    return ((identifier != "") && (lcexp1 == NULL) && (lcexp2 == NULL));
  }
  bool islambda()
  {
    return ((identifier != "") && (lcexp1 != NULL) && (lcexp2 == NULL));
  }
  bool isapp()
  {
    return ((identifier == "") && (lcexp1 != NULL) && (lcexp2 != NULL));
  }
  string varexp_var()
  {
    return identifier;
  }
  string lambdaexp_boundvar()
  {
    return identifier;
  }
  lcexp* lambdaexp_body()
  {
    return lcexp1;
  }
  lcexp* appexp_rator()
  {
    return lcexp1;
  }
  lcexp* appexp_rand()
  {
    return lcexp2;
  }
};

bool occursfree(string searchvar, lcexp* exp)
{
  if(exp->isvar())
    {
      if(exp->varexp_var() == searchvar)
	{
	  return false;
	}
      else
	{
	  return true;
	}
    }
  else if(exp->islambda())
    {
      if(exp->lambdaexp_boundvar() == searchvar)
	{
	  return false;
	}
      else
	{
	return (true && occursfree(searchvar, exp->lambdaexp_body()));
	}
    }
  else if(exp->isapp())
    {
      return (true && occursfree(searchvar, exp->appexp_rand()) && occursfree(searchvar, exp->appexp_rator()));
    }
}

int main()
{
  lcexp a = lcexp("a");
  lcexp b = lcexp("b",&a);
  lcexp c = lcexp(&a,&b);
  cout << "from occurs, should be 0: " << occursfree("a",&c) << endl;
  cout << "from occurs, should be 1: " << occursfree("c",&c) << endl;
}
