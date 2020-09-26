#include <stdio.h>
#include <malloc.h>
#define MAXSTR 22

/**
  Trie with MemoryPool
**/

typedef struct {
	int count;
	int startIndex[50000];
}RESULT;

struct TRIE {
	int end, cnt, size;
	int* start;
	TRIE* child[27];

	TRIE() {
		cnt = 0;
		size = 10;
		start = (int*)malloc(sizeof(int) * 10);
	}

	void insert(int data) {
		if (cnt >= size) {
			size *= 2;
			int* newArr = (int*)malloc(sizeof(int)*size);
			for (register int i = 0; i < cnt; i++)
				newArr[i] = start[i];
			delete(start);
			start = newArr;
		}
		start[cnt++] = data;
	}
};
TRIE memory[1000002];
int poolCnt;

TRIE* NewTrie() {
	memory[poolCnt].cnt = 0;
	memory[poolCnt].end = -1;
	for (register int i = 0; i < 27; i++)
		memory[poolCnt].child[i] = nullptr;
	return memory + (poolCnt++);
}

TRIE root;

char buffer[MAXSTR];
int bufidx, total;

void Insert(char* str) {
	TRIE* cur = &root;
	for (register int idx = 0; str[idx] != '\0'; idx++) {
		if (cur->child[str[idx] - 'a'] == nullptr)
			cur->child[str[idx] - 'a'] = NewTrie();
		cur = cur->child[str[idx] - 'a'];
	}
	cur->end = poolCnt;
	cur->insert(total - bufidx);
}

TRIE* Find(char *str) {
	TRIE* cur = &root;
	for (register int idx = 0; str[idx] != '\0'; idx++) {
		if (cur->child[str[idx] - 'a'] == nullptr)
			cur->child[str[idx] - 'a'] = NewTrie();
		cur = cur->child[str[idx] - 'a'];
	}
	return cur;
}

void FindCommon(char *str) {
	TRIE* cur = &root;
	for (register int idx = 0; str[idx] != '\0' ; idx++) {
		if (cur->child[str[idx] - 'a'] == nullptr)
			cur->child[str[idx] - 'a'] = NewTrie();
		cur = cur->child[str[idx] - 'a'];
	}
	
	int nextCnt = 0, i, nidx;
	TRIE* next;
	while (1) {
		nextCnt = 0;
		for ( i = 0; i < 27; i++)
			if (cur->child[i] != nullptr) {
				next = cur->child[i];
				nidx = i;
				nextCnt++;
			}

		if (nextCnt == 1) {
			cur = next;
			buffer[bufidx++] = (nidx + 'a');
			buffer[bufidx] = '\0';
			total++;
		}
		else
			break;
	}
}

void input(char c) {
	if (c == '+') {//space
		Insert(buffer);
		bufidx = 0;
		++total;
	}
	else if (c == '>') {//tab
		FindCommon(buffer);
	}
	else if (c == '-') {//tackspace
		buffer[--bufidx] = '\0';
		--total;
	}
	else {
		buffer[bufidx++] = c;
		buffer[bufidx] = '\0';
		++total;
	}
}

void find(char* str, RESULT* result) {
	TRIE* f = Find(str);

	result->count = f->cnt;
	for (register int i = 0; i < result->count; i++)
		result->startIndex[i] = f->start[i];
}

void init() {
	poolCnt = 0;
	root.cnt = 0;
	root.end = -1;
	for (register int i = 0; i < 27; i++)
		root.child[i] = nullptr;
	
	bufidx = 0;
	total = 0;
}

int main() {
	//cursor = 0;
	RESULT outputData;
	int tc;
	int cmd;
	char data;
	char str[100];
	scanf("%d", &tc);
	for (int n = 0; n < tc; n++) {
		while (1) {
			scanf("%d", &cmd);
			if (cmd == 0) {
				scanf(" %c", &data);
				input(data);
			}
			else if (cmd == 1) {
				scanf(" %s", str);
				find(str, &outputData);
				printf("%d\n", outputData.count);
				for (int i = 0; i < outputData.count; i++) {
					printf("%d\n", outputData.startIndex[i]);
				}
			}
			else if (cmd == 2) {
				break;
			}
		}
		init();
	}
	return 0;
}
