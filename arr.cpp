#include <iostream>
#include <vector>
using namespace std;

int main() {
    // int arr[100] = {1,};
    // for(int i = 0 ; i < 100; ++i) cout << arr[i] << endl;
    vector<int> v1;
    v1.resize(100);

    for(int i = 0; i < 100; ++i) cout << v1[i] << " ";
    int size = v1.size();
    int cap = v1.capacity();
    cout << endl;
    cout << cap << " " << size << endl;
    return 0;
}