#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
void Compute(int,int);
int main()
{
 int ch,LB,UB;
 cout<<"                                    WORDLE LEVEL                  "<<endl;
 cout<<"		                   --------------                  "<<endl;
 cout<<"1. Easy"<<endl;
 cout<<"2. Medium"<<endl;
 cout<<"3. Hard"<<endl;
 cout<<"Choose your level: ";
 cin>>ch;
 switch(ch)
 {
  case 1: cout<<"\nAssume a word whose length is between 2 to 5!"<<endl;
	      LB=2;
	      UB=5;
	      break;
  case 2: cout<<"\nAssume a word whose length is between 6 to 9!"<<endl;
	      LB=6;
	      UB=9;
	      break;
  case 3: cout<<"\nAssume a word whose length is greater than or equal to 10!"<<endl;
	      LB=10;
	      UB=45;
	      break;
  default: cout<<"Wrong Choice!";
	       exit(0);
 }
 Compute(LB,UB);
}
void Compute(int lb,int ub)
{
 char c,arr[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
 int pos1[20],pos2[20],no,i,j,z;
 cout<<"\n\rStep 1:\n\r=======\n\rTable-1:\n\n\r";
 for(i=0;i<5;i++)
  cout<<i+1<<" ";
 cout<<endl;
 for(i=0;i<26;i++)
 {
  if(i%5==0)
   cout<<endl;
  cout<<arr[i]<<" ";
 }
 cout<<"\n\n\rEnter Total Number of letters in word: ";
 cin>>no;
 if(no<lb || no>ub)
 {
  cout<<endl<<"Length of the word not in the specified range..."<<endl;
  cout<<endl<<"Want to Continue? Enter 'Y' for Yes and 'N' for No: ";
  cin>>c;
  if(c=='Y')
  {
   cout<<endl<<"Assume a word whose length is between "<<lb<<" to "<<ub<<"!"<<endl;
   Compute(lb,ub);
  }
  exit(0);
 }
 cout<<endl;
 for(i=0;i<no;i++)
 {
  cout<<"\rEnter Letter "<<i+1<<" Column number: ";
  cin>>pos1[i];
  pos1[i]--;
 }
 cout<<endl;
 cout<<"\n\rStep 2:\n\r=======\n\rTable-2:\n\n\r";
 for(i=0;i<6;i++)
  cout<<i+1<<" ";
 cout<<endl;
 for(i=0;i<no;i++)
 {
  cout<<endl;
  for(j=pos1[i];j<26;j+=5)
   cout<<arr[j]<<" ";
 }
 cout<<endl<<endl;
 for(i=0;i<no;i++)
 {
  cout<<"\rEnter Letter "<<i+1<<" Column number: ";
  cin>>pos2[i];
  pos2[i]--;
 }
 cout<<"\nWe Got U! "<<endl;
 cout<<"\nSURPRISED!"<<endl<<endl;
 for(i=0;i<no;i++)
  cout<<arr[pos2[i]*5+pos1[i]];
 cout<<"\n\n\rPress Esc To Exit...";
 while(getch()!=27);
}
