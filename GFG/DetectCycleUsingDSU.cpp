//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int par[10001]; 
    int siz[10001];
    
    void make(int u)
    {
        par[u]= u ;
        siz[u]=1; 
    }
    int find(int u)
    {
        if(par[u]==u)
        return u ;
        return par[u] = find(par[u]) ;
    }
    
    int Union(int u ,int v )
    {
        int a = find(u) ;
        int b = find(v) ; 
        
        if(a!=b)
        {
            if(siz[b]>siz[a])
            swap(a,b); 
            par[b] =a ; 
            siz[a]+=siz[b]; 
        }
    }
    
    
    
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    map<pair<int,int>, int >m ; 
	    for(int i =0 ;i<V; i++ )
	    {
	        make(i) ;
	    }
	    for(int i= 0; i<V ;i++ )
	    {
	        for(auto it: adj[i])
	        {
	            if(m.find({i, it})!=m.end() || m.find({it, i })!=m.end())
	            {
	                continue ;
	            }
	            int a = find(i) ;
	            int b = find(it) ;
	            if(a!=b)
	            {
	                Union(i, it ) ;
	                m[{i, it}]=1 ;
	            }
	            else
	            return true ;
	        }
	    }
	    return false ;
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
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends
