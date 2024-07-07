#include <fstream>
#include <iostream>
#include <string>

using namespace std;
 
int main() {
	char data[15];
	int n = 0, option = 0, count_n = 0;
	string empty = "00";
	string proctor = "";

	ifstream f("Studets_name.txt");
	string line;
	for (int i = 0; getline(f, line); ++i) {

		count_n++;

	}
	while (option != 6) {
		cout << "\nAvailable operations:\n1. Add new students\n2. Student login\n3. Faculty Login\n4. Proctor Login\n5. Admin View\n6. Exit\nEnter option: ";
		cin >> option;

		if (option == 1) {
			cout << "Enter the number of students: ";
			cin >> n;
			count_n += n;

			for (int i = 0; i < n; i++) {
				ofstream outfile;
				outfile.open("Studets_name.txt", ios::app);

				cout << "Enter your registraion number: ";
				cin >> data; 
				outfile << data << "\t";

				cout << "Enter your name registration number: ";
				cin >> data;
				outfile << data << "\t";

				cout << "Enter your name: ";
				cin >> data;
				int len = strlen(data);
				while (len < 15) {
					data[len] = ' ';
					len++;
				}
				outfile << data << "\t";
				outfile << empty << "\t";
				outfile << empty << "\t";

				cout << "Enter your proctor ID: ";
				cin >> proctor;
				outfile << proctor << endl;
			}
		}
		else if (option == 2) {
			char regno[9];
			cout << "Enter your registration number: ";
			cin >> regno;

			ifstream infile;
			int check = 0;
			infile.open("Studets_name.txt", ios::in);

			while (infile >> data) {
				if (strcmp(data, regno) == 0) {
					cout << "\nRegistration Number: " << data << endl;
					infile >> data;
					cout << "Name: " << data << endl;
					infile >> data;
					cout << "CSE1001 mark: " << data << endl;
					infile >> data;
					cout << "CSE1002 mark: " << data << endl;
					infile >> data;
					cout << "Proctor ID: " << data << endl;
					infile.close();
					check = 1;
				}
			}
			if (check == 0) {
				cout << "No such registration number found!" << endl;
			}
			else if (option == 3) {
				char subcode[7];
				cout << "Enter your subject code: ";
				cin >> subcode;

				string code1 = "CSE1001", code2 = "CSE1002", mark = "";
				ifstream infile;
				int check = 0;

				cout << "\nAvailable operations:\n1.Add data about marks\n2. View data\nEnter option: ";
				cin >> option;
				if (option == 1) {
					cout << "Warning! You would need to add mark details for all the students!" << endl;
					for (int i = 0; i < count_n; i++) {
						fstream file("Studets_name.txt");
						if (strcmp(subcode, code1.c_str()) == 0) {
							file.seekp(26 + 37 * i, ios_base::beg);
							cout << "Enter the mark of student #" << (i + 1) << " : ";
							
							cin >> mark;
							file.write(mark.c_str(), 2);
						}
					}
				}
			}
		}
	}
	return 0;
}