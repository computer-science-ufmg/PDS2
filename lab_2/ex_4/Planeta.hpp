#include <vector>

#include "Astro.hpp"

class Planeta: public Astro {
  public:
    Planeta(std::string name, unsigned int radius, int temperature, float gravity, bool is_gas);
    ~Planeta();
    std::vector<Astro*> get_moons();
    void add_moon(Astro* moon);
  private:
    std::vector<Astro*> moons;
};
