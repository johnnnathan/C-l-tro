
#include "playingCard.h"
#include <iomanip>
#include <sstream>

int int_to_hex(int value);

int int_to_hex(int value){
  std::stringstream ss;
  ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(value);
  std::string hexString = ss.str();
  int mask;
  std::istringstream(hexString) >> std::hex >> mask;
  return mask;
}
