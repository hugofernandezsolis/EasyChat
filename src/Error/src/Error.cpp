#include <Error.h>

namespace chat {
namespace error {

Error::Error(const code_t& iCode, const message_t& iMessage):
  code_(iCode),
  message_(iMessage)
  {}

code_t Error::get_code(void) const {
  return code_;
}

message_t Error::get_message(void) const {
  return message_;
}

void Error::set_code(const code_t& iCode) {
  code_ = iCode;
}

void Error::set_message(const message_t& iMessage) {
  message_ = iMessage;
}

std::string Error::what(void) {
  return std::string(std::to_string(code_) + ": " + message_);
}

} // namespace error
} // namespace chat