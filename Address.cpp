#include "l181213_Address.h"

Address::Address(char* house_Number, char* street_Name, char * city,char* county)
{
	this->house_Number=new char[strlen(house_Number)+1];
	strcpy(this->house_Number, house_Number);
	
	
	this->street_Name=new char[strlen(street_Name)+1];
	strcpy(this->street_Name, street_Name);

	this->city=new char[strlen(city)+1];
	strcpy(this->city, city);

	this->county=new char[strlen(county)+1];
	strcpy(this->county, county);
	
}

Address::Address(const Address& other)
{
	this->house_Number=new char[strlen(other.house_Number)+1];
	strcpy(this->house_Number, other.house_Number);
	
	
	this->street_Name=new char[strlen(other.street_Name)+1];
	strcpy(this->street_Name, other.street_Name);

	this->city=new char[strlen(other.city)+1];
	strcpy(this->city, other.city);

	this->county=new char[strlen(other.county)+1];
	strcpy(this->county, other.county);
}

ostream& operator<<(ostream& osObject, const Address& A)
{
	//cout<<A.city<<endl;

	osObject<<A.house_Number<<", "<<A.street_Name<<", "<<A.city<<", "<<A.county<<"."<<endl; 
	return osObject;
}

const Address &   Address::operator=(const Address& other)
{
	if(strlen(this->house_Number)!=0)
		delete[] this->house_Number;

	this->house_Number=new char[strlen(other.house_Number)+1];
	strcpy(this->house_Number, other.house_Number);	
	
	if(strlen(this->street_Name)!=0)
		delete[] this->street_Name;
	this->street_Name=new char[strlen(other.street_Name)+1];
	strcpy(this->street_Name, other.street_Name);

	if(strlen(this->city)!=0)
		delete[] this->city;
	this->city=new char[strlen(other.city)+1];
	strcpy(this->city, other.city);

	if(strlen(this->county)!=0)
		delete[] this->county;
	this->county=new char[strlen(other.county)+1];
	strcpy(this->county, other.county);

	return *this;
}

Address::~Address()
{
	if(strlen(this->house_Number)!=0)
		delete[] this->house_Number;

	
	if(strlen(this->street_Name)!=0)
		delete[] this->street_Name;

	if(strlen(this->city)!=0)
		delete[] this->city;
	
	if(strlen(this->county)!=0)
		delete[] this->county;
	
}
