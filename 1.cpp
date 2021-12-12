#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define N 7
using namespace std;
int d[N] = {4, 2, 4, 3, 1, 4, 6};
// int w[N] = {70, 60, 50, 40, 30, 20, 10};
int w[N] = { 0, 10, 20, 30, 40, 50, 60 };
int done[N] = {0};
bool cmp(int p1, int p2){
	return d[p1 - 1] < d[p2 - 1]; //升序排列
}
int main(){
	int n, i, j, t;
	int sum = 0;
	for (i = 0; i < N; i++){
		int key = d[i];
		for (j = key; j; j--){
			if (done[j - 1] == 0){
				done[j - 1] = i + 1;
				break;
			}
		}
		if (j == 0)
			sum += w[i]; //该任务无法完成 加入惩罚
	}
	printf("%d\n", sum);
	vector<int> a;
	for (int i = 0; i < N; i++){
		if (done[i] != 0)
			a.push_back(done[i]);
	}
	sort(a.begin(), a.end(), cmp);
	for (vector<int>::iterator it = a.begin(); it != a.end(); it++){
		cout<<'a'<< *it << ' ';
	}
	printf("\n");

	return 0;
}
