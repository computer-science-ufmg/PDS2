#include <string>
#include "Encoder.hpp"

#ifndef DECODER
#define DECODER

namespace Decoder {
  static std::string message;

  void print();
  int getDecipherIndex(char c);

  class Dec {

    public:
      Dec(Encoder::Enc *enc);
      void DecodeMessage(std::string message);

      Encoder::Enc *enc;
  };
}

#endif
