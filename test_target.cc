#include<iostream>
#include<gtest/gtest.h>

using namespace std;

int Foo(int a, int b) {
    return a + b;
}

TEST(Footest, ZeroEqual) {
    ASSERT_EQ(0, 0);
}


TEST(Footest, HandleNoneZeroInput) {
    EXPECT_EQ(12, Foo(4, 10));
    EXPECT_EQ(6, Foo(30, 18));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);

    int a = 1, b = 2;
    


    return RUN_ALL_TESTS();
}

