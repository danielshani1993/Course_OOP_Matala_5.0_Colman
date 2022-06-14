#ifndef ANIMAL_H
#define ANIMAL_H

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <typeinfo>
#include <fstream>

using namespace std;

class Animal
{
protected:
	Animal();//set the default color to GRAY and other params to 0
	Animal( const char* color, int childs, float avgLifetime );//init the Animal with a given attributes
	Animal( ifstream& in_file );//init the Animal from a binary file

public:
	virtual ~Animal();

public:
	const char* GetColor() const;//return the color of the animal
	int			GetChildCount() const;//return the child count of the animal
	float		GetLifetime() const;//return the life time of the animal
	void 		SetColor( const char* color );//set the color of the animal

public:
	virtual void Save(ofstream& out_file) const;//save the animal to a  file
	virtual void Load(ifstream& in_file);//load the animal from a  file
	virtual void SaveBin (ofstream& out_file) const;//save the animal to a binary file
	virtual void LoadBin (ifstream& in_file);//load the animal from a binary file

	virtual void SaveAddition (ofstream& out_file)const =0;//save the animal to a  file
	virtual void LoadAddition (ifstream& in_file)=0;//load the animal from a  file
	virtual void SaveBinAddition (ofstream& out_file)const=0;//save the animal to a binary file
	virtual void LoadBinAddition (ifstream& in_file)=0;//load the animal from a binary file

	virtual void saveType(ofstream& out_file) const = 0;

	Animal& operator=(Animal& other );//overload the operator =
	
protected:
	char*	m_color;
	int		m_childCount;
	float	m_avgLifetime;
};

#endif // ifndef