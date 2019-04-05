#include "Televisao.hpp"

Televisao::Televisao() {
  canal = 0;
  volume = 0;
}

void Televisao::setCanal(int c){
  if(c > 99) this->canal = 0;
  else if(c < 0) this->canal = 99;
  else this->canal = c;
}
void Televisao::setVolume(int v){
  if(v >= 0 && v <= 20) this->volume = v;
}
int Televisao::getCanal(){
  return this->canal;
}
int Televisao::getVolume(){
  return this->volume;
}
