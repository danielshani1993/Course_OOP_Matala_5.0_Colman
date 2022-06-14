#include "Mammals.h"

Mammals::Mammals(): Animal()
{
	cout << "Mammals constructor" << endl;
	this->m_milkLiters = 0;
	this->m_pregnancyTime = 0;
}


Mammals::Mammals(const char* color, int childs, float avgLifetime, float preg, float milk): Animal(color, childs, avgLifetime)
{
	cout << "Mammals constructor" << endl;
	this->m_milkLiters = milk;
	this->m_pregnancyTime = preg;
}

Mammals::Mammals(ifstream& in_file): Animal(in_file)
{
	cout << "Mammals constructor" << endl;
	Mammals::LoadBin(in_file);
}


Mammals::~Mammals()
{
	cout << "Mammals destructor" << endl;
}

float Mammals::GetPregnanceTime() const
{
	return this->m_pregnancyTime;
}

float Mammals::GetMilk() const
{
	return this->m_milkLiters;
}

void Mammals::Save(ofstream& out_file)const
{
	Animal::Save(out_file);
	Mammals::SaveAddition( out_file);
}

void Mammals::load(ifstream& in_file)
{
	Animal::Load(in_file);
	Mammals::LoadAddition(in_file);
}

void Mammals::LoadBin(ifstream& out_file)
{
	Animal::LoadBin(out_file);
	Mammals::LoadAdditionBin(out_file);
}

void Mammals::SaveBin(ofstream& in_file)const
{
	Animal::SaveBin(in_file);
	Mammals::SaveAdditionBin(in_file);
}

void Mammals::SaveAddition(ofstream& out_file)const
{
	out_file << this->m_milkLiters << endl;
	out_file << this->m_pregnancyTime << endl;
}

void Mammals::LoadAddition(ifstream& in_file)
{
	in_file >> this->m_milkLiters;
	in_file >> this->m_pregnancyTime;
}

void Mammals::SaveAdditionBin(ofstream& out_file) const 
{
	out_file.write((char*)&this->m_milkLiters, sizeof(this->m_milkLiters));
	out_file.write((char*)&this->m_pregnancyTime, sizeof(this->m_pregnancyTime));
}

void Mammals::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&this->m_milkLiters, sizeof(this->m_milkLiters));
	in_file.read((char*)&this->m_pregnancyTime, sizeof(this->m_pregnancyTime));
}
