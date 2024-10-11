/*
130. 둘러싸인 영역
난이도: 중간

문제 설명
m x n 크기의 행렬 board가 주어지며, 이 행렬에는 'X'와 'O' 문자들이 포함되어
있습니다. 다음 조건에 맞춰서 둘러싸인 영역을 잡아야 합니다:

연결(Connect): 셀은 수평 또는 수직으로 인접한 셀과 연결될 수 있습니다.
영역(Region): 모든 'O' 셀을 연결하여 하나의 영역을 형성합니다.
둘러싸기(Surround): 영역이 보드의 가장자리(엣지)에 있는 셀이 아닌 'X' 셀로
완전히 둘러싸여 있다면, 그 영역은 'X' 셀에 의해 둘러싸인 것입니다. 둘러싸인
영역을 잡는다는 것은, 입력된 행렬에서 모든 해당 영역의 'O'를 'X'로 바꾸는 것을
의미합니다.

*/

struct pos {
    int y;
    int x;

    pos() {}
    pos(int _y, int _x) : y(_y), x(_x) {}
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        // 1. 모서리 (인덱스 중 하나가 0 또는 size - 1)에 둘러쌓일 경우 x로
        // 바꾸지 않는다.
        // 2. 모서리에 해당하는 O 자리가 없을 경우 전부 x로 바꾼다.
        // 음... 이건 모서리에 해당하는 인덱스만 쭉 돌아서 O로 만든 다음
        // 나머지를 X로 만들면 될 것 같아요.

        vector<vector<char>> visited(board);

        int my[4]{0, 1, 0, -1};
        int mx[4]{1, 0, -1, 0};

        for (int y = 0; y < board.size(); ++y)
            for (int x = 0; x < board[0].size(); ++x) {
                if ((y == 0 || y == board.size() - 1 || x == 0 ||
                     x == board[0].size() - 1) &&
                    board[y][x] == 'O') {
                    list<pos> q;

                    pos p{y, x};

                    q.push_back(p);

                    visited[y][x] = 'V'; // visited을 V로 채우면 되지 않을까요?

                    while (!q.empty()) {
                        pos cur = q.front();
                        q.pop_front();

                        for (int i = 0; i < 4; ++i) {
                            pos np = cur;
                            np.y += my[i];
                            np.x += mx[i];

                            if (np.y < board.size() && np.y >= 0 &&
                                np.x < board[0].size() && np.x >= 0 &&
                                visited[np.y][np.x] == 'O') {
                                visited[np.y][np.x] = 'V';
                                q.push_back(np);
                            }
                        }
                    }
                }
            }

        for (int y = 0; y < board.size(); ++y)
            for (int x = 0; x < board[0].size(); ++x) {
                if (visited[y][x] != 'V')
                    board[y][x] = 'X';
            }
    }
};