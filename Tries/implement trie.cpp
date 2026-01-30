struct Node {
    Node* links[26];//all lower char
    bool flag = false;
    Node(){//constructor every body 1st null
        for(int i=0;i<26;i++) links[i] = NULL;
    }
    bool containsKey(char ch){
        return links[ch- 'a'] != NULL;//a =0, b==2,z==25 means the char exist
    }
    void put(char ch, Node* node ){
        links[ch -'a'] = node;// alphabet point a new trie insert
    }
    //for next alphabet
    Node* get(char ch){
        return links[ch-'a'];//where now pooint refrence trie
    }
    void setEnd(){
       flag = true;
    }
    bool isEnd(){
        return flag;
    }
   };
class Trie {
private: Node * root;//evey ties have root
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {//insert a word into trie
        Node* node = root;
        for(int i=0;i<word.length();i++){//all char check in the word O(len)
         //exist the alphabet have in trie or not
         if (!node->containsKey( word[i])){
            node->put(word[i], new Node());//put the word and new trie crete
         }
         //move the reference trie if find
         node = node->get(word[i]);
        }
        //if word end then node is last refernce trie
        node->setEnd();//change flag
    }
    
    bool search(string word) { //O(len)
        Node* node = root;
        for(int i=0;i<word.length();i++){
            if(!node->containsKey(word[i])) {
                return false;
            }
            node = node->get(word[i]);
        }
        return node ->isEnd();
    }
    
    bool startsWith(string prefix) {
         Node* node = root;
        for(int i=0;i<prefix.length();i++){
            if(!node->containsKey(prefix[i])) {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */