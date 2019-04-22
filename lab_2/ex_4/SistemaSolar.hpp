#include <vector>
#include <fstream>

#include "Planeta.hpp"

class SistemaSolar{
  public:
    SistemaSolar();
    ~SistemaSolar();
    void read_astro(std::ifstream &file);
    std::vector<Planeta*> get_planets();
    std::vector<Astro*> get_stars();
    void add_planet(Planeta *planet);
    void add_star(Astro *star);
    int get_astros_number();
    Planeta* get_largest_planet();
    Planeta* get_smaller_planet();
    Planeta* get_hotest_planet();
    Planeta* get_coldest_planet();
    Planeta* get_most_moons();
    Astro* get_largest_star();
    int get_planets_number();
    int get_solid_planets_number();
    double get_average_moons_per_planet();
  private:
    std::vector<Planeta*> planets;
    std::vector<Astro*> stars;
    void read_star(std::ifstream &file);
    void read_planet(std::ifstream &file);
    void read_moon(std::ifstream &file);
};
