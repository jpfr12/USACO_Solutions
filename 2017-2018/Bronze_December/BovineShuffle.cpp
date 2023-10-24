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
map<int,int> Map;
vector<string> vec;
int n;

void sol(){
  vector<string> temp(n);
  for(auto& i: Map){
    temp[i.second] = vec[i.first];
  }
  vec = temp;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("shuffle.in");
  ofstream fout("shuffle.out");
  //stop
  fin >> n;
  for(int i = 0; i < n; i++){
    int a;
    fin >> a;
    a--;
    Map[a] = i;
  }
  vec.resize(n);
  for(int i = 0; i < n; i++){
    fin >> vec[i];
  }
  for(int i = 0; i < 3; i++){
    sol();
  }
  for(string& i: vec){
    fout << i << '\n';
  }
  return 0;
}
