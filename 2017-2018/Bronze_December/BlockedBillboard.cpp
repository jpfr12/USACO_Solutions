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
class Rect{
  public:
  int x1, y1, x2, y2;

  Rect(int x1, int y1, int x2, int y2){
    this->x1 = x1;
    this->x2 = x2;
    this->y1 = y1;
    this->y2 = y2;
  }

  int area(){
    return (this->x2- this->x1) *(this->y2 - this->y1);
  }

  int overlap(Rect* r){
    int x = max(0, min(r->x2, this->x2) - max(r->x1, this->x1));
    int y = max(0, min(r->y2, this->y2) - max(r->y1, this->y1));
    return x*y;
  }
};

//global


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("billboard.in");
  ofstream fout("billboard.out");
  //stop
  int x1, y1, x2, y2;
  fin >> x1 >> y1 >> x2 >> y2;
  Rect* one = new Rect(x1, y1, x2, y2);
  fin >> x1 >> y1 >> x2 >> y2;
  Rect* two = new Rect(x1, y1, x2, y2);
  fin >> x1 >> y1 >> x2 >> y2;
  Rect* extra = new Rect(x1, y1, x2, y2);
  fout << one->area() + two->area() - one->overlap(extra) - two->overlap(extra) << '\n';
  return 0;
}
