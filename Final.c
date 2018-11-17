#include <windows.h>		
#include<stdio.h>            //contains printf,scanf etc       
#include<conio.h>            //contains delay(),getch(),gotoxy(),etc       
#include <stdlib.h>			 
#include<string.h>          //contains strcmp(),strcpy(),Strlen(),etc        
#include<ctype.h>           //contains toupper(),tolower(),etc        
#include<dos.h>             //contains dos getdate       
#include<time.h>

#define RETURNTIME 1

char catagories[][50]={"Computer Scence ","Electrical Engineering","Industrial Arts","Civil Engineering","Mechanical Engineering ","Architecture","Law","Business Management","Politics","Biology"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void editbooks(void);
void searchbooks(void);
void rentbooks(void);
void viewbooks(void);
int  getdata();
int  checkid(int);
int t(void);
void rentalrecord();
int choice;
void login(void);

void reg(void);

//list of global files that can be acceed form anywhere in program
struct web
{
char name[30];
char pass[30];
}w[99];

struct meroDate
{
int mm;
int dd;
int yy;
};


struct books
{
int id;
char stname[20];
char name[20];
char Author[20];
int quantity;
float Price;
int count;
char *cat;
struct meroDate rent;
struct meroDate duedate;
};

struct books a;


int s;
char findbook;
 


FILE *fp,*ft,*fs;
static int i=0;


int main(int argc, char *argv[])
{

		printf("        Welcome to Sonderlude Book Services \n\n\n");
	printf("__,,----------------..   ..---------------,,__\n");
	printf("|||                    Y                    |||\n");
	printf("|||                    |         To         |||\n");
	printf("|||        Pass        |                    |||\n");
	printf("|||                    |                    |||\n");
	printf("|||                    |         The        |||\n");
	printf("|||                    |                    |||\n");
	printf("|||         It         |                    |||\n");
	printf("|||                    |                    |||\n");
	printf("|||                    |        Future      |||\n");
	printf("|||       --->         |                    |||\n");
	printf("|||                    |                    |||\n");
	printf("|||                    |                    |||\n");
	printf("|||                    |                    |||\n");
	printf(" .--------------------.__.-------------------.\n");
	printf("\n\n\n          Serving Each other\n\n\n\n");

 printf("press enter to continue\n");	
 if (getch()==13)
 {
 	system("cls");
 	printf("\n\n\n\t\t\t1. LOGIN\t\t2. REGISTER");
    printf("\n\n\n\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d",&choice);
    switch(choice)
    {
     case 1: 
        login();
        break;

     case 2: 
        reg();
        break;

     default: printf("\n\n\t\t\t\tNO MATCH FOUND");

        printf("\n\n\t\t\tPress Enter to re-Enter the choice");

     

    }
  }
  return 0;
}


 void login()

    {

      FILE *fp;

      char c,name[30],pass[30]; int z=0;

      int checkun,checkpw;

      fp=fopen("Reg.txt","rb");

      printf("\n\n\t\t\t\tWELCOME TO LOG IN ZONE");

      printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^");

      for(i=0;i<1000;i++)

      {

        printf("\n\n\t\t\t\t  ENTER USERNAME: ");

        scanf("%s",name);

        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");

        while((c=getch())!=13)

        {

          pass[z++]=c;

          printf("%c",'*');

        }

        pass[z]='\0';

      while(!feof(fp))

        {

        fread(&w[i],sizeof(w[i]),1,fp);

          checkun=strcmp(name,w[i].name);

          checkpw=strcmp(pass,w[i].pass);

          if(checkun==0 && checkpw==0)

          {

    

            printf("\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");

            mainmenu();
            break;

          }

        else if(checkun==0 && checkpw!=0)

          {

            printf("\n\n\n\t\t\tWRONG PASSWORD!! Not %s??",name);

            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");

            if(getch()=='y'||getch()=='Y')

              login();

          }

        else if(checkun!=0)

          {

            printf("\n\n\n\t\t\tYou are not a Registered User\n \t\t\tPress enter to register yourself");

            if(getch()==13)


            reg();

          }

        }

        break;

      }

      getch(); 

    
}

void reg()

  {

    FILE *fp;

    char c,checker[30]; int z=0;

    fp=fopen("Reg.txt","r+");

    printf("\n\n\t\t\t\tWELCOME TO REGISTER ZONE");

    printf("\n\t\t\t\t^^^^^^^^^^^^^^^^^^^^^^^^");

    for(i=0;i<100;i++)

    {

      printf("\n\n\t\t\t\t  ENTER USERNAME: ");

      scanf("%s",checker);

        while(!feof(fp))

        {

          fread(&w[i],sizeof(w[i]),1,fp);

          if(strcmp(checker,w[i].name)==0)

            {

            printf("\n\n\t\t\tUSERNAME ALREDY EXISTS");


            reg();

            }

          else

          {

            strcpy(w[i].name,checker);

            break;

          }

        }

      printf("\n\n\t\t\t\t  DESIRED PASSWORD: ");

      while((c=getch())!=13)

        {

          w[i].pass[z++]=c;

          printf("%c",'*');

        }

      fwrite(&w[i],sizeof(w[i]),1,fp);

      fclose(fp);

      printf("\n\n\tPress enter if you agree with Username and Password");

      if((c=getch())==13)

        {


        printf("\n\n\t\tYou are successfully registered");

        printf("\n\n\t\tTry login your account??\n\n\t\t  ");

        printf(" PRESS 1 FOR YES\n\n\t\t   PRESS 2 FOR NO\n\n\t\t\t\t");

        scanf("%d",&choice);

        switch(choice)

          {

              case 1: 

                    login();
                   
				    break;

              case 2:

                    printf("\n\n\n\t\t\t\t\tTHANK YOU FOR REGISTERING");

                    break;

          }

        }

        break;

      }

    getch();

  }


void mainmenu()
{

system("cls");

int i;
printf("  \n                                      MAIN MENU                             \n  ");

printf("__,,------------------------------------..   ..---------------------------,,__\n");
printf("                                           Y                              ,,__\n");
printf("|||   1. Add Books                         |                              ,,__\n");                    
printf("                                           |                              ,,__\n");
printf("|||   2. Remove Books                      |                              ,,__\n");
printf("                                           |                              ,,__\n");
printf("|||   3. Search Books                      |                              ,,__\n");
printf("                                           |                              ,,__\n");
printf("|||   4. Rent Books                        |                              ,,__\n");
printf("                                           |                              ,,__\n");
printf("|||   5. View Book list                    |                              ,,__\n");
printf("                                           |                              ,,__\n");
printf("|||   6. Edit Book                         |                              ,,__\n");
printf("                                           |                              ,,__\n");
printf("|||   7. Exit                              |                              ,,__\n");
printf("                                           |                              ,,__\n");
printf("__,, .-----------------------------------.___.----------------------------,,__\n");

t();

printf("\nPlease enter your choice here:\n");


switch(getch())
{
case '1':
addbooks();
break;
case '2':
deletebooks();
break;
case '3':
searchbooks();
break;
case '4':
rentbooks();
break;
case '5':
viewbooks();
break;
case '6':
editbooks();
break;
case '7':
{
system("cls");

printf("******************************************\n");
printf("*        SUNDERLUDE BOOK SERVICES        *\n");
printf("******************************************\n");
printf("*            Be A Book Worm              *\n");
printf("******************************************\n");
printf("*       Producced by Empericism          *\n");
printf("******************************************\n");
printf("*               Thank You             *\n");
printf("******************************************\n");

Sleep(3000);
exit(0);
}
default:
{

printf("('_')TRY AGAIN('_')");
if(getch())
mainmenu();
}

}
}
void addbooks(void)    // add books function
{
system("cls");
int i;

    printf(" \n                                 SELECT CATEGORIES                       \n       ");


	printf("__,,------------------------------------..   ..---------------------------,,__\n");
    printf("                                           Y                              ,,__\n");
    printf("|||    1. Computer Scence                  /                              ,,__\n");
    printf("|||    2. Electrical Engineeering          /                              ,,__\n");
    printf("|||    3. Industrial Arts                  /                              ,,__\n");
    printf("|||    4. Civil Engineering                /                              ,,__\n");
    printf("|||    5. Mechanical Engineering           /                              ,,__\n");
    printf("|||    6. Architecture                     /                              ,,__\n");
    printf("|||    7. Law                              /                              ,,__\n");
    printf("|||    8. Business Management              /                              ,,__\n");
    printf("|||    9. Politics                         /                              ,,__\n");
    printf("|||   10. Biology                          /                              ,,__\n");
    printf("||| Press 20 to Display Menu               /                              ,,__\n");
    printf(" __,, .-----------------------------------.__.----------------------------,,__\n");


printf("Enter your choice:\n");
scanf("%d",&s);
if(s==20)

mainmenu() ;
system("cls");
fp=fopen("rec.dat","ab+");
if(getdata()==1)
{
a.cat=catagories[s-1];
fseek(fp,0,SEEK_END);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);

printf(" Record saved \n");

printf("Save any more?(Y / N):\n");
if(getch()=='n')
mainmenu();
else
system("cls");
addbooks();
}
}
void deletebooks()    //function that delete items from file fp
{
system("cls");
int d;
char another='y';
while(another=='y')  //infinite loop
{
system("cls");
printf("Enter the Book ID to  delete:");
scanf("%d",&d);
fp=fopen("rec.dat","rb+");
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==d)
{

printf("The book record is available\n");
printf("Book name is %s\n",a.name);
findbook='t';
}
}
if(findbook!='t')
{
printf("No record is found modify the search\n");
if(getch())
mainmenu();
}
if(findbook=='t' )
{
printf("Do you want to delete it?(Y/N):\n");
if(getch()=='y')
{
ft=fopen("test.dat","wb+");  //temporary file for delete
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id!=d)
{
fseek(ft,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,ft); //write all in tempory file except that
}                              //we want to delete
}
fclose(ft);
fclose(fp);
remove("rec.dat");
rename("test.dat","rec.dat"); //copy all item from temporary file to fp except that
fp=fopen("rec.dat","rb+");    //we want to delete
if(findbook=='t')
{

printf("The record deleted\n");

printf("Delete another record?(Y/N)\n");
}
}
else
mainmenu();
fflush(stdin);
another=getch();
}
}
mainmenu();
}
void searchbooks()
{
system("cls");
int idno;
    printf("                                      Search Books                              ");
    
	printf("__,,------------------------------------..   ..---------------------------,,__\n");
    printf("                                           Y                              ,,__\n");
    printf("|||       1. Search By ID                                                 ,,__\n");
    printf("|||       2. Search By Name                                               ,,__\n");
    printf(" __,, .----------------------------------.__.-----------------------------,,__\n");

   
printf("Enter Your Choice\n");
fp=fopen("rec.dat","rb+"); //open file for reading propose
rewind(fp);   //move pointer at the begining of file
switch(getch())
{
case '1':
{
system("cls");
printf("Search Books By Id \n");
printf("Enter the book id:\n");
scanf("%d",&idno);
printf("Searching........\n");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(a.id==idno)
{
Sleep(2);

printf("The Book is available\n");

printf(" __,, .----------------.__.-----------------,,__\n");
printf("_ ID:%d\n",a.id);
printf("_Name:%s\n",a.name);
printf("_Author:%s\n ",a.Author);
printf("_Qantity:%d \n",a.quantity);
printf("_ Price:Rs.%.2f\n",a.Price);
 printf(" __,, .---------------.__.-----------------,,__\n");
 
findbook='t';
}

}
if(findbook!='t')  //checks whether conditiion enters inside loop or not
{


printf("\aNo Record Found\n");
}

printf("Try another search?(Y/N)\n");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
case '2':
{
char s[15];
system("cls");

printf("****Search Books By Name****\n");

printf("Enter Book Name:\n");
scanf("%s",s);
int d=0;
while(fread(&a,sizeof(a),1,fp)==1)
{
if(strcmp(a.name,(s))==0) //checks whether a.name is equal to s or not
{

printf("The Book is available\n");


printf(" ID:%d\n",a.id);
printf(" Name:%s\n",a.name);
printf(" Author:%s\n",a.Author);
printf(" Qantity:%d\n",a.quantity);
printf(" Price:Rs.%.2f\n",a.Price);

d++;
}

}
if(d==0)
{





printf("\aNo Record Found\n");
}
;
printf("Try another search?(Y/N)\n");
if(getch()=='y')
searchbooks();
else
mainmenu();
break;
}
default :
mainmenu();
}
fclose(fp);
}
void rentbooks(void)  //function that issue books from library
{
int t;

system("cls");
printf("\n\n                                     Rental SECTION                                \n");

	printf("__,,------------------------------------..   ..---------------------------,,__\n");
    printf("|||                                        Y                              ,,__\n");
    printf("|||                                        |                              ,,__\n");                                                             
    printf("||| 1. Rent a Book                         |                              ,,__\n");                                                 
    printf("|||                                        |                              ,,__\n"); 
    printf("||| 2. View Rentd Book                     |                              ,,__\n");                                                
    printf("|||                                        |                              ,,__\n"); 
    printf("||| 3. Search Rented Book                  |                              ,,__\n");
    printf("|||                                        |                              ,,__\n"); 
    printf("||| 4. Remove Rented Book                  |                              ,,__\n");
    printf("|||                                        |                              ,,__\n"); 
	printf(" __,, .----------------------------------.__.-----------------------------,,__\n");

	   printf("\nEnter a Choice:\n");
switch(getch())
{
case '1':  //issue book
{
system("cls");
int c=0;
char another='y';
while(another=='y')
{
system("cls");

printf("\n*** Book Rental Section***\n");
printf("Enter the Book Id:\n");
scanf("%d",&t);
fp=fopen("rec.dat","rb");
fs=fopen("rent.dat","ab+");
if(checkid(t)==0) //issues those which are present in library
{

printf("The book record is available\n");
printf("There are %d unrented books in library \n",a.quantity);
printf("The name of book is %s\n",a.name);
printf("Enter student name:\n");
scanf("%s",a.stname);
//struct dosdate_t d; //for current date
//_dos_getdate(&d);
//a.issued.dd=d.day;
//a.issued.mm=d.month;
//a.issued.yy=d.year;

printf("Rent date=%d-%d-%d\n",a.rent.dd,a.rent.mm,a.rent.yy);

printf("The BOOK of ID %d is Rented\n",a.id);
a.duedate.dd=a.rent.dd+RETURNTIME;   //for return date
a.duedate.mm=a.rent.mm;
a.duedate.yy=a.rent.yy;
if(a.duedate.dd>30)
{
a.duedate.mm+=a.duedate.dd/30;
a.duedate.dd-=30;

}
if(a.duedate.mm>12)
{
a.duedate.yy+=a.duedate.mm/12;
a.duedate.mm-=12;

}

printf("To be return:%d-%d-%d\n",a.duedate.dd,a.duedate.mm,a.duedate.yy);
fseek(fs,sizeof(a),SEEK_END);
fwrite(&a,sizeof(a),1,fs);
fclose(fs);
c=1;
}
if(c==0)
{

printf("No record found\n");
}

printf("Rent any more(Y/N):\n");
fflush(stdin);
another=getche();
fclose(fp);
}

break;
}
case '2':  //show issued book list
{
system("cls");
int j=4;
printf("                             Rented book list                          \n");

printf("\nSTUDENT NAME    CATEGORY    ID    BOOK NAME    Rental DATE    RETURN DATE\n");
fs=fopen("rent.dat","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{


printf("%s\t",a.stname);
printf("%s\t",a.cat);
printf("%d\t",a.id);
printf("%s\t",a.name);
printf("%d-%d-%d\t",a.rent.dd,a.rent.mm,a.rent.yy );
printf("%d-%d-%d\t",a.duedate.dd,a.duedate.mm,a.duedate.yy);

j++;

}
fclose(fs);
returnfunc();
}
break;
case '3':   //search books by id
{
system("cls");
printf("Enter Book ID:\n");
int p,c=0;
char another='y';
while(another=='y')
{

scanf("%d",&p);
fs=fopen("rent.dat","rb");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==p)
{
rentalrecord();
printf("Press any key.......\n");
getch();
rentalrecord();
c=1;
}

}
fflush(stdin);
fclose(fs);
if(c==0)
{
printf("No Record Found\n");
}

printf("Try Another Search?(Y/N)\n");
another=getch();
}
}
break;
case '4':  //remove issued books from list
{
system("cls");
int b;
FILE *fg;  //declaration of temporary file for delete
char another='y';
while(another=='y')
{

printf("Enter book id to remove:\n");
scanf("%d",&b);
fs=fopen("rent.dat","rb+");
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id==b)
{
rentalrecord();
findbook='t';
}
if(findbook=='t')
{

printf("Do You Want to Remove it?(Y/N)\n");
if(getch()=='y')
{
fg=fopen("rec.dat","wb+");
rewind(fs);
while(fread(&a,sizeof(a),1,fs)==1)
{
if(a.id!=b)
{
fseek(fs,0,SEEK_CUR);
fwrite(&a,sizeof(a),1,fg);
}
}
fclose(fs);
fclose(fg);
remove("rent.dat");
rename("rec.dat","rent.dat");

printf("The Rented book is removed from list\n");

}

}
if(findbook!='t')
{

printf("No Record Found\n");
}
}

printf("Delete any more?(Y/N)\n");
another=getch();
}
}
default:
printf("\aWrong Entry!!\n");
getch();
rentbooks();
break;
}

returnfunc();
}
void viewbooks(void)  //show the list of book persists in library
{
int i=0,j;
system("cls");
printf("  \n                           Book List                      \n            ");

printf("\n\n CATEGORY		ID	BOOKNAME	AUTHOR	QTY	PRICE\n\n");
j=4;
fp=fopen("rec.dat","rb");
while(fread(&a,sizeof(a),1,fp)==1)
{

printf("%s\t",a.cat);

printf("%d\t",a.id);

printf("%s\t",a.name);

printf("%s\t",a.Author);

printf("%d\t",a.quantity);

printf("%.2f\t",a.Price);

printf("\n\n");
j++;
i=i+a.quantity;
}

printf("\nTotal Books =%d\n",i);
fclose(fp);
/*
     	size_t num, i;

    FILE *fp = fopen ("rec.dat", "rb");
    if (fp == NULL) {
        num = 0;
    } else {
        num = fread (book, sizeof(*book), sizeof(book) / sizeof(*book), fp);
        fclose (fp);
        }

    InsertionSort(a.names);

    printf("\nThe input set, in alphabetical order:\n");
    for (i = 0; i < num; i++)
    {printf ("   Item %d is %s, %d\n",book[i].cat, book[i].stock), book[i].name,book[i].Author, book[i].quantity,book[i].Price;
        
    return 0; }*/
returnfunc();
}

/* void InsertionSort(int num, char [name[20]])
{
    for (int i = 1; i < num; i++)
    {
        int j = i;

        while (j > 0 && strcmp(list[j - 1], list[j]) > 0)
        {
            char tmp[name[20]];
            strncpy(tmp, list[j - 1], sizeof(tmp) - 1);
            tmp[sizeof(tmp) - 1] = '\0';

            strncpy(list[j - 1], list[j], sizeof(list[j - 1]) - 1);
            list[j - 1][sizeof(list[j - 1]) - 1] = '\0';

            strncpy(list[j], tmp, sizeof(list[j]));
            list[j][sizeof(list[j]) - 1] = '\0';

            --j;
        }
    }
}
*/
void editbooks(void)  //edit information about book
{
system("cls");
int c=0;
int d,e;
printf("****Edit Books Section****\n");
char another='y';
while(another=='y')
{
system("cls");
printf("Enter Book Id to be edited:\n");
scanf("%d",&d);
fp=fopen("rec.dat","rb+");
while(fread(&a,sizeof(a),1,fp)==1)
{
if(checkid(d)==0)
{

printf("The book is availble\n");

printf("The Book ID:%d\n",a.id);

printf("Enter new name:\n");scanf("%s",a.name);

printf("Enter new Author:\n");scanf("%s",a.Author);

printf("Enter new quantity:\n");scanf("%d",&a.quantity);

printf("Enter new price:\n");scanf("%f",&a.Price);

printf("The record is modified\n");
fseek(fp,ftell(fp)-sizeof(a),0);
fwrite(&a,sizeof(a),1,fp);
fclose(fp);
c=1;
}
if(c==0)
{

printf("No record found\n");
}
}

printf("\nModify another Record?(Y/N)\n");
fflush(stdin);
another=getch() ;
}
returnfunc();
}
void returnfunc(void)
{
{
printf("\n\nPress ENTER to return to main menu\n\n");
}
a:
if(getch()==13) //allow only use of enter
mainmenu();
else
goto a;
}
int getdata()
{
int t;
printf("\n\nEnter the Information Below\n\n");


printf("Category:\n");

printf("%s",catagories[s-1]);

printf("Book ID:\t\n");

scanf("%d",&t);
if(checkid(t) == 0)
{

printf("\aThe book id already exists\a\n");
getch();
mainmenu();
return 0;
}
a.id=t;

printf("Book Name:\n");
scanf("%s",a.name);

printf("Author:\n");
scanf("%s",a.Author);

printf("Quantity:\n");
scanf("%d",&a.quantity);

printf("Price:\n");
scanf("%f",&a.Price);

return 1;
}
int checkid(int t)  //check whether the book is exist in library or not
{
rewind(fp);
while(fread(&a,sizeof(a),1,fp)==1)
if(a.id==t)
return 0;  //returns 0 if book exits
return 1; //return 1 if it not
}
int t(void) //for time
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));

return 0 ;
}



void rentalrecord()  	//function that displayed the book's information
{
		system("cls");
		printf("The Book has taken by Mr. %s",a.stname);
		printf("Rental Date:%d-%d-%d",a.rent.dd,a.rent.mm,a.rent.yy);
		printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}


// End of program

