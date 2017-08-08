#pragma once

#include "Arduino.h"
#include "StandardCplusplus.h"
#include <stdint.h>
#include <vector>

class I2CWrap {
public:
  void run(const String &verb, const String &destination,
           const std::vector<String> &sendBytes,
           const String &expectedByteCount);

private:
  void decodeResponse(uint8_t response, const String &stage = "");
  void read(uint8_t destination, uint8_t remoteRegister,
            uint8_t expectedReplyCount);
  void write(uint8_t destination, uint8_t remoteRegister,
             const std::vector<String> &sendBytes);
  std::vector<uint8_t> response_;
};
