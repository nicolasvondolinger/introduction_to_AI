#include <bits/stdc++.h>

using namespace std;
        
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define ff first
#define ss second
#define pb push_back
typedef long long ll;

int globalState = 0;
        
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

bool possible(vector<vector<int>>& board, int y, int x, int n){

  for(int i = 0; i < 9; i++){
    if(board[i][x] == n) return false;
  }

  for(int i = 0; i < 9; i++){
    if(board[y][i] == n) return false;
  }

  int x0 = (x/3) * 3, y0 = (y/3) * 3;

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(board[y0 + i][x0 + j] == n) return false;
    }
  }

  return true;
}

int bfs(vector<vector<int>>& board){

  queue<vector<vector<int>>> q;
  int states = 0;

  for(int i = 0; i < 9; i++){
    bool done = false;
    for(int j = 0; j < 9; j++){
      if(board[i][j] == 0){
        for(int k = 1; k < 10; k++){
          if(possible(board, i, j, k)){
            board[i][j] = k; q.push(board);
            done = true;
            states++;
          }
        }
        break;
      }
    }
    if(done) break;
  }

  while(!q.empty()){
    vector<vector<int>> aux = q.front(); q.pop();
    bool done = false;
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        if(aux[i][j] == 0){
          for(int k = 1; k < 10; k++){
            if(possible(aux, i, j, k)){
              aux[i][j] = k; q.push(aux); 
              states++;
            }
          }
          done = true;
          break;
        }
      }
      if(done) break;
    }
    if(done) board = aux;
  }
  return states;
}

bool dls(vector<vector<int>>& board, int limit){
    if(limit == 0) return false;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == 0){
                for(int k = 1; k < 10; k++){
                    if(possible(board, i, j, k)){
                        globalState++;
                        board[i][j] = k;
                        if(dls(board, limit - 1)) return true;
                        board[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

bool idfs(vector<vector<int>>& board, int max_depth){
    for(int i = 1; i <= max_depth; i++){
        if(dls(board, i)) return true;
    }
    return false;
}

int ucs(vector<vector<int>>& board){
  priority_queue<pair<int, vector<vector<int>>>> q;

  int c = 0;
  int states = 0;
  for(int i = 0; i < 9; i++){
    bool done = false;
    for(int j = 0; j < 9; j++){
      if(board[i][j] == 0){
        c--;
        for(int k = 1; k < 10; k++){
          if(possible(board, i, j, k)){
            board[i][j] = k; q.push({c, board});
            done = true;
            states++;
          }
        }
        break;
      }
    }
    if(done) break;
  }

  
  while(!q.empty()){
    vector<vector<int>> aux = q.top().second; q.pop();
    bool done = false;
    for(int i = 0; i < 9; i++){
      for(int j = 0; j < 9; j++){
        if(aux[i][j] == 0){
          c--;
          for(int k = 1; k < 10; k++){
            if(possible(aux, i, j, k)){
              aux[i][j] = k; q.push({c, aux}); states++;
            }
          }
          done = true;
          break;
        }
      }
      if(done) break;
    }
    if(done) board = aux;
  }

  return states;
}

bool dfs(vector<vector<int>>& board) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (board[i][j] == 0) {
        for (int k = 1; k < 10; k++) {
          if (possible(board, i, j, k)) {
            board[i][j] = k;
            globalState++;
            if (dfs(board)) { 
              return true;  
            } 
            board[i][j] = 0; 
          }
        }
        return false;
      }
    }
  }
  return true;
}

void setBoard(vector<vector<int>>& board){
    for(int i = 0; i < 9; i++){
        string s; cin >> s;
        for(int j = 0; j < 9; j++){
            board[i][j] = s[j] - '0';
        }
    }
}

void printBoard(vector<vector<int>>& board){
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

void solve(){
    
    char c; cin >> c;
    vector<vector<int>> board (9, vector<int> (9, 0));
    int n;
    switch (c) {
    case 'B': // BFS
        setBoard(board);
        n = bfs(board);
        printBoard(board);
        cout << n << endl;
        break;
    case 'I': // Iterative deepening search
        setBoard(board);
        idfs(board, 81);
        cout << globalState << endl;
        printBoard(board);
        break;
    case 'U': // Uniform-cost search
        setBoard(board);
        n = ucs(board);
        cout << n << endl;
        printBoard(board);
        break;
    case 'A': // A* search

        break;
    case 'G': // Greedy best-first search

        break;
    case 'D': // DFS
        setBoard(board);
        dfs(board);
        cout << globalState << endl;
        printBoard(board);
        break;
    default:
        cout << "Entrada incorreta." << endl;
        break;
    }

}
    
int main(){ 
    int t = 1;
    while(t--) solve();
    exit(0);
}