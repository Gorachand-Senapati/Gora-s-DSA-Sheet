
struct Node {
    Node* links[26];
    bool flag;

    Node() {
        flag = false;
        for(int i = 0; i < 26; i++) links[i] = NULL;
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};
class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    void insert(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    bool checkPrefixExists(string word) {
        Node* node = root;
        for(char ch : word) {
            if(!node->containsKey(ch)) return false;
            node = node->get(ch);
            if(!node->isEnd()) return false;
        }
        return true;
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        Trie trie;
        for(auto &w : words) {
            trie.insert(w);
        }
        string longest = "";
        for(auto &w : words) {
            if(trie.checkPrefixExists(w)) {
                if(w.length() > longest.length() ||
                   (w.length() == longest.length() && w < longest)) {//lexicograph check
                    longest = w;
                }
            }
        }
        return longest;
    }
};
