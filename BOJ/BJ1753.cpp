#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 999999
using namespace std;
int V, E, K;
int dist[20'001]; // 가중치 저장
vector <pair<int,int>> weight[20001];
void dijkstra(int start) {
    dist[start] = 0; //시작점 자신의 거리는 0
    priority_queue<pair<int,int>> pq; // 확인할 정점의 가중치, 확인할 정점 (default : less)
    int cur, d; 
    pq.push({0, start}); // 시작값 넣어주기
    while(!pq.empty()) {
        cur = pq.top().second; 
        d = -pq.top().first; // greater로 사용하기 위해 -붙임
        pq.pop();
        if(dist[cur] < d) continue; // 저장되어있는 가중치보다 더 크면 skip
        for(int i=0; i<weight[cur].size(); ++i) {
            int next = weight[cur][i].second; // cur의 인접노드 확인
            int next_dist = d + weight[cur][i].first; // 거쳐갈때 가중치 확인
            if(next_dist < dist[next]) {  // dist 갱신
                dist[next] = next_dist; 
                pq.push({-next_dist, next}); // 넣을때도 -해서 넣어주기
            }
        }
    }
}
int main(void)
{
    int v1, v2, e;
    cin >> V >> E >> K;
    fill(&dist[0], &dist[V+1], INF); //기본은 무한
    for(int i=0; i<E; ++i) {
        cin >> v1 >> v2 >> e;
        weight[v1].push_back({e, v2});
    }
    dijkstra(K);
    for(int i=1; i<=V; ++i) { // 결과 출력
        if(dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}