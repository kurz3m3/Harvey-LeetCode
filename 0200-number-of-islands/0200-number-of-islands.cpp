class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // need to find the num of islands on the grid
        // 1's represent land and 0's represent water

        // check first that grid isnt empty
        // use BFS to search through grid

        if(grid.empty() || grid.at(0).empty()){
            return 0;
        }

        int numIslands = 0;
        int m = grid.size();
        int n = grid.at(0).size();
        queue<pair<int, int>> q;
        vector<pair<int,int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == '1'){
                    numIslands++;
                    q.push({i,j});

                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        if(x < 0 || x>=m || y < 0 || y>=n || grid[x][y] != '1'){
                            continue;
                        }

                        grid[x][y] = '0';

                        for(auto& dir : directions){
                            int nx = x+dir.first;
                            int ny = y+dir.second;
                            if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1'){
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
        return numIslands;
    }
};