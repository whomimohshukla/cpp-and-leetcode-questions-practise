#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, steps;
};

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int>> grid(M, vector<int>(N));
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N; ++j)
            cin >> grid[i][j];

    int sx, sy, dx, dy, mx, my;
    cin >> sx >> sy;
    cin >> dx >> dy;
    cin >> mx >> my;

    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Cell> q;

    q.push({sx, sy, 0});
    visited[sx][sy] = true;

    vector<pair<int, int>> directions = {
        {mx, my},
        {my, -mx},
        {-my, mx},
        {-mx, -my}
    };

    while (!q.empty()) {
        Cell current = q.front(); q.pop();

        if (current.x == dx && current.y == dy) {
            cout << current.steps;
            return 0;
        }

        for (auto dir : directions) {
            int nx = current.x + dir.first;
            int ny = current.y + dir.second;

            if (nx >= 0 && nx < M && ny >= 0 && ny < N &&
                grid[nx][ny] == 0 && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny, current.steps + 1});
            }
        }
    }

    cout << -1;
    return 0;
}
