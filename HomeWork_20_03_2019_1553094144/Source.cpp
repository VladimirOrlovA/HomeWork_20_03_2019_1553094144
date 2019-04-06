//HomeWork_20_03_2019_1553094144


//1.	–азработать структуру Ђ∆ивотноеї(скорость передвижени€, тип(птица, скот, человек), цвет, характеристика(дл€ птицы Ц 
//      скорость полета, вещественное число, дл€ скота Ц парнокопытное, логическа€ переменна€, дл€ человека Ц уровень iq, 
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
	float speed;
	bool artiodactyls;
	int iq;
};

struct Animals
{
	int speed;
	Type type;
	char color[15];
	Characteristics chrct;
	
	void print()
	{
		cout << "  " << speed << "  " << "  " << color << "  ";
		
		if (type == human)
			cout << "human  " << chrct.iq << "  " << endl;
		
		else if (type == cattle && chrct.artiodactyls == 1)
			cout << "cattle  " << "It is artiodactyl  " << endl;
		
		else if (type == cattle && chrct.artiodactyls == 0)
			cout << "cattle  " << endl;
		
		else if (type == bird)
			cout << "bird  " << chrct.speed << "  " << endl;
	}
};


int main()
{
	ifstream fin("DataBase.txt");

	Animals *an;
	
	int n;
	fin >> n;
	
	an = new Animals[n];
	char form[15];

	if (!fin)
	{
		cout << "\n\n file \"DataBase.txt\" does not exist or empty \n\n";
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			fin >> an[i].speed >> form >> an[i].color;
			
			if (strcmp(form, "human") == 0)		// поиск записи human,  через сравнение ф. strcmp
			{
				an[i].type = human;
				fin >> an[i].chrct.iq;
			}

			else if (strcmp(form, "cattle") == 0)	// поиск записи cattle,  через сравнение ф. strcmp
			{
				an[i].type = cattle;
				char form1[20];
				fin >> form1;
				
				if (strcmp(form1, "artiodactyl") == 0) // поиск записи artiodactyl,  через сравнение ф. strcmp
					an[i].chrct.artiodactyls = true;
				else if (strcmp(form1, "notartiodactyl") == 0)
					an[i].chrct.artiodactyls = false;
			}
			
			else if (strcmp(form, "bird") == 0) // поиск записи bird,  через сравнение ф. strcmp
			{
				an[i].type = bird;
				fin >> an[i].chrct.speed;
			}
		}
		
		cout << "Menu:\n" << "\n (1) - Edit animal \n (2) - Print full list \n (3) - Search animal by characteristic \n";
		cout << "\n -> ";
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
			cout << "\n Which animal do you want to edit? -> ";
			int animal;
			cin >> animal;
			if (animal >= 1 && animal <= n)
			{
				cout << "\n Write the speed, type, color and characteristic of the animal: ";
				cin >> an[animal - 1].speed >> form;
				
				if (strcmp(form, "human") == 0)
				{
					an[animal - 1].type = human;
					cin >> an[animal - 1].color;
					cin >> an[animal - 1].chrct.iq;
				}
				
				if (strcmp(form, "cattle") == 0)
				{
					an[animal - 1].type = cattle;
					cin >> an[animal - 1].color;
					char form1[20];
					cin >> form1;
					if (form1 == "artiodactyl")
						an[animal - 1].chrct.artiodactyls = true;
					if (form1 == "notartiodactyl")
						an[animal - 1].chrct.artiodactyls = false;
				}
				
				if (strcmp(form, "bird") == 0)
				{
					an[animal - 1].type = bird;
					cin >> an[animal - 1].color;
					cin >> an[animal - 1].chrct.speed;
				}
				
				for (int i = 0; i < n; i++)
					an[i].print();
			}
			else cout << "\n\n Wrong number of animal \n\n";
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
			int character;
			cout << "Which characteristic:\n (1) - min speed \n (2) - artiodactyl/notartiodactyl \n (3) - min IQ \n";
			cin >> character;
			switch (character)
			{
			
			case 1:
			{
				int speed;
				cout << "min speed: ";
				cin >> speed;
				for (int i = 0; i < n; i++)
					if (an[i].chrct.speed >= speed)
						an[i].print();
				break;
			}
			
			case 2:
			{
				int artiodactyl;
				cout << "\n (1) - artiodactyl \n (2) - not artiodactyl \n";
				cin >> artiodactyl;
				
				if (artiodactyl == 1)
				{
					for (int i = 0; i < n; i++)
						if (an[i].chrct.artiodactyls == true)
							an[i].print();
				}
				if (artiodactyl == 2)
				{
					for (int i = 0; i < n; i++)
						if (an[i].chrct.artiodactyls == false)
							an[i].print();
				}
				break;
			}
			
			case 3:
			{
				int iq;
				cout << "min IQ: ";
				cin >> iq;

				for (int i = 0; i < n; i++)
					if (an[i].chrct.iq <= iq)
						an[i].print();
				break;
			}
			}
		}
		}
	}
	system("pause");
}