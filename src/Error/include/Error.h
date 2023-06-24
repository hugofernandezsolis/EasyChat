#pragma once

#include <string>
#include <exception>

namespace chat {
namespace error {

enum code_t : uint {
  UNDEFINED_ERROR,
  UNKNOWN_ERROR
};

typedef std::string message_t;


class Error : private std::exception {
  public:
    Error(const code_t& iCode, const message_t& iMessage);

    code_t get_code(void) const;
    message_t get_message(void) const;

    void set_code(const code_t& iCode);
    void set_message(const message_t& iMessage);

    std::string what(void);

  private:
    code_t code_;
    message_t message_;
};

} // namespace error
} // namespace chat