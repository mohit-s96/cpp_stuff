#include <iostream>
#define BOARD_SIZE 3

class TicTac
{
private:
	char nextMove;
public:
	int moves;
	static unsigned char gameBoard[BOARD_SIZE][BOARD_SIZE];
	TicTac()
		: nextMove('X'), moves(0) {}
	static void initBoard()
	{
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				gameBoard[i][j] = '?';
			}
		}
	}
	void printCurrent()
	{
		std::cout << "\033[2J\033[1;1H";
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				std::cout << gameBoard[i][j] << " ";
			}
			std::cout << std::endl;
		}

		std::cout << "Next move: " << nextMove << std::endl;
	}
	void makeOneMove(int i, int j)
	{
		if (gameBoard[i][j] == '?')
		{
			gameBoard[i][j] = nextMove;
			nextMove = nextMove == 'X' ? 'O' : 'X';
			moves++;
		}
	}

	// This algorithm is faster than the checkIfOver method below because it only checks for the row / column affected by the players last move instead of looping through the entire matrix.

	unsigned char checkIfWin(int i, int j)
	{
		char change = gameBoard[i][j];
		for (int p = 0; p < BOARD_SIZE; p++)
		{
			if (gameBoard[i][p] != change)
			{
				change = gameBoard[i][p];
				break;
			}
		}
		if (change == gameBoard[i][j])
			return change;
		
		change = gameBoard[i][j];
		for (int p = 0; p < BOARD_SIZE; p++)
		{
			if (gameBoard[p][j] != change)
			{
				change = gameBoard[p][j];
				break;
			}
		}
		if (change == gameBoard[i][j])
			return change;

		if (i == j)
		{
			change = gameBoard[i][j];
			for (int p = 0; p < BOARD_SIZE; p++)
			{
				if (gameBoard[p][p] != change)
				{
					change = gameBoard[p][p];
					break;
				}
			}
			if (change == gameBoard[i][j])
				return change;
		}
		if (i + j == BOARD_SIZE - 1)
		{
			change = gameBoard[i][j];
			for (int p = 0, q = BOARD_SIZE - 1; p < BOARD_SIZE; p++, q--)
			{
				if (gameBoard[p][q] != change)
				{
					change = gameBoard[p][q];
					break;
				}
			}
			if (change == gameBoard[i][j])
				return change;
		}
		return '?';
	}

	// This algorithm loops over the entire matriz everytime the player makes a move thus it's slower than the checkIfWin() method above.

	unsigned char checkIfOver()
	{
		for (int i = 0 ; i < BOARD_SIZE ; i++)
		{
			char change = gameBoard[i][0];
			for (int j = 1; j < BOARD_SIZE; j++)
			{
				if (gameBoard[i][j] != change)
				{
					change = gameBoard[i][j];
					break;
				}
			}
			if (change == gameBoard[i][0])
				return change;
		}
		for (int i = 0; i < BOARD_SIZE; i++)
		{
			char change = gameBoard[0][i];
			for (int j = 1; j < BOARD_SIZE; j++)
			{
				if (gameBoard[j][i] != change)
				{
					change = gameBoard[j][i];
					break;
				}
			}
			if (change == gameBoard[0][i])
				return change;
		}
		{
			char last = gameBoard[0][0];
			for (int i = 1 ; i < BOARD_SIZE; i++)
			{
				if (gameBoard[i][i] != last)
				{
					last = gameBoard[i][i];
					break;
				}
			}
			if (last == gameBoard[0][0])
				return last;
		}
		{
			char last = gameBoard[0][BOARD_SIZE - 1];
			for (int i = 0, j = BOARD_SIZE - 1; i < BOARD_SIZE; i++, j--)
			{
				if (gameBoard[i][j] != last)
				{
					last = gameBoard[i][j];
					break;
				}
				
			}
			if (last == gameBoard[0][BOARD_SIZE - 1])
				return last;
		}
		return '?';
	}
};

unsigned char TicTac::gameBoard[BOARD_SIZE][BOARD_SIZE];

int main()
{
	TicTac T;
	int i, j;
	unsigned char ch;
	TicTac::initBoard();
	while (true)
	{
		T.printCurrent();
		std::cin >> i;
		std::cin >> j;
		T.makeOneMove(i, j);
		if (T.moves == BOARD_SIZE * BOARD_SIZE)
		{
			T.printCurrent();
			std::cout << "Draw" << std::endl;
			break;
		}
		ch = T.checkIfWin(i, j);
		if (ch != '?')
		{
			T.printCurrent();
			std::cout << "Winner: " << ch << std::endl;
			break;
		}
	}
	
	return 0;
}