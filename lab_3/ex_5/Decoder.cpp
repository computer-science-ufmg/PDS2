#include <string>
#include <iostream>
#include "Encoder.hpp"
#include "Decoder.hpp"

void Decoder::print(){
  std::cout << "Decoded message: " << Decoder::message << std::endl;
}

int Decoder::getDecipherIndex(char c){
  int value = Encoder::getCifra().find(c);
  if(value > 25 && value < 36){
    return value - 26 + (int)'0';
  }
  else if(value > -1 && value < 26){
    return value + (int)'a';
  }
  else return -1;
}

Decoder::Dec::Dec(Encoder::Enc *enc){
  this->enc = enc;
}

void Decoder::Dec::DecodeMessage(std::string message){
  int decipher_index;
  std::string dec_message = message;
  for (unsigned int i = 0; i < message.size(); i++) {
    decipher_index = getDecipherIndex(message.at(i));
    if(decipher_index != -1){
      dec_message[i] = (char)decipher_index;
    }
  }
  Decoder::message = dec_message;
}
