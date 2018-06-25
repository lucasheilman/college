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
            c[k] = a[i];
            k++;
            i++;
        }
        else{
            c[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid){
        c[k] = a[i];
        k++;
        i++;
    }
    while (j <= high){
        c[k] = a[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++){
        a[i] = c[i];
    }
}
int main(){
    int a[20];
    int val;
    cout << "Enter a number to see if it's in the array: ";
    cin >> val;
    for(int i = 0; i < 20; i++){
      a[i] = rand()%100;
    }
    mergesort(a, 0, 19);
    cout << "Sorted Array: " << endl;
    cout << "[";
    for(int x = 0; x < (sizeof(a)/4)-1; x++){
	cout << a[x] << ",";
    }
    cout << a[sizeof(a)/4-1] << "]" << endl;
    int index = -1;
    for(int y = 0; y < sizeof(a)/4; y++){
      if(a[y] == val){
	index = y;
      }
    }
    if(index == -1){
      cout << "Value is not in array" << endl;
    }
    else{
      cout << "Index of " << val << " is " << index << endl;
    }
}
