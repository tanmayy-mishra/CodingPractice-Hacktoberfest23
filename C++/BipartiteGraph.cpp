//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private: 
    bool dfs(int start,int color,int col[],vector<int> adj[]) {
        col[start] = color;
        
        for(auto x:adj[start]) {
            if(col[x] == -1) {
                if(dfs(x,!color,col,adj) == false){
                    return false;
                }
               
            }
             else if(col[x] == color){
                    return false;
                }
        }
        
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	   int col[V];
	   for(int i=0;i<V;i++) {
	       col[i] = -1;
	   }
	    
	    for(int i=0;i<V;i++) {
	        if(col[i] == -1) {
	            if(dfs(i,0,col,adj) ==false){
	                return false;
	            }
	        }
	    }
	    
	    return true;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
