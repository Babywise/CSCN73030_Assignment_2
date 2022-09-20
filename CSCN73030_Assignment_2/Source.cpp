#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

const int NAME_LENGTH = 256;

struct STUDENT_DATA {
	std::string firstname;
	std::string lastname;
};

int main(void) {

	std::vector<STUDENT_DATA> studentList;

	std::ifstream Fin("Files/StudentData.txt", std::ios::in);

	char currName[NAME_LENGTH] = {};

	while (Fin) {
		Fin.getline(currName, NAME_LENGTH);
		std::istringstream nameStream(currName);

		if (nameStream.str().size() > 0) {
			STUDENT_DATA currStudent;
			std::getline(nameStream, currStudent.lastname, ',');
			std::getline(nameStream, currStudent.firstname);
			studentList.push_back(currStudent);
		}
	}

	Fin.close();

	return 1;

}