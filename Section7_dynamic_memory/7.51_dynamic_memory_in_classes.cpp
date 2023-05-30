#include <cstddef>
#include <iostream>
#include <string>
#include <assert.h>

class DynamicIntArray {
 public:
  DynamicIntArray() : moptrData(nullptr), mSize(0), mCapacity(0) {}
  DynamicIntArray(const DynamicIntArray& otherArray);
  ~DynamicIntArray();

  inline size_t Size() const { return mSize; }
  inline size_t Capacity() const { return mCapacity; }

  // allocates the dynamic array
  bool Init(size_t capacity = INITIAL_CAPACITY);

  bool Reserve(size_t capacity);

  bool Resize(size_t newSize);

  const int& operator[](size_t index) const;
  int& operator[](size_t index);

 private:
  int* moptrData;
  size_t mSize;
  size_t mCapacity;

  static const size_t INITIAL_CAPACITY = 10;
};

DynamicIntArray::DynamicIntArray(const DynamicIntArray& otherArray) {
  bool result = Init(otherArray.mCapacity);
  assert(result);

  mSize = otherArray.mSize;

  for (size_t i = 0; i < mSize; ++i) {
    moptrData[i] = otherArray.moptrData[i];
  }
}

void FuncFoo(DynamicIntArray copiedDynamicArray) {
  // do something with copiedDynamicArray
}

// TODO: Implement this
// const int& DynamicIntArray::operator[](size_t index) const {
  
// }
  
// // TODO: Implement this
// int& operator[](size_t index);

int main() {

  DynamicIntArray dynArray;

  int element0 = dynArray[0];
  dynArray[2] = 10;

  std::cout << "!!!Dynamic memory!!!" << std::endl;
  return 0;
}
