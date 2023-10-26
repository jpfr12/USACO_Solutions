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
  ifstream fin("outofplace.in");
  ofstream fout("outofplace.out");
  //stop
  int n;
  fin >> n;
  vector<int> vec(n);
  for(int& i: vec) fin >> i;
  vector<int> temp;
  temp.push_back(vec[0]);
  for(int i = 1; i < n; i++){
    if(vec[i] != temp.back()) temp.push_back(vec[i]);
  }
  int ans = 0;
  n = temp.size();
  for(int i = 1; i < n; i++){
    int j = i;
    while(j > 0 && temp[j-1] > temp[j]){
        swap(temp[j-1], temp[j]);
        j--;
        ans++;
    }
  }
  fout << ans << '\n';
  return 0;
}
