#include"l181213_Employee.h"
Employee::Employee(char* name, const Address& j)
	:x(j)
{
	int x=strlen(name);
	emp_name=new char[x+1];
	strcpy(emp_name,name);
	P=0;
}
Employee::Employee(const Employee &a)
	:emp_name(a.emp_name),x(a.x)
{
	P=a.P;
	for(int i=0;i<P;i++)
		y[i]=a.y[i];
}
ostream& operator<<(ostream& osObject, const Employee& b)
{
	osObject<<"The name of employee:"<<b.emp_name<<endl;
	osObject<<"The address of employee:"<<b.x<<endl;
	osObject<<"Working on:"<<endl;
	for(int i=0;i<b.P;i++)
		osObject<<*b.y[i];
	return osObject;
}
const Employee& Employee::   operator=(const Employee& other)
{
	emp_name=new char[strlen(other.emp_name)+1];
	x=other.x;
	P=other.P;
	for(int i=0;i<P;i++)
		y[i]=other.y[i];
	return *this;
}
void Employee::addProject(Project const *g )
{
   if(P<2)
   {
	   int n=0;
	   for(int i=0;i<P;i++)
	   {
		   if(y[i]==g)
		   {
			   n=1;
			   cout<<"The project is already present"<<endl;
			   break;
		   }
	   }
	   if(n==0)
	   {
		   cout<<"project added successfully"<<endl;
		   y[P]=g;
		   P++;
	   }
   }
   else
	   cout<<"Maximum project limit reached"<<endl;  
}
void Employee::removeProject(Project const *f )
{
	for(int i=0;i<P;i++)
	{
		int g;
		if(y[i]==f)
		{
			g=i;
			 y[i]=nullptr;
			for(int j=g;j<P;j++)
				y[j]=y[j+1];
			cout<<"removed successfully"<<endl;
			P=P-1;
		}
	}
}
Employee::~Employee()
{
	delete[]emp_name;
	emp_name=nullptr;
}