#include "Planeta.hpp"

using namespace std;

Planeta::Planeta(string name, unsigned int radius, int temperature, float gravity, bool is_gas){
  this->name = name;
  this->radius = radius;
  this->average_temperature = temperature;
  this->gravity = gravity;
  this->is_gas = is_gas;
}

Planeta::~Planeta(){
  for (unsigned int i = 0; i < this->moons.size(); i++) {
    delete this->moons[i];
  }
}

vector<Astro*> Planeta::get_moons(){
  return this->moons;
}

void Planeta::add_moon(Astro *moon){
  this->moons.push_back(moon);
}
