#include <iostream>
#include <cmath>

class VectorN {
    private:
        int dim;
        double *values;
    public: 
        VectorN(int _dim, double *values);
        double Mag();
};

VectorN::VectorN(int _dim, double *_values) : dim(_dim) {
    this->dim = _dim;

    this->values = new double[dim];
    for (int i = 0; i < dim; i++) {
        this->values[i] = _values[i];
    }
}

double VectorN::Mag() {
    double total = 0.0;
    for (int i = 0; i < this->dim; i++) {
        total += std::pow(this->values[i],2);
    }
    return std::sqrt(total);
}

int main() {
    int num;
    std::cin >> num;

    double *dtemp = new double[num];

    for (int i = 0; i < num; i++) {
        std::cin >> dtemp[i];
    }
    VectorN vn2(num,dtemp);
    delete[] dtemp;
    std::cout << vn2.Mag() << std::endl;
    return 0;
}