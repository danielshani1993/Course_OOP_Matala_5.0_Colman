#ifndef HORSE_H
#define HORSE_H

#include "Mammals.h"

class Horse : public Mammals
{
public:
	Horse();//set the default color to GRAY and other params to 0
	Horse( const char* color, int childs, float avgLifetime, float preg, float milk, const char* type );//init the Horse with a given attributes
	Horse( ifstream& in_file );//init the Horse from a binary file
	virtual ~Horse();
public:
	const char*		GetType() const;//return the type of the horse

public:
	virtual void Save(ofstream& out_file)const;
	virtual void load(ifstream& in_file);
	virtual void LoadBin(ifstream& in_file);
	virtual void SaveBin(ofstream& out_file)const;

	virtual void SaveAddition(ofstream& out_file)const;
	virtual void LoadAddition(ifstream& in_file);
	virtual void SaveAdditionBin(ofstream& out_file)const;
	virtual void LoadAdditionBin(ifstream& in_file);	
	
	virtual void saveType(ofstream& out_file) const;


protected:
	char*	m_type;
};

#endif // ifndef