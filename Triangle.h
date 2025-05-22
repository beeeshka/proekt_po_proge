#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Figura.h"
#include <stdexcept>
#include <cmath>
#include <vector>

template<typename T>
class Triangle : public Figura<T> {
public:
    Triangle(T a, T b, T c) {
        setSides(a, b, c);
        calculateAngles();
    }

    void setSide(int index, T value) override {
        if (index < 0 || index > 2)
            throw std::out_of_range("Недопустимый индекс стороны (должен быть от 0 до 2)");

        std::vector<T> temp = this->sides;
        temp[index] = value;

        if (!isValidTriangle(temp[0], temp[1], temp[2]))
            throw std::invalid_argument("Стороны не образуют допустимый треугольник");

        this->sides = temp;
        calculateAngles();
    }

    void setAngle(int index, T value) override {
        throw std::logic_error("Углы рассчитываются автоматически и не могут быть заданы вручную.");
    }

    T perimeter() const override {
        return this->sides[0] + this->sides[1] + this->sides[2];
    }

    bool isEqualSides() const override {
        return std::abs(this->sides[0] - this->sides[1]) < 1e-6 &&
               std::abs(this->sides[1] - this->sides[2]) < 1e-6;
    }

    T area() const {
        T s = perimeter() / 2;
        return std::sqrt(s * (s - this->sides[0]) * (s - this->sides[1]) * (s - this->sides[2]));
    }

private:
    void setSides(T a, T b, T c) {
        if (!isValidTriangle(a, b, c))
            throw std::invalid_argument("Стороны не образуют допустимый треугольник");

        this->sides = {a, b, c};
    }

    void calculateAngles() {
        T a = this->sides[0];
        T b = this->sides[1];
        T c = this->sides[2];

        T A = toDegrees(std::acos((b*b + c*c - a*a) / (2 * b * c)));
        T B = toDegrees(std::acos((a*a + c*c - b*b) / (2 * a * c)));
        T C = toDegrees(std::acos((a*a + b*b - c*c) / (2 * a * b)));

        T sum = A + B + C;
        if (std::abs(sum - 180) > 1e-4)
            throw std::runtime_error("Ошибка вычисления углов: сумма не равна 180");

        this->angles = {A, B, C};
    }

    bool isValidTriangle(T a, T b, T c) const {
        return (a + b > c) && (a + c > b) && (b + c > a);
    }

    T toDegrees(T radians) const {
        return radians * 180.0 / M_PI;
    }
};

#endif

