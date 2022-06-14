#include "Horse.h"
#pragma warning(disable:4996)
Horse::Horse(): Mammals()
{
	this->m_type = 0;
}

Horse::Horse(const char* color, int childs, float avgLifetime, float preg, float milk, const char* type): Mammals(color, childs, avgLifetime, preg, milk)
{
	this->m_type = strdup(type);
}


Horse::Horse(ifstream& in_file)
	:Mammals(in_file)
{
	Horse::LoadAdditionBin(in_file);
}

Horse::~Horse()
{
	delete[]m_type;
}

const char* Horse::GetType() const
{
	return this->m_type;
}

void Horse::Save(ofstream& out_file)const
{
	Animal::Save(out_file);
	Mammals::SaveAddition(out_file);
	Horse::SaveAddition(out_file);
}

void Horse::load(ifstream& in_file)
{
	Animal::Load(in_file);
	Mammals::LoadAddition(in_file);
	Horse::LoadAddition(in_file);
}

void Horse::LoadBin(ifstream& in_file)
{
	Animal::LoadBin(in_file);
	Mammals::LoadAdditionBin(in_file);
	Horse::LoadAdditionBin(in_file);
}

void Horse::SaveBin(ofstream& out_file)const
{
	Animal::SaveBin(out_file);
	Mammals::SaveAdditionBin(out_file);
	Horse::SaveAdditionBin(out_file);
}

void Horse::SaveAddition(ofstream& out_file)const
{
	out_file << this->m_type << endl;
}

void Horse::LoadAddition(ifstream& in_file)
{
	in_file >> this->m_type;
}

void Horse::SaveAdditionBin(ofstream& out_file) const
{
	out_file.write((char*)&this->m_type, sizeof(this->m_type) * strlen(m_type));
}

void Horse::LoadAdditionBin(ifstream& in_file)
{
	in_file.read((char*)&this->m_type, sizeof(this->m_type) * strlen(m_type));
}

void Horse::saveType(ofstream& out_file) const
{
	out_file.write((char*)"horse", 5);

}
