#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<string> board(8);
vector<int> columns(8, 0), diag1(15, 0), diag2(15, 0);

int NotAttacing(int row) {
    if (row == 8) return 1;
    int count = 0;
    for (int col = 0; col < 8; ++col) {
        if (board[row][col] == '.' && columns[col] == 0 && diag1[row - col + 7] == 0 && diag2[row + col] == 0) {
            columns[col] = diag1[row - col + 7] = diag2[row + col] = 1;
            count += NotAttacing(row + 1);
            columns[col] = diag1[row - col + 7] = diag2[row + col] = 0;
        }
    }
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 8; ++i) {
        cin >> board[i];
    }

    cout << NotAttacing(0) << endl;
    return 0;

}
