#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//LOGIN FUNCTION
int login(){
	
	int i,num,c;
	char username[20],password[20],checkuser[20],checkpass[20];
	
	FILE *fp;
	
	fp = fopen("uinfo.txt","r");
	fgets(checkuser,20,fp);
	fclose(fp);
	fopen("pinfo.txt","r");
	fgets(checkpass,20,fp);
	fclose(fp);
	start:
	system("cls");
	
	printf("\n\n\t\tLOGIN\n\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n\tUsername: ");
	gets(username);

	if(strcmp(username,checkuser)==0)
	{
		printf("\n\tPassword: ");
		for(i=0;i<5;i++)
		{
			password[i]= getch();
			c = password[i];
			if( c == 13)
			{
				break;
			}
			else
			{
				printf("*");
			}
		}
	if(strcmp(password,checkpass) == 0)
		{
			printf("\n\tWELCOME MBUS1!");
			printf("\n\tPress Enter to continue...");
			getch();
			return 0;
		}
		else
		{

			printf("\n\tAccess Denied, wrong password.\n");
			printf("\n\t[1]Continue or [2]Leave\n");
			scanf("%d",&num);
			fflush(stdin);
			
			switch(num)
			{
				case 1:
					goto start;
				case 2:
					return 1;
					break;
					
			}	
		}
	}
	else 
	{
		printf("\n\tAccess Denied, wrong username.");
		printf("\n\t[1]Continue or [2]Leave");
		scanf("%d",&num);
		fflush(stdin);
		switch(num)
			{
				case 1:
					goto start;
				case 2:
					return 1;
					break;
			}
			
		}
	}
	

//FUNCTION TO VERIFY EMPTY SEAT
int checkEmpty(char seat[][20],int num){
	
	if(strcmp(seat[num - 1],"[empty]") == 0){
		printf("Can't cancel, seat is already empty.\n\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
//FUNCTION TO VERIFY OCCUPIED SEAT
int check(char seat[][20],int num){
	
	if(strcmp(seat[num - 1],"[empty]") != 0){
		printf("Seat occupied please choose another one.\n\n");
		return 0;
	}
	else
	{
		return 1;
	}
}
//FUNCTION TO RESERVE A SEAT
void reserve(char arr[][20]){
	
	int i,num,reps;
	char name[20];
	printf("Enter the number of the seat you would like: ");
	scanf("%d",&reps);
	fflush(stdin);
	printf("\n");
	for(i=0;i<reps;i++){
		start:
		printf("Booking %d\n",i+1);
		printf("Enter desired seat: ");
		scanf("%d",&num);
		fflush(stdin);
		if (check(arr,num) == 0)
		{
			goto start;
		}
		else
		{
			printf("\n");
			printf("Enter name on reservation: ");
			gets(name);
			strcpy(arr[(num - 1)],name);	
			printf("\n\n");
		}
	
	}
	printf("Thank you, that will be $%d\n",50*reps);
	printf("Press Enter to return to the Menu....");
	getchar();
}
//FUNCTION TO INITIATE BOOKING
void booking(char seat1[][20], char seat2[][20], char seat3[][20],char bus1[25],char bus2[25], char bus3[25]) 
{
	system("cls");
	int i,num;
	char name[20];
		
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tWELCOME TO EASY BUS SERVICES'\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tBY MULERO ALAMOU\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
	printf("\tSEAT BOOKING\n\n");
	printf("\tCHOOSE A BUS\n");
	printf("\t[1] %s\n",bus1);
	printf("\t[2] %s\n",bus2);
	printf("\t[3] %s\n",bus3);
	
	scanf("%d",&num);
	fflush(stdin);
	
	switch(num){
		case (1):
			system("cls");
			printf("\tBUS SEATS FOR Good & Well Bus \n\n");
			for(i=0;i<20;i++){
				printf("\t[%d] %s\t",i+1,seat1[i]);
				if(i !=0)
				{
					if((i+1)%2 == 0)
					{
						printf("\n");
					}	
				}
			}
			printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			reserve(seat1);
			break;
		
		case (2):
			system("cls");
			printf("\tBUS SEATS FOR We Will Arrive Bus\n\n");
			for(i=0;i<20;i++){
				printf("\t[%d] %s\t",i+1,seat2[i]);
				if(i !=0){
					if((i+1)%2 == 0)
					{
						printf("\n");
					}	
				}
			}
		printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			reserve(seat2);
			break;
			
		case (3):
			system("cls");
			printf("\tBUS SEATS FOR World Tour Bus\n\n");
			for(i=0;i<20;i++)
			for(i=0;i<20;i++)
			{
				printf("\t[%d] %s\t",i+1,seat3[i]);
				if(i !=0)
				{
					if((i+1)%2 == 0)
					{
						printf("\n");
					}		
				}
			}
		printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			reserve(seat3);
			break;
	}
	
}
//FUNCTION TO VERIFY AVAILABLE SEATS
void status(char seat1[][20], char seat2[][20], char seat3[][20],char bus1[25],char bus2[25], char bus3[25])
{
	system("cls");
	int i,num;
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tWELCOME TO EASY BUS SERVICES'\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tBY MULERO ALAMOU\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
	printf("\tCheck Reservations\n\n");
	printf("\tCHOOSE A BUS\n");
	printf("\t[1] %s\n",bus1);
	printf("\t[2] %s\n",bus2);
	printf("\t[3] %s\n",bus3);
	
	scanf("%d",&num);
	fflush(stdin);
	
	switch(num){
		case (1):
			system("cls");
			printf("\tAvailable seats for Good & Well Bus \n\n");
			for(i=0;i<20;i++){
				printf("\t[%d] %s\t",i+1,seat1[i]);
				if(i !=0)
				{
					if((i+1)%2 == 0)
					{
						printf("\n");
					}	
				}
			}
			getchar();
			break;
		
		case (2):
			system("cls");
			printf("\tAvailable seats for We Will Arrive Bus\n\n");
			for(i=0;i<20;i++){
				printf("\t[%d] %s\t",i+1,seat2[i]);
				if(i !=0){
					if((i+1)%2 == 0)
					{
						printf("\n");
					}	
				}
			}
			getchar();
			break;
			
		case (3):
			system("cls");
			printf("\tAvailable seats for World Tour Bus\n\n");
			for(i=0;i<20;i++)
			{
				printf("\t[%d] %s\t",i+1,seat3[i]);
				if(i !=0)
				{
					if((i+1)%2 == 0)
					{
						printf("\n");
					}		
				}
			}
			getchar();
			break;
	}
}
//FUNCTION TO CANCEL A RESERVATION
void cancel(char seat1[][20], char seat2[][20], char seat3[][20],char bus1[25],char bus2[25], char bus3[25]){
	system("cls");
	int i,num,seat;
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tWELCOME TO EASY BUS SERVICES'\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tBY MULERO ALAMOU\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
	printf("\tCancel Reservations\n\n");
	printf("\tCHOOSE A BUS\n");
	printf("\t[1] %s\n",bus1);
	printf("\t[2] %s\n",bus2);
	printf("\t[3] %s\n",bus3);
	
	scanf("%d",&num);
	fflush(stdin);
	
	switch(num){
		case (1):
			system("cls");
			printf("\tAvailable Seats for Good & Well Bus \n\n");
			for(i=0;i<20;i++){
				printf("\t[%d] %s\t",i+1,seat1[i]);
				if(i !=0)
				{
					if((i+1)%2 == 0)
					{
						printf("\n");
					}	
				}
			}
			printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			start1:
			printf("What seat is your reservation: ");
			scanf("%d",&seat);
			fflush(stdin);
			if(checkEmpty(seat1,seat) == 0)
			{
				goto start1;
			}
			else
			{
				strcpy(seat1[(seat - 1)],"[empty]");
				printf("\n\nYour reservation has been canceled and your $50 have been returned.\nHave a nice Day!");
				getchar();
				break;	
			}
		
		case (2):
			system("cls");
			printf("\tAvailable Seats for We Will Arrive Bus\n\n");
			for(i=0;i<20;i++){
				printf("\t[%d] %s\t",i+1,seat2[i]);
				if(i !=0){
					if((i+1)%2 == 0)
					{
						printf("\n");
					}	
				}
			}
			printf("\n\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			start2:
			printf("What seat is your reservation: ");
			scanf("%d",&seat);
			fflush(stdin);
			if(checkEmpty(seat2,seat) == 0)
			{
				goto start2;
			}
			else
			{
				strcpy(seat2[(seat - 1)],"[empty]");
				printf("\n\nYour reservation has been canceled and your $50 have been returned.\nHave a nice Day!");
				getchar();
				break;	
			}
			
		case (3):
			system("cls");
			printf("\tAvailable Seats for World Tour Bus\n\n");
			for(i=0;i<20;i++)
			{
				printf("\t[%d] %s\t",i+1,seat3[i]);
				if(i !=0)
				{
					if((i+1)%2 == 0)
					{
						printf("\n");
					}		
				}
			}
			printf("\n\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
			start3:
			printf("What seat is your reservation: ");
			scanf("%d",&seat);
			fflush(stdin);
			if(checkEmpty(seat3,seat) == 0)
			{
				goto start3;
			}
			else
			{
				strcpy(seat3[(seat - 1)],"[empty]");
				printf("\n\nYour reservation has been canceled and your $50 have been returned.\nHave a nice Day!");
				getchar();
				break;	
			}
			
	}	
}
//FUNCTION FOR THE MAIN MENU
void menu(char seat1[][20], char seat2[][20], char seat3[][20],char bus1[25],char bus2[25], char bus3[25]){
	system("cls");
	int num,i;
	
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tWELCOME TO EASY BUS SERVICES'\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tBY MULERO ALAMOU\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n\n");
	
	printf("\t\tDo you want to\n\n");

	printf("\t[1] Book a seat\n\n\t[2] Check available seats\n\n\t[3] Cancel a booking\n\n\t[4]Leave\n");
	scanf("%d",&num);
	fflush(stdin);
	switch(num){
		case 1:
			booking(seat1,seat2,seat3,bus1,bus2,bus3);
			menu(seat1,seat2,seat3,bus1,bus2,bus3);
			break;
		case 2:
			status(seat1,seat2,seat3,bus1,bus2,bus3);
			menu(seat1,seat2,seat3,bus1,bus2,bus3);
			break;
		case 3:
			cancel(seat1,seat2,seat3,bus1,bus2,bus3);
			menu(seat1,seat2,seat3,bus1,bus2,bus3);
			break;
		case 4:
			system("cls");
			printf("\nCome again soon!");
			break;
	}
}

int main(){
	int i;
	char seat1[20][20],seat2[20][20],seat3[20][20];
	char bus1[25],bus2[25],bus3[25];
	for(i=0;i<20;i++)
	{
		strcpy(seat1[i],"[empty]");
		strcpy(seat2[i],"[empty]");
		strcpy(seat3[i],"[empty]");
	}
	strcpy(bus1,"Good & Well Bus");
	strcpy(bus2,"We Will Arrive Bus");
	strcpy(bus3,"World Tour Bus");

	printf("\n");
	printf("\n");
	printf("\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tWELCOME TO EASY BUS SERVICES'\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\tBY MULERO ALAMOU\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	printf("\n\tEST 2022\n");
	printf("\n\tPress enter to continue.....");
	getchar();
	printf("\n\n");
	printf("\t\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\n");
	if(login() == 0){
	
		menu(seat1,seat2,seat3,bus1,bus2,bus3);
	}
	else
	{
		printf("failed");
	}

	
	
}

