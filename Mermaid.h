#ifndef MERMAID_H
#define MERMAID_H

#include "MammalsFish.h"

class Mermaid : public MammalsFish
{
public:
	Mermaid();//set the default color to GRAY and other params to 0
	Mermaid( const char* color, int childs, float avgLifetime, float preg, float milk, int fin, int gills, const char* firstName, const char* lastName );//init the Mermaid with a given attributes
	Mermaid( ifstream& in_file );//init the Mermaid from a binary file
	virtual ~Mermaid();
	Mermaid(const Mermaid& other);

public:
	const char*		GetFirstName() const;//return the first name of the mermaid
	const char*		GetLastName() const;//return the last name of the mermaid
	void			SetFirstName( const char* firstName );//set the first name of the mermaid
	void			SetLastName( const char* lastName );//set the last name of the mermaid

	virtual void Save(ofstream& out_file)const;
	virtual void Load(ifstream& in_file);
	virtual void SaveBin(ofstream& out_file)const;
	virtual void LoadBin(ifstream& in_file);
	virtual void saveAddition(ofstream& out_file)const;
	virtual void saveAdditionBin(ofstream& out_file)const;
	virtual void loadAddition(ifstream& in_file);
	virtual void loadAdditionBin(ifstream& in_file);
	virtual void saveType(ofstream& out_file)const;

protected:
	char* m_firstName;
	char* m_lastName;
};

#endif // ifndef