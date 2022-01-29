#include <iostream>

using namespace std;


// baekjoon 10809 find alphabet 
int main() {
	char str[105];
	int isAlpha[27];
	int answer[27];
	scanf("%s", &str);
	
	for (int i = 0; i < 26; i++) {
		isAlpha[i] = (i + 'a');
		answer[i] = -1;
	}

	for (int i = 0; str[i] != '\0'; i++) {
		for (int j = 0; j < 26; j++) {
			if (isAlpha[j] == str[i]) {
				if (answer[j] == -1) {
					answer[j] = i;
				}				
			}
		}		
	}

	for (int i = 0; i < 26; i++) {
		printf("%d ", answer[i]);
	}

	return 0;
}