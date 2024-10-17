#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;  

int parent[MAXN];  


bool isAncestor(int x, int y) {
    while (y != 0) {   
        if (y == x) return true; 
        y = parent[y]; 
    }
    return false;  
}

int main() {
    int n;  
    cin >> n;

    
    for (int i = 2; i <= n; ++i) {
        int a, b;
        cin >> a >> b;
        parent[b] = a;  
    }

    int T;  
    cin >> T;

    
    for (int i = 0; i < T; ++i) {
        int x, y;
        cin >> x >> y;
        if (isAncestor(x, y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}