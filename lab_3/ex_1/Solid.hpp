#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Solid{
	public:
		const double pi = 3.14; //Nao modifique este valor.
		double raio;
		double altura;
		double largura_base;
		std::string tipo_solido;

		Solid(double raio, double altura, double largura_base, std::string tipo_solido);
		double virtual getArea();
		double virtual getVolume();
		std::string virtual getType();
};

class Cylinder : public Solid{
	public:
		Cylinder(double raio, double altura, double largura_base, std::string tipo_solido);
		double virtual getArea();
		double virtual getVolume();
		std::string virtual getType();
};

class Sphere : public Solid{
	public:
		Sphere(double raio, double altura, double largura_base, std::string tipo_solido);
		double getArea() override;
		double getVolume() override;
		std::string getType() override;
};

class Cube : public Solid{
	public:
		Cube(double raio, double altura, double largura_base, std::string tipo_solido);
		double getArea() override;
		double getVolume() override;
		std::string getType() override;
};

#endif
