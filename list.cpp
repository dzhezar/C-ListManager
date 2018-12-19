#include <fstream>
#include <iostream>
#include <Windows.h>
#include <string>
#include <iomanip>
using namespace std;

class Auto{
	public:
		int phone;
		string date;
		string name;
		int number;
		Auto *next;
		
		Auto(int phoneA, string nameA, string dateA, int numberA): phone(phoneA), name(nameA), date(dateA), number(numberA){
			cout<<"Auto created: "<<name;
		}
		void showAll(){
			if(name.empty())
				cout << "That`s all"<<endl;
			else{
				cout<<"---------------"<<endl;
				cout<<setw(30)<<left<<"Name: "<<name<<endl;
				cout<<setw(30)<<left<<"Phone: "<<phone<<endl;
				cout<<setw(30)<<left<<"Date: "<<date<<endl;
				cout<<setw(30)<<left<<"Number: "<<number<<endl;
				cout<<"---------------"<<endl;
			}
		}		
};



class List{
	private:
		Auto *start;
	public:
		List(): start(NULL){
		}
		
		void showAllList(){
			if(start == NULL)
				cout<<"List is empty...";
			else{
				Auto *temp = start;
				while(temp != NULL){
					temp->showAll();
					temp = temp->next;
					cout<<1;
				}
				cout<<2;
			}
				cout<<3;
		}
		void deleteFromList(){
			string Name;
			bool found = false;
			cout<<"Enter name: ";
			cin>>Name;
			Auto *temp = start;
				while(temp != NULL){
					if(temp->next->name == Name){
						found = true;
						temp->next = temp->next->next;
						break;
					}
					cout<<"Searching...."<<endl;
					temp = temp->next;
				}
			if(!found)
				cout<<"Not found..."<<endl;
		}
		
		
		void addToStartOfList(){
			
			if(start == NULL){
				start = createAuto();
				cout<<"List empty"<<endl;
			}
			else{
				Auto *temp = start;
				start = createAuto();
				start->next = temp;
			}
		}
		
		Auto * createAuto(){
			int phoneA;
			string nameA;
			string dateA;
			int numberA;
			
			cout<<"Enter phone: ";
			cin>>phoneA;
			cout<<"Enter name: ";
			cin>>nameA;
			cout<<"Enter date: ";
			cin>>dateA;
			cout<<"Enter number: ";
			cin>>numberA;
			
			return new Auto(phoneA, nameA, dateA, numberA);
		}
		
		void addToEndOfList(){
			
			if(start == NULL){
				start = createAuto();
			}
			else{
				Auto *temp = start;
				while(temp->next != NULL){
					temp = temp->next;
				}
				temp->next = createAuto();
			}
		}
		
		void addToList(string name1){
			
			if(start == NULL){
				start = createAuto();
			}
			else{
				Auto *temp = start;
				while(temp->name != name1){
					temp = temp->next;
				}
				
				Auto *temp1 = temp->next;
				temp->next = createAuto();
				if(temp1 != NULL)
				    temp->next->next = temp1;
			}    
				
				
		}
		void readToFile(){
			ofstream fout; 
		    fout.open("example.txt");
		    fout.write((char*)this, sizeof(List));
		    fout.close();
		}
		
		void pushToListFromFile(){
			List file;
		    ifstream fin;
		    fin.open("example.txt");
			fin.read((char*)&file, sizeof(List));
			start = file.start;
			fin.close();
		}
		
		void clearList(){
			start = NULL;
			cout<<"List was cleared";
		}
		
};



void showMenu(){
	List list;
	int choice;
	int add;
	string name1;
	bool exit = false;
	do{
		cout<<endl<<"Menu"<<endl;
		cout<<"1. Add to List."<<endl;
		cout<<"2. Delete from list."<<endl;
		cout<<"3. Show all list."<<endl;
		cout<<"4. Write to file."<<endl;
		cout<<"5. Push list from file."<<endl;
		cout<<"6. Clear list."<<endl;
		cout<<"7. Exit."<<endl;
		cout<<"---------------------------"<<endl;
		cout<<"Select one of the options: ";
		cin>>choice;
		cout<<"---------------------------"<<endl;
		switch(choice){
			case 1:
				cout<<endl<<"Ways of adding"<<endl;
				cout<<"1. Add to the end of List."<<endl;
				cout<<"2. Add to the start of List."<<endl;
				cout<<"3. Add to List after smth."<<endl;
				cout<<"---------------------------"<<endl;
				cout<<"Select one of the options: ";
				cin >> add;
				switch(add){
					case 1:
						list.addToEndOfList();
						break;
					case 2:	
						list.addToStartOfList();
						break;
					case 3:
						cout << "---------------------------"<<endl;
						cout << "Enter name : ";
						cin >> name1;
						cout << "---------------------------"<<endl;
						list.addToList(name1);
						break;	
				}
				break;
			case 2:
				list.deleteFromList();
				break;
			case 3:
				list.showAllList();
				break;				
			case 4:
				list.readToFile();
				break;
			case 5:
				list.pushToListFromFile();
				break;
			case 6:
				list.clearList();
				break;
			case 7:
				cout<<"Exit";
				exit = true;
				break;
			default:
				cout<<"Try again;";
		}
	}
	while(!exit);	
}


 

