#include "Birds.h"

Birds::Birds(): Animal()
{
	this->m_incubationTime = 0;
}

Birds::Birds(const char* color, int childs, float avgLifetime, float incubation): Animal(color, childs, avgLifetime)
{
	this->m_incubationTime = incubation;
}

Birds::Birds(ifstream& in_file)
{
}

Birds::~Birds()
{
	
}

float Birds::GetIncubationTime() const
{
    return this->m_incubationTime;
}

void Birds::Save(ofstream& out_file)const
{
	Animal::Save(out_file);
	Birds::SaveAddition( out_file );
}

void Birds::load(ifstream& in_file)
{
	Animal::Load(in_file);
	Birds::LoadAddition( in_file );
}

void Birds::LoadBin(ifstream& in_file)
{
	Animal::LoadBin(in_file);
	Birds::LoadAdditionBin( in_file );
}

void Birds::SaveBin(ofstream& out_file)const
{
	Animal::SaveBin(out_file);
	Birds::SaveAdditionBin( out_file );
}

void Birds::SaveAddition(ofstream& out_file)const
{
	out_file << this->m_incubationTime << endl;
}

void Birds::LoadAddition(ifstream& in_file)
{
	in_file >> this->m_incubationTime;
}

void Birds::SaveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&this->m_incubationTime, sizeof(this->m_incubationTime));
}

void Birds::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&this->m_incubationTime, sizeof(this->m_incubationTime));
}

