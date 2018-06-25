#include <iostream>
using namespace std;
#include <cstdlib>

void merge(int *,int, int , int );
void mergesort(int *a, int low, int high){
    int mid;
    if (low < high){
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,high,mid);
    }
    return;
}
void merge(int *a, int low, int high, int mid){
    int i, j, k, c[50];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high){
        if (a[i] < a[j]){
	  //if(a[i] != c[k-1]){
            c[k] = a[i];
	    //}
            k++;
            i++;
        }
        else{
	  //if(a[j] != c[k-1]){
            c[k] = a[j];
	    //}
            k++;
            j++;
        }
    }
    while (i <= mid){
      //if(a[i] != c[k-1]){
        c[k] = a[i];
	// }
        k++;
        i++;
    }
    while (j <= high){
      //if(a[j] != c[k-1]){
        c[k] = a[j];
	//}
        k++;
        j++;
    }
    for (i = low; i < k; i++){
        a[i] = c[i];
    }
}
int main(){
    int a[20];
    for(int i = 0; i < 20; i++){
      a[i] = rand()%100;
    }
    mergesort(a, 0, 19);
    //cout << "[";
    //for(int x = 0; x < (sizeof(a)/4)-1; x++){
    //  cout << a[x] << ",";
    // }
    // cout << a[sizeof(a)/4-1] << "]" << endl;
    // int a[20];
    // for(int i = 0; i < 20; i++){
    //   a[i] = rand()%100;
    //  }
    int b[sizeof(a)/4];
    int summ = 0;
    b[0] = a[0];
    for(int j = 1; j < sizeof(a)/4; j++){
      if(a[j] != b[j-1-summ]){
	b[j-summ] = a[j];
      }
      else{
	summ = summ + 1;
      }
    }
    cout << "[";
    for(int x = 0; x < (sizeof(b)/4)-1-summ; x++){
	cout << b[x] << ",";
    }
    cout << b[sizeof(b)/4-summ-1] << "]" << endl;
}
