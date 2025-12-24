class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        //using floyed warshall
        vector<vector<int>>dist(n, vector<int>(n,1e9));//create a matrix assin int max
        for(int i=0;i<n;i++){
            dist[i][i]=0;//self loop 
        }
        for(auto it: edges){
            dist[it[0]] [it[1]] = it[2];
            dist[it[1]] [it[0]] = it[2];//bidierectional so  both
        }
        //floyed warshall
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][via] == 1e9 || dist[via][j] == 1e9) continue;
                    dist[i][j]= min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
        int cntCity = n;
        int cityNo= -1;//no city visited
        for(int city=0;city<n;city++){
            int cnt =0;
            for(int adCit =0; adCit<n;adCit++){
                if(dist[city][adCit] <= distanceThreshold){
                    cnt++;
                }
            }
            if(cnt<= cntCity){
                cntCity= cnt;
                cityNo= city;
            }
        }
        return cityNo;
    }
}; //using floyed warshall TC= O(n^3) SC= O(n^2)

//dijkstra approach
