#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int R, C, N;
char grid[100][100];
int shrineDist[16][16];
int dp[1 << 15][15];
vector<pair<int, int>> shrines;


int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};


void bfs(int sx, int sy, vector<vector<int>>& d) {
    queue<pair<int, int>> q;
    d[sx][sy] = 0;
    q.push({sx, sy});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        int x = current.first;
        int y = current.second;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] != '#' && d[nx][ny] == INF) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}


int tsp(int mask, int pos) {
    if (mask == (1 << N) - 1) return 0; 
    if (dp[mask][pos] != -1) return dp[mask][pos];

    int ans = INF;
    for (int i = 0; i < N; i++) {
        if (!(mask & (1 << i))) { 
            ans = min(ans, shrineDist[pos][i] + tsp(mask | (1 << i), i));
        }
    }

    return dp[mask][pos] = ans;
}

int main() {
    cin >> R >> C >> N;

    
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                shrines.push_back({i, j});  
            }
        }
    }

   
    vector<vector<int>> startDist(R, vector<int>(C, INF));
    bfs(0, 0, startDist);

   
    for (int i = 0; i < N; i++) {
        int sx = shrines[i].first, sy = shrines[i].second;
        if (startDist[sx][sy] == INF) {
            cout << -1 << endl;  
            return 0;
        }
    }

    
    for (int i = 0; i < N; i++) {
        vector<vector<int>> d(R, vector<int>(C, INF));
        bfs(shrines[i].first, shrines[i].second, d); 

        for (int j = 0; j < N; j++) {
            shrineDist[i][j] = d[shrines[j].first][shrines[j].second];
        }
    }

    
    memset(dp, -1, sizeof(dp));
    int ans = INF;

    
    for (int i = 0; i < N; i++) {
        ans = min(ans, startDist[shrines[i].first][shrines[i].second] + tsp(1 << i, i));
    }

    cout << (ans == INF ? -1 : ans) << endl;  
    return 0;
}
