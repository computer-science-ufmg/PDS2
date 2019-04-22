#include <fstream>

#include "SistemaSolar.hpp"

using namespace std;

SistemaSolar::SistemaSolar(){

}

SistemaSolar::~SistemaSolar(){
  for (unsigned int i = 0; i < this->planets.size(); i++) {
    delete this->planets[i];
  }
  for (unsigned int i = 0; i < this->stars.size(); i++) {
    delete this->stars[i];
  }
}

void SistemaSolar::read_astro(ifstream &file){
  string type;

  file >> type;
  if(type == "Estrela"){
    this->read_star(file);
  }
  else if(type == "Planeta"){
    this->read_planet(file);
  }
  else if(type == "Lua"){
    this->read_moon(file);
  }
}

void SistemaSolar::read_star(ifstream &file){
  string instruction, name, is_gas;
  int temperature;
  unsigned int radius;
  float gravity;

  file >> name;
  file >> instruction;
  if(instruction != "Temperatura") exit(2);
  file >> temperature;
  file >> instruction;
  if(instruction != "Raio") exit(2);
  file >> radius;
  file >> instruction;
  if(instruction != "Gravidade") exit(2);
  file >> gravity;
  file >> instruction;
  if(instruction != "Gasoso") exit(2);
  file >> is_gas;

  Astro* star = new Astro(name, radius, temperature, gravity, is_gas == "True");
  this->stars.push_back(star);
}

void SistemaSolar::read_planet(ifstream &file){
  string instruction, name, is_gas;
  int temperature;
  unsigned int radius;
  float gravity;

  file >> name;
  file >> instruction;
  if(instruction != "Temperatura") exit(2);
  file >> temperature;
  file >> instruction;
  if(instruction != "Raio") exit(2);
  file >> radius;
  file >> instruction;
  if(instruction != "Gravidade") exit(2);
  file >> gravity;
  file >> instruction;
  if(instruction != "Gasoso") exit(2);
  file >> is_gas;

  Planeta* planet = new Planeta(name, radius, temperature, gravity, is_gas == "True");
  this->planets.push_back(planet);
}

void SistemaSolar::read_moon(ifstream &file){
  string instruction, name, orbited_planet, is_gas;
  int temperature;
  unsigned int radius;
  float gravity;
  bool planet_found = false;

  file >> name;
  file >> instruction;
  if(instruction != "Orbita") exit(2);
  file >> orbited_planet;
  file >> instruction;
  if(instruction != "Temperatura") exit(2);
  file >> temperature;
  file >> instruction;
  if(instruction != "Raio") exit(2);
  file >> radius;
  file >> instruction;
  if(instruction != "Gravidade") exit(2);
  file >> gravity;
  file >> instruction;
  if(instruction != "Gasoso") exit(2);
  file >> is_gas;

  Astro* moon = new Astro(name, radius, temperature, gravity, is_gas == "True");
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if(planet->get_name() == orbited_planet){
      planet_found = true;
      planet->add_moon(moon);
    }
  }
  if(!planet_found) delete moon;
}

vector<Planeta*> SistemaSolar::get_planets(){
  return this->planets;
}

vector<Astro*> SistemaSolar::get_stars(){
  return this->stars;
}

void SistemaSolar::add_planet(Planeta* planet){
  this->planets.push_back(planet);
}

void SistemaSolar::add_star(Astro* star){
  this->stars.push_back(star);
}

int SistemaSolar::get_astros_number(){
  int astros_number = this->planets.size() + this->stars.size();
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    astros_number += planet->get_moons().size();
  }
  return astros_number;
}

Planeta* SistemaSolar::get_largest_planet(){
  Planeta* largest_planet = NULL;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if((largest_planet == NULL) || (planet->get_radius() > largest_planet->get_radius())){
      largest_planet = planet;
    }
  }
  return largest_planet;
}

Planeta* SistemaSolar::get_smaller_planet(){
  Planeta* smaller_planet = NULL;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if((smaller_planet == NULL) || (planet->get_radius() < smaller_planet->get_radius())){
      smaller_planet = planet;
    }
  }
  return smaller_planet;
}

Planeta* SistemaSolar::get_hotest_planet(){
  Planeta* hotest_planet = NULL;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if((hotest_planet == NULL) || (planet->get_average_temperature() > hotest_planet->get_average_temperature())){
      hotest_planet = planet;
    }
  }
  return hotest_planet;
}

Planeta* SistemaSolar::get_coldest_planet(){
  Planeta* coldest_planet = NULL;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if((coldest_planet == NULL) || (planet->get_average_temperature() < coldest_planet->get_average_temperature())){
      coldest_planet = planet;
    }
  }
  return coldest_planet;
}

Planeta* SistemaSolar::get_most_moons(){
  Planeta* most_moons = NULL;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if((most_moons == NULL) || (planet->get_moons().size() > most_moons->get_moons().size())){
      most_moons = planet;
    }
  }
  return most_moons;
}

Astro* SistemaSolar:: get_largest_star(){
  Astro* largest_star = NULL;
  for (vector<Astro*>::iterator it = this->stars.begin(); it != this->stars.end(); ++it) {
    Astro* star = *it;
    if((largest_star == NULL) || (star->get_radius() > largest_star->get_radius())){
      largest_star = star;
    }
  }
  return largest_star;
}

int SistemaSolar::get_planets_number(){
  return this->planets.size();
}

int SistemaSolar::get_solid_planets_number(){
  int solid_planets = 0;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    if(!planet->is_gas) solid_planets++;
  }
  return solid_planets;
}

double SistemaSolar::get_average_moons_per_planet(){
  int total_moons = 0;
  double moon_average;
  for (vector<Planeta*>::iterator it = this->planets.begin(); it != this->planets.end(); ++it) {
    Planeta* planet = *it;
    total_moons += planet->get_moons().size();
  }
  moon_average = ((float)total_moons)/((float)this->planets.size());
  return moon_average;
}
