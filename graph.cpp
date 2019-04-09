#include<iostream>
#include<list>
#include<queue>
using namespace std;
const int unit=6;
class graph{
int V;
list<int> *adj;

public:
graph(int v)
{
    V=v;
    adj=new list<int>[V+1];

}
void addEdge(int u,int v,bool Bidir=true)
{
    adj[u].push_back(v);
    if(Bidir)
        adj[v].push_back(u);
}
void print()
{
    for(int i=1; i<=V; i++)
    {
        cout<<i<<"->";
        for(int node: adj[i])
            cout<<node<<",";
        cout<<"\n";
    }
}
void bfs(int src,int des)
{
    queue<int> q;
    bool *visited=new bool[V+1]{0};
    int *dist=new int[V+1]{0};
//int *parent=new int[V+1]{-1};
    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int node=q.front();

        //cout<<node<<" ";

        for(int neighbour:adj[node])
        if(!visited[neighbour]){
            q.push(neighbour);
            visited[neighbour]=true;
            dist[neighbour]=dist[node]+unit;
            //parent[neighbour]=node;
            }
            }
            q.pop();

        if(dist[des]==0)
            cout<<"-1"<<" ";
        else
          cout<<dist[des]<<" ";
    /*int temp=des;
//(temp!=-1)
{
    cout<<temp<<"<--";
    temp=parent[temp];

//}*/

}

};
int main()
{
    int q;cin>>q; int n,m; int u,v; int src;
    while(q--)
    {
        cin>>n>>m;
        graph g1(n);
        for(int i=1; i<=m; i++)
        {
           cin>>u>>v;
                  g1.addEdge(u,v);
        }
        cin>>src;
        for(int i=1; i<=n; i++)
        {

            g1.bfs(src,i);
        }
       cout<<endl;
    }
      return 0;
}
