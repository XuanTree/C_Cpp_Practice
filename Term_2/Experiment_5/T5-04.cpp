#include <iostream>

//! 提交时请额外包含下面的这个头文件
#include <cmath>

template <class T>
class Vector {
private:
    T x, y, z;
public:
    Vector() = default;
    Vector(T x, T y, T z);
    Vector(const Vector<T> &v);
    Vector<T> &operator=(const Vector<T> &v) = default;

    friend Vector operator*(T d, const Vector &v) {
        return Vector(d * v.x, d * v.y, d * v.z);
    }

    friend Vector operator+(const Vector &v1, const Vector &v2) {
        return Vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector &v) {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }

    friend std::istream &operator>>(std::istream &is, Vector &v) {
        is >> v.x >> v.y >> v.z;
        return is;
    }

    bool operator==(const Vector &v) const;
};

template <class T>
Vector<T>::Vector(T x, T y, T z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

template <class T>
Vector<T>::Vector(const Vector<T> &v) {
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
}

template <class T>
bool Vector<T>::operator==(const Vector &v) const {
    const T eps = static_cast<T>(1e-10);
    return (std::abs(this->x - v.x) < eps &&
            std::abs(this->y - v.y) < eps &&
            std::abs(this->z - v.z) < eps);
}

//! 不用提交main函数
int main() {
    double a, b, c;
    std::cin >> a >> b >> c;
    Vector<double> v1(a, b, c), v2(v1), v3, v4;
    double d;
    std::cin >> d;
    v4 = d * v1 + v2;

    std::cout << v4 <<std::endl;

    Vector<double>  v;
    std::cin >> v;

    int flag = (v4 == v);
    std::cout << flag << std::endl; 

    return 0;
}
