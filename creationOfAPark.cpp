#include <bits/stdc++.h>
using namespace std;
#define MAXN (100)
int N;
char m[MAXN + 10][MAXN + 10];

char ans;//구매자 이름 Buyer's name
int areacnt;//구매자 영역 개수 Number of buyer's area

void InputData() {
	cin >> N;
	for (int h = 0; h < N; h++) {
		cin >> m[h];
	}
}

void dfs(int x, int y, vector<vector<int>>& vis, char a) {
	int drow[] = {-1, 0, 1, 0};
	int dcol[] = {0, 1, 0, -1};
	vis[x][y] = 1;
	for(int i = 0; i < 4; i++) {
		int nx = x + drow[i], ny = y + dcol[i];
		if (nx >= 0 and nx < N and ny >= 0 and ny < N) {
			if (!vis[nx][ny] and m[nx][ny] == a) {
				dfs(nx, ny, vis, a);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	InputData();// 입력받는 부분 Input
	
	int grid_r = 0, grid_g = 0, grid_b = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			if (m[i][j] == 'R') grid_r++;
			if (m[i][j] == 'G') grid_g++;
			if (m[i][j] == 'B') grid_b++;
		}
	}
	
	int zone_r = 0, zone_g = 0, zone_b = 0;
	vector<vector<int>> vis(N, vector<int>(N, 0));
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			char a = m[i][j];
			if (!vis[i][j]) {
				dfs(i, j, vis, a);
				if (a == 'R') zone_r++;
				if (a == 'G') zone_g++;
				if (a == 'B') zone_b++;
			}
		}
	}


	if (zone_r >= zone_g and zone_r >= zone_b) {
		areacnt = zone_r;
		ans = 'R';
	}
	if (zone_g > zone_r and zone_g > zone_b) {
		areacnt = zone_g;
		ans = 'G';
	}
	if (zone_b > zone_g and zone_b > zone_r) {
		areacnt = zone_b;
		ans = 'B';
	}
	
	if (zone_r == zone_g and zone_r > zone_b) {
		if (grid_r >= grid_g) {
			areacnt = zone_r;
			ans = 'R';
		}
		if (grid_r < grid_g) {
			areacnt = zone_g;
			ans = 'G';
		}
	}
	
		if (zone_r == zone_b and zone_r > zone_g) {
		if (grid_r >= grid_b) {
			areacnt = zone_r;
			ans = 'R';
		}
		if (grid_r < grid_b) {
			areacnt = zone_b;
			ans = 'B';
		}
	}
	
		if (zone_g == zone_b and zone_g > zone_r) {
		if (grid_g >= grid_b) {
			areacnt = zone_g;
			ans = 'G';
		}
		if (grid_g < grid_b) {
			areacnt = zone_b;
			ans = 'B';
		}
	}
	
	
	// 여기서부터 작성 Write from here

	cout << ans << " " << areacnt << "\n";// 출력하는 부분 Output
	return 0;
}
