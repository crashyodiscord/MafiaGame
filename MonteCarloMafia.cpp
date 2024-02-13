#include <iostream>
#include <vector>

using namespace std;

void TheVote(int &Traitors, int &Faithful)
{

	vector<int> AllPlayers(Traitors + Faithful);

	fill(AllPlayers.begin(), AllPlayers.end(), 0);

	AllPlayers[rand() % Faithful] += Traitors;

	for (int i = 0; i < Faithful; i++)
	{
		AllPlayers[rand() % (Faithful + Traitors)]++;
	}

	int index = 0;
	int max = 0;
	for (int i = 0; i < (Faithful + Traitors); i++)
	{
		if (AllPlayers[i] > max)
		{
			max = AllPlayers[i];
			index = i;
		}
	}
	if (index + 1 >= Faithful) Traitors--;
	else Faithful--;
}

int main()
{
	srand(time(NULL));

	int OriginalFaithful;
	cin >> OriginalFaithful;

	int OriginalTraitors;
	cin >> OriginalTraitors;

	int TraitorWins = 0;

	int Simulations;
	cin >> Simulations;

	for (int i = 0; i < Simulations; i++)
	{
		int Faithful = OriginalFaithful;
		int Traitors = OriginalTraitors;
		//Main Game loop
		while (Faithful + Traitors > 2 && Faithful > 0 && Traitors > 0)
		{
			Faithful--;
			TheVote(Traitors, Faithful);
		}

		if (Traitors > 0) TraitorWins++;

	}
	
	cout << ((double)TraitorWins / (double)Simulations) * 100 << endl;
}