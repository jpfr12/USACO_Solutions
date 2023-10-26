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
  ifstream fin("paint.in");
  ofstream fout("paint.out");
  //stop
  int a, b, c, d;
  fin >> a >> b >> c >> d;
  int area1 = b-a;
  int area2 =d-c;
  int overlap = max(0, min(d,b) - max(a, c));
  fout << area1 + area2 - overlap << '\n';
  return 0;
}
