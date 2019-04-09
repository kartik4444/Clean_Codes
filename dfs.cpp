#include<iostream>
#include<list>
using namespace std;
int visited[1000]={0};
class graph{
int V;
list<int> *adj;
public :
    graph(int v)
    {
        V=v;
        adj=new list<int>[v+1];

    }
    void dfs(int v)
    {
        bool *visited=new bool[v+1]{false};
        dfs_util(v,visited);

     }
    void dfs_util(int v,bool visited[])
    {

                visited[v]=true;
                cout<<v<<" ";
                for(int node:adj[v])
                {
                    if(visited[node]==0)
                        dfs_util(node,visited);
                }

    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


};
int main()
{
       graph g(10);
       g.addEdge(1,2);
       g.addEdge(1,3);
       g.addEdge(1,6);
       g.addEdge(2,5);
       g.addEdge(2,7);
       g.addEdge(3,4);
       g.addEdge(6,8);g.addEdge(8,9);g.addEdge(8,10);


    g.dfs(1);
}
