/*
final c++ project
2018-2019
simple school managment
teacher:
Ahmad Yoosofan (yoosofan@gmx.com)
written by:
hamed kharazmi
*/

#include <iostream>
#include <string>
#include <cstring>
#include "list.h"
using namespace std;

class date
{
public:
    int day,month,year;
    friend ostream& operator<<(ostream&,date&);
};

ostream& operator<<(ostream & out,date & d)
{
    out<<d.year<<'/'<<d.month<<'/'<<d.day;
}


class student
{
    char fname[15];
    char lname[15];
    char stdno[15];
    date bdt;
    void input_student(student a);
public:
    int add_stds(list<student>& list_std );
    int add_stds_crss(list<std_crs>& list_sc , list<student>& list_std , list<course>& list_crs);
};

class teacher{
    char fname[15];
    char lname[15];
    date daemp[15];
    int tchno;
    void teacher::input_teacher(teacher a);
public:
    int add_tchs(list<teacher>& list_tch );
	int add_tchs_crss(list<tch_crs>& list_tc , list<teacher>& list_tch , list<course>& list_crs);
  };

  class course{
      int csno;
      char csname[20];
  };

  class tch_crs{
      int tchno ;
      int crsno;
  };

  class std_crs{
      int csno;
      char stdno[15];
      double score;
  };

void student::input_student(student a){
  cout<<"student's first name: "; cin>>a.fname;
  cout<<"student's last name: ";  cin>>a.lname;
  cout<<"student id: ";        cin>>a.sdtno;
  cout<<" BirthDate :"<<endl;
  cout<<"Day: ";                   cin>>a.bdt.day;
  cout<<"Month: ";                 cin>>a.bdt.month;
  cout<<"year: ";                  cin>>a.bdt.year;
  cout<<"***************\n";
}
// end
void teacher::input_teacher(teacher a){
  cout<<"teacher's first name: ";  cin>>a.fname;
  cout<<"teacher's last name: ";   cin>>a.lname;
  cout<<"teacher id: ";         cin>>a.ctsno;
  cout<<"Recruitment date: "<<endl;
  cout<<"Day: ";                    cin>>a.daemp.day;
  cout<<"Month: ";                  cin>>a.daemp.month;
  cout<<"year: ";                   cin>>a.daemp.year;
  cout<<"***************\n";
}

int student::add_stds(list<student>& list_std ){
    int n,i;
    cout<<"How many students do you want to add? ";  cin>>n;
    for(i=0; i<n ;i++){
      list_std.push_back(student());
      input_student(list_std[ list_std.size()-1 ]);
    }
    return list_std.size();
}

int teacher::add_tchs(list<teacher>& list_tch ){
    int n,i;
    cout<<"How many teachers do you want to add? ";  cin>>n;
    for(i=0; i<n ;i++){
      list_tch.push_back(teacher());
      input_teacher(list_tch[ list_tch.size()-1 ]);
    }
  return list_tch.size();
}

int â€«â€ªstudent::add_stds_crss(list<std_crs>& list_sc , list<student>& list_std , list<course>& list_crs)â€¬â€¬{
  int n,i,counter,crsn,stdn,crsnnn=-1,stdnnn=-1;
  cout<<"How many std_crs do you want to add? "
  for(i=0;i<n;i++){
    cout<<"enter student id :"; cin>>stdn;
    cout<<"enter course id:"; cin>>crsn;
    for(counter=0;counter<list_std.size();counter++){
      if(strcmp(list_std[counter].stdno , stdn)){ stdnnn=counter; break;}
    }
    for(counter=0;counter<list_crs.size();counter++){
      if(list_crs[counter].csno == crsn){ crsnnn=counter; break;}
    }
    if(stdnnn!=-1 && crsnnn!=-1){
      list_sc.push_back(std_crs());
      list_sc[list_sc.size()-1].stdno = list_std[crsnnn].stdno;  //error
      list_sc[list_sc.size()-1].csno = list_crs[crsnnn].csno;
    }
    if(stdnnn==-1) cout<<"student id is not available";
    if(crsnnn==-1) cout<<"course id is not available";
  }
  return list_sc.size();
}

int â€«â€ªteacher::add_tchs_crss(list<tch_crs>& list_tc , list<teacher>& list_tch , list<course>& list_crs)â€¬â€¬{
  int n,i,counter,crsn,tchn,crsnnn=-1,tchnnn=-1;
  cout<<"How many tch_crs do you want to add? "
  for(i=0;i<n;i++){
    cout<<"enter teacher id :"; cin>>tchn;
    cout<<"enter course id:"; cin>>crsn;
    for(counter=0;counter<list_tch.size();counter++){
      if(strcmp(list_tch[counter].tchno , tchn)){ tchnnn=counter; break;}
    }
    for(counter=0;counter<list_crs.size();counter++){
      if(list_crs[counter].csno == crsn){ crsnnn=counter; break;}
    }
    if(tchnnn!=-1 && crsnnn!=-1){
      list_tc.push_back(tch_crs());
      list_tc[list_tc.size()-1].tchno = list_std[crsnnn].tchno; 
      list_tc[list_tc.size()-1].csno = list_crs[crsnnn].csno;
    }
    if(tchnnn==-1) cout<<"teacher id is not available";
    if(crsnnn==-1) cout<<"course id is not available";
  }
  return list_tc.size();
}

int rem_stds_crss( list<std_crs> & , int number_of_std_crs){
	int n,crsn,temp=0,counter;
	char stdn[15];
	cout<<"How many std_crs do you want to remove: ";
	cin>>n;
	for(int i=0 ; i<n ; i++){
		cout<<"enter student id :"; cin>>stdn;
		cout<<"enter course id :"; cin>>crsn;
		for(counter=0,temp=0;counter<n;counter++){
    		if(list[counter].csno == crsn){
    			if(strcmp(list[counter].stdno , stdn ) ){
                    list.erase(counter);
                    break;
          }
    		}
     }
  }
}

int main()
{
    //////
};
