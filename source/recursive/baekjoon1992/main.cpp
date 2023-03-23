#include <iostream>
#include <string>

using namespace std;

int N;
int ** arr;

void dfs (int y, int x, int size) {
    if (size == 1) {
        cout << arr[y][x];
        return;
    }

    bool is_one = true;
    bool is_zero = true;
    for (int i = x; i < x+size; i++) {
        for (int j = y; j < y+size; j++) {
            if (arr[j][i] == 0)
                is_one = false;
            if (arr[j][i] == 1)
                is_zero = false;
        }
    }

    if (is_one){
        cout << "1";
        return;
    }
    if (is_zero == true){
        cout << "0";
        return;
    }

    cout << "(";
    int next_size = size/2;
    dfs(y, x, next_size);
    dfs(y, x+next_size, next_size);
    dfs(y+next_size, x, next_size);
    dfs(y+next_size, x+next_size, next_size);
    cout << ")";
    
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    arr = new int* [N+1];

    for (int i = 0; i <= N; i++) {
        arr[i] = new int[N+1];
    }
    
    for (int y = 0; y < N; y++) {
        string str;
        cin >> str;
        for (int x = 0; x < str.length(); x++) {
            arr[y][x] = str[x] - '0';
        }
    }

    dfs(0,0,N);

    // delete memory 
    for (int i = 0; i <= N; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}