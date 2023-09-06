#include <iostream>
#include <string>
#include <Windows.h>
#include <locale.h>

class FIO {
public:
	std::string firstName;
	std::string secondName;
	std::string lastName;
	//public:

	FIO() {
		firstName = "first";
		secondName = "second";
		lastName = "last";
	}

	~FIO();//деструктор

	FIO(std::string _firstName, std::string _secondName, std::string _lastName) {
		firstName = _firstName;
		secondName = _secondName;
		lastName = _lastName;
	}
	FIO(FIO& fio) {
		firstName = fio.firstName;
		secondName = fio.secondName;
		lastName = fio.lastName;
	}
	FIO& operator=(const FIO& f) {
		if (this != &f) {
			this->firstName = f.firstName;
			this->secondName = f.secondName;
			this->lastName = f.lastName;
			return *this;
		}
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& out, const FIO& f);
	friend std::istream& operator>>(std::istream& in, FIO& f);

};
std::ostream& operator<<(std::ostream& out, const FIO& f) {
	out << "<" << f.firstName << f.secondName << f.lastName << ">";
	return out;
};
std::istream& operator>>(std::istream& in, FIO& f) {
	in >> f.firstName >> f.secondName >> f.lastName;
	return in;

};

//void Average_score(float avr_scr) {
//	std::cout << avr_scr;
//	//потом вызывать в мейне
//
//}
//void ID_student(int id[], const int size) {
//	for (int i = 0; i < size; i++) {
//		id[i] = rand() % 8;
//	}
// }
class Student {
public:
	FIO student_FIO;
	float avr_scr;
	int arr[8];
	int id_arr[8];
	bool platnoe;
	bool stepuha;

	//перегрузка фио- не получилась :( 

//public:
	//функци
	void Average_score(float avr_scr) {

		std::cin >> avr_scr;

		//потом вызывать в мейне

	}
	void Average_score_srav(Student a, Student b) {
		if (a.avr_scr > b.avr_scr) {
			std::cout << a.avr_scr;
		}
		else {
			std::cout << b.avr_scr;
		}

	}
	void ID_student(Student id) {
		for (int i = 0; i < 9; i++) {
			id.id_arr[i] = rand() % 8;
		}
	}
	void record_book(Student r) {
		for (int i = 0; i < 9; i++) {
			std::cin >> r.arr[i];
		}
	}
	void Set_platnoe(Student auf, bool p) {
		auf.platnoe = p;
	}
	void Set_stepuha(Student money, bool stud) {
		money.stepuha = stud;
	}
};
std::ostream& operator<<(std::ostream& out, Student& student) {
	out << "Фамилия Имя Отчество студента" << student.student_FIO;
	out << "Средний балл студента" << student.avr_scr;
	out << "Номер зачётной книжки студента";
	for (int i = 0; i < 9; i++) {
		std::cout << student.arr[i];
	}
	out << "На какой форме обучения находится студент";
	if (student.platnoe == 0) {
		std::cout << "Бюджет";
	}
	else
		std::cout << "Внебюджет";
	out << "Степуха";
	if (student.stepuha== 0) {
		std::cout << "троечник, без степухи";
	}
	else
		std::cout << "степедия ура";
	return out;

}
std::istream& operator>>(std::istream& in, Student& student) {
	std::cout << "Ввод Фамилии Имени Отчества студента";
	in >> student.student_FIO;
	std::cout << "Ввод среднего балла студента";
	in >> student.avr_scr;
	std::cout << "Ввод зачётной книжки студента";
	for (int i = 0; i < 9; i++) {
		std::cin>> student.arr[i];
	}

		
}
class Arhiv {

public:
	std::string secondName;
	Arhiv() {
		secondName = "second";
	}
	~Arhiv();
	Arhiv(std::string _secondName) {
		secondName = _secondName;
	}
	Arhiv(Arhiv& arhiv) {
		secondName = arhiv.secondName;
	}
	Student& Stud_id() {

	}
};

int main() {
	setlocale(LC_ALL, "russ");
	//создаём массив объектов класса для дальшнейшего сравнения и поиска учащихся
	std::cout << "Ввод количества учащихся";
	int n; 
	std::cin >> n;
	Student* array[n];
	for (int i = 0; i < n; i++) {
		array[i] = new Student();
	}
	Student a;
	std::cin >> a.student_FIO >> a.avr_scr >> a.id_arr >> a.platnoe >> a.stepuha;
	bool c = true;
	bool b = false;
	a.Set_platnoe(a, c);
	a.Set_stepuha(a, b);
	std::cout << "Фамилия Имя Отчество студента" << "Средний балл студента" << "Номер зачётной книжки студента" << "На какой форме обучения студент"
		<< "Есть ли степендия у студента";
}