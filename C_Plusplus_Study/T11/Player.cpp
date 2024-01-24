#include "pch.h"
#include "Player.h"
#include "Board.h"
#include <stack>

void Player::Init(Board* board)
{
	_pos = board->GetEnterPos();
	_board = board;

	MyAStar();
}

void Player::Update(uint64 deltaTick)
{
	if (_pathIndex >= _path.size())
	{
		_board->GenerateMap();
		Init(_board);
		return;
	}

	_sumTick += deltaTick;
	if (_sumTick >= MOVE_TICK)
	{
		_sumTick = 0;

		_pos = _path[_pathIndex];
		_pathIndex++;
	}

}

bool Player::CanGo(Pos pos)
{
	TileType tileType = _board->GetTileType(pos);
	return tileType == TileType::EMPTY;
}

void Player::RightHand()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);
	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	// y  x
	Pos front[4] =
	{
		Pos {-1, 0},	// UP
		Pos { 0,-1},	// LEFT
		Pos { 1, 0},	// DOWN
		Pos { 0, 1},	// RIGHT
	};

	while (pos != dest)
	{
		// 1. 현재 바라보는 방향을 기준으로 오른쪽으로 갈 수 있는지 확인.
		int newDir = (_dir - 1 + DIR_COUNT) % DIR_COUNT;
		if (CanGo(pos + front[newDir]))
		{
			// 오른쪽 방향으로 90도 회전
			_dir = newDir;
			// 앞으로 한 보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		// 2. 현재 바라보는 방향을 기준으로 전진할 수 있는지 확인.
		else if (CanGo(pos + front[_dir]))
		{
			// 앞으로 한 보 전진.
			pos += front[_dir];
			_path.push_back(pos);
		}
		else
		{
			// 왼쪽 방향으로 90도 회전.
			_dir = (_dir + 1) % DIR_COUNT;
		}
	}

	stack<Pos> s;

	for (int i = 0; i < _path.size() - 1; i++)
	{
		if (s.empty() == false && s.top() == _path[i + 1])
			s.pop();
		else
			s.push(_path[i]);
	}

	// 목적지 도착
	if (_path.empty() == false)
		s.push(_path.back());

	vector<Pos> path;
	while (s.empty() == false)
	{
		path.push_back(s.top());
		s.pop();
	}

	std::reverse(path.begin(), path.end());

	_path = path;
}

void Player::Bfs()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);
	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	// y  x
	Pos front[4] =
	{
		Pos {-1, 0},	// UP
		Pos { 0,-1},	// LEFT
		Pos { 1, 0},	// DOWN
		Pos { 0, 1},	// RIGHT
	};

	const int32 size = _board->GetSize();
	vector<vector<bool>> discoverd(size, vector<bool>(size, false));

	//vector<vector<Pos>> parent; 
	// parent[A] = B; -> A는 B로 인해 발견함
	map<Pos, Pos> parent;

	queue<Pos> q;
	q.push(pos);
	discoverd[pos.y][pos.x] = true;
	parent[pos] = pos;

	while (q.empty() == false)
	{
		pos = q.front();
		q.pop();

		// 방문
		if (pos == dest)
			break;

		for (int32 dir = 0; dir < 4; dir++)
		{
			Pos nextPos = pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인

			if (CanGo(nextPos) == false)
				continue;
			// 이미 발견한 지역인지 확인.
			if (discoverd[nextPos.y][nextPos.x])
				continue;
			
			q.push(nextPos);
			discoverd[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	// TODO

	_path.clear();

	// 거꾸로 거슬러 올라간다.
	pos = dest;

	while (true)
	{
		_path.push_back(pos);

		// 시작점은 자신이 곧 부모
		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}

void Player::MyBfs()
{
	Pos pos = _pos;

	_path.clear();
	_path.push_back(pos);
	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos front[4] =
	{
		Pos {-1, 0 }, // up // left // down // right
		Pos { 0,-1 },
		Pos { 1,-0 },
		Pos { 0, 1 },
	};

	// 사이즈 가져오고 한번 싹 밀기
	const int32 size = _board->GetSize();
	vector<vector<bool>> discovered(size, vector<bool>(size, false));

	map<Pos, Pos> parent;
	discovered[pos.y][pos.x] = true;
	parent[pos] = pos;

	queue<Pos> data;
	data.push(pos);


	// 데이터가 빌때까지 계속해서 서칭
	while (data.empty() == false)
	{
		pos = data.front(); // 0,0이 튀어나오고
		data.pop();

		// 상하좌우로 검색을 해야하며
		for (int check = 0; check < 4; check++)
		{
			Pos nextPos = pos + front[check]; // 다음 위치를 가져오고
			
			if (discovered[nextPos.y][nextPos.x] == true)
				continue;

			if (nextPos.y < 0 || nextPos.y >= size || nextPos.x < 0 || nextPos.y >= size
				|| CanGo(nextPos) == false)
				continue;

			data.push(nextPos); // 다음 위치를 다시 집어넣고
			discovered[nextPos.y][nextPos.x] = true;
			parent[nextPos] = pos;
		}
	}

	_path.clear();

	pos = dest;

	// 부모 자신을 만날때까지 계속 순회
	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());

}


struct PQNode
{
	bool operator<(const PQNode& other) const { return f < other.f; }
	bool operator>(const PQNode& other) const { return f > other.f; }

	int32	f; // f = g+ h;
	int32	g; 
	Pos		pos;
};

void Player::AStar()
{
	// 점수 매기기
	// F = G + H
	// F = 최종 점수 (작을 수록 좋음, 경로에 따라 달라짐)
	// G = 시작점에서 해당 좌표까지 이동하는데 드는 비용 (작을 수록 좋음, 경로에 따라 다름)
	// H = 목적지에서 얼마나 가까운지 (작을 수록 좋음, 고정) 휴리스틱


	Pos start= _pos;
	Pos dest = _board->GetExitPos();

	enum
	{
		DIR_COUNT = 8
	};

	Pos front[] =
	{
		Pos {-1, 0 },	// UP
		Pos { 0,-1 },	// LEFT
		Pos { 1,-0 },	// DOWN
		Pos { 0, 1 },	// RIGHT
		Pos {-1, -1},	// UP_LEFT
		Pos {1, -1},	// DOWN_LEFT
		Pos {1, 1},		// DOWN_RIGHT
		Pos {-1, 1},	// UP_RIGHT
	};

	int32 cost[] =
	{
		10, // UP
		10, // LEFT
		10, // DOWN
		10, // RIGHT
		14, // 대각선들
		14,
		14,
		14,
	};

	const int32 size = _board->GetSize();

	// CloseList
	// closed[y][x] -> (y, x)에 방문을 했는지 여부
	vector<vector<bool>> closed(size, vector<bool>(size, false));

	// best[y][x] -> 지금까지 (y, x)에 대한 가장 좋은 비용 (작을 수록 좋음)
	vector<vector<int32>> best(size, vector <int32>(size, INT32_MAX));

	// 부모 추적 용도
	map<Pos, Pos> parent;

	// OpenList
	priority_queue<PQNode, vector<PQNode>, greater<PQNode>> pq;

	// 1) 예약(발견) 시스템 구현
	// 2) 뒤늦게 더 좋은 경로가 발견 될 수 있음 -> 예외 처리 필수
	
	// f = g + h;
	// 초기값
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(PQNode{ g + h, g, start });
		best[start.y][start.x] = g + h;
		parent[start] = start;
	}

	while (pq.empty() == false)
	{
		// 제일 좋은 후보 찾는다
		PQNode node = pq.top();
		pq.pop();

		// 동일한 좌표를 여러 경로로 찾아서
		// 더 빠른 경로로 인해서 이미 방문(closed)된 경우 스킵
		// [선택]
		if (closed[node.pos.y][node.pos.x])
			continue;
		if (best[node.pos.y][node.pos.x] < node.f)
			continue;

		// 방문
		closed[node.pos.y][node.pos.x] = true;

		// 목적지에 도착했으면 바로 종료
		if (node.pos == dest)
			break;

		for (int32 dir = 0; dir < DIR_COUNT; dir++)
		{
			Pos nextPos = node.pos + front[dir];
			// 갈 수 있는 지역은 맞는지 확인
			if (CanGo(nextPos) == false)
				continue;
			// [선택] 이미 방문한 곳이면 스킵
			if (closed[nextPos.y][nextPos.x])
				continue;

			// 비용 계산
			int32 g = node.g + cost[dir];
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x));
			// 다른 경로에서 더 빠른 길을 찾았으면 스킵
			if (best[nextPos.y][nextPos.x] <= g + h)
				continue;

			// 예약 진행
			best[nextPos.y][nextPos.x] = g + h;
			pq.push(PQNode{ g + h, g, nextPos });
			parent[nextPos] = node.pos;
		}
	}

	// 거꾸로 거슬러 올라간다.
	Pos pos = dest;
	_path.clear();
	_pathIndex = 0;

	// 부모 자신을 만날때까지 계속 순회
	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());
}

struct Node
{
	bool operator>(const Node& other)const { return (g + h) > other.g + other.h; }
	bool operator<(const Node& other)const { return (g + h) < other.g + other.h; }

	int32 g;
	int32 h;
	Pos pos;
};

void Player::MyAStar()
{
	// f = g + h
	Pos start = _pos;
	// 목적지 도착하기 전에는 계속 실행
	Pos dest = _board->GetExitPos();

	Pos dir[] =
	{
		Pos {-1, 0 }, // up // left // down // right
		Pos { 0,-1 },
		Pos { 1,-0 },
		Pos { 0, 1 },
		Pos { 1 -1 },
		Pos {-1,-1 },
		Pos {-1, 1 },
		Pos { 1, 1 },
	};

	const int32 cost[] =
	{
		10,
		10,
		10,
		10,
		14,
		14,
		14,
		14,
	};

	// 사이즈 가져오고 한번 싹 밀기
	const int32 size = _board->GetSize();

	enum
	{
		DIR_COUNTS = 4,
	};

	// 닫혔는지 열렸는지 확인 // closedList
	map<Pos, bool> closed;

	// 체크
	// f의 값 비교용
	map<Pos, int32> best;

	// 부모 확인
	map<Pos, Pos> parent;

	// 우선순위 큐로 확인 // openList
	priority_queue<Node, vector<Node>, greater<Node>> pq;
	
	//     자기까지의 거리
	// f = g + h;
	// 초기화
	{
		int32 g = 0;
		int32 h = 10 * (abs(dest.y - start.y) + abs(dest.x - start.x));
		pq.push(Node{ g, h, start });
		best[start] = g + h;
		parent[start] = start;
	}

	
	while (pq.empty() == false)
	{
		// 제일 값이 낮은 노드를 꺼내와서 f값!
		Node temp = pq.top();
		pq.pop();
		
		// 이미 최고로 좋은 값이 뽑은값보다 안좋다면 // 여기서는 f값으로 서로 비교
		if (best[temp.pos] < temp.g + temp.h)
			continue;

		// 방문 성공
		closed[temp.pos] = true;

		// 목적지에 도착했다면 끝
		if (dest == temp.pos)
			break;

		for (int32 i = 0; i < DIR_COUNTS; i++)
		{
			// 다음 갈곳 정하고
			Pos nextPos = temp.pos + dir[i];

			// 갈수없다면 넘기고
			if (CanGo(nextPos) == false)
				continue;

			// 이미 방문한 지역이라면
			if (closed[nextPos] == true)
				continue;

			// f = g + h // g는 
			int32 g = temp.g + cost[i]; // 현재까지의 값
			int32 h = 10 * (abs(dest.y - nextPos.y) + abs(dest.x - nextPos.x)); // 목적지까지의 값

			// 이미 더 좋은 길을 알고있다면
			if (best[nextPos] <= g + h && best[nextPos] != 0)
				continue;

			pq.push(Node{ g, h, nextPos });
			best[nextPos] = g + h;
			parent[nextPos] = temp.pos;

		}

	}

	// 거꾸로 거슬러 올라간다.
	Pos pos = dest;
	_path.clear();
	_pathIndex = 0;

	// 부모 자신을 만날때까지 계속 순회
	while (true)
	{
		_path.push_back(pos);

		if (pos == parent[pos])
			break;

		pos = parent[pos];
	}

	std::reverse(_path.begin(), _path.end());

}