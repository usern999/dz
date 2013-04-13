#include <stdio.h>

class TEAM					//Класс команда
{

	char NameOfTeam[25];	//Название команды
	int NumberOfPlayers;	//Количество игроков в команде
	int AverageSalary;		//Средняя зарплата в команде
	int NumberOfWins;		//Количество побед команды
	int NumberOfLoses;		//Количество поражений

public:
	TEAM()
	{
		NumberOfPlayers=0;
		AverageSalary=0;
		NumberOfWins=0;
		NumberOfLoses=0;
	}
	TEAM(int i)
	{
		SetName();
		NumberOfPlayers=0;
		AverageSalary=0;
		NumberOfWins=0;
		NumberOfLoses=0;
	}
	void SetName()
	{
		printf("New team\n");
		scanf("%s",&NameOfTeam);
	}
	void PrintName()
	{
		printf("%s\n",NameOfTeam);
	}
	void SetWinsLoses()
	{
		int n;
		printf("NumberOfWins\n");
		scanf("%d",&n);
		NumberOfWins=n;
		printf("NumberOfLoses\n");
		scanf("%d",&n);
		NumberOfLoses=n;

	}
	void SetNumberOfPlayers()
	{
		int n;
		printf("Number of players\n");
		scanf("%d",&n);
		NumberOfPlayers=n;
	}
	void SetSalary()
	{
		int n;
		printf("Salary\n");
		scanf("%d",&n);
		AverageSalary=n;
	}

	int GetSalary()
	{
		return AverageSalary;
	}
	int GetNumberOfPlayers()
	{
		return NumberOfPlayers;
	}
	int GetWins()
	{
		return NumberOfWins;
	}
	int GetLoses()
	{
		return NumberOfLoses;
	}
	void Delete()
	{
		AverageSalary=0;
		NumberOfPlayers=0;
		NumberOfLoses=0;
		NumberOfWins=0;
	}
	~TEAM()
	{
		NumberOfPlayers=0;	
		AverageSalary=0;		
		NumberOfWins=0;		
		NumberOfLoses=0;
	}
};						

class LEAGUE					//Класс лига
{
	char NameOfLeague[25];		//Название лиги
	int NumberOfTeams;			//Количество команд
	double AverageSalary;		//Средняя зарплата по лиге
	int NumberOfPlayers;		//Количество игроков в лиге
	TEAM team[10];				//Команды лиги

public:
	LEAGUE()
	{
		SetEmptyName();
		NumberOfPlayers=0;
		NumberOfTeams=0;
		AverageSalary=0;
	}
	LEAGUE(int i)
	{
		SetName();
		NumberOfPlayers=0;
		NumberOfTeams=0;
		AverageSalary=0;
	}
	void SetName()
	{
		printf("New name\n");
		scanf("%s",&NameOfLeague);
		printf("\n");
	}
	void SetEmptyName()
	{
		NameOfLeague[0]='\0';
	}
	void PrintName()
	{
		printf("%s\n",NameOfLeague);
	}
	void PrintNameOfTeam(int i)
	{
		team[i].PrintName();
	}
	void PrintNumberOfPlayers(int i)
	{
		printf("Number of players %d\n",team[i].GetNumberOfPlayers());
	}
	void PrintSalary(int i)
	{
		printf("Salary %d\n",team[i].GetSalary());
	}
	void PrintWins(int i)
	{
		printf("Wins %d\n",team[i].GetWins());
	}
	void PrintLoses(int i)
	{
		printf("Loses %d\n",team[i].GetLoses());
	}
	int GetNumberOfTeams()
	{
		return NumberOfTeams;
	}
	double GetSalary()
	{
		return AverageSalary;
	}
	int GetNumberOfPlayers()
	{
		return NumberOfPlayers;
	}
	void Calculate()
	{
		double s=0;
		for (int i=0;i<NumberOfTeams;++i)
		{
			s+=team[i].GetSalary();
		}
		s/=NumberOfTeams;
		AverageSalary=s;
		s=0;
		for (int i=0;i<NumberOfTeams;++i)
		{
			s+=team[i].GetNumberOfPlayers();
		}
		NumberOfPlayers=s;
	}
	void AddTeam()
	{
		if (NumberOfTeams==10)
		{
			printf("League is full\n");
			return;
		}
		else
		{
			team[NumberOfTeams].SetName();
			++NumberOfTeams;
		}
	}
	void InitTeam()
	{
		team[NumberOfTeams-1].SetNumberOfPlayers();
		team[NumberOfTeams-1].SetWinsLoses();
		team[NumberOfTeams-1].SetSalary();
		printf("\n");
		Calculate();
	}
	void DeleteTeam()
	{
		if(!NumberOfTeams)
		{
			printf("League is empty\n");
			return;
		}
		else
		{
			NumberOfTeams-=1;
			team[NumberOfTeams].Delete();
			Calculate();
		}
	}
	friend LEAGUE operator+(LEAGUE l0,LEAGUE l1)
	{
		if (l0.GetNumberOfTeams()+l1.GetNumberOfTeams()>10)
		{
			printf("error");
		}
		else
		{
			int g=0;
			for(int i=l0.GetNumberOfTeams();i<l0.GetNumberOfTeams()+l1.GetNumberOfTeams();++i)
			{
				l0.team[i]=l1.team[g];
				++g;
			}
		}
		l0.NumberOfTeams=l0.GetNumberOfTeams()+l1.GetNumberOfTeams();
		l0.Calculate();
		return l0;
	}
	~LEAGUE()
	{ 
		NumberOfTeams=0;			
		AverageSalary=0;		
		NumberOfPlayers=0;
	}
};