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
class Cow{
  public:
  int value;
  string name;
  Cow(string name){
    this->name = name;
    value = 7;
  }
};

//global
set<string> lista;
vector<tuple<int, string, int>> vec;
vector<Cow*> cows;
set<Cow*> top;
int ans = 0;

bool compare(Cow* a, Cow* b){
  return a->name < b->name;
}

void bs(string& name, int x){
  int n = cows.size();
  int left = 0, right = n-1;
  Cow* c = NULL;
  while(left <= right){
    int mid = left +(right-left)/2;
    if(cows[mid]->name == name){
      c = cows[mid];
      break;
    }
    else if(name < cows[mid]->name) right = mid-1;
    else left = mid+1;
  }
  c->value += x;
}

void changes(){
  int ma = 0;
  set<Cow*> temp;
  for(Cow* c: cows){
    if(c->value > ma){
      ma = c->value;
      temp.clear();
      temp.insert(c);
    }
    else if(c->value == ma){
      temp.insert(c);
    }
  }
  if(top != temp){
    ans++;
    top = temp;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("measurement.in");
  ofstream fout("measurement.out");
  //stop
  int n;
  fin >> n;
  for(int i = 0; i < n; i++){
    int day, value;
    string name;
    fin >> day >> name >> value;
    vec.emplace_back(day, name, value);
    if(!lista.count(name)){
      lista.insert(name);
      Cow* c = new Cow(name);
      cows.push_back(c);
      top.insert(c);
    }
  }
  sort(cows.begin(), cows.end(), compare);
  sort(vec.begin(), vec.end());
  int left = 0;
  for(int right = 0; right < n; right++){
    if(get<0>(vec[left]) != get<0>(vec[right])){
      left = right;
      changes();
    }
    bs(get<1>(vec[right]), get<2>(vec[right]));

  }
  changes();
  fout << ans << '\n';
  return 0;
}
