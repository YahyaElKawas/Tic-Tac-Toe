#include <iostream>
using namespace std;

bool wether_wins(char arr2[9][9], int n, char player)
{
	for (int r = 0; r < n; r++)
	{
		int cnt = 0;
		for (int c = 0; c < n; c++)
		{
			if (arr2[r][c] == player) cnt++;
		}
		if (cnt == n) return true;
	}

	for (int c = 0; c < n; c++)
	{
		int cnt = 0;
		for (int r = 0; r < n; r++) if (arr2[r][c] == player) cnt++;
		if (cnt == n) return true;
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr2[i][i] == player) cnt++;
	}

	if (cnt == n) return true;
	else return false;
}

int main()
{
	char arr[9][9];
	cout << "Enter number of rows and columns: " << endl;
	int n;
	cin >> n;

	while (!(3 <= n && n <= 9))
	{
		cout << "Please enter a valid number: " << endl;
		cin >> n;
	}

	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++) arr[x][y] = '.';
	}

	for (int i = 0; i < n * n; i++)
	{
		int r1, c1;
		cout << "Player x turn. Enter empty location (r, c): " << endl;
		cin >> r1 >> c1;
		while (arr[r1 - 1][c1 - 1] != '.')
		{
			cout << "Please enter an empty location: " << endl;
			cin >> r1 >> c1;
		}
		arr[r1 - 1][c1 - 1] = 'x';

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++) cout << arr[a][b];
			cout << endl;
		}

		if (wether_wins(arr, n, 'x'))
		{
			cout << "Player x wins!" << endl;
			return 0;
		}

		int r2, c2;
		cout << "Player o turn. Please enter an empty location: " << endl;
		cin >> r2 >> c2;
		while (arr[r2 - 1][c2 - 1] != '.')
		{
			cout << "Please enter a valid location: " << endl;
			cin >> r2 >> c2;
		}
		arr[r2 - 1][c2 - 1] = 'o';

		for (int a = 0; a < n; a++)
		{
			for (int b = 0; b < n; b++) cout << arr[a][b];
			cout << endl;
		}

		if (wether_wins(arr, n, 'o'))
		{
			cout << "Player 2 wins!";
			return 0;
		}
	}

	cout << "It's a tie!";
	return 0;
}
