bool cop(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}

int CalLargestBlock(int id_ignore){
	set<pair<int, int>> s;
	int curMax = 1, maxMax = 0;
	for(int i = 0; i < N; i++) s.insert({ID[i], 1});
	
	for(auto itr = s.begin(); itr != s.end(); itr++) {
		vector<int> data;
		
		for(int i = 0; i < N; i++) if (ID[i] != id_ignore) data.push_back(ID[i]);
		
		int ds = data.size();
		for(int i = 1; i < ds; i++) {
			if (data[i] == data[i - 1]) {
				curMax ++;
				maxMax = max(maxMax, curMax);
			}
			else curMax = 1;
		}
		s.erase(itr);
		s.insert({itr->first, maxMax});
	}
	
	vector<pair<int, int> > vec(s.begin(), s.end());
	sort(vec.begin(), vec.end(), cop);
	return vec[0].second;
}
