#include <algorithm>
#include <stack>
#include <vector>
#include <gtest/gtest.h>

std::vector<int> getBuildingsWithSunset(std::vector<int>::const_iterator begin,
					const std::vector<int>::const_iterator& end) {
  struct Building {
    int id;
    int height;
  };

  int id = 0;
  std::stack<Building> candidates;
  while (begin != end) {
    int height = *begin++;
    while (!candidates.empty() && height >= candidates.top().height) {
      candidates.pop();
    }
    candidates.emplace(Building{id++, height});
  }
  std::vector<int> result;
  while (!candidates.empty()) {
    result.emplace_back(candidates.top().id);;
    candidates.pop();
  }
  std::sort(result.begin(), result.end());
  return result;
}

TEST(Sunset, testGetBuildings1) {
  std::vector<int> buildings = {1, 2, 3, 4, 5};  // building heights
  std::vector<int> expected = {4};  // building ids
  EXPECT_EQ(expected, getBuildingsWithSunset(buildings.cbegin(), buildings.cend()));
}

TEST(Sunset, testGetBuildings2) {
  std::vector<int> buildings = {1, 5, 2, 4, 3};  // building heights
  std::vector<int> expected = {1, 3, 4};
  EXPECT_EQ(expected, getBuildingsWithSunset(buildings.cbegin(), buildings.cend()));
}
