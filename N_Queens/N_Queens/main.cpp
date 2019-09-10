//
//  main.cpp
//  N_Queens
//
//  Created by Ayush Tiwari on 10/09/19.
//  Copyright © 2019 Ayush Tiwari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

bool noConfilcts(vector<int> const &board, int row, int col) {
    
    for(int i=0; i<board.size(); i++) {
        if(board[i] == row ||
           board[i] + i == row + col ||
           board[i] - i == row - col) {
            return false;
        }
    }
    return true;
}

vector<vector<int> > findSolutions(int dimension) {
    
    vector<vector<int> > res;
    vector<int> board;
    
    board.push_back(0);
    int j=0;
    
    while(!board.empty()) {
        
        int curr_col = (int)board.size();
        
        while(curr_col!=dimension && j < dimension && !noConfilcts(board, j, curr_col)) j++;
        
        if(curr_col==dimension) res.push_back(board);

        if(curr_col==dimension || j==dimension) {
            j = board.back()+1;
            board.pop_back();
        } else {
            board.push_back(j);
            j = 0;
        }
        
        if(board.empty() && j!=dimension) {
            board.push_back(j);
            j=0;
        }
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    vector<int> board;
    
    cout << findSolutions(8).size();
    
    return 0;
}
