#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSorted(const string& a, const string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int N;
    vector<string> strings;

    cin >> N;
    strings.resize(N);
    
    for (int i = 0; i < N; ++i) {
        cin >> strings[i];
    }

    sort(strings.begin(), strings.end(), isSorted);

    // 중복 제거를 위한 코드 추가
    auto it = unique(strings.begin(), strings.end());
    strings.resize(distance(strings.begin(), it));

    for (const string& s : strings) {
        cout << s << "\n";
    }

    return 0;
}
