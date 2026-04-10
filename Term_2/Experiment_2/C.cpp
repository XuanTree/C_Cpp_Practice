#include <iostream>

class Score {
    private:
        std::string name;
        double *s;
        double total;
        char grade = 'B';
    public:
        void Input();
        void Evalauate();
        void Output() const;
};

void Score::Input() {
    std::cin >> this->name;

    double *scores = new double[4];
    this->s = new double[4];

    for (int i = 0; i < 4; i++) {
        std::cin >> scores[i];
    }
    for (int i = 0; i < 4; i++) {
        this->s[i] = scores[i];
    }
    
    delete[] scores;
}

void Score::Evalauate() {
    this->total = 0.0;
    this->total += (this->s[0] + this->s[1]) * 0.25 + this->s[2] * 0.25 + this->s[3] * 0.5;

    if (this->total >= 90) {
        this->grade = 'A';
    } else if (this->total >= 80) {
        this->grade = 'B';
    } else if (this->total >= 70) {
        this->grade = 'C';
    } else if (this->total >= 60) {
        this->grade = 'D';
    } else {
        this->grade = 'E';
    }
}

void Score::Output() const {
    bool isValid = true;
    if (this->s[0] > 50 || this->s[1] > 50 || 
        this->s[2] > 100 || this->s[3] > 100 ||
        this->s[0] < 0 || this->s[1] < 0 || 
        this->s[2] < 0 || this->s[3] < 0) {
        std::cout << "error" << std::endl;
        isValid = false;
    }
    if (isValid) {
        std::cout << "name: " << this->name << ", " << "total: " << this->total << 
            ", " << "grade: " << this->grade << std::endl;
    }
}

int main() {
    Score *s1=new Score;
    s1->Input();
    s1->Evalauate();
    s1->Output();
    return 0;
}