#include <bits/stdc++.h>
using namespace std;
    
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
#define pb push_back
    
typedef long long ll;
     
vector<vector<int>> board (9, vector<int> (9, 0));

void setBoard(){
    for(int i = 0; i < 9; i++){
        string s; cin >> s;
        for(int j = 0; j < 9; j++){
            board[i][j] = s[j] - '0';
        }
    }
}

void printBoard(){
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            cout << board[i][j];
        }
        cout << " ";
    }
}

void solve(){
    
    char c; cin >> c;
    setBoard();

    switch (c) {
    case 'B': // BFS
        
        break;
    case 'I': // Iterative deepening search

        break;
    case 'U': // Uniform-cost search

        break;
    case 'A': // A* search

        break;
    case 'G': // Greedy best-first search

        break;
    default:
        cout << "Entrada incorreta." << endl;
        break;
    }

    printBoard();

}
    
int main(){ 
    int t = 1;
    while(t--) solve();
    exit(0);
}