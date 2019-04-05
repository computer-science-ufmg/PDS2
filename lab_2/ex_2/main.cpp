#include "Animal.hpp"
#include <iostream>
#include <map>

using namespace std;

int main(){
  int hoje = 0;
  char instruction;
  map<string, Animal*> animals;
  while(cin >> instruction){
    if(instruction == 'S'){
      for (map<string, Animal*>::iterator it = animals.begin(); it != animals.end(); ++it) {
        Animal *animal = it->second;
        if(animal->getTempoPesagem(hoje) >= 2){
          cout << "Semana " << hoje << ": Aviso! Animal " << animal->getNome() << " nao foi pesado por " << animal->getTempoPesagem(hoje) << " semanas." << endl;
        }
      }
      cin >> hoje;
    }
    else if(instruction == 'P'){
      string nome;
      int peso;
      cin >> nome >> peso;
      if(animals.find(nome) == animals.end()){
        Animal *animal = new Animal();
        animal->setNome(nome);
        animals[nome] = animal;
      }
      if(peso < 0.9*animals[nome]->getPeso()){
        cout << "Semana " << hoje << ": Aviso! Animal " << nome << " perdeu 10% ou mais de seu peso." << endl;
      }
      animals[nome]->setPeso(peso, hoje);
    }
  }
  for (map<string, Animal*>::iterator it = animals.begin(); it != animals.end(); ++it) {
    Animal *animal = it->second;
    if(animal->getTempoPesagem(hoje) >= 2){
      cout << "Semana " << hoje << ": Aviso! Animal " << animal->getNome() << " nao foi pesado por " << animal->getTempoPesagem(hoje) << " semanas." << endl;
    }
  }
  for (map<string, Animal*>::iterator it = animals.begin(); it != animals.end(); ++it) {
    Animal *animal = it->second;
    delete animal;
  }
}
