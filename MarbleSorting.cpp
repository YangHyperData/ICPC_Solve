#include <iostream>
#include <vector>
using namespace std;


const int dx[5] = {0, -1, 0, 1, 0}; 
const int dy[5] = {0, 0, 1, 0, -1}; 

int main() {
    ios_base::sync_with_stdio(false);  
    cin.tie(0);                       
    
    int N, P, M;
    cin >> N >> P >> M;

    vector<int> x(P), y(P), dir(P);

    
    for (int i = 0; i < P; i++) {
        cin >> x[i] >> y[i] >> dir[i];
    }

    
    for (int i = 0; i < M; i++) {
        char command;
        int K;
        cin >> command >> K;

        if (command == 'A') { 
            for (int j = 0; j < P; j++) {
                
                x[j] = (x[j] + K * dx[dir[j]] + N) % N; 
                y[j] = (y[j] + K * dy[dir[j]] + N) % N;
            }
        }
        else if (command == 'R') {  
            for (int j = 0; j < P; j++) {
                
                dir[j] = (dir[j] + K - 1) % 4 + 1;
            }
        }
        else if (command == 'Z') {  
            for (int j = 0; j < P; j++) {
                x[j] = K / N;  
                y[j] = K % N;  
            }
        }
    }

   
    for (int i = 0; i < P; i++) {
        cout << x[i] << " " << y[i] << endl;
    }

    return 0;
}