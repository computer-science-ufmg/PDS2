#include <string>

namespace Encoder {
  std::string cifra;
  std::string message;

  void print();
  std::string getMessage();
  
  class Enc {

    public:
      Enc(std::string cifra);
      void EncodeMessage(std::string message);

  }
}
