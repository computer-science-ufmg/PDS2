#include <string>
#include <iostream>
#include "Encoder.hpp"

void Encoder::print(){
  std::cout << "Encoded message: " << Encoder::message << std::endl;
}

int Encoder::getCipherIndex(char c){
  int value = (int)c;
  if(value > 47 && value < 58){
    return 26 + value - (int)'0';
  }
  else if(value > 96 && value < 123){
    return value - (int)'a';
  }
  else return -1;
}

std::string Encoder::getMessage(){
  return Encoder::message;
}

std::string Encoder::getCifra(){
  return Encoder::cifra;
}

Encoder::Enc::Enc(std::string cifra){
  Encoder::cifra = cifra;
}

void Encoder::Enc::EncodeMessage(std::string message){
  int cipher_index;
  std::string enc_message = message;
  for (unsigned int i = 0; i < message.size(); i++) {
    cipher_index = getCipherIndex(message.at(i));
    if(cipher_index != -1){
      enc_message[i] = cifra.at(cipher_index);
    }
  }
  Encoder::message = enc_message;
}
