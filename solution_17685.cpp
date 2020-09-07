#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

struct Node {
    int count;
    bool isEnd;
    Node* child[27];
    
    Node() {
        count = 1;
        isEnd = false;
        for (int i = 0; i < 27; i++)
            child[i] = NULL;
    }
};
Node* rootTrie;

void insertNode(string cur) {
    Node* par = rootTrie;

    for (int idx = 0; idx < cur.size(); idx++) {
        if (par->child[cur.at(idx)-'a'] == NULL) {
            Node* newNode = new Node();
            par->child[cur.at(idx) - 'a'] = newNode;
            par = newNode;
        }
        else {
            par = par->child[cur.at(idx) - 'a'];
            par->count += 1;
        }

        if (idx == cur.size() - 1)
            par->isEnd = true;
    }
}

int findNode(string cur) {
    Node* curPtr = rootTrie;
    int cnt = 0;

    for (int idx = 0; idx < cur.size(); idx++) {
        curPtr = curPtr->child[cur.at(idx) - 'a'];
        cnt++;
        if (curPtr->count == 1)
            return cnt;
    }

    return cur.size();
}

int solution(vector<string> words) {
    int answer = 0;
    rootTrie = new Node();

    for (auto iter : words) {
        insertNode(iter);
    }

    for (auto iter : words) {
        answer += findNode(iter);
    }

    return answer;
}
