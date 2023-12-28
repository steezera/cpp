#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
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
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(board[i + x][j + y] != black[i][j]) cnt += 1;
        }
    }
    return cnt;
}

int countWB(int x, int y) {
    int cnt = 0;
    for(int i = 0; i < 8; ++i) {
        for(int j = 0; j < 8; ++j) {
            if(board[i + x][j + y] != white[i][j]) cnt += 1;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int minVal = 10000; // 충분히 큰 숫자
    int N,M;
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        getline(cin, board[i]);
    }

    for(int i = 8; i < N; ++i){
        for(int j = 8; j < M; ++j) {
            int tmp = min(countWB(i, j), countBW(i, j));
            if(tmp < minVal) minVal = tmp;
        }
    }
    cout << minVal;
    return 0;
}