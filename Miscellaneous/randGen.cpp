#include <iostream>
#include <random>

vector<int> randoms;

//generate n randoms uniformly distributed in the range (l-r)
void generateRandomBits(int l, int r, int n) {
  std :: random_device rd; 		//Will be used to obtain a seed for the random number engine
  std :: mt19937 gen(rd());  	//Standard mersenne_twister_engine seeded with rd()

  std :: uniform_int_distribution<int> dist(l, r);

  for (int i = 0; i < n; i++)
    randoms.pb(dist(gen)), cout<<randoms[i]<<endl;
}

int main() {
    return 0;
}
