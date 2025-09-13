class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        unordered_set<int>sadUsers;//create a set for unique sad users

        for(auto &friends : friendships){
            int u= friends[0]-1;//to convert 0 based indexing
            int v= friends[1]-1;

            unordered_set<int>langSet(begin(languages[u]) , end(languages[u]));//store all 'u' friends lang
            //and check 'v' frend know the lang or not
            bool canTalk= false;
            for(int  lang : languages[v]){
                if(langSet.count(lang)) {//if find v in u 
                    canTalk= true;
                    break;//common language they can talk
                };
            }
            if(!canTalk){//dont common so sad users
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }
        //find maxKnown language among sad users
        vector<int>language(n+1,0);//total n language for 0 indexing +1
        int mostKnownLang =0;
        for(int user : sadUsers){
            for(int lang: languages[user]){
                language[lang]++;
                mostKnownLang = max(mostKnownLang, language[lang]);
            }
        }
     return sadUsers.size()- mostKnownLang;
    }
};