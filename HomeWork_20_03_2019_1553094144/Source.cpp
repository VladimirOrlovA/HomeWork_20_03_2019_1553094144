//HomeWork_20_03_2019_1553094144


//1.	–азработать структуру Ђ∆ивотноеї(скорость передвижени€, тип(птица, скот, человек), цвет, характеристика(дл€ птицы Ц 
//      скорость полета, вещественное число, дл€ скота Ц парнокопытное, логическа€ переменна€, дл€ человека Ц уровень IQ, 
//      цела€ переменна€).
//	–екомендации: характеристику реализовать как объединение, тип реализовать как перечислимый тип данных.
//	ј)** —оздать экземпл€р структуры Ђ∆ивотноеї и реализовать дл€ него следующие функции :
//Х	¬вод информации
//Х	ѕечать информации
//Ѕ)*** —оздать массив из 10 экземпл€ров структуры Ђ∆ивотноеї и реализовать дл€ него следующие функции :
//Х	–едактировать животное
//Х	ѕечать всего списка
//Х	ѕоиск животного по характеристике

#include<iostream>
#include<fstream>
using namespace std;


enum Type
{
	bird,
	cattle,
	human
};

union Characteristics
{
	double speed;
	bool artiodactyls;
	int IQ;
};

struct Animals
{
	int speed;
	Type t;
	char color[15];
	Characteristics chrct;
	
	void print()
	{
		cout << "  " << speed << "  " << "  " << color << "  ";
		
		if (t == human)
			cout << "human  " << chrct.IQ << "  " << endl;
		
		else if (t == cattle && chrct.artiodactyls == 1)
			cout << "cattle  " << "It is artiodactyl  " << endl;
		
		else if (t == cattle && chrct.artiodactyls == 0)
			cout << "cattle  " << endl;
		
		else if (t == bird)
			cout << "bird  " << chrct.speed << "  " << endl;
	}
};


int main()
{
	Animals *an;
	int n;
	ifstream fin("DataBase.txt");
	fin >> n;
	
	an = new Animals[n];
	char c[10];

	for (int i = 0; i < n; i++)
	{
		fin >> an[i].speed >> c >> an[i].color;
		if (strcmp(c, "human") == 0)
		{
			an[i].t = human;
			fin >> an[i].chrct.IQ;
		}

		else if (strcmp(c, "cattle") == 0)
		{
			an[i].t = cattle;
			char c1[20];
			fin >> c1;
			if (strcmp(c1, "artiodactyl") == 0)
				an[i].chrct.artiodactyls = true;
			else if (strcmp(c1, "notartiodactyl") == 0)
				an[i].chrct.artiodactyls = false;
		}
		else if (strcmp(c, "bird") == 0)
		{
			an[i].t = bird;
			fin >> an[i].chrct.speed;
		}
	}
	cout << "Menu:\n" << "\n (1) - Edit animal \n (2) - Print full list \n (3) - Search animal by characteristic \n";
	
	int choose;
	cin >> choose;
	
	switch (choose)
	{
	case 1:
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << " - ";
			an[i].print();
		}
		cout << "Which animal do you want to edit? ";
		int a;
		cin >> a;
		if (a >= 1 && a <= n)
		{
			cout << "Write the speed, type, color and characteristic of the animal: ";
			cin >> an[a - 1].speed >> c;
			if (strcmp(c, "human") == 0)
			{
				an[a - 1].t = human;
				cin >> an[a - 1].color;
				cin >> an[a - 1].chrct.IQ;
			}
			if (strcmp(c, "cattle") == 0)
			{
				an[a - 1].t = cattle;
				cin >> an[a - 1].color;
				char c1[20];
				cin >> c1;
				if (c1 == "artiodactyl")
					an[a - 1].chrct.artiodactyls = true;
				if (c1 == "notartiodactyl")
					an[a - 1].chrct.artiodactyls = false;
			}
			if (strcmp(c, "bird") == 0)
			{
				an[a - 1].t = bird;
				cin >> an[a - 1].color;
				cin >> an[a - 1].chrct.speed;
			}
			for (int i = 0; i < n; i++)
				an[i].print();
		}
		else cout << "Wrong number of animal";
		break;
	}
	case 2:
	{
		for (int i = 0; i < n; i++)
			an[i].print();
		break;
	}
	case 3:
	{
		int a;
		cout << "Which characteristic:\n1 - min speed\n2 - artiodactyl/notartiodactyl\n3 - min IQ\n";
		cin >> a;
		switch (a)
		{
		case 1:
		{
			int sp;
			cout << "min speed: ";
			cin >> sp;
			for (int i = 0; i < n; i++)
				if (an[i].chrct.speed >= sp)
					an[i].print();
			break;
		}
		case 2:
		{
			int art;
			cout << "1 - artiodactyl\n2 - not artiodactyl\n";
			cin >> art;
			if (art == 1)
			{
				for (int i = 0; i < n; i++)
					if (an[i].chrct.artiodactyls == true)
						an[i].print();
			}
			if (art == 2)
			{
				for (int i = 0; i < n; i++)
					if (an[i].chrct.artiodactyls == false)
						an[i].print();
			}
			break;
		}
		case 3:
		{
			int IQ;
			cout << "min IQ: ";
			cin >> IQ;
			for (int i = 0; i < n; i++)
				if (an[i].chrct.IQ >= IQ)
					an[i].print();
			break;
		}
		}
	}
	}
	system("pause");
}