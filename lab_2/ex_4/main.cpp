#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>

#include "SistemaSolar.hpp"

using namespace std;

int main() {
  Astro *largest_star;
  Planeta *most_moons, *hotest_planet, *coldest_planet, *largest_planet, *smaller_planet;
  SistemaSolar* solar_sistem = new SistemaSolar();
  ifstream file;
  string file_name, instruction;

  cin >> file_name;
  file.open(file_name);
  if(!file.is_open()){
    cout << "Arquivo não aberto!" << endl;
    return 1;
  }
  while(file >> instruction){
    if(instruction == "defastro"){
      solar_sistem->read_astro(file);
    }
  }

  largest_star = solar_sistem->get_largest_star();
  most_moons = solar_sistem->get_most_moons();
  hotest_planet = solar_sistem->get_hotest_planet();
  coldest_planet = solar_sistem->get_coldest_planet();
  largest_planet = solar_sistem->get_largest_planet();
  smaller_planet = solar_sistem->get_smaller_planet();

  cout << largest_star->get_name() << endl;
  cout << largest_star->get_average_temperature() << endl;
  cout << solar_sistem->get_astros_number() << endl;
  cout << solar_sistem->get_planets_number() << endl;
  cout << solar_sistem->get_solid_planets_number() << endl;
  cout << fixed << setprecision(2) << solar_sistem->get_average_moons_per_planet() << endl;
  cout << most_moons->get_name() << endl;
  cout << hotest_planet->get_name() << endl;
  cout << coldest_planet->get_name() << endl;
  cout << largest_planet->get_name() << endl;
  cout << smaller_planet->get_name() << endl;

  delete solar_sistem;
}
