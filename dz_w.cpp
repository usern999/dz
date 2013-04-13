#include <vector>
#include <conio.h>
#include "classes.h"


using namespace std;

int checkc(int c)
{
	if((c<0)||(c>2))
	{
		return 1;
	}
	return 0;
}


void main()
{
	int b,i=0,c=0;
	vector<LEAGUE> a(3,LEAGUE());
	while(1)
	{
		printf("0-Init league\n"
			"1-add team\n"
			"2-delete team\n"
			"3-print information\n"
			"4-print information about league\n"
			"5-join leagues\n");
		scanf("%d",&b);
		switch(b)
		{
		case 0:								//Инициализация лиги
			printf("Select league\n");
			scanf("%d",&c);
			if(checkc(c))
			{
				printf("error\n");
				break;
			}
			a[c].SetName();
			break;
		case 1:								//Добавление команды
			printf("Select league\n");
			scanf("%d",&c);
			if(checkc(c))
			{
				printf("error\n");
				break;
			}
			a[c].AddTeam();
			a[c].InitTeam();
			break;
		case 2:								//Удаление команды
			printf("Select league\n");
			scanf("%d",&c);
			if(checkc(c))
			{
				printf("error\n");
				break;
			}
			a[c].DeleteTeam();
			break;
		case 3:								//Распечатка информации о командах в лиге
			printf("Select league\n");
			scanf("%d",&c);
			if(checkc(c))
			{
				printf("error\n");
				break;
			}
			printf("**************************************\n");
			for(int i=0;i<a[c].GetNumberOfTeams();++i)
			{
				a[c].PrintNameOfTeam(i);
				a[c].PrintNumberOfPlayers(i);
				a[c].PrintSalary(i);
				a[c].PrintWins(i);
				a[c].PrintLoses(i);
				printf("\n");
			}
			printf("**************************************\n");
			break;
		case 4:									//Распечатка информации о лиге
			printf("Select league\n");
			scanf("%d",&c);
			if(checkc(c))
			{
				printf("error\n");
				break;
			}
			printf("**************************************\n");
			a[c].PrintName();
			printf("NumberOfTeams %d\n",a[c].GetNumberOfTeams());
			printf("NumberOfPlayers %d\n",a[c].GetNumberOfPlayers());
			printf("AverageSalary %f\n",a[c].GetSalary());
			printf("**************************************\n");
			break;
		case 5:									//Объединение лиг
			int c1;
			printf("Select league 1\n");
			scanf("%d",&c);
			printf("Select league 2\n");
			scanf("%d",&c1);
			if(checkc(c)||checkc(c1))
			{
				printf("error\n");
				break;
			}
			if(c1!=c)
			{
				a[c]=a[c]+a[c1];
			}
		}
	}
}