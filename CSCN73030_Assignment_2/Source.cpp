#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#define PreRelease

const int NAME_LENGTH = 256;

struct STUDENT_DATA {
	std::string firstname;
	std::string lastname;
#ifdef PreRelease
	std::string email;
#endif //PreRelease
};


int main(void) {

#ifdef PreRelease
	std::cout << "You are currently running the 'PreRelease' version" << std::endl;
	std::ifstream Fin("Files/StudentData_Emails.txt", std::ios::in);
#else
	std::cout << "You are currently running the 'Standard' version" << std::endl;
	std::ifstream Fin("Files/StudentData.txt", std::ios::in);
#endif //PreRelease

	std::vector<STUDENT_DATA> studentList;

	char currName[NAME_LENGTH] = {};

	while (Fin) {
		Fin.getline(currName, NAME_LENGTH);
		std::istringstream nameStream(currName);

		if (nameStream.str().size() > 0) {

			STUDENT_DATA currStudent;

		#ifdef PreRelease
			std::getline(nameStream, currStudent.lastname, ',');
			std::getline(nameStream, currStudent.firstname, ',');
			std::getline(nameStream, currStudent.email);
			studentList.push_back(currStudent);

		#else
			std::getline(nameStream, currStudent.lastname, ',');
			std::getline(nameStream, currStudent.firstname);
			studentList.push_back(currStudent);

		#endif //PreRelease

		#ifdef _DEBUG
		#ifdef PreRelease
			std::cout << currStudent.lastname;
			std::cout << ", " << currStudent.firstname;
			std::cout << " - \t" << currStudent.email << std::endl;
		#else
			std::cout << currStudent.lastname;
			std::cout << ", " << currStudent.firstname << std::endl;
		#endif //PreRelease
		#endif //DEBUG

		}
	}

	Fin.close();

	return 1;

}