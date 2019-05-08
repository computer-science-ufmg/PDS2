#include "Solid.hpp"

Solid::Solid(double raio, double altura, double largura_base, std::string tipo_solido){
  this->raio = raio;
  this->altura = altura;
  this->largura_base = largura_base;
  this->tipo_solido = tipo_solido;
}

double Solid::getArea(){
  return 0.0;
}

double Solid::getVolume(){
  return 0.0;
}

std::string Solid::getType(){
  return this->tipo_solido;
}


Cylinder::Cylinder(double raio, double altura, double largura_base, std::string tipo_solido) : Solid(raio, altura, largura_base, tipo_solido){}

double Cylinder::getArea(){
  return (double)((2.0*this->pi*this->raio*this->altura)+(2.0*this->pi*this->raio*this->raio));
}

double Cylinder::getVolume(){
  return (double)(this->pi*this->raio*this->raio*this->altura);
}

std::string Cylinder::getType(){
  return this->tipo_solido;
}


Sphere::Sphere(double raio, double altura, double largura_base, std::string tipo_solido) : Solid(raio, altura, largura_base, tipo_solido){}

double Sphere::getArea(){
  return (double)(4.0*this->pi*this->raio*this->raio);
}

double Sphere::getVolume(){
  return (double)((4.0/3.0)*this->pi*this->raio*this->raio*this->raio);
}

std::string Sphere::getType(){
  return this->tipo_solido;
}


Cube::Cube(double raio, double altura, double largura_base, std::string tipo_solido) : Solid(raio, altura, largura_base, tipo_solido){}

double Cube::getArea(){
  return (double)(6.0*this->largura_base*this->largura_base);
}

double Cube::getVolume(){
  return (double)(this->largura_base*this->largura_base*this->largura_base);
}

std::string Cube::getType(){
  return this->tipo_solido;
}
