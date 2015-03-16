#include <iostream>
#include <string>
#include <list>

using namespace std;

class Human
{
protected:
	string name;

public:
	Human(string name)
	{
		this->name = name;
	}

	void Display(void)
	{
		cout << "Name: " << this->name << endl;
	}
};

class Student : public Human
{
private:
	int identificationNumber;
	int gradeComputerScience;

public:
	Student(string name, int identificationNumber)
		: Human(name)
	{
		this->identificationNumber = identificationNumber;
	}

	void Display(void)
	{
		Human::Display();
		cout << this->name << endl;
		cout << "Identification number: " << this->identificationNumber << endl;
		//this->gradeComputerScience;
	}


};

int main(void)
{
	Student st("Jan", 12345);
	st.Display();

	list<Human*> peopleAtUniversity;
	peopleAtUniversity.push_back(&st);

	Student *newStudent = new Student("Tomasz", 99987);
	peopleAtUniversity.push_back(newStudent);

	for (auto item : peopleAtUniversity)
	{
		item->Display();
	}

	return 1;
}