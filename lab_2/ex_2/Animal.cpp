#include "Animal.hpp"

string Animal::getNome(){
  return this->nome;
}
int Animal::getPeso(){
  return this->peso;
}
int Animal::getTempoPesagem(int hoje){
  return hoje - this->dataPesagem;
}
void Animal::setNome(string novoNome){
  this->nome = novoNome;
}
void Animal::setPeso(int novoPeso, int novaData){
  this->peso = novoPeso;
  this->dataPesagem = novaData;
}
