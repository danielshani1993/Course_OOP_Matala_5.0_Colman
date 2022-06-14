#include "MammalsFish.h"

MammalsFish::MammalsFish() : Mammals(), Fish() {}


MammalsFish::MammalsFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills)
	: Mammals(color, childs, avgLifetime, preg, milk), Fish(color, childs, avgLifetime, fin, gills){}

MammalsFish::MammalsFish(ifstream& in_file): Mammals(in_file), Fish(in_file){}


MammalsFish::~MammalsFish() = default;

void MammalsFish::Save(ofstream& out_file) const
{
	Animal:: Save(out_file);
	Mammals::SaveAddition(out_file);
	Fish::SaveAddition(out_file);
}

void MammalsFish::load(ifstream& in_file)
{
	Animal::Load(in_file);
	Mammals::LoadAddition(in_file);
	Fish::LoadAddition(in_file);
}

void MammalsFish::LoadBin(ifstream& in_file)
{
	Animal::LoadBin(in_file);
	Mammals::LoadAdditionBin(in_file);
	Fish::LoadAdditionBin(in_file);
}

void MammalsFish::SaveBin(ofstream& out_file)const
{
	Animal::SaveBin(out_file);
	Mammals::SaveAdditionBin(out_file);
	Fish::SaveAdditionBin(out_file);
}
