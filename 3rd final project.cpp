#include<iostream>
using namespace std;
#include<conio.h>
class Node{
public:

void setObject(int object){
this->object=object;
}
int getObject(void){
return object;
}
string getName()
{
	return name;
}

void setName(string name)
{
	this->name=name;
}
string get_lname()
		{
			return lname;
		}
		void set_lname(string lname)
		{
			this->lname=lname;
		}
		string get_fatherName()
		{
			return fatherName;
		}
		void setfather_Name(string fatherName)
		{
			this->fatherName=fatherName;
		}
		string get_gender()
		{
			return gender;
		}
		void set_gender(string gender)
		{
			this->gender=gender;
		}
		string get_dep()
		{
			return dep;
		}
		void set_dep(string dep)
		{
			this->dep=dep;
		}
		string get_adrs()
		{
			return adrs;
		}
		void set_adrs(string adrs)
		{
			this->adrs=adrs;
		}
void setNext(Node *next){
this->next=next;
}
Node* getNext(void){
return next;
}

public:
string name,lname,fatherName,gender,adrs,dep;
int object;
Node *next;

};
class List{
	public:
		Node *headNode,*current,*lastCurrent;
		int size;
 public:
         List() {

		 headNode= new Node;
		 headNode->setNext(NULL);
		 current = headNode;		headNode->setfather_Name("\0");
		headNode->set_adrs("\0");
		headNode->set_dep("\0");
		headNode->set_gender("\0");
		headNode->set_lname("\0");
		 size=0;
	}
	       void addNode(int object,string name,string lname,string fatherName,string dep,string gender,string adrs){
            Node* newNode=new Node;
            newNode->setObject(object);
        newNode->setName(name);
         newNode->set_lname(lname);
		newNode->setfather_Name(fatherName);
		newNode->set_dep(dep);
		newNode->set_gender(gender);
		newNode->set_adrs(adrs);
             if(current!=NULL&&current!=headNode){

                newNode->setNext(current->getNext());
                current->setNext(newNode);
                lastCurrent=current;
                current=newNode;

             }
             else{

                newNode->setNext(NULL);
		        headNode->setNext(newNode);
		        lastCurrent=headNode;
                current= newNode;

             }

             ++size;
         }
         void getNode(){

        if(current!=NULL){
   	   cout<<"......SEARCHING MODE......."<<endl; 
        cout<<".... ROLL.NO OF STUDENT IS....:"<<current->getObject()<<endl;
	   cout<<"....THE FIRST NAME OF STUDENT IS....:"<<current->getName()<<endl;	
	  	 cout<<"....THE LAST NAME OF STUDENT IS....:"<<current->get_lname()<<endl;
		cout<<"....FATHER_NAME...."<<current->get_fatherName()<<endl;
		cout<<".... DEPARTMENT...."<<current->get_dep()<<endl;
		cout<<".... GENDER...."<<current->get_gender()<<endl;
		cout<<"....ADDRESS...."<<current->get_adrs()<<endl;
}
         }
         
         
         
void next()
         {
         	lastCurrent=current;
         	current=lastCurrent->getNext();
		 }
		 void start()
		 {
		 	lastCurrent=current;
		 	current=headNode;
		 }
		 void search(int obj)
{
	start();
	int c=0;
	while(current!=NULL)
	{
		if(obj==current->getObject())
		{
					    getNode();
		    c=1;
		    
			break;
		}
		else{
		
		next();
	}
	
	}
	if(c==0)
	cout<<"not found";
}
 void search_fname(string name)
	     {
	     	int i=0;
	     	start();
	     	while(current!=NULL)
	     	{
	     		if(name==current->getName())
	     		{
	     			getNode();
	     			i=1;
	     			break;
				 }
				 else
				 {
				 	next();
				 }
			 }
			 if(i==0)
			 cout<<"not found";
			 
		 }
	     



	     };
	    

int main()
{
	List list;
	int choice;
	cout<<".........STUDENT INFORMATION SYSTEM.........."<<endl<<endl;
	cout<<"what do you want to do?"<<endl;
	cout<<"Enter 1 to add data of student"<<endl;
	cout<<"Enter 2 to search data of student";
	cin>>choice;
	int roll;
	string fName,lName,FatherName,Gender,Adrs,Dep;
	switch(choice)
	{
		case 1:
			cout<<"ENTER ROLL.NO OF STUDENT";
			cin>>roll;
			cout<<"ENTER FIRST NAME OF STUDENT";
			cin>>fName;
			cout<<"ENTER LAST NAME OF STUDENT";
			cin>>lName;
			cout<<"ENTER FATHER_NAME OF STUDENT";
			cin>>FatherName;
			cout<<"ENTER DEPARTMENT OF STUDENT";
			cin>>Dep;
			cout<<"ENTER GENDER OF STUDENT";
			cin>>Gender;
			cout<<"ENTER ADDRESS OF STUDENT";
			cin>>Adrs;
			list.addNode(roll,fName,lName,FatherName,Dep,Gender,Adrs);
			break;
			case 2:
				int choic;
				string na;
				cout<<"what do you want to do"<<endl;
				cout<<"Enter 1 for search by Id??"<<endl;
				cout<<"Enter 2 for search by first_name"<<endl;
				cin>>choic;
				if(choic==1){
				
				int Id;
				cout<<"enter Id of student you want to search";
				list.search(Id);
			}
				else if(choic==2){
			     cout<<"enter name of student you want to search";
		         cin>>na;
				list.search_fname(na);
			}
		  			break;
		
	
			
	}

	getch();
	return 0;
}

         
