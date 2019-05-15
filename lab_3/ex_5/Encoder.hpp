#include <string>

#ifndef ENCODER
#define ENCODER

namespace Encoder {
  static std::string cifra;
  static std::string message;

  void print();
  int getCipherIndex(char c);
  std::string getMessage();
  std::string getCifra();

  class Enc {

    public:
      Enc(std::string cifra);
      void EncodeMessage(std::string message);
  };
}

#endif
