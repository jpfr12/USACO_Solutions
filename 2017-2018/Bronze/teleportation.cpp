#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <cmath>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <assert.h>
#include <fstream>
#include <bitset>
#include <iomanip>

typedef long long ll;
using namespace std;
int MOD = (int)1e18;
int MAXN = 1e6;

//classes


//global


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("teleport.in");
  ofstream fout("teleport.out");
  //stop
  int s, e, t1,t2;
  fin >> s >> e >> t1 >> t2;
  vector<bool> vis(101);
  vector<int> dis(101);
  vis[s] = true;
  dis[s] = 0;
  queue<int> q;
  q.push(s);
  while(!q.empty()){
    int x = q.front();
    q.pop();
    if(x == e){
      fout << dis[e] << '\n';
      return 0;
    }
    if(x == t1 && !vis[t2]){
      vis[t2] = true;
      dis[t2] = dis[t1];
      q.push(t2);
    }
    if(x == t2 && !vis[t1]){
      vis[t1] = true;
      dis[t1] = dis[t2];
      q.push(t1);
    }
    if(x-1 >= 0 && !vis[x-1]){
      vis[x-1] = true;
      dis[x-1] = dis[x]+1;
      q.push(x-1);
    }
    if(x+1 <= 100 && !vis[x+1]){
      vis[x+1] = true;
      dis[x+1] = dis[x]+1;
      q.push(x+1);
    }
  }
  return 0;
}
