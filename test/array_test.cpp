#include "array.h"
#include "gtest/gtest.h"

TEST(array, binary_find)
{
    std::vector<int> a;
    for (int i = 0; i < 10; i += 2) {
        a.push_back(i);
    }

    auto ret = binary_find(a.begin(), a.end(), 2, std::less<int>());
    ASSERT_TRUE(ret.second);
    ASSERT_EQ((ret.first - a.begin()), 1);

    ret = binary_find(a.begin(), a.end(), 3, std::less<int>());
    ASSERT_FALSE(ret.second);
    ASSERT_EQ((ret.first - a.begin()), 2);
}

TEST(array, add_unique)
{
    std::vector<int> a;
    for (int i = 0; i < 10; i += 2) {
        a.push_back(i);
    }

    auto ret = add_unique(a, 2, std::less<int>());
    ASSERT_FALSE(ret.second);
    ASSERT_EQ((ret.first - a.begin()), 1);

    ret = add_unique(a, 3, std::less<int>());
    ASSERT_TRUE(ret.second);
    ASSERT_EQ((ret.first - a.begin()), 2);
}
