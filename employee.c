#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
COORD coord={0,0};
struct emp
	{
		int ID;
		char name[30];
		char gender;
		int age;
		int salary;
		char designation[20];
		char address[100];
		char martial_status;
		char d_o_b[15];
		char CNIC_NO[15];
		int attendance;
	};
int welcome_screen(void);
int password_screen(void);
void add_record(FILE *fp);
void view_record(FILE *fp);
void menu_screen(FILE *fp);
void edit_record(FILE *fp);
void delete_record(FILE *fp);
void search_record(FILE *fp);
void gotoxy(int x,int y);

int main() 
{
     
	FILE *fp,*ft;
	char another,choice;
	
	struct emp e;
	char id;
	size_t recsize = sizeof(struct emp);

	fp = fopen("EMPLOYEE1.DAT", "rb+");
	if (fp == NULL)
	{
		fp = fopen("EMPLOYEE1.DAT", "wb+");
		if (fp == NULL)
		{
    	printf("can not open file");
    	exit (1);
    	}
	}
	menu_screen(fp);
	fclose(fp);
	return 0;
}
void gotoxy(int x,int y)
{
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void menu_screen(FILE *fp)
{
    char another, choice;
    while (1)
    {
        system("cls\n");
        gotoxy(90,15);
        printf(" MAIN MENU");
        gotoxy(90,20);
        printf("1-VIEW RECORD\n");
        gotoxy(90,22);
        printf("2-ADD RECORD\n");
        gotoxy(90,24);
        printf("3-EDIT RECORD\n");
        gotoxy(90,26);
        printf("4-DELETE RECORD\n");
        gotoxy(90,28);
        printf("5-SEARCH RECORD\n");
        gotoxy(90,30);
        printf("6-ATTENDANCE\n");
        gotoxy(90,32);
        printf("7-SALARY\n");
        gotoxy(90,34);
        printf("8-NOTIFICATIONS\n");
        gotoxy(90,36);
        printf("9-ABOUT\n");
        gotoxy(90,38);
        printf("0-EXIT");
        fflush(stdin);
        gotoxy(90,40);
        printf("\nEnter your choice: ");
        choice = getche();
        switch (choice)
        {
        case '1':
            view_record(fp);
            break;
        case '2':
            add_record(fp);
            break;
        case '3' :
        	edit_record(fp);
        	break;
        case '4' :
        	delete_record(fp);
        	break;
        case '5' :
        	search_record(fp);
        	break;	
        case '6' :
        	//edit_record();
        	break;	
        case '7' :
        	//edit_record();	        	
        	break;
        case '8' :
        	//edit_record();
        	break;
        case '9' :
        	//edit_record();
        	break;
        case '0':
            exit(0);
            break;
        }
    }
}
void view_record(FILE *fp)
{
    system("cls");
    struct emp e;
    rewind(fp);
    while (fread(&e, sizeof(struct emp), 1, fp) == 1)
    {
        printf("ID: %d\n", e.ID);
        printf("Name: %s\n", e.name);
        printf("Gender: %c\n", e.gender);
        printf("Age: %d\n", e.age);
        printf("Salary: %d\n", e.salary);
        printf("Designation: %s\n", e.designation);
        printf("Address: %s\n", e.address);
        printf("Marital Status: %c\n", e.martial_status);
        printf("Date of Birth: %s\n", e.d_o_b);
        printf("CNIC No.: %s\n", e.CNIC_NO);
        printf("Attendance: %d\n", e.attendance);

        printf("\n------------------------\n");
    }
    getch();
}
void add_record(FILE *fp)
{
	system("cls");
	struct emp e;
	fseek(fp,0,SEEK_END);
	char another='y';
	while(another=='y')
	{
		printf("\nEnter the ID: ");
		scanf("%d",&e.ID);
		printf("\nEnter the name: ");
		scanf("%s",&e.name);
		printf("\nEnter the gender: ");
		scanf(" %c",&e.gender);
		printf("\nEnter the age: ");
		scanf("%d",&e.age);	
		printf("\nEnter the salary: ");
		scanf("%d",&e.salary);
		printf("\nEnter the designation: ");
		scanf("%s",&e.designation);
		printf("\nEnter the address: ");
		scanf("%s",&e.address);
		printf("\nEnter the martial status: ");
		scanf(" %c",&e.martial_status);
		printf("\nEnter the date of birth: ");
		scanf("%s",&e.d_o_b);
		printf("\nEnter the CNIC No.: ");
		scanf("%s",&e.CNIC_NO);
		printf("\nEnter the attendance: ");
		scanf("%d",&e.attendance);	
		fwrite(&e,sizeof(struct emp),1,fp);
		printf("\nDo you want to add another record? (y/n): ");
		fflush(stdin);
		another=getchar();	
	}
		
}
int welcome_screen(void)
{
    char login;
	system("cls");
	gotoxy(80,18);
	printf("________________________________________");
	gotoxy(88,20);
	printf("EMPLOYEE MANAGEMENT SYSTEM");
	gotoxy(80,22);
	printf("________________________________________");	
    printf("\n\n \t\t\t \t\t\t\t\t\t\t Enter L/l to login and any key to exit:");
    login=getche();
    if(login=='L'||login=='l')
    {
        return 1;
    }
    else
    exit(0);
}
void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int password_screen(void)
{
	system("cls");
	gotoxy(80,15);
	char password[10]="employee";
	char password1[10];
	char key[15]="thisisakey??";
	char key1[15];
	char new;
	printf("\n \t\t\t \t\t\t\t\t\t\t Enter the 8 digit password to enter:");
	scanf("%s",password1);
	if(strcmp(password,password1)==0)
	{
		return 1;
	}
	else
	{
		while (strcmp(password,password1)!=0)
		{
		printf("\n \t\t\t \t\t\t\t\t\t\t Wrong password");
		printf("\n \t\t\t \t\t\t\t\t\t\t Forgot your password? Enter F/f to enter the key:");
		printf("\n \t\t\t \t\t\t\t\t\t\t To re-enter the password press r/R:");
		new=getche();
		switch(new)
		{
			case 'r':
			case 'R':
					printf("\n \t\t\t \t\t\t\t\t\t\t Enter the 8 digit password to enter:");
					scanf("%s",password1);
                    if(strcmp(password,password1)!=0)
                    {
                        printf("\n \t\t\t \t\t\t\t\t\t\t Wrong password");
                        password_screen();
                    }
					break;
			case 'f':
			case 'F':
					printf("\n \t\t\t \t\t\t\t\t\t\t Enter the 12 digit key to change the password:");
					scanf("%s",key1);
					if(strcmp(key,key1)==0)
					{
						return 1;
					}	
					else
					{
						printf("\n \t\t\t \t\t\t\t\t\t\t Ask your administrator for the valid key");
						exit(0);
					}
		}
		return 1;	
		}
	}
	
}

void edit_record(FILE *fp) {
    system("cls");
    struct emp e;
    char another = 'y';
    int emp_id, op;

    while (another == 'y') {
        printf("Enter employee id to modify:\n");
        scanf("%d", &emp_id);
        rewind(fp);

        while (fread(&e, sizeof(struct emp), 1, fp) == 1) {
            if (emp_id == e.ID) {
                printf("What do you want to edit:\n");
                printf("1.ID\n2.Name\n3.Gender\n4.Age\n5.Salary\n6.Designation\n7.Address\n8.Marital Status\n9.Date of Birth\n10.CNIC\n11.Attendance\n");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("Enter new ID: ");
                        scanf("%d", &e.ID);
                        break;
                    case 2:
                        printf("Enter new name: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.name, sizeof(e.name), stdin);
                        break;
                    case 3:
                        printf("Enter new gender: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.gender, sizeof(e.gender), stdin);
                        break;
                        case 4:
                        printf("Enter new age: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.age, sizeof(e.age), stdin);
                        break;
                        case 5:
                        printf("Enter new salary: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.salary,4, stdin);
                        break;
                        case 6:
                        printf("Enter new designation: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.designation, sizeof(e.designation), stdin);
                        break;
                        case 7:
                        printf("Enter new address: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.designation, sizeof(e.designation), stdin);
                        break;
                        case 8:
                        printf("Enter new martial status: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.martial_status, sizeof(e.martial_status), stdin);
                        break;
                        case 9:
                        printf("Enter new CNIC No: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.CNIC_NO, sizeof(e.CNIC_NO), stdin);
                        break;
                        case 10:
                        printf("Enter new Date of birth: ");
                        clearBuffer();  // Clear input buffer before fgets
                        fgets(e.d_o_b, sizeof(e.d_o_b), stdin);
                        break;
                        case 11:
                        printf("Enter new attendance: ");
                        clearBuffer();  // Clear input buffer before fgets
						scanf("%d", &e.attendance);
                        //fgets(e.attendance, sizeof(e.attendance), stdin);
                        break;
                    
                }

                fseek(fp, -sizeof(struct emp), SEEK_CUR);
                fwrite(&e, sizeof(struct emp), 1, fp);
                break;  // Exit the loop after modifying the record
            }
        }

        printf("Do you want to edit another record(y/n):\n");
        clearBuffer();  // Clear input buffer before getche
        another = getche();
    }
}
void delete_record(FILE *fp) {
    struct emp e;
    FILE *ft;
    system("cls");
    char another = 'y';
    int emp_id;

    while (another == 'y') {
        printf("Enter employee id to delete record:\n");
        scanf("%d", &emp_id);
        clearBuffer();  // Clear input buffer before getche

        ft = fopen("temp.DAT", "wb");
        rewind(fp);

        while (fread(&e, sizeof(struct emp), 1, fp) == 1) {
            if (emp_id != e.ID) {
                fwrite(&e, sizeof(struct emp), 1, ft);
            }
        }

        fclose(fp);
        fclose(ft);

        remove("EMPLOYEE1.DAT");
        rename("temp.DAT", "EMPLOYEE1.DAT");
        fp = fopen("EMPLOYEE1.DAT", "rb+");  // Reopen the file here

        printf("Delete another record(y/n): ");
        clearBuffer();  // Clear input buffer before getche
        another = getche();
    }
}
void search_record(FILE *fp)
{
    struct emp e;
    int n;
    system("cls");
    rewind(fp);
    char another = 'y';

    while (another == 'y')
    {
        printf("SEARCH RECORD\n");
        printf("Enter ID_NO of the employee you want to search: ");
        fflush(stdin);
        scanf("%d", &n);

        fp = fopen("EMPLOYEE1.DAT", "rb");  // Corrected file opening mode

        if (fp == NULL)
        {
            printf("Unable to open the file.\n");
            exit(1);
        }

        int found = 0;

        while (fread(&e, sizeof(struct emp), 1, fp) == 1)
        {
            if (n == e.ID)
            {
                printf("ID: %d\n", e.ID);
                printf("Name: %s\n", e.name);
                printf("Gender: %c\n", e.gender);
                printf("Age: %d\n", e.age);
                printf("Salary: %d\n", e.salary);  // Corrected format specifier
                printf("Designation: %s\n", e.designation);
                printf("Address: %s\n", e.address);
                printf("Marital Status: %c\n", e.martial_status);
                printf("Date of Birth: %s\n", e.d_o_b);
                printf("CNIC No.: %s\n", e.CNIC_NO);
                printf("Attendance: %d\n", e.attendance);
                printf("------------------------\n");

                found = 1;
                break;
            }
        }

        fclose(fp);

        if (!found)
        {
            printf("Record not found.\n");
        }

        printf("Do you want to search another record? (y/n): ");
        fflush(stdin);
        another = getchar();
    }
}