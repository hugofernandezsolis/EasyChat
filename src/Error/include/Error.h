#include <iostream>


namespace ect {

typedef std::string ErrorMessage;

enum ErrorCode {
  UNDEFINED_ERROR = 0,
  UNKNOWN_ERROR = 1
}; 

/* 
 * Defines a basic Error.
 */
class Error { 

  private:
    ErrorMessage _message;
    ErrorCode _code;

  public:
    Error(const ErrorMessage& iMessage = "", const ErrorCode& iCode = UNDEFINED_ERROR);

    const ErrorMessage& get_message(void) const;
    const ErrorCode& get_code(void) const;

    void set_message(const ErrorMessage& iMessage);
    void set_code(const ErrorCode& iCode);
};

} // namespace ect