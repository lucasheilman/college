#include <iostream>
#include <vector>
using namespace std;

bool pop(vector <int> &vec)
{
    int max;
    int select;
    for(int j = 0; j < vec.size(); j++){
        if(vec[j] > max){
            max = vec[j];
        }
    }
    for(int i = vec.size()-1; i >= 0; i--){
        if(vec[i] == max){
            select = vec[i];
            vec.erase(vec.begin() + i);
            cout << "Popped: " << select << endl;
            max = 0;
            return true;
        }
    }
    return false;
}

void push(vector <int> &vec, int x)
{
    vec.insert(vec.begin(),x);
    cout << "Pushed: " << x << endl;

}

int main()
{
    vector <int> prio;

    push(prio, 3);
    push(prio, 22);
    push(prio, 66);
    push(prio, 3);
    pop(prio);
    push(prio,8);

    pop(prio);
    pop(prio);
    pop(prio);
    pop(prio);
    pop(prio);
    //cout << "Here" << endl;
    return 0;
}
