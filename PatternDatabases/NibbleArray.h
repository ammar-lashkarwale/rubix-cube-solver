#ifndef NIBBLE_ARRAY_H
#define NIBBLE_ARRAY_H

#include <bits/stdc++.h>

using namespace std;

class NibbleArray {
    size_t size;
    vector<uint8_t> arr;

public:
    NibbleArray(const size_t size, const uint8_t value = 0xFF);

    uint8_t get(const size_t idx) const;

    void set(const size_t idx, const uint8_t value);

    unsigned char *data();

    const unsigned char *data() const;

    size_t storageSize() const;

    void inflate(vector<uint8_t> &dest) const;

    void reset(const uint8_t value = 0xFF);

};

#endif
