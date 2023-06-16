#include <Error.h>


namespace ect {

Error::Error(const ErrorMessage& iMessage, const ErrorCode& iCode):
 _message(iMessage),
 _code(iCode)
 {}

const ErrorMessage& Error::get_message(void) const {
  return _message;
}

const ErrorCode& Error::get_code(void) const {
  return _code;
}

void Error::set_message(const ErrorMessage& iMessage) {
  _message = iMessage;
}

void Error::set_code(const ErrorCode& iCode) {
 _code = iCode;
}

} // namespace ect