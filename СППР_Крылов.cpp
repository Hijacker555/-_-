#include <iostream>
#include <string>
#include <array>
#include <vector>

using namespace std;

void print_arr(int* array, int dim1, int dim2) {
	for (int i = 0; i < dim1; i++) {
		for (int j = 0; j < dim2; j++)
			std::cout << ' ' << array[i * dim2 + j];
		std::cout << '\n' << std::endl;
	}
	std::cout << '\n' << std::endl;
}

int main()
{
	string Brand[8] = { "Jeep", "BMW", "MB", "VW", "LC200", "LC150", "Q7", "Q5" };
	string Specifications[6] = { "Cost", "Power", "V_engine", "Acceleration", "Fuel consumption", "Tax" };
	double matrix[6][8] = { -50000, -80000, -70000,-60000, -70000, -45000, -80000, -50000,
					243, 249, 245, 249, 249, 177, 249, 249,
					3.0, 3.0, 2.0, 3.0, 4.5, 2.8, 3.0, 2.0,
					-8.2, -6.5, -6.5, -6.8, -8.9, -12.7, -6.9, -6.3,
					-7.5, -6.8, -5.9, -7.1, -10.2, -7.4, -8.0, -6.8,
					-18225, -18675, -18375, -18675, -18675, -8850, -18675, -18675 };

	//Составление БО
	int tmp[8];
	int arr_tmp[8][8];
	int arr_bo[6][8][8];
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 8; i++) {
			for (int k = 0; k < 8; k++) {
				if (matrix[j][i] >= matrix[j][k]) {
					arr_tmp[i][k] = 1;
				}
				else {
					arr_tmp[i][k] = 0;
				}
				arr_bo[j][i][k] = arr_tmp[i][k];
			}
		}
		cout << "Specifications: " << Specifications[j] << endl;;
		print_arr((int*)arr_tmp, 8, 8);
	}

	//Механизм доминирования
	vector<string> score;
	cout << "The mechanism of dominance" << endl;
	for (int i = 0; i < 6; i++) {
		cout << Specifications[i] << endl;
		for (int j = 0; j < 8; j++) {
			int sum = 0;
			for (int k = 0; k < 8; k++) {
				sum = sum + arr_bo[i][j][k];
			}
			if (sum == 8) {
				score.push_back(Brand[j]);
				cout << Brand[j] << endl;
			}
		}
		cout << endl;
	}
	cout << "Result: " << endl;
	for (int j = 0; j < 8; j++) {
		int k = 0;
		for (int i = 0; i < score.size(); i++) {
			if (Brand[j] == score[i]) {
				k++;
			}
		}
		cout << Brand[j] << " - " << k << "     ";
	}
	cout << endl<<endl;

	cout << "Locking mechanism" << endl;
	vector<string> score_lock;
	for (int i = 0; i < 6; i++) {
		cout << Specifications[i] << endl;
		for (int k = 0; k < 8; k++) {
			int sum = 0;
			for (int j = 0; j < 8; j++) {
				sum = sum + arr_bo[i][j][k];
			}
			if (sum == 1) {
				score_lock.push_back(Brand[k]);
				cout << Brand[k] << endl;
			}
		}
		cout << endl;
	}
	cout << "Result: " << endl;
	for (int j = 0; j < 8; j++) {
		int k = 0;
		for (int i = 0; i < score_lock.size(); i++) {

			if (Brand[j] == score_lock[i]) {
				k++;
			}
		}
		cout << Brand[j] << " - " << k << "     ";
	}
	cout << endl;
	
}
