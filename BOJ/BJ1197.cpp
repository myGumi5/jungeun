#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int parent[10'001];
class Edge {
public:
    int node[2];
    int weight;
    Edge(int a, int b, int c) {
        this->node[0] = a;
        this->node[1] = b;
        this->weight = c;
    }
};
bool comp(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}
int getParent(int a) {
    if(parent[a] == a)  return a;
    else    return getParent(parent[a]);
}

bool findParent(int a, int b) { // a,b가 같은 부모인지 찾기
    if (getParent(a)==getParent(b)) return true;
    return false;
}

void unionParent(int a, int b) { // 각 부모 노드를 합치기 (적은쪽이 부모)
    a = getParent(a);
    b = getParent(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

int main(void)
{
    int V, E, a, b, c, res = 0; //V: 정점개수, E:간선개수
    vector<Edge> v;
    cin >> V >> E;
    for(int i=0; i<E; ++i) {
        cin >> a >> b >> c;
        v.push_back(Edge(a,b,c));
    }
    sort(v.begin(), v.end(), comp); // 간선 비용으로 오름차순 정렬
    for(int i=1; i<=V; ++i) { // 초기 부모는 각자의 값
        parent[i] = i;
    }
    for(int i=0; i<v.size(); ++i) {
        a = v[i].node[0];
        b = v[i].node[1];
        if(!findParent(a, b)) { // 간선이 있고, 부모가 다르면 선택 (acyclic)
            res += v[i].weight;
            unionParent(a,b);
        }
    }
    cout << res << "\n";
    return 0;
}