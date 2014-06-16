#ifndef ADJMWGRAPH_H
#define ADJMWGRAPH_H

#include "seqlist.h"

const int MaxVertices = 10;
const int MaxWeight   = 100;

class AdjMWGraph
{
private:
    SeqList<char> Vertices;
    int Edge[MaxVertices][MaxVertices];
    int numofEdges;

public:
    AdjMWGraph(int sz=MaxListSize)
    {
        for(int i=0; i<sz; ++i)
            for(int j=0; j<sz; ++j)
            {
                if(i == j)
                    Edge[i][j] = 0;
                else
                    Edge[i][j] = MaxWeight;
            }
        numofEdges = 0;
    }
    ~AdjMWGraph(){}

    bool GraphEmpty(){ return Vertices.ListEmpty(); }
    int numofVertices(){ return Vertices.ListSize(); }
    int getNumofEdges(){ return numofEdges; }
    char GetValue(int index){ return Vertices.GetData(index); }
    int getWeight(int v1, int v2)
    {
        if(v1<0 || v1>MaxVertices || v2<0 || v2>MaxVertices)
        {
            std::cerr<<"the v1 or v2 is not right...";
            exit(1);
        }
        return Edge[v1][v2];
    }
    void insertVertex(const char& item){ Vertices.Insert(item, Vertices.ListSize());}
    void insertEdge(int v1, int v2, int weight)
    {
        if(v1<0 || v1>Vertices.ListSize() ||
           v2<0 || v2>Vertices.ListSize() ||
           v1==v2 || weight>MaxWeight)
        {
            std::cerr<<"the v1 or v2 or weight is not right...";
            exit(1);
        }

        Edge[v1][v2] = weight;
        ++numofEdges;
    }
    void deleteVertex(int index)
    {
        for(int i=0; i<Vertices.ListSize(); ++i)
            for(int j=0; j<Vertices.ListSize(); ++j)
            {
                if((i == index || j==index) && Edge[i][j]>0 && Edge[i][j]<MaxWeight)
                {
                    Edge[i][j] = MaxWeight;
                    --numofEdges;
                }
            }
        Vertices.Delete(index);
    }
    void deleteEdge(int v1, int v2)
    {
        if(v1<0 || v1>MaxVertices || v2<0 || v2>MaxVertices || v1==v2)
        {
            std::cerr<<"the v1 or v2 is not right...";
            exit(1);
        }
        Edge[v1][v2] = MaxWeight;
        --numofEdges;
    }
    int getFirstNeighbor(int v)
    {
        if(v<0 || v>Vertices.ListSize())
        {
            std::cerr<<"the v is not right...";
            exit(1);
        }
        for(int i=0; i<Vertices.ListSize(); ++i)
        {
            if(Edge[v][i]>0 && Edge[v][i]<MaxWeight)
                return i;
        }
        return -1;
    }
    int getNextNeighbor(int v1, int v2)
    {
        if(v1<0 || v1>Vertices.ListSize() || v2<0 || v2>Vertices.ListSize())
        {
            std::cerr<<"the v1 or v2 is not right..."<<"v1: "<<v1<<"v2: "<<v2;
            exit(1);
        }
        for(int i=v2+1; i<Vertices.ListSize(); ++i)
        {
            if(Edge[v1][i]>0 && Edge[v1][i]<MaxWeight)
                return i;
        }
        return -1;
    }

    void DepthFirstSearch(int v, int visited[], void visit(char item))
    {
        visit(GetValue(v));
        visited[v] = 1;
        int neighbor = getFirstNeighbor(v);

        while(-1 != neighbor)
        {
            if(!visited[neighbor])
                DepthFirstSearch(neighbor, visited, visit);
            neighbor = getNextNeighbor(v, neighbor);
        }
    }
    void dfs(int arg, int visited[], void visit(char item))
    {
        visit(GetValue(arg));
        visited[arg] = 1;

        int neighbor = getFirstNeighbor(arg);

        if(-1 != neighbor)
        {
            if(!visited[neighbor])
                dfs(neighbor, visited, visit);
            neighbor = getNextNeighbor(arg, neighbor);
        }
    }

    void DepthFirstSearch(int visited[], void visit(char item))
    {
        for(int i=0; i<Vertices.ListSize(); ++i)
        {
            if(!visited[i])
            {
                dfs(i, visited, visit);
            }
        }
    }
};

#endif // ADJMWGRAPH_H
