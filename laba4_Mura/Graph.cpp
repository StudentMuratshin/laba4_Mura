#include "Graph.h"
#include <stack>
#include <algorithm>
#include <utility>
std::ostream& operator<<(std::ostream& file, const Graph& g)
{
    for (int i = 0; i < g.N; i++) {
        file << i<<std::endl;
    }
    for (int i = 0; i < g.N; i++) {
        for (int j = i+1; j < g.N; j++) {
            if (g.edges[i][j]) {
                file << i << "-" << j<<std::endl;
            }
        }
    }
    file << "draw" << std::endl;
    return file;
}
/*
void Graph::DFSUtil(std::ostream& file,int v, std::vector<bool> &visited){
    visited[v] = true;
    file << v << ",color=red\n";
    file << "w,1000\n";
    for (int i = 0; i != N; ++i)
        if (!visited[i]&&edges[v][i])
            DFSUtil(file,i, visited);

}
*/
Graph::Graph(int N)
{
    this->N = N;
    edges.resize(N, vector<bool>(N, false));

}
/*
bool Graph::isConnected(std::ostream& file) {
    std::vector<bool> visited(N,false);

    int i;
    for (i = 0; i < N; i++)
        for(int j=i+1;j<N;j++)
            if (edges[i][j])
                break;

    if (i == N)
        return true;

    DFSUtil(file,i, visited);

    for (i = 0; i < N; i++) {
        bool hasNeighbors = false;
        for (int j = i + 1; j < N; j++)
            hasNeighbors = hasNeighbors|| edges[i][j];
        if (visited[i] == false && hasNeighbors)
            return false;
    }
    return true;
}*/
bool Graph::hasNeighbors(int i) {
    bool h = false;
    for (int j = 0; j < N; j++)
        h = h || edges[i][j] && i!=j;
    return h;
}
void Graph::addEdge(int i, int j)
{
    edges[i][j] = true;
    edges[j][i] = true;
}

std::vector<int> Graph::getEulerCycle(std::ostream& file)
{
    std::vector<int> ans;
    std::stack<int> st;
    std::stack<std::pair<int, int>> Pairs;
    st.push(0);
    file << 0 << ",color=lime\n";
    while (st.size()) {
        if (!hasNeighbors(st.top())) {
            if (ans.size()) {
                file << std::min(ans.back(), st.top()) << "-" << std::max(ans.back(), st.top()) << ",label=" << Pairs.size() << std::endl;
                Pairs.push(make_pair(ans.back(), st.top()));
            }
            ans.push_back(st.top());
            file << st.top() << ",color=lime\n";
            file << "p,вершина " << st.top() << " обработана" << "\n";
            file << "w,1000\n";
            st.pop();
        }
        else
        {
            int v = st.top();
            for (int i = 0; i < N; i++) {
                if (edges[v][i]&&i!=v) {
                    
                    edges[v][i] = false;
                    edges[i][v] = false;
                    st.push(i);
                    break;
                }
            }
            file << std::min(v, st.top()) << "-" << std::max(v, st.top()) << ",color=red\n";
            file << "p,ребро " << std::min(v, st.top()) << "-" << std::max(v, st.top()) << " пройдена" << "\n";
            file << "w,1000\n";
        }
    }
    return ans;
}
