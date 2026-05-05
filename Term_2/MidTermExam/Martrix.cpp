#include <iostream>

/* 
    设计矩阵类，用运算符重载实现矩阵的加、减、乘运算
*/

template <class T>
class Martrix {
public:
    int row;
    int col;
    T* data;
    Martrix(int row, int col) {
        this->row = row;
        this->col = col;
        this->data = new T[row * col];
    }
    Martrix(const Martrix& a) {
        this->row = a.row;
        this->col = a.col;
        this->data = new T[row * col];
        for (int i = 0; i < row * col; i++) {
            this->data[i] = a.data[i];
        }
    }
    ~Martrix() {
        delete[] data;
    }
    void initMartrix(); // 初始化矩阵
    void printMartrix(); // 打印矩阵
    template<class U>
    friend Martrix<U> operator+(const Martrix& a, const Martrix& b);
    template<class U>
    friend Martrix<U> operator-(const Martrix& a, const Martrix& b);
    template<class U>
    friend Martrix<U> operator*(const Martrix& a, const Martrix& b);
};

template <class T>
void Martrix<T>::initMartrix() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cin >> data[i * col + j];
        }
    }
}

template <class T>
void Martrix<T>::printMartrix() {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            std::cout << data[i * col + j] << " ";
        }
        std::cout << std::endl;
    }
}

template <class T>
Martrix<T> operator+(const Martrix<T>& a, const Martrix<T>& b) {
    Martrix<T> c(a);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            c.data[i * c.col + j] = a.data[i * a.col + j] + b.data[i * b.col + j];
        }
    }
    return c;
}

template <class T>
Martrix<T> operator-(const Martrix<T>& a, const Martrix<T>& b) {
    Martrix<T> c(a);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < a.col; j++) {
            c.data[i * c.col + j] = a.data[i * a.col + j] - b.data[i * b.col + j];
        }
    }
    return c;
}

template <class T>
Martrix<T> operator*(const Martrix<T>& a, const Martrix<T>& b) {
    Martrix<T> c(a.row, b.col);
    for (int i = 0; i < a.row; i++) {
        for (int j = 0; j < b.col; j++) {
            for (int k = 0; k < a.col; k++) {
                c.data[i * c.col + j] += a.data[i * a.col + k] * b.data[k * b.col + j];
            }
        }
    }
    return c;
}

template class Martrix<int>;
template class Martrix<double>;
template class Martrix<float>;

int main () {
    Martrix<int> m1(3, 3);
    m1.initMartrix();

    Martrix<int> m2(3, 3);
    m2.initMartrix();

    std::cout << "Martrix addition:" << std::endl;
    Martrix<int> m3 = m1 + m2;
    m3.printMartrix();

    std::cout << "Martrix subtraction:" << std::endl;
    Martrix<int> m4 = m1 - m2;
    m4.printMartrix();

    std::cout << "Martrix multiplication:" << std::endl;
    Martrix<int> m5 = m1 * m2;
    m5.printMartrix();

    return 0;
}