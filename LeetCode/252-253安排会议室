#include<bits/stdc++.h>

using namespace std;

int minMeetZRooms(vector<vector<int>>& meetings){
	int n = meetings.size():
	vector<int>beg(n), fin(n);
	for(int i = 0; i < n; ++i){
		beg[i] = meetings[i][0];
		fin[i] = meetings[i][1];
	}
	sort(beg.begin(), beg.end());
	sort(fin.begin(), fin.end());
	int cnt = 0, i = 0, j = 0, res = 0;
	while(i < n && j < n){
		if(beg[i] < fin[j]){
			cnt++;
			++i;
		}else{
			cnt--;
			++j;
		}
		res = max(res, cnt);
	}
	return res;
}
