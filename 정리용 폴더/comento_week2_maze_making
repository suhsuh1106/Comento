#include <bits/stdc++.h>
#include <random>
#include <queue>
#include <time.h>

using namespace std;

#define MAX_SIZE 1000
int MIN = MAX_SIZE * MAX_SIZE;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int x_size = 50;
int y_size = 50;

void build_maze(int** map, int** visit, int x_size, int y_size) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(0, 1);

	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			map[i][j] = dis(gen);
			//map[i][j] = 1;
			map[0][j] = 0;
			map[i][y_size - 1] = 0;
		}
	}
	map[0][0] = 0; //출발지점
	map[x_size - 1][y_size - 1] = 0; // 도착지점
	cout << "미로 생성 완료" << endl;
}
void visit_init(int** visit, int x_size, int y_size) {
	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			visit[i][j] = 0;
		}
	}
}

void check_init(int** check, int x_size, int y_size) {
	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			check[i][j] = 0;
		}
	}
}

void printmap(int** map) {
	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void printvisit(int** visit) {
	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			printf("%d", visit[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void DFS(int** visit, int** map, int x, int y, int depth) {
	if (x < 0 || y < 0 || x >= x_size || y >= y_size) {
		return;
	}
	if (x == x_size - 1 && y == y_size - 1) {
		if (depth < MIN) {
			MIN = depth;
		}
		//printvisit(visit);
		//cout << "도착했습니다. 거리는" << depth << endl;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int Next_x = x + dx[i];
		int Next_y = y + dy[i];
		if (Next_x < 0 || Next_x > x_size || Next_y < 0 || Next_y > y_size) {
			return;
		}
		if (visit[Next_x][Next_y] == 0 && map[Next_x][Next_y] == 0) {
			visit[Next_x][Next_y] = 1;
			DFS(visit, map, Next_x, Next_y, depth + 1);
			visit[Next_x][Next_y] = 0;
		}


	}
}

void BFS(int** visit, int** map, int** check, int x, int y, int depth)
{
	visit[x][y] = 1; // 방문표시

	queue<pair<int, int> > q; // 큐 생성
	q.push(make_pair(x, y)); // 시작점 넣기

	while (!q.empty()) // 큐에 데이터가 없을때까지
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop(); // 큐 맨 앞 데이터 제거

		for (int i = 0; i < 4; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (0 <= next_x && next_x < x_size && 0 <= next_y && next_y < y_size) // 미로의 범위
			{
				// 길이 존재하고 이전에 방문했던적이 없는 경우
				if (map[next_x][next_y] == 0 && visit[next_x][next_y] == 0)
				{
					check[next_x][next_y] = check[x][y] + 1;
					visit[next_x][next_y] = 1;
					q.push(make_pair(next_x, next_y)); // 큐에 데이터 밀어넣기
				}

			}

		}
	}

}

int minDistance(int** check, int** visit) {
	int min = INT_MAX, min_idx_x, min_idx_y;
	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			if (visit[i][j] == 0 && check[i][j] <= min) {
				min = check[i][j];
				min_idx_x = i;
				min_idx_y = j;
			}
		}
	}
	return min_idx_x, min_idx_y;
}

void dijstra(int** map, int** visit, int** check, int x, int y, int depth) {
	for (int i = 0; i < x_size; i++) {
		for (int j = 0; j < y_size; j++) {
			check[i][j] = INT_MAX;
		}
	}
	check[0][0] = 0;

	for (int count = 0; count < x_size; count++) {
		int u = minDistance(check, visit);

	}
}

int main() {

	int** map = new int* [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		map[i] = new int[MAX_SIZE];
	} // map 동적 할당

	int** visit = new int* [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		visit[i] = new int[MAX_SIZE];
	} // visit 동적 할당

	int** check = new int* [MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		check[i] = new int[MAX_SIZE];
	} // check 동적 할당

	time_t start, end;
	double result;
	int i, j;

	build_maze(map, visit, x_size, y_size);
	//printmap(map);

	int x = 0, y = 0;
	int depth = 1;
	visit_init(visit, x_size, y_size);
	start = time(NULL);
	DFS(visit, map, x, y, depth);
	end = time(NULL); // 시간 측정 끝
	result = (double)(end - start);
	cout << "최소 거리는" << MIN << endl;
	cout << "소요 시간 (DFS) " << result << endl;

	x = 0, y = 0;
	visit_init(visit, x_size, y_size);
	check_init(check, x_size, y_size);
	start = time(NULL);
	BFS(visit, map, check, x, y, depth);
	end = time(NULL); // 시간 측정 끝
	result = (double)(end - start);
	cout << "최소 거리는" << check[x_size - 1][y_size - 1] + 1 << endl;
	cout << "소요 시간 (BFS) " << result << endl;


	for (int i = 0; i < MAX_SIZE; i++) {
		delete[] map[i];
	}
	delete[] map;

	for (int i = 0; i < MAX_SIZE; i++) {
		delete[] visit[i];
	}
	delete[] visit;

	for (int i = 0; i < MAX_SIZE; i++) {
		delete[] check[i];
	}
	delete[] check;
}
