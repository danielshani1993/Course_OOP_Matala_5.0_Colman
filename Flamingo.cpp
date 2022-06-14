#include "Flamingo.h"

Flamingo::Flamingo():Birds()
{
	this->m_avgHeight = 0;
}

Flamingo::Flamingo(const char* color, int childs, float avgLifetime, float incubation, float avgHeight):
	Birds(color, childs, avgLifetime, incubation)
{
	this->m_avgHeight = avgHeight;
}

Flamingo::Flamingo(ifstream& in_file) : Birds(in_file)
{
	Flamingo::loadAdditionBin(in_file);
}

Flamingo::~Flamingo()
{
}

Flamingo::Flamingo(const Flamingo& other): Birds(other.GetColor(), other.m_childCount, other.m_avgLifetime, other.m_incubationTime)
{
	this->m_avgHeight = other.GetHeight();
}


float Flamingo::GetHeight() const
{
	return this->m_avgHeight;
}

void Flamingo::Save(ofstream& out_file)const
{
	Birds::Save(out_file);
	Flamingo::saveAddition(out_file);
}

void Flamingo::Load(ifstream& in_file)
{
	Birds::load(in_file);
	Flamingo::loadAddition(in_file);
}

void Flamingo::SaveBin(ofstream& out_file)const
{
	Birds::SaveBin(out_file);
	Flamingo::saveAdditionBin(out_file);
}

void Flamingo::LoadBin(ifstream& in_file)
{
	Birds::LoadBin(in_file);
	Flamingo::loadAdditionBin(in_file);
}

void Flamingo::saveAddition(ofstream& out_file)const
{
	out_file<< this->m_avgHeight << endl;
}

void Flamingo::saveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&m_avgHeight, sizeof(m_avgHeight));
}

void Flamingo::loadAddition(ifstream& in_file)
{
	in_file >> this->m_avgHeight;
}

void Flamingo::loadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&m_avgHeight, sizeof(m_avgHeight));
}

void Flamingo::saveType(ofstream& out_file)const
{
	out_file.write((char*)"FL", 2);
}


