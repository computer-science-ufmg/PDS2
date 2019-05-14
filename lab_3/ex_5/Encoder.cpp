#include <string>
#include "Encoder.hpp"

Encoder::Enc::Enc(std::string cifra){
  this->cifra = cifra;
}

void Encoder::Enc::EncodeMessage(std::string message){

}

void Encoder::print(){
  std::cout << "Encoded message: " << Encoder::message << std::endl;
}

std::string Encoder::getMessage(){
  return Encoder::message;
}
