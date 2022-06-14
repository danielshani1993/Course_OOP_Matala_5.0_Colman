#include "Fish.h"

Fish::Fish()
{
    this->m_finCount = 0;
    this->m_gillsCount = 0;
}

Fish::Fish(const char* color, int childs, float avgLifetime, int fin, int gills): Animal(color, childs, avgLifetime)
{
	this->m_finCount = fin;
	this->m_gillsCount = gills;
}

Fish::Fish(ifstream& in_file): Animal(in_file)
{
	Fish::LoadBin(in_file);
}

Fish::~Fish()
{
}

int Fish::GetFinCount() const
{
    return this->m_finCount;
}

int Fish::GetGillsCount() const
{
    return this->m_gillsCount;
}

void Fish::Save(ofstream& out_file)const
{
	Animal::Save(out_file);
	Fish::SaveAddition(out_file);
}

void Fish::load(ifstream& in_file)
{
	Animal::Load(in_file);
	Fish::LoadAddition(in_file);
}

void Fish::LoadBin(ifstream& in_file)
{
	Animal::LoadBin(in_file);
	Fish::LoadAdditionBin(in_file);
}

void Fish::SaveBin(ofstream& out_file)const
{
	Animal::SaveBin(out_file);
	Fish::SaveAdditionBin(out_file);
}

void Fish::SaveAddition(ofstream& out_file)const
{
	out_file << this->m_finCount << endl;
	out_file<< this->m_gillsCount << endl;
}

void Fish::LoadAddition(ifstream& in_file)
{
	in_file >> this->m_finCount;
	in_file >> this->m_gillsCount;
}

void Fish::SaveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&this->m_finCount, sizeof(this->m_finCount));
	out_file.write((char*)&this->m_gillsCount, sizeof(this->m_gillsCount));
}

void Fish::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&this->m_finCount, sizeof(this->m_finCount));
	in_file.read((char*)&this->m_gillsCount, sizeof(this->m_gillsCount));
}
