#include <iostream>
#include <string>

#include "Televisao.hpp"
#include "Controle.hpp"

using namespace std;

int main(){
  Televisao *tv = new Televisao();
  Controle *control = new Controle(tv);
  string instruction;
  int arg;
  while(cin >> instruction){
    if(instruction.compare("SC") == 0){
      cin >> arg;
      control->setCanal(arg);
    }
    if(instruction.compare("SV") == 0){
      cin >> arg;
      control->setVolume(arg);
    }
    if(instruction.compare("MC") == 0){
      cout << tv->getCanal() << endl;
    }
    if(instruction.compare("MV") == 0){
      cout << tv->getVolume() << endl;
    }
    if(instruction.compare("AC") == 0){
      control->aumentaCanal();
    }
    if(instruction.compare("AV") == 0){
      control->aumentaVolume();
    }
    if(instruction.compare("DC") == 0){
      control->diminuiCanal();
    }
    if(instruction.compare("DV") == 0){
      control->diminuiVolume();
    }
  }
  delete control;
  delete tv;
  return 0;
}
