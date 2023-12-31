#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N, tmp;
    cin >> N;

    int v1[10001] = { };

    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        v1[tmp] += 1;
    }

    for(int i = 1; i <= 10000; i++) {
        for(int j = 1; j <= v1[i]; j++) cout << i << '\n';
    }
    
    return 0;
}
