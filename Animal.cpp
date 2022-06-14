#define _CRT_SECURE_NO_WARNINGS
#include "Animal.h"

Animal::Animal():m_avgLifetime(0),m_childCount(0)
{
	SetColor("GRAY");
}

Animal::Animal(const char* color, int childs, float avgLifetime)
{
	SetColor(color);
	this->m_childCount = childs;
	this->m_avgLifetime = avgLifetime;
}

Animal::Animal(ifstream& in_file)
	:m_color(nullptr), m_avgLifetime(0), m_childCount(0)
{
	Animal::LoadBin(in_file);
}
 

Animal::~Animal(){ delete[] m_color;}
const char* Animal::GetColor() const { return m_color;}
int Animal::GetChildCount() const { return m_childCount;}
float Animal::GetLifetime() const {return m_avgLifetime;}

void Animal::SetColor(const char* color)
{
	delete[] m_color;
	m_color = new char[strlen(color) + 1];
	strcpy(m_color, color);
}

void Animal::Save(ofstream& out_file) const
{
	saveType(out_file);
	out_file << endl;
	out_file << m_color << endl;
	out_file << m_childCount << endl;
	out_file << m_avgLifetime << endl;
}

void Animal::Load(ifstream& in_file)
{
	char buff[200];
	in_file >> buff;
	SetColor(buff);
	in_file >> m_childCount;
	in_file >> m_avgLifetime;
}

void Animal::SaveBin(ofstream& out_file) const
{
	out_file.write(typeid(*this).name() + 1, 2);
	int len = strlen(m_color);
	out_file.write((char*)&len, sizeof(len));
	out_file.write(m_color, len);
	out_file.write((char*)&m_childCount, sizeof(m_childCount));
	out_file.write((char*)&m_avgLifetime, sizeof(m_avgLifetime));
}

void Animal::LoadBin(ifstream& in_file)
{
	int len;
	char buff[200];
	in_file.read((char*)&len, sizeof(len));
	in_file.read(buff, len);
	buff[len] = '\0';
	this->SetColor(buff);
	in_file.read((char*)&m_childCount, sizeof(m_childCount));
	in_file.read((char*)&m_avgLifetime, sizeof(m_avgLifetime));
}


Animal& Animal::operator=(Animal& other)
{
	if (this == &other)
	{
		return *this;
	}
	SetColor(other.GetColor());
	m_childCount = other.GetChildCount();
	m_avgLifetime = other.GetLifetime();
	return *this;
}
