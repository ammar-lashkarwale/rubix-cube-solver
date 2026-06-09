#include <bits/stdc++.h>
#include "CornerPatternDatabase.h"

using namespace std;

CornerPatternDatabase::CornerPatternDatabase() : PatternDatabase(100179840) {}

CornerPatternDatabase::CornerPatternDatabase(uint8_t defaultMoves) : PatternDatabase(100179840, defaultMoves) {}

uint32_t CornerPatternDatabase::getDatabaseIndex(const RubiksCube &cube) const {
    array<uint8_t, 8> cornerPositions = {
            cube.getCornerIndex(0),
            cube.getCornerIndex(1),
            cube.getCornerIndex(2),
            cube.getCornerIndex(3),
            cube.getCornerIndex(4),
            cube.getCornerIndex(5),
            cube.getCornerIndex(6),
            cube.getCornerIndex(7),
    };

    uint32_t permRank = this->permIndexer.rank(cornerPositions);

    array<uint8_t, 7> orientationsArr = {
            cube.getCornerOrientation(0),
            cube.getCornerOrientation(1),
            cube.getCornerOrientation(2),
            cube.getCornerOrientation(3),
            cube.getCornerOrientation(4),
            cube.getCornerOrientation(5),
            cube.getCornerOrientation(6),
    };

    uint32_t orientationBase3 =
            orientationsArr[0] * 729 +
            orientationsArr[1] * 243 +
            orientationsArr[2] * 81 +
            orientationsArr[3] * 27 +
            orientationsArr[4] * 9 +
            orientationsArr[5] * 3 +
            orientationsArr[6];

    return (permRank * 2187) + orientationBase3;
}
