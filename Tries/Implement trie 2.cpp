#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    int cntPrefix = 0;
    int cntEndWith = 0;

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void increaseEndWith() {
        cntEndWith++;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    void reduceEndWith() {
        cntEndWith--;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEndWith();
    }

    int countWordsEqualTo(string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return 0;
            node = node->get(ch);
        }
        return node->getPrefix();
    }

    void erase(string &word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch))
                return;
            node = node->get(ch);
            node->reducePrefix();
        }
        node->reduceEndWith();
    }
};
