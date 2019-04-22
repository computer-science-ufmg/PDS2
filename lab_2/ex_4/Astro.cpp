#include "Astro.hpp"

using namespace std;

Astro::Astro(){
}

Astro::Astro(string name, unsigned int radius, int temperature, float gravity, bool is_gas){
  this->name = name;
  this->radius = radius;
  this->average_temperature = temperature;
  this->gravity = gravity;
  this->is_gas = is_gas;
}

string Astro::get_name(){
  return this->name;
}

unsigned int Astro::get_radius(){
  return this->radius;
}

int Astro::get_average_temperature(){
  return this->average_temperature;
}

float Astro::get_gravity(){
  return this->gravity;
}

void Astro::set_name(string name){
  this->name = name;
}

void Astro::set_radius(unsigned int radius){
  this->radius = radius;
}

void Astro::set_average_temperature(int temperature){
  this->average_temperature = temperature;
}

void Astro::set_gravity(float gravity){
  this->gravity = gravity;
}
