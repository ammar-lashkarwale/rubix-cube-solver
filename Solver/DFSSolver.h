#ifndef DFS_SOLVER_H
#define DFS_SOLVER_H

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

using namespace std;

template<typename T, typename H>
class DFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    int maxDepth;

    bool dfs(int currentDepth) {
        if (rubiksCube.isSolved()) return true;
        if (currentDepth > maxDepth) return false;
        
        for (int i = 0; i < 18; i++) {
            rubiksCube.move(RubiksCube::MOVE(i));
            moves.push_back(RubiksCube::MOVE(i));
            
            if (dfs(currentDepth + 1)) return true;
            
            moves.pop_back();
            rubiksCube.invert(RubiksCube::MOVE(i));
        }
        return false;
    }

public:
    T rubiksCube;

    DFSSolver(T initialCube, int depthLimit = 8) {
        rubiksCube = initialCube;
        maxDepth = depthLimit;
    }

    vector<RubiksCube::MOVE> solve() {
        dfs(1);
        return moves;
    }
};

#endif
