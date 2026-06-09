#ifndef BFS_SOLVER_H
#define BFS_SOLVER_H

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"

using namespace std;

template<typename T, typename H>
class BFSSolver {
private:
    vector<RubiksCube::MOVE> moves;
    unordered_map<T, bool, H> visitedStates;
    unordered_map<T, RubiksCube::MOVE, H> parentMove;

    T bfs() {
        queue<T> stateQueue;
        stateQueue.push(rubiksCube);
        visitedStates[rubiksCube] = true;

        while (!stateQueue.empty()) {
            T currentState = stateQueue.front();
            stateQueue.pop();
            
            if (currentState.isSolved()) {
                return currentState;
            }
            
            for (int i = 0; i < 18; i++) {
                auto nextMove = RubiksCube::MOVE(i);
                currentState.move(nextMove);
                
                if (!visitedStates[currentState]) {
                    visitedStates[currentState] = true;
                    parentMove[currentState] = nextMove;
                    stateQueue.push(currentState);
                }
                
                currentState.invert(nextMove);
            }
        }
        return rubiksCube;
    }

public:
    T rubiksCube;

    BFSSolver(T initialCube) {
        rubiksCube = initialCube;
    }

    vector<RubiksCube::MOVE> solve() {
        T solvedCube = bfs();
        assert(solvedCube.isSolved());
        T backtrackCube = solvedCube;
        
        while (!(backtrackCube == rubiksCube)) {
            RubiksCube::MOVE lastMove = parentMove[backtrackCube];
            moves.push_back(lastMove);
            backtrackCube.invert(lastMove);
        }
        
        rubiksCube = solvedCube;
        reverse(moves.begin(), moves.end());
        return moves;
    }
};

#endif
