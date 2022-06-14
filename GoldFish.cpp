#include "GoldFish.h"

GoldFish::GoldFish() : MammalsFish(), m_avgLength(0), m_avgWeight(0)
{
}

GoldFish::GoldFish(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, float avgW, float avgL):
	MammalsFish(color, childs, avgLifetime, preg, milk, fin, gills),m_avgLength(avgL), m_avgWeight(avgW) {}

GoldFish::GoldFish(ifstream& in_file): MammalsFish(in_file)
{
	GoldFish::loadAdditionBin(in_file);
}

GoldFish::~GoldFish() {}

GoldFish::GoldFish(const GoldFish& other): MammalsFish(other)
{
	m_avgLength = other.m_avgLength;
	m_avgWeight = other.m_avgWeight;
}


float GoldFish::GetWeight() const
{
	return m_avgWeight;
}

float GoldFish::GetLength() const
{
	return m_avgLength;
}

void GoldFish::Save(ofstream& out_file)const 
{
	MammalsFish::Save(out_file);
	GoldFish::saveAddition(out_file);
}

void GoldFish::Load(ifstream& in_file)
{
	MammalsFish::load(in_file);
	GoldFish::loadAddition(in_file);
}

void GoldFish::SaveBin(ofstream& out_file) const
{
	MammalsFish::SaveBin(out_file);
	GoldFish::saveAdditionBin(out_file);
}

void GoldFish::LoadBin(ifstream& in_file)
{
	MammalsFish::LoadBin(in_file);
	GoldFish::loadAdditionBin(in_file);
}

void GoldFish::saveAddition(ofstream& out_file) const
{
	out_file<< m_avgLength <<endl;
	out_file<< m_avgWeight <<endl;
}

void GoldFish::saveAdditionBin(ofstream& out_file) const
{
	out_file.write((char*)&m_avgLength, sizeof(m_avgLength));
	out_file.write((char*)&m_avgWeight, sizeof(m_avgWeight));
}

void GoldFish::loadAddition(ifstream& in_file)
{
	in_file>> m_avgLength;
	in_file>> m_avgWeight;
}

void GoldFish::loadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&m_avgLength, sizeof(m_avgLength));
	in_file.read((char*)&m_avgWeight, sizeof(m_avgWeight));
}

void GoldFish::saveType(ofstream& out_file) const
{
	out_file.write((char*)"Gold Fish", 9);
}
