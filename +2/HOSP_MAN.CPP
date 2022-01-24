//Program of HOSPITAL MANAGEMENT

#include<iostream>
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;
//start of classes
class Basic
 {
  protected:
   string city;
   int ID;
   int age;

  public:
   string name;
   void get_basic(void);
   void show_basic(void);
   int check_ID(int,int);
 };

class Doctor:public Basic
 {
  private:
    string quali;
    string doc_spec;
    int exp;

  public:
    void getdata(void);
    void display(void);
    void Disp_Alldoc();
 };

class Patient:public Basic
 {
  private:
    string pat_disease;
    string pat_severity;
    string Adm_date;
    int med_no;
    string med_name;
    int med_cost[5];
  public:
    void Get_Patient(void);
    void Display_Patient(void);
    void Disp_Allpat(void);
    float Generate_Bill(int,int);
    void Display_Bill(int,int,int);
 };

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Function Definitions*/

void Doctor::getdata()
 {
   get_basic();
   cout<<"\nEnter Doctor's Qualification     : ";
   cin>>quali;
   cout<<"\nEnter Doctor's Specialization    : ";
   cin>>doc_spec;
   cout<<"\nEnter Doctor's Experience        : ";
   cin>>exp;
 }

void Doctor::display()
 {
   show_basic();
   cout<<"\nDoctor's Qualification      : "<<quali;
   cout<<"\nDoctor's Specialization     : "<<doc_spec;
   cout<<"\nDoctor's Experience         : "<<exp;
 }

void Basic::get_basic()
 {
   cout<<"\n\nEnter the ID                     : ";
   cin>>ID ;
   cout<<"\nEnter the name                   : ";
   cin>>name;
   cout<<"\nEnter age                        : ";
   cin>>age;
   cout<<"\nEnter the name of the city       : ";
   cin>>city;
 }

void Basic::show_basic()
 {
   cout<<"\n\nID                          : "<<ID;
   cout<<"\nName                        : "<<name;
   cout<<"\nAge                         : "<<age;
   cout<<"\nCity                        : "<<city;
 }

int Basic::check_ID(int n,int m)
 {
   for(int i=0;i<m;i++)
    {
     if(n==ID)
      {
       return 1;
      }
    }
   return -1;
 }

void Doctor::Disp_Alldoc()
  {
     cout<<" \t "<<ID<<"\t"<<"       "<<name<<" \t\t "<<doc_spec<<"   \t\t "<<age<<"\n";
  }

void Patient::Get_Patient()
 {
   get_basic();
   cout<<"\nEnter Patient's disease          :  ";
   cin>>pat_disease;
   cout<<"\nEnter the severity               :  ";
   cin>>pat_severity;
   cout<<"\nEnter the date of admission      :  ";
   cin>>Adm_date;
 }

void Patient::Display_Patient()
 {
   show_basic();
   cout<<"\nPatient's Disease           : "<<pat_disease;
   cout<<"\nPatient's Severity          : "<<pat_severity;
   cout<<"\nDate of Admission           : "<<Adm_date;
 }
void Patient::Disp_Allpat()
 {
     cout<<" \t "<<ID<<"\t"<<"       "<<name<<" \t\t "<<pat_disease<<"   \t\t "<<age<<"\n";
 }

float Patient::Generate_Bill(int x,int y)
 {
   float tot_cost=0;
   system("cls");
   cout<<"\n\n\t\t\tGENERATION OF BILL............" ;
   for(int i=0;i<y;i++)
     {
       if(x==ID)
	{
	 cout<<"\nThe Name of the Patient        : "<<name;
	 cout<<"\nDisease                        : "<<pat_disease;
	 cout<<"\n\n Enter the number of prescribed medicines : " ;
	 cin>>med_no;
	 for(int j=0;j<med_no;j++)
	   {
	     cout<<"\n MEDICINE NO. "<<j+1;
	     cout<<"\nEnter the name of medicine : ";
	     cin>>med_name;
	     cout<<"\nEnter the cost of medicine : " ;
	     cin>>med_cost[j];
	     tot_cost+=med_cost[j];
	   }
	  break;
	}
     }
   return tot_cost;
 }
  void Patient::Display_Bill(int x,int y,int z)
  {
   const int fee=200;
   int c=(z+fee) ;

   system("cls");
   for(int i=0;i<y;i++)
   {
    if(x==ID)
     {
       cout<<"\n\t\t\t...VIRTUAL HOSPITAL BILL...";
       cout<<"\n";
       cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
       cout<<"\n  ID : "<<ID<<" \t\t\t Name : "<<name<<"\t\t\t Age : "<<age;
       cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
       cout<<"\n SL.NO \t\t\t NAME OF MEDICINE   \t\t\t COST";
       for(int j=0;j<med_no;j++)
       {
	cout<<"\n";
	cout<<"  "<<j+1<<"  \t \t \t  "<<med_name[j]<<"     \t\t\t\t     "<<med_cost[j];
       }
       cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
       cout<<"\n\t\tCONSULTATION FEE  :   \t\t\t\t   "<<fee;
       cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
       cout<<"\n\t\tTOTAL BILL CHARGE :   \t\t\t\t   "<<c ;
       cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
     }
     break;
   }
  }

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Start of Main function

int main()
{
  system("cls");
  Doctor doc[10];
  Patient pat[10];

  fstream file1;
  file1.open("Doc.text",ios::in|ios::out|ios::app|ios::binary);
  if(!file1)
   {
    cout<<"\nCannot open file!!!..";
    exit(2);
   }
   fstream file2;
   file2.open("Pat.text",ios::in|ios::out|ios::app|ios::binary) ;
   if(!file2)
    {
     cout<<"\nCannot open file!!!..";
     exit(0);
    }

  int no,num=0,choice1,choice2,choice3,display_id,con_id;
  int total,flag,bil_id,count1=0,count2=0;

  fstart:
  cout<<"\n\n\n\n\n+--------------------------------------------------------------------------+";
  cout<<"\n\t\tWELCOME TO HOSPITAL MANAGEMENT SYSTEM PROGRAM\t\t";
  cout<<"\n\t\t\t\tVIRTUAL HOSPITAL";
  cout<<"\n\n\t1.Enter...";
  cout<<"\n\n\t2.Exit...\n\n\t\t\t";
  cout<<"\n\n+------------------------------------------------------------------------------+"<<endl;
  cin>>no;
  if(no==1)
   {
     goto start;
   }
  else
    goto last;
//............................................................................

start:

  system("cls");
  cout<<"\n\n\t\tMENU BAR";
  cout<<"\n\t 1.Doctor's Database";
  cout<<"\n\t 2.Patient's Database";
  cout<<"\n\t 3.Generate Patient's Report";
  cout<<"\n\t 4.Generate Patient's Bill";
  cout<<"\n\t 5.Exit";

  cout<<"\n\nEnter your choice : ";
  cin>>choice1;

substart1:

    switch(choice1)
     {
      case 1: system("cls");
	      cout<<"\n\t\tSUB MENU ";
	      cout<<"\n\t1.Enter Details of New doctor..";
	      cout<<"\n\t2.Display details of New doctors..";
	      cout<<"\n\t3.Display Total number of Doctors..";
	      cout<<"\n\t4.Table of Details.. ";
	      cout<<"\n\t5.Exit";
	      cout<<"\n\nEnter your choice.. ";
	      cin>>choice2;
	       system("cls");
		switch(choice2)
		 {
		   case 1: cout<<"\nHow many Doctors' information do you want to enter?\n";
			   cin>>num;
			   for(int i=0;i<num;i++)
			    {
			      system("cls");
			      cout<<"\nEnter the details of Doctor "<<i+1<<": ";
			      doc[i].getdata();
			      file1.write((char*)&doc[i],sizeof(doc[i]));
			      count1++;
			    }
			   cout<<"\n\n";
			   system("pause");
			   goto substart1;


		   case 2: cout<<"\n\nEnter the Doctor's Id of the doctor you want to display\n";
			   cin>>display_id;
			   for(int j=0;j<count1;j++)
			    {
			      flag=doc[j].check_ID(display_id,count1);
			      if(flag==1)
				{
				  cout<<"\nThe Details of the doctor are : "<<endl;
				  file1.read((char*)&doc[j],sizeof(doc[j]));
				  doc[j].display();
				  break;
				}
			    }
			  if(flag==-1)
			   {
			    cout<<"\nNo doctors with this ID!!!";
			   }
			  cout<<"\n\n";
			  file1.seekg(0);
			  system("pause");
			  goto substart1;

		   case 3: system("cls");
			   cout<<"\n\nThe total number of Doctors : \n";
			   cout<<"\t\t"<<count1<<endl;
			   system("pause");
			   goto substart1;

		   case 4: system("cls");
			   cout<<"\nLIST OF ALL THE DOCTORS :"<<endl;
			   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			   cout<<"  No.    ID.    \tName.\t    \t Specialization\t        Age   " ;
			   cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			   for(int i=0;i<count1;i++)
			    {
			      cout<<"\n  "<<i+1;
			      doc[i].Disp_Alldoc();
			    }
			  cout<<"\n\n";
			  system("pause");
			  goto substart1;

		   case 5: goto start;

		   default: system("cls");
			    cout<<"\n\nError!!!!\nSelect any valid option";
			    system("pause");
			    goto substart1;

		 }

substart2:

      case 2: system("cls");
	      cout<<"\n\t\tSUB MENU ";
	      cout<<"\n\t1.Enter Details of New patient..";
	      cout<<"\n\t2.Display details of patients..";
	      cout<<"\n\t3.Display total number of Patients.." ;
	      cout<<"\n\t4.Table of Details.. ";
	      cout<<"\n\t5.Exit";
	      cout<<"\n\nEnter your choice.. ";
	      cin>>choice3;
	      system("cls");
	       switch(choice3)
		{
		  case 1: cout<<"\nHow many Patients' information do you want to enter?\n";
			  cin>>num;
			  for(int j=0;j<num;j++)
			    {
			      system("cls");
			      cout<<"\nEnter the details of Patient "<<j+1<<": "<<endl;
			      pat[j].Get_Patient();
			      file2.write((char*)&pat[j],sizeof(pat[j]));
			      system("cls");
			      cout<<"\nEnter the ID of the doctor for consultation: ";
			      cout<<endl;
			      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			      cout<<"  No.    ID.    \tName.\t    \t Specialization\t        Age   " ;
			      cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			      for(int i=0;i<count1;i++)
				{
				  cout<<"\n  "<<i+1;
				  doc[i].Disp_Alldoc();
				}
			      cout<<endl;
			      cin>>con_id;
			      count2++;
			    }
			  cout<<"\n\n";
			  system("pause");
			  goto substart2;

		  case 2: cout<<"\n\nEnter the Patient's Id of the patient you want to display\n";
			  cin>>display_id;
			  for(int j=0;j<count2;j++)
			    {
			     flag=pat[j].check_ID(display_id,count2);
			     if(flag==1)
			      {
				cout<<"\nThe Details of the patient are : "<<endl;
				file2.read((char*)&pat[j],sizeof(pat[j]));
				pat[j].Display_Patient();
				cout<<"\nThe doctor for cnsultation  : " ;
				cout<< doc[j].name;
				break;
			      }
			    }
			  if(flag==-1)
			   {
			     cout<<"\nNo Patient with this ID!!!! ";
			   }
			  cout<<"\n\n";
			  file2.seekg(0);
			  system("pause");
			  goto substart2;

		  case 3: system("cls");
			  cout<<"\n\nThe total number of Patients : \n";
			  cout<<"\t\t"<<count2<<endl;
			  system("pause");
			  goto substart2;

		  case 4: system("cls");
			  cout<<"\nLIST OF ALL THE PATIENTS :"<<endl;
			  cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
			  cout<<"  No.    ID.    \tName.\t    \t Disease\t        Age   " ;
			  cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
			  for(int i=0;i<count2;i++)
			    {
			      cout<<"\n  "<<i+1;
			      pat[i].Disp_Allpat();
			    }
			  cout<<"\n\n";
			  system("pause");
			  goto substart2;

		  case 5: goto start;

		  default: cout<<"\n\nError!!!!\nSelect any valid option";
			   system("pause");
			   goto substart2;
		}

      case 3: system("cls");
	       cout<<"\nLIST OF ALL THE PATIENTS :"<<endl;
	       cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	       cout<<"  No.    ID.    \tName.\t    \t Disease\t        Age   " ;
	       cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
		  for(int i=0;i<count2;i++)
		    {
		      cout<<"\n  "<<i+1;
		      pat[i].Disp_Allpat();
		    }
	       cout<<"\n\n\n Enter the ID of the patient : ";
	       cin>>bil_id;
		  for(int j=0;j<count2;j++)
		    {
		      total=(pat[j].Generate_Bill(bil_id,count2));
		    }
	       cout<<"\n";
	       system("pause");
	       goto start;

      case 4: system("cls");
	      cout<<"\n\n\t\t\t.....BILL OF PATIENT....."<<endl;

	      system("cls");
	      cout<<"\nLIST OF ALL THE PATIENTS :"<<endl;
	      cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	      cout<<"  No.    ID.    \tName.\t    \t Disease\t        Age   " ;
	      cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	       for(int i=0;i<count2;i++)
		 {
		   cout<<"\n  "<<i+1;
		   pat[i].Disp_Allpat();
		 }
	      cout<<"\n\nEnter the ID of the patient : ";
	      cin>>bil_id;
	       for(int j=0;j<count2;j++)
		 {
		   pat[j].Display_Bill(bil_id,count2,total);
		 }
	      cout<<"\n\n";
	      system("pause");
	      goto start;

      case 5: goto last;

      default: system("cls");
		cout<<"\n\nError!!!!\nSelect any valid option";
		system("pause");
		goto start;
      }
  last:
   file1.close();
   file2.close();

  return 0;
}
