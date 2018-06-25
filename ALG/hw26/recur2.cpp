#include <iostream>
#include <vector>
using namespace std;

int F(int num){
  if(num <= 0){
    return num;
  }
  else
    return F(num - 2) + F(num - 4) + F(num - 6);
}


/*Problem with n = 10
 * 10   8       6       4       2       0       -2      -4
 * 1    1       2       4       7       13      11      7
 * solve recursively from num subtracting 2 until num = -2
 * by adding the three values before it together to get its value
 * to find -2 then add the two values together before the last value
 * to find -4 find the 3rd to last value
 */

//This function computes F1 value much quicker
int F2(int num){
  vector <int> nums;
  nums.push_back(1);
  nums.push_back(1);
  nums.push_back(2);
  num -= 6;
  while(num != -2){
    nums.push_back(nums[nums.size() -1] +
		   nums[nums.size()-2] +
		   nums[nums.size()-3]);
    num -= 2;
  }
  nums.push_back(nums[nums.size()-2] + nums[nums.size()-3]);
  nums.push_back(nums[nums.size()-3]);

  int total;
  total += nums.back() * -4;
  total += nums[nums.size() -2] * -2;
  return total;
}

int main(){
  int n=1;
  cout << "num: ";
  cin >> n;
  cout << endl;
  cout << n << endl << F2(n) << endl;

  return 0;
}
