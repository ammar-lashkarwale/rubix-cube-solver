#ifndef CORNER_DB_MAKER_H
#define CORNER_DB_MAKER_H

#include <bits/stdc++.h>
#include "CornerPatternDatabase.h"
#include "../Model/RubiksCubeBitboard.cpp"

using namespace std;

class CornerDBMaker {
private:
    string fileName;
    CornerPatternDatabase cornerDB;

public:
    CornerDBMaker(string dbFileName);
    CornerDBMaker(string dbFileName, uint8_t defaultMoves);

    bool bfsAndStore();
};

#endif
