#include <Socket.h>

std::string error_c(void) {
  chat::error::Error err(chat::error::UNDEFINED_ERROR, "TEST");
  return err.what();
}
