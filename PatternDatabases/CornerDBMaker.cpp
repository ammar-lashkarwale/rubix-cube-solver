#include <bits/stdc++.h>
#include "CornerDBMaker.h"

using namespace std;

CornerDBMaker::CornerDBMaker(string dbFileName) {
    fileName = dbFileName;
}

CornerDBMaker::CornerDBMaker(string dbFileName, uint8_t defaultMoves) {
    fileName = dbFileName;
    cornerDB = CornerPatternDatabase(defaultMoves);
}

bool CornerDBMaker::bfsAndStore() {
    RubiksCubeBitboard rootCube;
    queue<RubiksCubeBitboard> stateQueue;
    
    stateQueue.push(rootCube);
    cornerDB.setNumMoves(rootCube, 0);
    
    int currentDepth = 0;
    
    while (!stateQueue.empty()) {
        int levelSize = stateQueue.size();
        currentDepth++;
        
        if (currentDepth == 9) break;
        
        for (int idx = 0; idx < levelSize; idx++) {
            RubiksCubeBitboard currentState = stateQueue.front();
            stateQueue.pop();
            
            for (int i = 0; i < 18; i++) {
                auto nextMove = RubiksCube::MOVE(i);
                currentState.move(nextMove);
                
                if ((int) cornerDB.getNumMoves(currentState) > currentDepth) {
                    cornerDB.setNumMoves(currentState, currentDepth);
                    stateQueue.push(currentState);
                }
                
                currentState.invert(nextMove);
            }
        }
    }

    cornerDB.toFile(fileName);
    return true;
}
