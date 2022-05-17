#include <queue>
#include <vector>
#include <gtest/gtest.h>

using Integers = std::vector<int>;

struct IteratorCurrentAndEnd {
  bool operator>(const IteratorCurrentAndEnd& other) const {
    return *current > *other.current;
  }

  Integers::const_iterator current;
  Integers::const_iterator end;
};

Integers mergeSortedArrays(const std::vector<Integers>& arrays) {
  std::priority_queue<IteratorCurrentAndEnd, std::vector<IteratorCurrentAndEnd>, std::greater<>> min_heap;
  for (const Integers& array : arrays) {
    if (!array.empty()) {
      min_heap.emplace(IteratorCurrentAndEnd{array.cbegin(), array.cend()});
    }
  }
  Integers result;
  while (!min_heap.empty()) {
    IteratorCurrentAndEnd smallest_array = min_heap.top();
    min_heap.pop();
    result.emplace_back(*smallest_array.current);
    if (std::next(smallest_array.current) != smallest_array.end) {
      min_heap.emplace(IteratorCurrentAndEnd{std::next(smallest_array.current), smallest_array.end});
    }
  }
  return result;
}

TEST(Merge, testMergeSortedArrays) {
  std::vector<Integers> arrays = {
    {3, 5, 7},
    {0, 6},
    {0, 6, 28},
  };
  Integers expected = {0, 0, 3, 5, 6, 6, 7, 28};
  EXPECT_EQ(expected, mergeSortedArrays(arrays));
}
