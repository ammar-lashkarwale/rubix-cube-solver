#include <bits/stdc++.h>
#include "NibbleArray.h"

using namespace std;

NibbleArray::NibbleArray(const size_t size, const uint8_t value) :
        size(size), arr(size / 2 + 1, value) {
}

uint8_t NibbleArray::get(const size_t idx) const {
    size_t byteIdx = idx / 2;
    assert(idx <= this->size);
    uint8_t dataByte = this->arr.at(byteIdx);

    if (idx % 2) {
        return dataByte & 0x0F;
    } else {
        return dataByte >> 4;
    }
}

void NibbleArray::set(const size_t idx, const uint8_t value) {
    size_t byteIdx = idx / 2;
    uint8_t currentByte = this->arr.at(byteIdx);
    assert(idx <= this->size);

    if (idx % 2) {
        this->arr.at(byteIdx) = (currentByte & 0xF0) | (value & 0x0F);
    } else {
        this->arr.at(byteIdx) = (currentByte & 0x0F) | (value << 4);
    }
}

uint8_t *NibbleArray::data() {
    return this->arr.data();
}

const uint8_t *NibbleArray::data() const {
    return this->arr.data();
}

size_t NibbleArray::storageSize() const {
    return this->arr.size();
}

void NibbleArray::inflate(vector<uint8_t> &dest) const {
    dest.reserve(this->size);

    for (unsigned i = 0; i < this->size; ++i)
        dest.push_back(this->get(i));
}

void NibbleArray::reset(const uint8_t value) {
    fill(this->arr.begin(), this->arr.end(), value);
}
