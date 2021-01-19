#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#include<conio.h> //contains delay(),getch(),gotoxy()
#include<windows.h>

//For gotoxy function
COORD coord = {0, 0}; // sets coordinates to 0,0
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}





struct patient//Structure
{
	char name[20], gender[10], complaint[50], diagnosis[20], prescription[20];
	int age,appointment;
	struct patient *next;

};


int count=1, d=1;


struct patient *start=NULL;
struct patient *new_patient(struct patient *start);
struct patient *display(struct patient *start);
struct patient *display_pre(struct patient *start);
struct patient *insert_app(struct patient *start);


int genereateApp();


void admin();
void menu();
void check_user(char username[10], char password[10]);
struct patient *next_ap(struct patient *start);




void login()//Code For Login Function
{
char password[10], username[10], ch;
int i, option;
printf("Enter User name: ");
scanf("%s",username);

printf("Enter the password : ");

for(i=0;i<7;i++)
{
	ch = getch();
	password[i] = ch;
	ch = '*' ;
	printf("%c",ch);
}

password[i] = '\0';

check_login(username, password);

getch();
}



int genereateApp()//Generating Appointment Numbers
{

	return count++;
}


struct patient *new_patient(struct patient *start)//Creating New Node And Inserting
{
    system("cls");

	int age,n,val, y;
	char name[20], gender[10], diagnosis[20],complaint[50];
	struct patient *new_node, *ptr;
	new_node=(struct patient *)malloc(sizeof(struct patient));

    printf("\n Enter The Details\n");
	printf("\nEnter Name: ");
	scanf("%s",name);
	printf("Enter Age: ");
	scanf("%d",&age);
	printf("Press the desired key for Gender\n 1. Male\t 2. Female\t 3. Other: ");
	scanf("%d",&n);
	if(n==1)
		strcpy(gender,"Male");
	else if(n==2)
		strcpy(gender,"Female");
	else
		strcpy(gender,"Other");

	printf("Patient's Complaint: ");
	scanf("%s",complaint);

	new_node=(struct patient *)malloc(sizeof(struct patient));
	strcpy(new_node->name,name);
	strcpy(new_node->gender,gender);
	strcpy(new_node->complaint,complaint);
	new_node->age=age;

	printf("\nPress 1. To insert the person in the appointment list else press 2: ");
	scanf("%d",&y);
	if(y==1) {
		val=genereateApp();
		new_node->appointment=val;   }
	else{
		new_node->appointment=0;}



	if(start==NULL)
	{
		new_node->next=NULL;
		start=new_node;


	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;

		ptr->next=new_node;
		new_node->next=NULL;

	}




	return start;
    }



struct patient *display(struct patient *start)//Display
{
    system("cls");
    gotoxy(1,1);
    printf("****************************************************Appointment Lists Are***********************************************************");
    gotoxy(2,2);
    printf(" Appointment_NO      Name            Age      Gender     Complaint        Diagnosis   ");
	struct patient *ptr;
	int i=1,p=4;
	ptr=start;
	while(ptr!=NULL)
	{
	//printf("\n\n%d",i);
	if(ptr->appointment!=0)
		{
            gotoxy(3,p);
            printf("%d",ptr->appointment);
		}
		gotoxy(23,p);
		printf("%s",ptr->name);
		gotoxy(40,p);
		printf("%d",ptr->age);
		gotoxy(49,p);
		printf("%s",ptr->gender);
		gotoxy(59,p);
		printf("%s",ptr->complaint);
		gotoxy(79,p);
		printf("%s",ptr->diagnosis);


		ptr=ptr->next;
		i++;
		p++;

	}
	getch();

	return start;
}







void menu()
{

	int choice;
	do{
            system("cls");
    gotoxy(20,3);
    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Main Menu \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(20,5);
	printf("1. Add new Patient\n");
	gotoxy(20,7);
	printf("2.Display Details of the Patient\n");
	gotoxy(20,9);
	printf("3. Log In");
	gotoxy(20,11);
	printf("4. Exit\n");
    gotoxy(20,13);
	printf("Enter Your Option: ");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					start=new_patient(start);
				break;
			case 2:
					start=display(start);
				break;
			case 3:
					login();
				break;
			case 4:
					exit(0);
				break;

		}
	}while(choice!=7);
}



void check_login(char username[10], char password[10])//Login Check
{
int n;

	if(strcmp(username, "admin") == 0  )
{
	if(strcmp(password, "default") == 0)
	{
		printf("\n \nWELCOME DR. HOUSE\n");
		admin();
	}
}

else
{
printf("\nPassword or User ID entered is invalid");
printf("\nPress 1 to Try AGAIN or press 2 to exit: ");
scanf("%d",&n);
if(n==1)
{
	main();
}
else
{
	exit(0);
}
}

}



struct patient *next_ap(struct patient *start)
{
    system("cls");
	struct patient *ptr;
	int p,pre,z;


	ptr=start;

	while(ptr!=NULL)
	{
		if(ptr->appointment==d)
		{
		    gotoxy(20,3);
		    printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Counsulting Patient Details\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
		    gotoxy(20,5);
			printf("Name: %s",ptr->name);
			gotoxy(20,7);
			printf("Age: %d",ptr->age);
			gotoxy(20,9);
			printf("Gender: %s",ptr->gender);
			gotoxy(20,11);
			printf("Complaint: %s",ptr->complaint);
			gotoxy(20,13);
			printf("Press 1 to Enter Diagnosis or press 2: ");
			scanf("%d",&p);
			if(p==1)
			{
				printf("\nEnter Diagnosis: ");
				scanf("%s",ptr->diagnosis);

			}

			break;

		}
		ptr=ptr->next;

	}
	d++;


return start;
}




void admin()//Function For Admin Access
{
    system("cls");
	int choice;


	do{
    system("cls");
    gotoxy(20,3);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Welcome To Admin Access \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
    gotoxy(20,5);
	printf("1. View Next Patient");
	gotoxy(20,6);
	printf("2. Display Details of the Patient");
	gotoxy(20,7);
	printf("3. Log Out\n");
	gotoxy(20,8);
	printf("4. Exit\n");
	gotoxy(20,10);


	printf("Enter Your Option: ");
	scanf("%d",&choice);

		switch(choice)
		{
			case 1:
					start=next_ap(start);

				break;
			case 2:
					start=display(start);
				break;
			case 3:
				       menu();
				break;
			case 4:
				exit(1);
				break;
		}
	}while(choice!=5);


}

void typewriter(const char* letter, int rate) {
  for (int i = 0; letter[i] != '\0'; i++)
  {
    printf("%c", letter[i]);
    fflush(stdout);
    usleep((500) * rate);
  }
}


int main()//Welcome Page
{
    int choice;
       typewriter("\n                       :::::::::::::::::::::::::::::::::::::",2);
       typewriter("\n                       ::                                 ::",2);
       typewriter("\n                       ::     ***********************     ::",2);
       typewriter("\n                       ::     *      Greetings!     *     ::",2);
       typewriter("\n                       ::     *                     *     ::",2);
       typewriter("\n                       ::     *      Book Your      *     ::",2);
       typewriter("\n                       ::     *      Appointment!   *     ::",2);
       typewriter("\n                       ::     *                     *     ::",2);
       typewriter("\n                       ::     ***********************     ::",2);
       typewriter("\n                       ::                                 ::",2);
       typewriter("\n                       :::::::::::::::::::::::::::::::::::::\n\n",2);

    menu();
}

