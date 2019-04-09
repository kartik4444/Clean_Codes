#include<bits/stdc++.h>
#include<map>
using namespace std;
template<typename T>
class graph{
    unordered_map<T,list<pair<T,int>>> m;
public:
    void addEdge(T u,T v,int dist,bool Bidir=true)
    {
        m[u].push_back(make_pair(v,dist));
        if(Bidir)
            m[v].push_back(make_pair(u,dist));
    }
void print()
{
    for(auto j:m)
    {
    cout<<j.first<<"-->";
    for(auto l:j.second)
        cout<<l.first<<","<<l.second;
        cout<<"\n";
    }
}
void dijstra(T src)
{
    unordered_map<T,int> dist;
    for(auto j:m)
        dist[j.first]=INT_MAX;
    set<pair<int,T>> s;
    dist[src]=0;
    s.insert(make_pair(0,src));
    while(!s.empty())
    {
       auto p=*(s.begin());
       T node=p.second;
       int nodedist=p.first;
       s.erase(s.begin());
       for(auto childpair:m[node])
       {
           T dest;
           if(nodedist+childpair.second<dist[childpair.first])
           {
               dest=childpair.first;
            auto f=s.find(make_pair(dist[dest],dest));

            if(f!=s.end())
                s.erase(f);
                dist[dest]=nodedist+childpair.second;
           s.insert(make_pair(dist[dest],dest));
           }



}
}
for(auto it:dist)
cout<<it.first<<" is located at distance of "<<it.second<<"\n";
}


};
int main()
{
graph<string> india;
india.addEdge("amritsar","delhi",1);
india.addEdge("amritsar","jaipur",4);
india.addEdge("jaipur","Delhi",2);
india.addEdge("jaipur","Mumbai",8);
india.addEdge("Bhopal","Agra",2);
india.addEdge("Mumbai","Bhopal",3);
india.addEdge("Agra","Delhi",1);
/*
graph<int> g;
g.addEdge(1,2,1);
g.addEdge(1,3,4);
g.addEdge(2,3,1);
g.addEdge(3,4,2);
g.addEdge(1,4,7);
g.print();
*/
india.print();
india.dijstra("amritsar");
return 0;


}
