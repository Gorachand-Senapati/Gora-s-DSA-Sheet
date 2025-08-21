class Node {
public:
    int key ,val, cnt;
    Node* prev;
    Node* next;
    // constructor for key val
    Node(int k, int v){
        key = k;
        val = v;
        cnt = 1; // initial frequency
        prev = nullptr;
        next = nullptr;
    }
};

class List {
public:
    int size;
    Node* head;
    Node* tail;

    List(){
        head= new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size= 0;
    }

    void addFront(Node* mru){//most recently use
        Node* temp = head->next;
        mru->next = temp;
        mru->prev= head;
        head->next= mru;
        temp->prev= mru;
        size++;
    }

    void removeNode(Node* delNode){
        Node* delNext =delNode->next;
        Node* delPrev = delNode->prev;
        delPrev->next= delNext;
        delNext->prev= delPrev;
        size--;
    }
};

class LFUCache {
    map<int, Node*>keyNode;     // key -> Node address store
    map<int, List*>freqListMap; // freq -> Doubly linked list
    int maxSizeCache;
    int currSize;
    int minFreq;
public:
    LFUCache(int cap) {
        // code here
        maxSizeCache= cap;
        currSize =0;
        minFreq =0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);//1st delete from keynode map where key+address store
        freqListMap[node->cnt]->removeNode(node);//also delete from freqmap where store cnt

        //now after delete node cnt = minfreq(previous)and freqlistmap also the key cnt empty
        if(node->cnt == minFreq && freqListMap[node->cnt]->size ==0){
            minFreq++;//minfreq ++ assume if all delete from 1 freqency
        }

        List*nextHigherFreqList = new List();//create a new list for new freqency
        if(freqListMap.find(node->cnt+1) != freqListMap.end()) {//after increase find it
            nextHigherFreqList = freqListMap[node->cnt +1]; //also freqlist map frequcy change
        }

        node->cnt +=1;// and obbiusly the key node count increase
        nextHigherFreqList->addFront(node);//now most recently use so add after head
        freqListMap[node->cnt]= nextHigherFreqList;//and store the next higer in the freqlist map
        keyNode[node->key]= node;//and also store in keymap with address
    }

    int get(int key) {
        // code here
        if(keyNode.find(key) != keyNode.end()){ //if the key exists
            Node* node = keyNode[key];
            int val = node->val;//then store the value
            updateFreqListMap(node); //and update freq +1
            return val;
        }
        return -1;//if not find
    }

    void put(int key, int value) {
        // code here
        if(maxSizeCache == 0){//if cache size 0 nothing insert
            return ;
        }
        if(keyNode.find(key) != keyNode.end()){//if the key exist so simple change it value
            Node* node= keyNode[key];
            node->val= value;
            updateFreqListMap(node);
        } else{
            if(currSize== maxSizeCache){
                //if size = total capacity then delete the minimum freq key
                List* list= freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);// LFU + LRU
                freqListMap[minFreq]->removeNode(list->tail->prev);// LFU + LRU also remove
                currSize--;//now decrease aso insertable
            }
            currSize++;//new value also add which not the previous
            minFreq=1;//new element
            List* listFreq=new List();//if brand new list
            if(freqListMap.find(minFreq) != freqListMap.end()){//if it is there then take the list
                listFreq= freqListMap[minFreq];
            }
            Node* node= new Node(key, value);
            listFreq->addFront(node);//add front 
            keyNode[key]= node;
            freqListMap[minFreq]= listFreq;
        }
    }
};

