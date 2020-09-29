#include<iostream>
#include<vector>
#include<climits>
#include<list>
#include<string>

using namespace std;

class Edge{

    public:
      int n;
      int w;
      Edge(int n,int w){

          this->n=n;
          this->w=w;
        }
};

class BHelper{
    public:
    int v;
    int level;

    BHelper(int v,int level){
        this->v=v;
        this->level=level;
    }

};

void addEdge(vector<vector< Edge > >& graph,int v1,int v2,int wt){

    graph[v1].push_back(Edge(v2,wt));
    graph[v2].push_back(Edge(v1,wt));
}

void display(vector<vector<Edge> >& graph){

    cout<<"---------------------------"<<endl;

    for(int v=0; v < graph.size(); v++){

        cout<<v<<" -> ";

        for(int n=0;n<graph[v].size();n++){

            Edge ne = graph[v][n];

            cout<<"[ "<<ne.n<<" @ "<<ne.w<<" ] ";

        }
        cout<<endl;

    }
    cout<<"---------------------------"<<endl;

}

bool haspath(vector<vector<Edge> >& graph ,int src,int dest,vector<bool>& visited ){

    if(src==dest) return true;

    visited[src]=true;

    for(int n=0;n < graph[src].size();n++){

        Edge ne = graph[src][n];

        if(visited[ne.n]==false){

            if(haspath(graph,ne.n,dest,visited)==true){
                return true;
            }
        }
    }
    return false;
}

//practice
bool haspath2(vector<vector<Edge > >& graph,int src,int dest,vector<bool>& visited){

    if(src==dest) return true;

    visited[src]=true;

    for(int i=0;i<graph[src].size();i++){

        Edge ne=graph[src][i];

        if(visited[ne.n]==false){

            if(haspath2(graph,ne.n,dest,visited)==true) return true;
        
        }
    }

    return false;
}

void printAllpaths(vector<vector<Edge> >& graph,int src,int dest,vector<bool>& visited,string psf){

    if (src == dest) {
        cout <<psf << dest <<endl;
        return ;
    }

    visited[src]=true;

    for(int i=0;i< graph[src].size() ;i++){

        Edge ne=graph[src][i];

        if(visited[ne.n]==false){

            printAllpaths(graph,ne.n,dest,visited,psf+to_string(src)+"-> ");
    
        }
    }

    visited[src]=false;

}

string getconnectedComponent(vector<vector<Edge> >& graph,vector<bool>& visited,int src){

    string comp;

    list<int> queue;

    queue.push_back(src);

    while(queue.size()>0){

        int rem=queue.front();
        queue.pop_front();

        if(visited[rem]==true) continue;
        else visited[rem]=true;

        comp+=to_string(rem);

        for(int n=0;n<graph[rem].size();n++){

            Edge ne=graph[rem][n];

            if(visited[ne.n]==false) queue.push_back(ne.n);
        }
    }
    return comp;

}


vector<string> getconnectedComponents(vector<vector<Edge> >& graph){

    vector<string> comps;

    vector<bool> visited(graph.size(),false);

    for(int v=0;v<graph.size();v++){

        if(visited[v]==false){

            string comp=getconnectedComponent(graph,visited,v);

            comps.push_back(comp);
        }


    }
    return comps;
}


int main(int argc, char const *argv[])
{
    vector<vector<Edge> > graph;

    for(int i=0;i<7;i++) graph.push_back( vector<Edge>());

    addEdge(graph,0,1,10);
    addEdge(graph,1,2,10);
    addEdge(graph,2,3,10);
    addEdge(graph,0,3,40);
    addEdge(graph,3,4,2);
    addEdge(graph,4,5,3);
    addEdge(graph,4,6,8);


   //display(graph);

    cout<<endl;

    vector<bool> visited(graph.size(),false);

    //cout<<haspath2(graph,0,1,visited);

  //  cout<<endl;
    
//printAllpaths(graph,0,5,visited," ");

    //string ans=getconnectedComponent(graph,visited,0);

    //cout<<ans<<endl;

    vector<string> ans=getconnectedComponents(graph);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }



    return 0;
}

