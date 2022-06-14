#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#include "Zoo.h"
#include "Animal.h"
#include "Fish.h"
#include "Birds.h"
#include "Horse.h"
#include "Mammals.h"
#include "MammalsFish.h"


Zoo::Zoo(): m_name(nullptr), m_address(nullptr),m_ticketPrice(0), 
m_openHours(nullptr), m_closeHours(nullptr), m_numOfAnimals(0), m_animals(nullptr)
{
}

Zoo::Zoo(const char* name, const char* address, float ticket, const char* open, const char* close)
{
	m_name = new char[strlen(name) + 1];
	strcpy(m_name, name);
	m_address = new char[strlen(address) + 1];
	strcpy(m_address, address);
	m_ticketPrice = ticket;
	m_openHours = new char[strlen(open) + 1];
	strcpy(m_openHours, open);
	m_closeHours = new char[strlen(close) + 1];
	strcpy(m_closeHours, close);
	m_numOfAnimals = 0;
	m_animals = nullptr;
}

Zoo::Zoo(ifstream& in_file): m_numOfAnimals(0)
{
	Zoo::LoadBin(in_file);
}

Zoo::~Zoo()
{
	delete[] m_name;
	delete[] m_address;
	delete[] m_openHours;
	delete[] m_closeHours;
	delete[] m_animals;
}

Zoo::Zoo(const Zoo& z)
{
	m_name = new char[strlen(z.m_name) + 1];
	strcpy(m_name, z.m_name);
	m_address = new char[strlen(z.m_address) + 1];
	strcpy(m_address, z.m_address);
	m_ticketPrice = z.m_ticketPrice;
	m_openHours = new char[strlen(z.m_openHours) + 1];
	strcpy(m_openHours, z.m_openHours);
	m_closeHours = new char[strlen(z.m_closeHours) + 1];
	strcpy(m_closeHours, z.m_closeHours);
	m_numOfAnimals = z.m_numOfAnimals;
	m_animals = new Animal*[m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; i++)
	{
		AddAnimal(z.m_animals[i]);
	}
}

const char* Zoo::GetName() const
{
	return m_name;
}

const char* Zoo::GetAddress() const
{
	return m_address;
}

float Zoo::GetTicketPrice() const
{
	return m_ticketPrice;
}

const char* Zoo::GetOpenHour() const
{
	return m_openHours;
}

const char* Zoo::GetCloseHour() const
{
	return m_closeHours;
}

int Zoo::GetNumOfAnimals() const
{
	return m_numOfAnimals;
}

Animal** Zoo::GetAnimals() const
{
	return m_animals;
}

void Zoo::AddAnimal(Animal* an)
{
	*this += an;
}

Zoo& Zoo::operator+(Animal* an)
{
	Animal** temp = new Animal*[m_numOfAnimals + 1];
	for (int i = 0; i < m_numOfAnimals; i++)
	{
		temp[i] = m_animals[i];
	}
	temp[m_numOfAnimals] = an;
	delete[] m_animals;
	m_animals = temp;
	m_numOfAnimals++;
	return *this;
}

Zoo Zoo::operator+(const Zoo& other) const
{
	Zoo tmpZ(*this);
	for (int i = 0; i < other.m_numOfAnimals; i++)
	{
		tmpZ.AddAnimal(other.m_animals[i]);
	}
	return tmpZ;
}

Zoo Zoo::operator+=(Animal* an)
{
	Animal** tmpA = new Animal*[m_numOfAnimals + 1];
	for (int i = 0; i < m_numOfAnimals; i++)
	{
		tmpA[i] = m_animals[i];
	}
	if(typeid(*an) == typeid(Horse))
	{
		Horse*h= dynamic_cast<Horse*>(an);
		tmpA[m_numOfAnimals] = new Horse(*h);
	}
	else if( typeid(*an) == typeid(Mermaid))
	{
		Mermaid *m = dynamic_cast<Mermaid*>(an);
		tmpA[m_numOfAnimals] = new Mermaid(*m);
	}
	else if (typeid(*an) == typeid(GoldFish))
	{
		GoldFish* gf = dynamic_cast<GoldFish*>(an);
		tmpA[m_numOfAnimals] = new GoldFish(*gf);
	}
	else if (typeid(*an) == typeid(Flamingo))
	{
		Flamingo* fl = dynamic_cast<Flamingo*>(an);
		tmpA[m_numOfAnimals] = new Flamingo(*fl);
	}
	m_animals = tmpA;
	m_numOfAnimals++;
	tmpA = nullptr;
	return *this;
}

void Zoo::Save(ofstream& ofs) const
{
	ofs << m_name << endl;
	ofs << m_address << endl;
	ofs << m_ticketPrice << endl;
	ofs << m_openHours << endl;
	ofs << m_closeHours << endl;
	ofs << m_numOfAnimals << endl;
	for (size_t i = 0; i < m_numOfAnimals; ++i)
	{
		m_animals[i]->Save(ofs);
	}
}

void Zoo::Load(ifstream& ifs)
{
	char buffer[200];
	ifs.getline(buffer, 200);
	m_name = strdup((buffer));

	ifs.getline(buffer, 200);
	m_address = strdup((buffer));
	ifs >> m_ticketPrice;
	ifs.read(buffer, 1);
	ifs.getline(buffer, 200);
	m_openHours = strdup(buffer);
	ifs.getline(buffer, 200);
	m_closeHours = strdup(buffer);
	ifs >> m_numOfAnimals;
	char* type = nullptr;
	m_animals = new Animal * [m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; ++i) {
		m_animals[i] = makeObject(ifs);
	}
}

void Zoo::SaveBin(ofstream& ofs) const
{
	int len = strlen(m_name);
	ofs.write((char*)&len, sizeof(len));
	ofs.write(m_name, len);
	// save address : char*
	len = strlen(m_address);
	ofs.write((char*)&len, sizeof(len));
	ofs.write(m_address, len);
	// save ticketPrice
	ofs.write((char*)&m_ticketPrice, sizeof(m_ticketPrice));
	// save open hours : char*
	len = strlen(m_openHours);
	ofs.write((char*)&len, sizeof(len));
	ofs.write(m_openHours, len);
	// save close hours : char*
	len = strlen(m_closeHours);
	ofs.write((char*)&len, sizeof(len));
	ofs.write(m_closeHours, len);
	// save num of animals : int
	ofs.write((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));
	// save each animal
	for (int i = 0; i < m_numOfAnimals; ++i) {
		m_animals[i]->SaveBin(ofs);
	}
}

void Zoo::LoadBin(ifstream& ifs)
{
	int len=0;
	char buffer[200];
	// load name : char*
	ifs.read((char*)&len, sizeof(len));
	ifs.read(buffer, len);
	m_name = strdup(buffer);
	// load address : char*
	ifs.read((char*)&len, sizeof(len));
	ifs.read(buffer, len);
	buffer[len] = '\0';
	m_address = strdup(buffer);
	// load ticket price : float
	ifs.read((char*)&m_ticketPrice, sizeof(m_ticketPrice));
	// load open hours : char*
	ifs.read((char*)&len, sizeof(len));
	ifs.read(buffer, len);
	buffer[len] = '\0';
	m_openHours = strdup(buffer);
	// load close hours : char*
	ifs.read((char*)&len, sizeof(len));
	ifs.read(buffer, len);
	buffer[len] = '\0';
	m_closeHours = strdup(buffer);
	// load num of animals : int
	ifs.read((char*)&m_numOfAnimals, sizeof(m_numOfAnimals));
	// load each animal
	m_animals = new Animal * [m_numOfAnimals];
	for (int i = 0; i < m_numOfAnimals; ++i) {
		m_animals[i] = makeObjectBin(ifs);
	}
}

char* Zoo::loadTypetxt(ifstream& ifs)
{
	char* tpy = new char[3];
	ifs.read(tpy, 2);
	return tpy;
}

Animal* Zoo::makeObject(ifstream& ifs)
{
	char* type;
	type = loadTypetxt(ifs);

	if (strcmp(type, "Ho") == 0) {
		Horse* h = new Horse();
		h->Load(ifs);
		delete[] type;
		return h;
	}
	if (strcmp(type, "Me") == 0) {
		Mermaid* m = new Mermaid();
		m->Load(ifs);
		delete[] type;
		return m;
	}
	if (strcmp(type, "Go") == 0) {
		GoldFish* g = new GoldFish();
		g->Load(ifs);
		delete[] type;
		return g;
	}

	Flamingo* f = new Flamingo();
	f->Load(ifs);
	delete[] type;
	return f;
}

Animal *Zoo::makeObjectBin(ifstream& ifs)
{
	char* type;
	type = loadTypetxt(ifs);

	if (strcmp(type, "Ho") == 0) {
		Horse* h = new Horse(ifs);
		delete[] type;
		return h;
	}
	if (strcmp(type, "Me") == 0) {
		Mermaid* m = new Mermaid(ifs);
		delete[] type;
		return m;
	}
	if (strcmp(type, "Go") == 0) {
		GoldFish* g = new GoldFish(ifs);
		delete[] type;
		return g;
	}
	Flamingo* f = new Flamingo(ifs);
	delete[] type;
	return f;
}

ofstream& operator<<(ofstream& out, const Zoo& z)
{
	z.Save(out);
	return out;
}

ifstream& operator>>(ifstream& in, Zoo& z)
{
	z.Load(in);
	return in;
}
