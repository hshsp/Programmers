#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> city(50, vector<int>(50, -1));
int minDist;
vector<vector<int>> houses;
vector<vector<int>> stores;
vector<int> storesSelected; // 1: 포함O, 0: 포함X
int storeSize;

void calChickenDistance() {
  vector<int> distV( houses.size(), 99999);

  for(int i=0;i<stores.size();i++) {
    if(!storesSelected[i]) continue;
    // 치킨집을 중심으로 모든 집의 거리를 계산
    for(int x=0;x<houses.size();x++) {
      int dist = abs(stores[i][0] - houses[x][0]) + abs(stores[i][1] - houses[x][1]);
      if(distV[x] > dist) {
        distV[x] = dist;
      }
    }
  }

  int newDist = accumulate(distV.begin(), distV.end(), 0);


  if(minDist > newDist) {
    minDist = newDist;
  }

}

void DFS(int index, int removed) {
  if(removed == storeSize - M) {
    // 치킨거리 구해서 최소값 비교
    calChickenDistance();
    return;
  }


  for(int i=index;i<storeSize;i++) {
    storesSelected[i] = 0;
    DFS(i+1, removed + 1);
    storesSelected[i] = 1;
  }
}


int main() {

  string temp;

  getline(cin, temp);
  stringstream stream;
  stream.str(temp);
  string tempN, tempM;
  stream >> tempN;
  stream >> tempM;
  N = stoi(tempN);
  M = stoi(tempM);

  for(int i=0;i<N;i++) {
    int j=0;
    getline(cin, temp);
    stringstream streamCity;
    streamCity.str(temp);
    string cell;
    while(streamCity >> cell) {
      int cellInt = stoi(cell);
      if(cellInt == 2) {
        vector<int> store{i, j};
        stores.push_back(store);
      }
      if(cellInt == 1) {
        vector<int> house{i, j};
        houses.push_back(house);
      }
      city[i][j++] = cellInt;
    }
  }

  storeSize = stores.size();
  for(int i=0;i<storeSize;i++) {
    storesSelected.push_back(1);
  }

  minDist = 9999999;

  
  DFS(0, 0);

  cout << minDist << endl;

  return 0;
}
