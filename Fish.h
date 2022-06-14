#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish :virtual public Animal
{
public:
	Fish();//set the default color to GRAY and other params to 0
	Fish( const char* color, int childs, float avgLifetime, int fin, int gills );//init the Fish with a given attributes
	Fish( ifstream& in_file );//init the Fish from a binary file
	virtual ~Fish();

public:
	int		GetFinCount() const;//return the fin count of the animal
	int		GetGillsCount() const;//return the gills count of the animal
public:	
	virtual void Save(ofstream& out_file)const;
	virtual void load(ifstream& in_file);
	virtual void LoadBin(ifstream& in_file);
	virtual void SaveBin(ofstream& out_file)const;

	virtual void SaveAddition(ofstream& out_file)const;
	virtual void LoadAddition(ifstream& in_file);
	virtual void SaveAdditionBin(ofstream& out_file)const;
	virtual void LoadAdditionBin(ifstream& in_file);

	virtual void saveType(ofstream& out_file) const = 0;



protected:
	int m_finCount;
	int m_gillsCount;
};

#endif // ifndef