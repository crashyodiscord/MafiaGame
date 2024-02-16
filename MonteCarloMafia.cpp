#include <iostream>
#include <vector>

using namespace std;

void TheVote(int &Traitors, int &Faithful)
{
	//Making int array with all 0s
	vector<int> AllPlayers(Traitors + Faithful);
	fill(AllPlayers.begin(), AllPlayers.end(), 0);

	AllPlayers[rand() % Faithful] += Traitors;

	for (int i = 0; i < Faithful; i++)
	{
		AllPlayers[rand() % (Faithful + Traitors)]++;
	}

	vector<int> index;
	index.push_back(0);
	vector<int> max;
	max.push_back(0);
	bool tie = false;
	for (int i = 0; i < (Faithful + Traitors); i++)
	{
		if (AllPlayers[i] == max[0])
		{
			max.push_back(AllPlayers[i]);
			index.push_back(i);
		}
		if (AllPlayers[i] > max[0])
		{
			max[0] = AllPlayers[i];
			index[0] = i;
		}
	}
	if (tie)
	{
		index[0] = rand() % index.size();
	}
	//Justification for dealing with a draw: Choosing the first person to appear
	if (index[0] + 1 >= Faithful) Traitors--;
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
			TheVote(Traitors, Faithful);
			Faithful--;
		}

		if (Traitors > 0) TraitorWins++;

	}
	
	cout << ((double)TraitorWins / (double)Simulations) * 100 << endl;
}