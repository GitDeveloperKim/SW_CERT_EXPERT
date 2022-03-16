#include <iostream>
#include <queue> // �켱���� ť ��� 

//https://etst.tistory.com/324

using namespace std;

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int N;
    cin >> N;
    priority_queue<pair<int, bool>> pq; // �Է� ���� �ε�ȣ�� �ٲ�� ���� ����, ���ڰ� ������ �ι�° ������ �������� 

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x == 0) {
            if (pq.empty()) {
                cout << 0 << endl;
            }
            else {
                pair<int, int> temp = pq.top();
                if (temp.second) {
                    cout << temp.first << endl;
                }
                else {
                    cout << -temp.first << endl;
                }               
                pq.pop();
            }

        }
        else {
            if (x < 0) {
                pq.emplace(x, true);
            }
            else {
                pq.emplace(-x, false);
            }            
        }
    }

    return 0;
}