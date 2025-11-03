class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //using bfs traverse for level wise
        queue<pair<string, int>>q;//make q for bfs {word, step}
        q.push({beginWord,1});
     unordered_set<string>set(wordList.begin(), wordList.end());//making a vis set for normal O(1) worst O(n)
     set.erase(beginWord);//here for visted remove it 
       while(!q.empty()){
        string word = q.front().first;
        int step = q.front().second;
        q.pop();
        if(word == endWord) return step;
        //check every letter in word //hot
        //O(n)+ O(26*word.length()) O(log n)
        for(int i=0;i<word.length();i++){
            char original = word[i];
            for(char ch = 'a'; ch<='z'; ch++){//hot hat hit....
                word[i]= ch;
                if(set.find(word) != set.end()){//if exist in set
                  set.erase(word);//make visited so remove it
                    q.push({word, step+1});
                }
            }
            word[i] = original;
        }
       }
       return 0;//if not find 
    }
};