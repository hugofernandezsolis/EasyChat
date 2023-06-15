#include <gtest/gtest.h>

// Example test case
TEST(ExampleTestCase, ExampleTest) {
    EXPECT_EQ(2 + 2, 4);
    ASSERT_TRUE(true);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
