#include<iostream>
using namespace std;
bool isSafe(bool graph[50][50],int v,int visited[],int vex)
{
    if(graph[v][vex]==1&&visited[vex]==0)
        return true;

    return false;
}
bool findHamPath(bool graph[50][50],int v,int visited[],int vex)
{
    if(vex==v-1)
        return true;
        for(int i=0; i<v;i++)
        {
            if(isSafe(graph,vex,visited,i)==true)
            {
                visited[vex]=1;
                if(findHamPath(graph,v,visited,i)==true)
                 return true;
                visited[vex]=0;
            }
        }
        return false;
}
bool HamPath(bool graph[50][50],int v)
{
    int *visited=new int[v]{0};
    for(int i=0; i<v; i++){
   if(findHamPath(graph,v,visited,i)==true)
        return true;
    }
    return false;

}
int main()
{
    bool graph[50][50]={0};int test;
    cin>>test;int v,e;
    while(test--)
    {
    cin>>v>>e;
    graph[v][v]={0};
    for(int i=0; i<e; i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x-1][y-1]=1;
        graph[y-1][x-1]=1;
    }
     for(int i=0; i<v; i++){for(int j=0;j<v;j++)cout<<graph[i][j]<<" ";cout<<"\n";}
cout<<HamPath(graph,v)<<endl;

    }
    return 0;
}





