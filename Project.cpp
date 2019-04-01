#include"l181213_Project.h"
#include<cstring>

 Project ::Project(char* name1, int budget1, int duration1)
 {
	 int x=strlen(name1);
	 name=new char[x+1];
	 strcpy(name,name1);
	 budget=budget1;
	 duration=duration1;
 }
 Project ::Project(const Project& c)
 {
	 int x=strlen(c.name);
	 name=new char[x+1];
	 strcpy(name,c.name);
	 budget=c.budget;
	 duration=c.duration;
 }
  ostream& operator<<(ostream& osObject, const Project& d)
 {
	 osObject<<"Project Name:"<<d.name<<endl;
	 osObject<<"Budget:"<<d.budget<<endl;
	 osObject<<"Duration:"<<d.duration<< "weeks"<<endl;
	 return osObject;
 }
  const Project &Project::operator=(const Project& other)
  {
     int x=strlen(other.name);
	 name=new char[x+1];
	 strcpy(name,other.name);
	 budget=other.budget;
	 duration=other.duration;
	 return *this;
  }
  void Project::setBudget(int u)
  {
	  budget=u;
  }
 Project::~Project()
 {
	 if(strlen(name)!=0)
	 {
      delete[]name;
	  name=nullptr;
	 }
 }