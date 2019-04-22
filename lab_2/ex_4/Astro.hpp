#include <string>

class Astro{
  public:
    Astro();
    Astro(std::string name, unsigned int radius, int temperature, float gravity, bool is_gas);
    bool is_gas;
    std::string get_name();
    unsigned int get_radius();
    int get_average_temperature();
    float get_gravity();
    void set_name(std::string name);
    void set_radius(unsigned int radius);
    void set_average_temperature(int temperature);
    void set_gravity(float gravity);
  protected:
    std::string name;
    unsigned int radius;
    int average_temperature;
    float gravity;
};
