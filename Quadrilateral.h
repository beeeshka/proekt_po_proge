#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include "Figura.h"
#include <vector>
#include <cmath>
#include <stdexcept>

template<typename T>
class Quadrilateral : public Figura<T> {
public:
    Quadrilateral(T a, T b, T c, T d, T A, T B, T C, T D) {
        setAngles(A, B, C, D);

        bool allRightAngles = (std::abs(A - 90) < 1e-6) &&
                              (std::abs(B - 90) < 1e-6) &&
                              (std::abs(C - 90) < 1e-6) &&
                              (std::abs(D - 90) < 1e-6);
        if (allRightAngles) {
            bool case1 = (std::abs(a - c) < 1e-6) && (std::abs(b - d) < 1e-6);
            bool case2 = (std::abs(a - b) < 1e-6) && (std::abs(c - d) < 1e-6);
            bool case3 = (std::abs(a - d) < 1e-6) && (std::abs(b - c) < 1e-6);

            if (!(case1 || case2 || case3)) {
                throw std::invalid_argument("Прямоугольник должен иметь противоположные стороны попарно равными");
            }
        }

        setSides(a, b, c, d);
    }

    void setSide(int index, T value) {
        if (index < 0 || index >= 4) {
            throw std::out_of_range("Недопустимый индекс стороны (должен быть от 0 до 3)");
        }

        std::vector<T> temp = this->sides;
        temp[index] = value;

        if ((temp[0] + temp[1] + temp[2] <= temp[3]) ||
            (temp[0] + temp[1] + temp[3] <= temp[2]) ||
            (temp[0] + temp[2] + temp[3] <= temp[1]) ||
            (temp[1] + temp[2] + temp[3] <= temp[0])) {
            throw std::invalid_argument("Стороны не образуют допустимый четырёхугольник");
        }

        this->sides = temp;
    }

    void setAngle(int index, T value) {
        if (index < 0 || index >= 4) {
            throw std::out_of_range("Недопустимый индекс угла (должен быть от 0 до 3)");
        }

        std::vector<T> temp = this->angles;
        temp[index] = value;

        T sum = temp[0] + temp[1] + temp[2] + temp[3];
        if (std::abs(sum - 360) > 1e-6) {
            throw std::invalid_argument("Сумма углов четырёхугольника должна быть равна 360 градусам");
        }

        this->angles = temp;
    }

    T perimeter() const override {
        T sum = 0;
        for (T s : this->sides)
            sum += s;
        return sum;
    }

    bool isEqualSides() const override {
        return (std::abs(this->sides[0] - this->sides[1]) < 1e-6) &&
               (std::abs(this->sides[1] - this->sides[2]) < 1e-6) &&
               (std::abs(this->sides[2] - this->sides[3]) < 1e-6);
    }

    bool isRectangle() const {
        for (T angle : this->angles) {
            if (std::abs(angle - 90) > 1e-6)
                return false;
        }

        T a = this->sides[0];
        T b = this->sides[1];
        T c = this->sides[2];
        T d = this->sides[3];

        bool case1 = (std::abs(a - c) < 1e-6) && (std::abs(b - d) < 1e-6);
        bool case2 = (std::abs(a - b) < 1e-6) && (std::abs(c - d) < 1e-6);
        bool case3 = (std::abs(a - d) < 1e-6) && (std::abs(b - c) < 1e-6);

        return case1 || case2 || case3;
    }

private:
    void setSides(T a, T b, T c, T d) {
        if ((a + b + c <= d) ||
            (a + b + d <= c) ||
            (a + c + d <= b) ||
            (b + c + d <= a)) {
            throw std::invalid_argument("Стороны не образуют допустимый четырёхугольник");
        }

        this->sides = {a, b, c, d};
    }

    void setAngles(T A, T B, T C, T D) {
        T sum = A + B + C + D;
        if (std::abs(sum - 360) > 1e-6)
            throw std::invalid_argument("Сумма углов четырёхугольника должна быть равна 360 градусам");

        this->angles = {A, B, C, D};
    }
};

#endif
