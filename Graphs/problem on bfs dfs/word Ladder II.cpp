class Solution {
     unordered_map<string, int>mpp;//word, distance store here
     vector<vector<string>>ans;//store ans
     string b;
private:
  void dfs(string word, vector<string>&seq){
    if(word == b){//backtrac so it is need 1st word
//  Before reversing, seq = ["cog", "dog", "dot", "hot", "hit"]After reverse → ["hit", "hot", "dot", "dog", "cog"]
        reverse(seq.begin(), seq.end());
        ans.push_back(seq);
        reverse(seq.begin(), seq.end());//re-reverse
        return;//if beginword is the end word
    }
    int steps=mpp[word];
    int sz = word.size();
    for(int i=0;i<sz;i++){
        char original = word[i];
        for(char ch = 'a'; ch<='z';ch++){//need to backtrack 1st cog- dog -4 so 4+1 == 5 so push in seq and again..
            word[i]= ch;
            if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps){
                seq.push_back(word);
                dfs(word, seq);
                seq.pop_back();
            }
        }
        word[i]= original;
    }
         
  }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
     unordered_set<string>set(wordList.begin(), wordList.end());//visited set
        queue<string>q;
        b= beginWord;
        q.push({beginWord});
        mpp[beginWord] = 1;
        int sz = beginWord.size();
        set.erase(beginWord);
        while(!q.empty()){
            string  word = q.front();
            int steps = mpp[word];//steps which store in map
            q.pop();
            if(word == endWord)break;
            for(int i=0;i<sz;i++){
                char original = word[i];
                for(char ch = 'a'; ch<='z';ch++){
                    word[i]=ch;
                    if(set.count(word)){
                        q.push(word);
                        set.erase(word);//also visited make
                        mpp[word]= steps+1;//for other word step
                    }
                }
                word[i]= original;
            }
        }
        if(mpp.find(endWord) != mpp.end()){
            vector<string>seq;
            seq.push_back(endWord);
            dfs(endWord,seq);//if find in map then backtrack with dfs
        }
        return ans;
    }
};//BFS + DFS hybrid approach fo leet code 

// User function Template for C++

class Solution {
  public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());//make a visited set when all check sequnece push it 
        queue<vector<string>>q;//{"des","der","dfr","dgt","dfs"}
        q.push({beginWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;//1st onzerod level befor pop from que
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string> vec= q.front();
            q.pop();
            //erase all words that has been use in privious level to transform
            if(vec.size() > level){
                level++;
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
                usedOnLevel.clear();//every level clear when used
            }
            string word = vec.back();//the last guy
            if(word == endWord){
               //the first sequence where we reached the end  
               if(ans.size() == 0){//1st ans is empty so push
                   ans.push_back(vec);
               }else if(ans[0].size()== vec.size()){// if ans size is equal to vec size then 2nd seq also push
                   ans.push_back(vec);//for another sequence
               }
               continue; //no need to go further after reaching endWord
            }
            
            
            for(int i=0;i<word.size();i++){
                char original = word[i];//change all char
                for(char c ='a';c<='z';c++){
                    word[i]= c;
                    if(st.count(word) > 0){//if exist
                        vec.push_back(word);
                        q.push(vec);//push the seq in que
                        usedOnLevel.push_back(word);//this word used mark as visited on the level
                        vec.pop_back();//need pop for another {bat, bot} {bat, pat}
                    }
                }
                word[i]= original;
            }
        }
        return ans; //return all shortest sequences
    }
};