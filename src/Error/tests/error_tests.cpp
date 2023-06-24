#include <gtest/gtest.h>

#include <Error.h>

namespace chat {
namespace error {

code_t aCode = UNDEFINED_ERROR;
message_t aMessage = "Test message";
Error aError(aCode, aMessage);

TEST(Error, Constructor) {
  EXPECT_EQ(aError.get_message(), aMessage);
  EXPECT_EQ(aError.get_code(), aCode);
}

TEST(Error, GettersAndSetters) {
  message_t aNewMessage = "New test message";
  code_t aNewCode = UNKNOWN_ERROR;

  EXPECT_NO_THROW(aError.set_message(aNewMessage));
  EXPECT_NO_THROW(aError.set_code(aNewCode));
  EXPECT_EQ(aError.get_message(), aNewMessage);
  EXPECT_EQ(aError.get_code(), aNewCode);
  
  EXPECT_NO_THROW(aError.set_message(aMessage));
  EXPECT_NO_THROW(aError.set_code(aCode));
  EXPECT_EQ(aError.get_message(), aMessage);
  EXPECT_EQ(aError.get_code(), aCode);
}

TEST(Error, Functionality) {
  EXPECT_NO_THROW(
    try {
      throw aError;
    }
    catch (const Error& e)  {
      EXPECT_EQ(e.get_message(), aError.get_message());
      EXPECT_EQ(e.get_code(), aError.get_code());
    }
  );
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

} // namespace error
} // namespace chat