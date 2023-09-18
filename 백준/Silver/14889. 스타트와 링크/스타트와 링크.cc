#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int N;
vector<vector<int>> v(20, vector<int>(20, 0));
bool check[22];
int ans = 1000000000;


void DFS(int x, int pos) {
  if(x == N / 2) {
    int start, link;
    start = 0;
    link = 0;

    for(int i=0;i<N ;i++) {
      for(int j=0;j<N;j++) {
        if(check[i] && check[j]) start += v[i][j];
        if(!check[i] && !check[j]) link += v[i][j];
      }
    }

    int temp = abs(start - link);
    if(ans > temp) ans = temp;

    return;
  }
  
  for(int i=pos; i<N;i++) {
    check[i] = true;
    DFS(x+1, i+1);
    check[i] = false;
  }
}


int main() {
  string temp;
  getline(cin, temp);
  N = stoi(temp);

  for(int i=0; i<N ;i++) {
    getline(cin, temp );
    stringstream stream;
    stream.str(temp);
    int num;
    int j = 0;
    while(stream >> num) {
      v[i][j++] = num;
    }
  }

  DFS(0, 1);

  cout << ans;

  return 0;
}
