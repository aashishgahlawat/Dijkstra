
//dijkastra without priority queue TLE on test 31 link: http://codeforces.com/contest/20/submission/34416661

//Explained at: https://medium.com/@aashishgahlawat/dijkstra-code-explaination-in-c-af0058270052


#include <iostream>
#include <bits/stdc++.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#define endl '\n'
#define ll long long int
#define pb push_back
#define mp make_pair
#define foriter(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
using namespace std;
int mod=1000000007;
long long ll_int_max=999999999999;
long long int answer;

void printVector(vector<int> v)
{
    for_each(v.begin(), v.end(), [](int i){std::cout << i << " ";});//from to fn, lambda
    cout << endl;
}
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
}

std::vector<pair<int,int>> graph[100001];
int vCount,eCount;
int index=0;
int currV;
int startV=1;
int shortest=1;
int endV;
long long int pathLength[100001];
priority_queue< pair<long long int,int>, vector <pair<long long int,int>> , greater<pair<long long int,int>> > shortest_path_queue;
bool pathStutus[100001];
int Parent[100001];
void dijkastra();
int findShortest_path_among_unvisited();
void printPath();
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // aashish gahlawat
    cin>>vCount>>eCount;
    endV=vCount;

    for(int i=0;i<eCount;i++){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back(make_pair(b,w));
        graph[b].push_back(make_pair(a,w));
    }

    fill(pathLength,pathLength+endV+1,ll_int_max);

    Parent[startV]=-1;
    pathLength[startV]=0;

    dijkastra();

    printPath();

    #ifndef ONLINE_JUDGE
    cout<<endl<<endl<< "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms.\n";
    #endif
    return 0;
}

void dijkastra(){
    shortest_path_queue.push(make_pair(0,1));
    while(!shortest_path_queue.empty()){
    currV=findShortest_path_among_unvisited();
    if(currV==0 || currV==endV) return;
    pathStutus[currV]=true;
    for(int i=0;i<graph[currV].size();i++){
        int temp=graph[currV][i].first;
        if(!pathStutus[temp]){
            if(pathLength[currV]+graph[currV][i].second<pathLength[temp]){
                pathLength[temp]=pathLength[currV]+graph[currV][i].second;
                shortest_path_queue.push(make_pair(pathLength[temp],temp));
                Parent[temp]=currV;
            }
        }
    }
    }
}

int findShortest_path_among_unvisited(){
    int shortest=0;
    if(!shortest_path_queue.empty()){
        shortest=shortest_path_queue.top().second;
        shortest_path_queue.pop();
        return shortest;
    }else return 0;
}

void printPath(){
    if(Parent[endV]==0){cout<<-1; return;}
    std::vector<int> Path;
    for(int current=endV;Parent[current]!=-1;current=Parent[current]){
        Path.push_back(current);
    }
    cout<<1<<" ";
    for(int i=Path.size()-1;i>=0;i--){
        cout<<Path[i]<<" ";
    }
}
