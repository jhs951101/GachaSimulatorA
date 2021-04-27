#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

/*
	Made by: SharPing - Sharp Coder
	Date of Modification: 2020-10-24
*/

struct GaChaInfo {
	int rare;
	int probability;
};

int GaChaArray[100];

int randomNumber(int min, int max)
{
	return rand() % (max-min+1) + min;
}

void shakeGaChaArray()
{
	for (int n = 1; n <= 100; n++) {
		int a = randomNumber(0, 99);
		int b = randomNumber(0, 99);
		int swap;

		if(a != b){
			swap = GaChaArray[a];
			GaChaArray[a] = GaChaArray[b];
			GaChaArray[b] = swap;
		}
	}
}

void setGaCha(GaChaInfo* pros, int numOfPros)
{
	int index = 0;

	for (int i = 0; i < numOfPros; i++) {
		int rare = pros[i].rare;
		int probability = pros[i].probability;

		int j = 0;
		while (j < probability) {
			GaChaArray[index] = rare;
			j++;
			index++;
		}
	}

	shakeGaChaArray();
}

int* startGaCha(int num)
{
	int* result = new int[num];

	for (int n = 0; n < num; n++) {
		int random = randomNumber(0, 99);
		int rare = GaChaArray[random];

		result[n] = rare;

		cout << "Layer " << rare << " ";

		for (int a = 1; a <= rare; a++) {
			cout << "¡Ú";
		}

		cout << " Get!" << endl;
	}

	cout << endl;
	cout << "The GaCha Finished!" << endl << endl;

	return result;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << "Welcome to the GaCha Simulation!" << endl;

	while (true) {

		char start;
		cout << "Will you try? (y/n): ";
		cin >> start;
		cout << endl;

		if (start == 'n') {
			break;
		}
		else if(start == 'y') {
			GaChaInfo layerPros[5];
			
			while (true) {
				int sum = 0;

				for (int i = 0; i < 5; i++) {
					cout << "Input a probability about Layer " << i+1 << ": ";
					cin >> layerPros[i].probability;

					layerPros[i].rare = i + 1;
					sum += layerPros[i].probability;
				}

				if (sum == 100) {
					break;
				}
				else {
					cout << "Error: The sum of probabilities must be 100" << endl << endl;
				}
			}

			int tryNum;
			cout << endl << "Input a try number to start GaCha: ";
			cin >> tryNum;
			cout << endl;

			setGaCha(layerPros, 5);
			int* result = startGaCha(tryNum);

			delete[] result;
		}
		else {
			cout << "Error: Input the character y or n" << endl << endl;
		}
	}

	cout << "Good Bye~" << endl << endl;

	return 0;
}