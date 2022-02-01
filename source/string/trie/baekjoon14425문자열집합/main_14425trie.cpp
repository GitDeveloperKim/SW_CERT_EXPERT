#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 26;

// 14425 문자열 집합 
// https://blog.naver.com/cocokelly1229/222059739350
typedef struct TrieNode {
	TrieNode* children[ALPHABET_SIZE];
	bool isEndOfWord;

	~TrieNode() {
		for (int i = 0; i < ALPHABET_SIZE; i++) {
			if (children[i]) delete children[i];
		}
	}
}TrieNode;

TrieNode* makeNode(void) {
	TrieNode* pNode = new TrieNode;
	pNode->isEndOfWord = false;

	// init 
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		pNode->children[i] = NULL;
	}
	return pNode;
}

void insert(TrieNode* parent, string keyword) {
	TrieNode* pNode = parent;

	for (int i = 0; i < keyword.length(); i++) {
		int index = keyword[i] - 'a';

		if (!pNode->children[index]) {
			pNode->children[index] = makeNode();
		}

		pNode = pNode->children[index];
	}

	pNode->isEndOfWord = true;
}

bool query(TrieNode* parent, string keyword) {
	TrieNode* pNode = parent;

	for (int i = 0; i < keyword.length(); i++) {
		int index = keyword[i] - 'a';

		if (!pNode->children[index]) {
			return false;
		}

		pNode = pNode->children[index];
	}

	return (pNode != NULL && pNode->isEndOfWord);
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	int N; // 문자열의 갯수 -> (keys)
	int M; // 검사 문자열 갯수 -> S{query_strings}
	cin >> N >> M;

	string keys[10004];
	string S[10004];

	for (int i = 0; i < N; i++) {
		cin >> keys[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> S[i];
	}


	TrieNode* root = makeNode(); // 아무것도 들어있지 않은 root 생성

	for (int i = 0; i < N; i++) // 주어진 keys로 Trie 생성
		insert(root, keys[i]);

	int answer = 0;

	for (int i = 0; i < M; i++) {
		if (query(root, S[i]))
			answer++;
	}
	cout << answer << endl;
	delete root;

	return 0;
}
