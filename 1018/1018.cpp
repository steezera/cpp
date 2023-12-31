#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h> // INT_MAX를 사용하기 위한 헤더
using namespace std;

string board[50];
string white[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};

string black[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

int countBW(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i + x][j + y] != black[i][j]) cnt += 1;
        }
    }
    return cnt;
}

int countWB(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (board[i + x][j + y] != white[i][j]) cnt += 1;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int minVal = INT_MAX; // 충분히 큰 숫자
    int N, M;
    cin >> N >> M;
    cin.ignore(); // 개행 문자 처리

    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    for (int i = 0; i <= N - 8; ++i) {
        for (int j = 0; j <= M - 8; ++j) {
            int tmp = min(countWB(i, j), countBW(i, j));
            if (tmp < minVal) minVal = tmp;
        }
    }
    cout << minVal;
    return 0;
}
