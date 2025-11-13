#include <bits/stdc++.h>
using namespace std;

int n;
int a, b, c;
int solve(int num) {
    long long ans = 1;
    if (num <= b)
        return ans;
    else {
        num -= b;
        num % c ? ans += (num / c) + 1 : ans += (num / c);
        return ans;
    }
}
void solver() {
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }

    cin >> b >> c;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += solve(arr[i]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solver();
    return 0;
}