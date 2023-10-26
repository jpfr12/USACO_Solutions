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
  ifstream fin("lifeguards.in");
  ofstream fout("lifeguards.out");
  //stop
  int n;
  fin >> n;
  vector<vector<int>> vec(n);
  for(int i = 0; i < n; i++){
    int a, b;
    fin >> a >> b;
    vec[i] = {a,b};
  }
  int ans = 0;
  for(int i = 0; i < n; i++){
    vector<int> temp(1000+1);
    for(int j = 0; j < n; j++){
      if(i == j) continue;
      temp[vec[j][0]]++;
      temp[vec[j][1]]--;
    }
    int cnt = temp[0] == 1? 1: 0;
    int sum = temp[0];
    for(int j = 1; j <= 1000; j++){
      temp[j] += sum;
      if(temp[j]) cnt++;
      sum = temp[j];
    }
    ans = max(ans, cnt);
    
  }
  fout << ans << '\n';
  return 0;
}
