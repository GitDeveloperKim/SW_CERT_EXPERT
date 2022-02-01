#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

#define MAX_NUM 1000000

using namespace std;

// bit 연산 예제 

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
	//freopen("input.txt", "r", stdin);	// 제출시 제거

	char src[] = { 'a','b','c' };

	int len = 3;

	for (int i = 0; i < (1 << len); i++) {
		printf("{");
		for (int j = 0; j < len; j++) {
			if ( (i & (1 << j)) == (1 << j)) {
				printf("%c ", src[j]);
			}
		}
		printf("} \n");
	}

	return 0;
}