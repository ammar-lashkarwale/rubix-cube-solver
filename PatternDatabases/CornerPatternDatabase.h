#ifndef CORNER_PATTERN_DATABASE_H
#define CORNER_PATTERN_DATABASE_H

#include <bits/stdc++.h>
#include "../Model/RubiksCube.h"
#include "PatternDatabase.h"
#include "PermutationIndexer.h"

using namespace std;

class CornerPatternDatabase : public PatternDatabase {

    typedef RubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;

public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t defaultMoves);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;

};

#endif
