#include "Mermaid.h"

Mermaid::Mermaid(): MammalsFish(), m_firstName(nullptr), m_lastName(nullptr)
{
	this->SetFirstName(nullptr);
	this->SetLastName(nullptr);
}

Mermaid::Mermaid(const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName)
     :MammalsFish( color, childs, avgLifetime, preg, milk, fin, gills), m_firstName(nullptr), m_lastName(nullptr)
{
    this->SetFirstName(firstName);
	this->SetLastName(lastName);
}

Mermaid::Mermaid(ifstream& in_file):MammalsFish(in_file)
{
	Mermaid::loadAdditionBin(in_file);
}



Mermaid::~Mermaid()
{
	delete[] m_firstName;
	delete[] m_lastName;
}

Mermaid::Mermaid(const Mermaid& other): MammalsFish(other)
{
	this->SetFirstName(other.m_firstName);
	this->SetLastName(other.m_lastName);
}

const char* Mermaid::GetFirstName() const
{
    return this->m_firstName;
}

const char* Mermaid::GetLastName() const
{
    return this->m_lastName;
}

void Mermaid::SetFirstName(const char* firstName)
{
	if (this->m_firstName != nullptr)
	{
		delete[] this->m_firstName;
	}
	this->m_firstName = new char[strlen(firstName) + 1];
	strcpy(this->m_firstName, firstName);
}

void Mermaid::SetLastName(const char* lastName)
{
	if (this->m_lastName != nullptr)
	{
		delete[] this->m_lastName;
	}
	this->m_lastName = new char[strlen(lastName) + 1];
	strcpy(this->m_lastName, lastName);
}

void Mermaid::Save(ofstream& out_file)const
{
	MammalsFish::Save(out_file);
	Mermaid::saveAdditionBin(out_file);
}

void Mermaid::Load(ifstream& in_file)
{
	MammalsFish::load(in_file);
	Mermaid::loadAdditionBin(in_file);
}

void Mermaid::SaveBin(ofstream& out_file)const
{
	MammalsFish::SaveBin(out_file);
	Mermaid::saveAdditionBin(out_file);
}

void Mermaid::LoadBin(ifstream& in_file)
{
	MammalsFish::LoadBin(in_file);
	Mermaid::loadAdditionBin(in_file);
}

void Mermaid::saveAddition(ofstream& out_file)const
{
	out_file << this->m_firstName << endl;
	out_file << this->m_lastName << endl;
}

void Mermaid::saveAdditionBin(ofstream& out_file)const
{
	out_file.write((char*)&this->m_firstName, sizeof(this->m_firstName)*strlen( this->m_firstName));
	out_file.write((char*)&this->m_lastName, sizeof(this->m_lastName)* strlen(this->m_lastName));
}

void Mermaid::loadAddition(ifstream& in_file)
{
	char buffer[200];
	in_file >> buffer;
	this->SetFirstName(buffer);
	in_file >> buffer;
	this->SetLastName(buffer);
}

void Mermaid::loadAdditionBin(ifstream& in_file)
{
	int len;
	char buff[200];
	in_file.read((char*)&len, sizeof(len));
	in_file.read(buff, len);
	buff[len] = '\0';
	this->SetFirstName(buff);
	in_file.read((char*)&len, sizeof(len));
	in_file.read(buff, len);
	buff[len] = '\0';
	this->SetLastName(buff);
}

void Mermaid::saveType(ofstream& out_file)const
{
	out_file.write((char*) "Mermaid", 7);
}
