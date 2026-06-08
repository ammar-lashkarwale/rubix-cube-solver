#include "PatternDatabase.h"

using namespace std;

PatternDatabase::PatternDatabase(const size_t size) :
        database(size, 0xFF), size(size), numItems(0) {
}

PatternDatabase::PatternDatabase(const size_t size, uint8_t defaultVal) :
        database(size, defaultVal), size(size), numItems(0) {
}

bool PatternDatabase::setNumMoves(const uint32_t idx, const uint8_t moves) {
    uint8_t currentMoves = this->getNumMoves(idx);

    if(currentMoves == 0xF){
        ++this->numItems;
    }

    if(currentMoves > moves){
        this->database.set(idx, moves);
        return true;
    }
    return false;
}

bool PatternDatabase::setNumMoves(const RubiksCube &cube, const uint8_t moves) {
    return this->setNumMoves(this->getDatabaseIndex(cube), moves);
}

uint8_t PatternDatabase::getNumMoves(const uint32_t idx) const {
    return this->database.get(idx);
}

uint8_t PatternDatabase::getNumMoves(const RubiksCube &cube) const {
    return this->getNumMoves(this->getDatabaseIndex(cube));
}

size_t PatternDatabase::getSize() const {
    return this->size;
}

size_t PatternDatabase::getNumItems() const {
    return this->numItems;
}

bool PatternDatabase::isFull() const {
    return this->numItems == this->size;
}

void PatternDatabase::toFile(const string &fileName) const {
    ofstream outFile(fileName, ios::out | ios::binary | ios::trunc);

    if(!outFile.is_open())
        throw "Failed to open the file to write";

    outFile.write(
            reinterpret_cast<const char*>(this->database.data()),
            this->database.storageSize()
            );

    outFile.close();
}

bool PatternDatabase::fromFile(const string &fileName) {
    ifstream inFile(fileName, ios::in | ios::ate);

    if(!inFile.is_open())
        return false;

    size_t totalBytes = inFile.tellg();

    if(totalBytes != this->database.storageSize()){
        inFile.close();
        throw "Database corrupt! Failed to open Reader";
    }

    inFile.seekg(0, ios::beg);
    inFile.read(
            reinterpret_cast<char*> (this->database.data()),
            this->database.storageSize()
            );
    inFile.close();
    this->numItems = this->size;
    return true;
}

vector<uint8_t> PatternDatabase::inflate() const {
    vector<uint8_t> expandedDb;
    this->database.inflate(expandedDb);
    return expandedDb;
}

void PatternDatabase::reset() {
    if(this->numItems != 0){
        this->database.reset(0xFF);
        this->numItems = 0;
    }
}
