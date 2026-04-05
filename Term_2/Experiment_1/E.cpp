#include <iostream>

class Subject {
    private:
        double score[3];
        const int SMath = 4, SEng = 2, SCpp = 2;
    public:
        Subject(double score_math = 0, double score_eng = 0, double score_cpp = 0);
        void Input();
        friend class Student;
};

Subject::Subject(double, double, double) {}

void Subject::Input() {
    for(int i = 0; i < 3; i++) {
        std::cin >> this->score[i];
    }
}

class Student {
    private: 
        std::string ID;
        std::string name;
        double GPA;
    public: 
        Student(std::string id = "00000", std::string na = "Noname");
        void CalculateGPA(const Subject& sub);
        void Input();
        void Show(const Subject& sub);
};

Student::Student(std::string _id, std::string _na) {
    this->ID = _id;
    this->name = _na;
}

void Student::CalculateGPA(const Subject& su) {
    double total = 0;
    for(int i = 0; i < 3; i++) {
        if(i == 0) {
            total += su.score[i] * 4;
        } else {
            total += su.score[i] * 2;
        }
    }
    this->GPA = total / (su.SMath + su.SEng + su.SCpp);
}

void Student::Input() {
    std::cin >> this->ID;
    std::cin >> this->name;
}

void Student::Show(const Subject& su) {
    std::cout << "ID: " << this->ID << ", " << "Name: " << this->name
        << std::endl << "Math " << "Eng " << "Cpp" << std::endl
        << su.score[0] << " " << su.score[1] << " " << su.score[2] << " "
        << std::endl << "GPA: " << this->GPA << std::endl;
}

int main() {
    int n;        //学生人数
    std::cin >> n;
    Student *stu = new Student[n];
    Subject *sub = new Subject[n];
    
    for (int i = 0; i < n; i++){
        stu[i].Input();
        sub[i].Input();
    }
    for (int i = 0; i < n; i++){
        stu[i].CalculateGPA(sub[i]);
        stu[i].Show(sub[i]);
    }
    
    delete[] stu;
    delete[] sub;
    return 0;
}