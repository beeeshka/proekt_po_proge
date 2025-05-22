#include <iostream>
#include "Triangle.h"
#include "Quadrilateral.h"
using namespace std;
void clearCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
int main() {
    setlocale(LC_ALL, "Rus");
    Figura<double>* shape = nullptr;
    int choice;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1. Создать треугольник\n";
        cout << "2. Создать четырехугольник\n";
        cout << "3. Показать фигуру\n";
        cout << "4. Изменить сторону\n";
        cout << "5. Изменить угол\n";
        cout << "6. Периметр\n";
        cout << "7. Площадь (только для треугольника)\n";
        cout << "8. Равны ли стороны?\n";
        cout << "9. Равны ли углы?\n";
        cout << "10. Является ли прямоугольником?\n";
        cout << "11. Создать произвольную фигуру (n сторон и углов)\n";
        cout << "0. Выход\nВыбор: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "Ошибка: ввод должен быть числом.\n";
            clearCin();
            continue;
        }
        try {
            switch (choice) {
                case 1: {
                    double a, b, c;
                    cout << "Введите стороны треугольника (3): ";
                    cin >> a >> b >> c;
                    if (cin.fail()) {
                        cout << "Ошибка ввода сторон.\n";
                        clearCin();
                        break;
                    }

                    if (a + b <= c || a + c <= b || b + c <= a) {
                        cout << "Ошибка: такие стороны не образуют треугольник.\n";
                        break;
                    }

    delete shape;
    shape = new Triangle<double>(a, b, c);
    break;
}

                case 2: {
                    double a, b, c, d, A, B, C, D;
                    cout << "Введите стороны (4): ";
                    cin >> a >> b >> c >> d;
                    if (cin.fail()) { cout << "Ошибка ввода сторон.\n"; clearCin(); break; }

                    cout << "Введите углы (4): ";
                    cin >> A >> B >> C >> D;
                    if (cin.fail()) { cout << "Ошибка ввода углов.\n"; clearCin(); break; }

                    delete shape;
                    shape = new Quadrilateral<double>(a, b, c, d, A, B, C, D);
                    break;
                }
                case 3:
                    if (shape) shape->show();
                    else cout << "Сначала создайте фигуру.\n";
                    break;
                case 4:
                    if (shape) {
                        int idx;
                        double val;
                        cout << "Введите индекс стороны (с 0) и новое значение: ";
                        cin >> idx >> val;
                        if (cin.fail()) {
                            cout << "Ошибка ввода.\n";
                            clearCin();
                            break;
                        }
                        shape->setSide(idx, val);
                    } else {
                        cout << "Сначала создайте фигуру.\n";
                    }   
                    break;
                case 5:
                    if (shape) {
                        int idx;
                        double val;
                        cout << "Введите индекс угла (с 0) и новое значение: ";
                        cin >> idx >> val;
                        if (cin.fail()) {
                            cout << "Ошибка ввода.\n";
                            clearCin();
                            break;
                        }
                        shape->setAngle(idx, val);
                    } else {
                        cout << "Сначала создайте фигуру.\n";
                    }
                    break;
                case 6:
                    if (shape) cout << "Периметр: " << shape->perimeter() << endl;
                    else cout << "Сначала создайте фигуру.\n";
                    break;
                case 7: {
                    auto* t = dynamic_cast<Triangle<double>*>(shape);
                    if (t) cout << "Площадь: " << t->area() << endl;
                    else cout << "Это не треугольник.\n";
                    break;
                }
                case 8:
                    if (shape) cout << (shape->isEqualSides() ? "Стороны равны.\n" : "Стороны не равны.\n");
                    else cout << "Сначала создайте фигуру.\n";
                    break;
                case 9:
                    if (shape) cout << (shape->isEqualAngles() ? "Углы равны.\n" : "Углы не равны.\n");
                    else cout << "Сначала создайте фигуру.\n";
                    break;
                case 10: {
                    auto* q = dynamic_cast<Quadrilateral<double>*>(shape);
                    if (q) cout << (q->isRectangle() ? "Это прямоугольник.\n" : "Это не прямоугольник.\n");
                    else cout << "Это не четырехугольник.\n";
                    break;
                }
                case 11: {
                    int n;
                    cout << "Введите количество сторон/углов фигуры: ";
                    cin >> n;
                    if (cin.fail() || n < 3) {
                        cout << "Ошибка ввода количества сторон (не менее 3).\n";
                        clearCin();
                        break;
                    }
                    if (n == 3){
                            double a, b, c;
                    cout << "Введите стороны треугольника (3): ";
                    cin >> a >> b >> c;
                    if (cin.fail()) {
                        cout << "Ошибка ввода сторон.\n";
                        clearCin();
                        break;
                    }

                    if (a + b <= c || a + c <= b || b + c <= a) {
                        cout << "Ошибка: такие стороны не образуют треугольник.\n";
                        break;
                    }

                        delete shape;
                        shape = new Triangle<double>(a, b, c);
                    }else if (n == 4) {
                        double a, b, c, d, A, B, C, D;
                        cout << "Введите 4 стороны: ";
                        cin >> a >> b >> c >> d;
                        if (cin.fail()) { cout << "Ошибка ввода сторон.\n"; clearCin(); break; }
                        cout << "Введите 4 угла: ";
                        cin >> A >> B >> C >> D;
                        if (cin.fail()) { cout << "Ошибка ввода углов.\n"; clearCin(); break; }

                        delete shape;
                        shape = new Quadrilateral<double>(a, b, c, d, A, B, C, D);
                    } else {
                        vector<double> s(n), a(n);
                        cout << "Введите " << n << " сторон: ";
                        for (int i = 0; i < n; ++i) {
                            cin >> s[i];
                            if (cin.fail()) {
                                cout << "Ошибка ввода стороны.\n";
                                clearCin();
                                break;
                            }
                        }
                        cout << "Введите " << n << " углов: ";
                        for (int i = 0; i < n; ++i) {
                            cin >> a[i];
                            if (cin.fail()) {
                                cout << "Ошибка ввода угла.\n";
                                clearCin();
                                break;
                            }
                        }
                        delete shape;
                        shape = new Figura<double>(s, a);
                    }
                    break;
                }
                case 0:
                    cout << "Выход.\n";
                    break;
                default:
                    cout << "Неверный выбор.\n";
            }
        }
        catch (const exception& ex) {
            cout << "Ошибка: " << ex.what() << endl;
        }
    } while (choice != 0);
    delete shape;
    return 0;
}