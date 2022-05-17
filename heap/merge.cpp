#include <queue>
#include <vector>
#include <gtest/gtest.h>

struct IteratorCurrentAndEnd {
  bool operator>(const IteratorCurrentAndEnd& other) const {
    return *current > *other.current;
  }

  std::vector<int>::const_iterator current;
  std::vector<int>::const_iterator end;
};

std::vector<int> mergeSortedArrays(const std::vector<std::vector<int>>& arrays) {
  std::priority_queue<IteratorCurrentAndEnd, std::vector<IteratorCurrentAndEnd>, std::greater<>> min_heap;
  for (const std::vector<int>& array : arrays) {
    if (!array.empty()) {
      min_heap.emplace(IteratorCurrentAndEnd{array.cbegin(), array.cend()});
    }
  }
  std::vector<int> result;
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
  std::vector<std::vector<int>> arrays = {
    {3, 5, 7},
    {0, 6},
    {0, 6, 28},
  };
  std::vector<int> expected = {0, 0, 3, 5, 6, 6, 7, 28};
  EXPECT_EQ(expected, mergeSortedArrays(arrays));
}
