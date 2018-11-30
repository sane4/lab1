#include "Exception.hpp"

Exception::Exception(const std::string &message):message(message){}
const std::string& Exception::what() const { return message; }