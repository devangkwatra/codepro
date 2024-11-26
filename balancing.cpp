int main() {
	int ans = -1;
	InputData(); // 입력 받는 부분

	// 여기서부터 작성
	vector<int> vec1(N);
	vector<int> vec2(N);
	int maxi = 0;
	
	for(int i = 0; i < N; i++) {
		int temp1 = 0;
		int temp2 = 0;
		for(int j = 0; j < N; j++) {
			temp2 += Box[j][i];
			temp1 += Box[i][j];
		}
		vec1.push_back(temp1);
		vec2.push_back(temp2);
	}
	
	sort (vec1.begin(), vec1.end());
	sort(vec2.begin(), vec2.end());
	int n1 = vec1.size();
	int n2 = vec2.size();
	
	int max1 = vec1[n1 - 1];
	int max2 = vec2[n2 - 1];
	
	int req = max(max1, max2);
	
	int total = accumulate(vec1.begin(), vec1.end(), 0);
	total += accumulate(vec2.begin(), vec2.end(), 0);
	
	int diff = 2 * req * N;
	
	ans = (diff - total) / 2;
	
	
	cout << ans << endl;// 출력하는 부분
	return 0;
}
