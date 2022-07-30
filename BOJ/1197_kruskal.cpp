#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Edge{
public:
  int node[2];
  int weight;
  Edge(int a, int b, int c) {
    this->node[0] = a;
    this->node[1] = b;
    this->weight = c;
  }
};

bool comp(Edge &edge1, Edge &edge2) {
  return edge1.weight < edge2.weight;
}

int getParent(int parent[], int x) { // x의 루트 노드 구하기
  if(parent[x] == x) return x;
  return (parent[x] = getParent(parent, parent[x]));
}

int unionParent(int parent[], int a, int b) { // a, b중 작은 쪽이 부모
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a < b) parent[b] = a;
  else parent[a] = b;
  return 0;
}

bool findParent(int parent[], int a, int b) { // 같은 부모인지 확인
  a = getParent(parent, a);
  b = getParent(parent, b);
  if(a==b) return true;
  return false; 
}

int main(void) {
    int V, E, a, b, c, res;
    vector <Edge> v;
    cin >> V >> E;
    for(int i=0; i<V; ++i) {
        cin >> a >> b >> c;
        v.push_back(Edge(a,b,c));
    }
    sort(v.begin(), v.end(), comp);
    
    int parent[E];
    for (int i=0; i<E; ++i) {
        parent[i] = i;
    }
    res = 0;
    for(int i = 0; i<V; ++i) {
      // 사이클에 발생하지 않을때 그래프에 포함
      if(!findParent(parent, v[i].node[0]-1, v[i].node[1]-1)) {
        res += v[i].weight;
        unionParent(parent, v[i].node[0]-1, v[i].node[1]-1);
      }
    }
    cout << res << "\n";
    return 0;
}