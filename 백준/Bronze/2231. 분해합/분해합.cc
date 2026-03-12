#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int n;
int a[1000004];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int d = (int)to_string(n).size();
    int start = max(1, n - 9 * d);

    for (int i = start; i <= n; i++) {
        int dest = i;
        int curr = i;
        while (curr > 0) {
            dest += curr % 10;
            curr /= 10;
        }
        if (dest == n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;
}