#include<bits/stdc++.h>
using namespace std;
class Graph{
    int V;
    bool *visited;
    bool complete_tree=false;
    list<int> *adj;
    void is_complete(){
        for(auto i=0;i<=V;i++){
            if(!(adj[i].size()==0||adj[i].size()==2)){
                complete_tree=false;
            }
        }
        complete_tree=true;
        return;
    }
    void inorder(int s){
        
        if(adj[s].size()==0){
            if(visited[s]==false){
                visited[s]=true;
            cout<<s<<" ";
            return;}
        }
        inorder(*(adj[s].begin()));
       if(visited[s]==false){
            visited[s]=true;
            cout<<s<<" ";}
        inorder(*(++adj[s].begin()));
    }
     void preorder(int s){
        
        if(adj[s].size()==0){
            if(visited[s]==false){
                visited[s]=true;
            cout<<s<<" ";
            return;}
        }
        if(visited[s]==false){
            visited[s]=true;
            cout<<s<<" ";}
        preorder(*(adj[s].begin()));
        preorder(*(++adj[s].begin()));
    }
    void postorder(int s){
        
        if(adj[s].size()==0){
            if(visited[s]==false){
                visited[s]=true;
            cout<<s<<" ";
            return;}
        }
        
        postorder(*(adj[s].begin()));
        postorder(*(++adj[s].begin()));
        if(visited[s]==false){
            visited[s]=true;
            cout<<s<<" ";}
    }
        void DFS(int v, bool visited[]) { 
        visited[v] = true; 
        cout << v << " "; 
  
        list<int>::iterator i; 
        for (i = adj[v].begin(); i != adj[v].end(); ++i) 
            if (!visited[*i]) 
                DFS(*i, visited); 
                            } 
    public:
    Graph(int V){
        this->V=V;
        adj = new list<int>[V+1];
        visited = new bool[V+1];
    }
    void addEdge(int s,int d){
     adj[s].push_back(d); 
     is_complete();
    }
    void inorder_util(int s){
        if(complete_tree==false)
        return;
        memset(visited,false,sizeof(bool)*(V+1));
        cout<<"inorder: ";
        inorder(s);
        cout<<"\n";
        return;
    }
    
    void preorder_util(int s){
         if(complete_tree==false)
        return;
        memset(visited,false,sizeof(bool)*(V+1));
        cout<<"Preorder: ";
        preorder(s);
        cout<<"\n";
        return;
    }
   
    void postorder_util(int s){
         if(complete_tree==false)
        return;
        memset(visited,false,sizeof(bool)*(V+1));
        cout<<"Postorder: ";
        postorder(s);
        cout<<"\n";
        return;
    }
    
    void BFS_util(int s){
        int x;
        queue<int> tmp;
        memset(visited,false,sizeof(bool)*(V+1));
        visited[s]=true;
        tmp.push(s);
        cout<<"BFS: ";
        cout<<s<<" ";
        while(!tmp.empty()){
            x=tmp.front();
        for(auto i=adj[x].begin();i!=adj[x].end();i++){
            if(visited[*i]==false){
            visited[*i]=true;
        tmp.push(*i);
        cout<<*i<<" ";}}
        tmp.pop();
        
        }
        cout<<"\n";
        return;
    }

  
void DFSUtil(int v) 
{ 
    bool *visited = new bool[V]; 
    memset(visited,false,sizeof(bool)*(V+1)); 
    cout<<"DFS: ";
    DFS(v, visited); 
    cout<<"\n";
}
    
};

int main(){
    // program runs for only complete binary tree
    Graph g1(10);
    g1.addEdge(5,3);
    g1.addEdge(5,7);
    g1.addEdge(3,2);
    g1.addEdge(3,4);
    g1.addEdge(7,6);
    g1.addEdge(7,8);
    g1.inorder_util(5);
    g1.preorder_util(5);
    g1.postorder_util(5);
    g1.BFS_util(5);
    g1.DFSUtil(5);
    return 0;
}
