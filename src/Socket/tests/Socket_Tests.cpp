#include <gtest/gtest.h>

namespace chat {
int main(int argc, char** argv) {
    // Initialize the Google Test framework
    ::testing::InitGoogleTest(&argc, argv);

    // Run the tests and suppress the message
    ::testing::FLAGS_gtest_catch_exceptions = false;
    return RUN_ALL_TESTS();
}

TEST(Error, Basic) {
  EXPECT_EQ(1, 1);
}



} // namespace chat