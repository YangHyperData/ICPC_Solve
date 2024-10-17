#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 105;  


long long BIT[MAX_N][MAX_N][MAX_N];


void update(int x, int y, int z, int n, long long delta) {
    for (int i = x; i <= n; i += (i & -i))
        for (int j = y; j <= n; j += (j & -j))
            for (int k = z; k <= n; k += (k & -k))
                BIT[i][j][k] += delta;
}


long long query(int x, int y, int z) {
    long long sum = 0;
    for (int i = x; i > 0; i -= (i & -i))
        for (int j = y; j > 0; j -= (j & -j))
            for (int k = z; k > 0; k -= (k & -k))
                sum += BIT[i][j][k];
    return sum;
}


long long range_query(int x1, int y1, int z1, int x2, int y2, int z2) {
    return query(x2, y2, z2) 
         - query(x1 - 1, y2, z2) - query(x2, y1 - 1, z2) - query(x2, y2, z1 - 1)
         + query(x1 - 1, y1 - 1, z2) + query(x1 - 1, y2, z1 - 1) + query(x2, y1 - 1, z1 - 1)
         - query(x1 - 1, y1 - 1, z1 - 1);
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;

       
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                for (int k = 0; k <= n; ++k)
                    BIT[i][j][k] = 0;

        while (m--) {
            string operation;
            cin >> operation;

            if (operation == "UPDATE") {
                int x, y, z;
                long long w;
                cin >> x >> y >> z >> w;
                
                long long current_value = range_query(x, y, z, x, y, z); 
                update(x, y, z, n, w - current_value);  
            } else if (operation == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << range_query(x1, y1, z1, x2, y2, z2) << endl;
            }
        }
    }
    return 0;
}