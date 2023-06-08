//Cheung Ka Yan,1155162671,1155162671@link.cuhk.edu.hk
#include <iostream>
#include <stdio.h>      /* printf */
using namespace std;

int gridState(long long grid, int pos)
{
	//To get the integer part of the grid and return the lastest digit
	int temp = 0 ;//To store the state of th
	int expoent = 10;
	//if (pos == 1 || pos == 2 || pos == 3)
	//{
	//	return 0;
	//}
	switch (pos) 
	{
	case 1:
		{
			temp = (grid / 1000000000000000) % expoent;
			return temp;
		}
	case 2:
		{
			temp = (grid / 100000000000000) % expoent;
			return temp;
		}
	case 3:
		{
			temp = (grid / 10000000000000) % expoent;
			return temp;
		}
	case 4:
		{
			temp = (grid / 1000000000000) % expoent;
			return temp;
		}
	case 5:
		{
			temp = (grid / 100000000000) % expoent;
			return temp;
		}
	case 6:
		{
			temp = (grid / 10000000000) % expoent;
			return temp;
		}
	case 7:
		{
			temp = (grid / 1000000000) % expoent;
			return temp;
		}
	case 8:
		{
			temp = (grid / 100000000) % expoent;
			return temp;
		}
	case 9:
		{
			temp = (grid / 10000000) % expoent;
			return temp;
		}
	case 10:
		{
			temp = (grid / 1000000) % expoent;
			return temp;
		}
	case 11:
		{
			temp = (grid / 100000) % expoent;
			return temp;
		}
	case 12:
		{
			temp = (grid / 10000) % expoent;
			return temp;
		}
	case 13:
		{
			temp = (grid / 1000) % expoent;
			return temp;
		}
	case 14:
		{
			temp = (grid / 100) % expoent;
			return temp;
		}
	case 15:
		{
			temp = (grid / 10) % expoent;
			return temp;
		}
	case 16:
		{
			temp = grid % expoent;
			return temp;
		}
	}
	

}

void printGrid(long long grid)//To get the state of the figure and output the figure
{
	int temp = 0;//Temp store the moving point of state in the figure
	int counter = 0;//Count the loops to print the dots
	//Print from right to downwards
	while(counter < 4)
	{
		for (int i = 0 ; i < 4 ; i++)
		{
			temp = counter * 4 + i + 1;
			if (gridState(grid, temp) == 1)
			{
				cout << "A "; //When the state is 1 , print out A
			} 
			else if (gridState(grid, temp) == 2)
			{
				cout << "B "; //When the state is 2 , print out B
			}
			else
			{
				cout << ". "; //When the state is 0, print out a dot wth space
			}
		}
		cout << endl;
		counter = counter + 1;
	}
}

bool isPlaceable(long long grid, int pos, int p)//The bool will be true if it is placeable
{
	//To check whether the value of the figure is addable or not
	int checkp1empty, checkp2empty = 0; //Checking player1 for the line and checking player2 for the row
	bool isPlaceable = true; //int that the bool is able to place; 

	//Check whether the input had out if range
	if (pos < 1 || pos > 16 || p == '1' || p == '2')
	{
		isPlaceable = false;
	}
	//Check for player1
	if (p == 1)
	{
		checkp1empty = pos + 4;
		if (gridState(grid, pos) == 0 && gridState(grid, checkp1empty) == 0)
		{
			isPlaceable = true;
		}
		else
		{
			isPlaceable = false;
		}

	}
	//Check for player2
	if (p == 2)
	{
		checkp2empty = pos + 1;
		if (gridState(grid, pos) == 0 && gridState(grid, checkp2empty) == 0)
		{
			isPlaceable = true;
		}
		else
		{
			isPlaceable = false;
		}
	}
	
	return isPlaceable;
}

void putToGrid(long long& grid, int pos, int p)
{
	int setpos = 10;
	//Check for player1
	if (p == 1)
	{
		grid = grid + (1 * pow(setpos, (16 - pos)));
		grid = grid + (1 * pow(setpos, (16 - pos - 4)));

	}
	else if (p == 2)
	{
		grid = grid + (2 * pow(setpos, (16 - pos)));
		grid = grid + (2 * pow(setpos, (16 - pos - 1)));
	}

}


int main() 
{
	int userinputmove;
	long long grid = 0;
	int current_player = 1; // start with Player1
	int endgame = 0;//determine when the game will end
	printGrid( grid);
	
	while (1)
	{
	resetplayer1:
		if (current_player == 1)
		{
			cout << "Player 1 's move: ";
			cin >> userinputmove;
			//cout << endl;
			while (isPlaceable(grid, userinputmove, current_player) == false || userinputmove == 16 || userinputmove == 15 || userinputmove == 14 || userinputmove == 13)//To check whether the move the player input is available or not
			{
				cout << "Invalid! Try again.";
				cout << endl;
				cout << "Player 1 's move: ";
				cin >> userinputmove;
			}
			putToGrid(grid, userinputmove, current_player);
			printGrid(grid);
			int iamuselesscounter = 1;
			int counterj = 0;
			for (int i = 1; i <= 16; i++)
			{
				counterj = i + 4;
				{
					if (i == 13 || i == 14 || i == 15 || i == 16)//skip to count this when is here
					{
						iamuselesscounter = iamuselesscounter + 1;
						counterj = counterj - 4;

						//counterj = i + 4;
					}
					else if (isPlaceable(grid, i, current_player) == false && isPlaceable(grid, counterj, current_player) == false)
					{
						endgame = endgame + 1;
					}
				}

			}
			if (endgame == 12)//When the game check all the place to replace is false, endgame is trigger
			{
				//cout << "Player 2 wins !";
				//cout << endl;
				//break;
				cout << "Player 2 's move: ";
				cin >> userinputmove;
				putToGrid(grid, userinputmove, 2);
				printGrid(grid);
				cout << "Player 2 wins!";
				cout << endl;
				break;
			}
			else
			{
				endgame = 0;
				if (current_player == 1) current_player = 2; else current_player = 1;//switch player when the vaule is input correctly and not yet endgame
			}
			
		}

		//Swith between player 1 and 2		
		if (current_player == 2)
		{
			cout << "Player 2 's move: ";
			cin >> userinputmove;
			//cout << endl;
			while (isPlaceable(grid, userinputmove, current_player) == false)
			{
				cout << "Invalid! Try again.";
				cout << endl;
				cout << "Player 2 's move: ";
				cin >> userinputmove;
			}
			putToGrid(grid, userinputmove, current_player);
			printGrid(grid);
			//int i = 1;
			int counterj = 0;
			for ( int i = 1 ; i <= 16; i++ )
			{
				counterj = i + 1;
				{
					if (i == 4 || i == 8 || i == 12 || i == 16)//skip to count this when is here
					{
						//i = i + 1;
						counterj = counterj - 1;
					}
					else if (isPlaceable(grid, i, current_player) == false && isPlaceable(grid, counterj, current_player) == false)
					{
						endgame = endgame + 1;
					}
				}
				
			}
			endgame = endgame + 1;
			if (endgame == 13)
			{
				cout << "Player 1 's move: ";
				cin >> userinputmove;
				putToGrid(grid, userinputmove, 1);
				printGrid(grid);
				cout << "Player 1 wins!";
				cout << endl;
				break;
			}
			else
			{
				endgame = 0;
				if (current_player == 1) current_player = 2; else current_player = 1; //switch player when the vaule is input correctly and not yet endgame
			}

		}
	}
	

}