#include <iostream>

using namespace std;

int main() {
	int A = 0;
	int B = 0;
	scanf("%d %d", &A, &B);

	if (A > B) {
		printf(">");
	}
	else if (A < B) {
		printf("<");
	}
	else {
		printf("==");
	}
}