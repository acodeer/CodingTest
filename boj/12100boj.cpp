#include <bits/stdc++.h>
using namespace std;

int n;
int best = 0;
vector<vector<int>> move_l(vector<vector<int>> map) {
    vector<vector<bool>> merged(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int y = j;
            while (y > 0 && map[i][y - 1] == 0) {
                swap(map[i][y], map[i][y - 1]);
                y--;
            }
            if (y > 0 && map[i][y - 1] == map[i][y] && !merged[i][y - 1]) {
                map[i][y - 1] *= 2;
                map[i][y] = 0;
                merged[i][y - 1] = true;
            }
        }
    }
    return map;
}

vector<vector<int>> move_r(vector<vector<int>> map) {
    vector<vector<bool>> merged(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            int y = j;
            while (y < n - 1 && map[i][y + 1] == 0) {
                swap(map[i][y], map[i][y + 1]);
                y++;
            }
            if (y < n - 1 && map[i][y + 1] == map[i][y] && !merged[i][y + 1]) {
                map[i][y + 1] *= 2;
                map[i][y] = 0;
                merged[i][y + 1] = true;
            }
        }
    }
    return map;
}

vector<vector<int>> move_u(vector<vector<int>> map) {
    vector<vector<bool>> merged(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
        for (int i = 1; i < n; i++) {
            int x = i;
            while (x > 0 && map[x - 1][j] == 0) {
                swap(map[x][j], map[x - 1][j]);
                x--;
            }
            if (x > 0 && map[x - 1][j] == map[x][j] && !merged[x - 1][j]) {
                map[x - 1][j] *= 2;
                map[x][j] = 0;
                merged[x - 1][j] = true;
            }
        }
    }
    return map;
}

vector<vector<int>> move_d(vector<vector<int>> map) {
    vector<vector<bool>> merged(n, vector<bool>(n, false));
    for (int j = 0; j < n; j++) {
        for (int i = n - 2; i >= 0; i--) {
            int x = i;
            while (x < n - 1 && map[x + 1][j] == 0) {
                swap(map[x][j], map[x + 1][j]);
                x++;
            }
            if (x < n - 1 && map[x + 1][j] == map[x][j] && !merged[x + 1][j]) {
                map[x + 1][j] *= 2;
                map[x][j] = 0;
                merged[x + 1][j] = true;
            }
        }
    }
    return map;
}

void solve(vector<vector<int>> map, int depth) {
    if (depth == 5) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                best = max(best, map[i][j]);
            }
        }
        return;
    }
    solve(move_l(map), depth + 1);
    solve(move_r(map), depth + 1);
    solve(move_u(map), depth + 1);
    solve(move_d(map), depth + 1);
}
void solver() {
    cin >> n;
    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }
    solve(map, 0);
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solver();
    return 0;
}