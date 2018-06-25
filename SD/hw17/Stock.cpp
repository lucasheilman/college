#include <iostream>
using namespace std;

/** Information about shares in a publicly held company */
class Stock {
protected:
  char *symbol; /**< identifier in stock market listings */
  float price;   /**< dollars per share */
public:
  Stock(const char *sym, float pr) {
    int len;
    for (len = 0;  sym[len] != '\0';  len++)
      ;
    symbol = new char[len + 1];
    for (int i = 0;  i <= len;  i++)
      symbol[i] = sym[i];
    price = pr;
  }
  Stock(const Stock &st){
    int len;
    for(len=0; st.symbol[len] != '\0'; ++len) ;
    symbol = new char[len+1];
    for(int i=0; i<len+1; ++i) symbol[i] = st.symbol[i];
    price = st.price;
  }
  ~Stock () { delete [] symbol; }
  char *getSymbol() { return symbol; }
  float getPrice() { return price; }
};

int main() {
  Stock s("MSFT", 42.53);
  Stock s2(s);
  cout << s.getSymbol() << " $" << s.getPrice() << endl;
  cout << s2.getSymbol() << " $" << s2.getPrice() << endl;
}
