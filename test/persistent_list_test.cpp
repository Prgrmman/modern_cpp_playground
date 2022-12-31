#include <iostream>
#include <persistent_list.hpp>
#include <gtest/gtest.h>
using namespace std;

// NOTE: made from https://google.github.io/googletest/quickstart-cmake.html

TEST(PersistentList, basics) {
    PersistentList<int> list;
    ASSERT_EQ(list.get_head(), nullptr);

    auto list2 = list.prepend(1).prepend(2).prepend(3);
    ASSERT_EQ(*list2.get_head(), 3);

    auto list3 = list2.tail();
    ASSERT_EQ(*list3.get_head(), 2);

    auto list4 = list3.tail();
    ASSERT_EQ(*list4.get_head(), 1);

    // check empty tail
    auto list5 = list4.tail();
    ASSERT_EQ(list5.get_head(), nullptr);
}
