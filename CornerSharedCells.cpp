#include <iostream>
using namespace std;

int main()
{
    int M, N, p, q;
    cin >> M >> N; 
    cin >> p >> q; 

    int count = 0;

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
           
            int newRow = p + i;
            int newCol = q + j;

            if (newRow >= 1 && newRow <= M && newCol >= 1 && newCol <= N)
            {
                count++;
            }
        }
    }
    cout << count - 1 << endl; 

    return 0;
}
