#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>
using namespace std;

template<typename T>
class Figura {
protected:
    vector<T> sides;
    vector<T> angles;

public:
    Figura() {}

    Figura(const vector<T>& s, const vector<T>& a) : sides(s), angles(a) {
        if (!isValid()) {
            throw runtime_error("Ошибка: фигура не существует.");
        }
    }   

    virtual ~Figura() {}

    virtual void setSide(int index, T value) {
        if (index >= 0 && index < sides.size())
            sides[index] = value;
    }

    virtual void setAngle(int index, T value) {
        if (index >= 0 && index < angles.size())
            angles[index] = value;
    }

    T getSide(int index) const {
        return sides.at(index);
    }

    T getAngle(int index) const {
        return angles.at(index);
    }

    virtual T perimeter() const {
        T sum = 0;
        for (T s : sides)
            sum += s;
        return sum;
    }
    virtual void show() const {
        cout << "Стороны: ";
        for (T s : sides) cout << s << " ";
        cout << "\nУглы: ";
        for (T a : angles) cout << a << " ";
        cout << endl;
    }
    virtual bool isEqualSides() const {
        for (size_t i = 1; i < sides.size(); ++i)
            if (abs(sides[i] - sides[0]) > 1e-6)
                return false;
        return true;
    }
    virtual bool isEqualAngles() const {
        for (size_t i = 1; i < angles.size(); ++i)
            if (abs(angles[i] - angles[0]) > 1e-6)
                return false;
        return true;
    }

    virtual bool isValid() const {
        if (sides.size() != angles.size() || sides.empty()) return false;
        for (T s : sides) if (s <= 0) return false;
        for (T a : angles) if (a <= 0) return false;
        return true;
    }
};

#endif
