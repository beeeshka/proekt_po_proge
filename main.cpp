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
        cout << "\n--- ���� ---\n";
        cout << "1. ������� �����������\n";
        cout << "2. ������� ���������������\n";
        cout << "3. �������� ������\n";
        cout << "4. �������� �������\n";
        cout << "5. �������� ����\n";
        cout << "6. ��������\n";
        cout << "7. ������� (������ ��� ������������)\n";
        cout << "8. ����� �� �������?\n";
        cout << "9. ����� �� ����?\n";
        cout << "10. �������� �� ���������������?\n";
        cout << "11. ������� ������������ ������ (n ������ � �����)\n";
        cout << "0. �����\n�����: ";
        cin >> choice;
        if (cin.fail()) {
            cout << "������: ���� ������ ���� ������.\n";
            clearCin();
            continue;
        }
        try {
            switch (choice) {
                case 1: {
                    double a, b, c;
                    cout << "������� ������� ������������ (3): ";
                    cin >> a >> b >> c;
                    if (cin.fail()) {
                        cout << "������ ����� ������.\n";
                        clearCin();
                        break;
                    }

                    if (a + b <= c || a + c <= b || b + c <= a) {
                        cout << "������: ����� ������� �� �������� �����������.\n";
                        break;
                    }

    delete shape;
    shape = new Triangle<double>(a, b, c);
    break;
}

                case 2: {
                    double a, b, c, d, A, B, C, D;
                    cout << "������� ������� (4): ";
                    cin >> a >> b >> c >> d;
                    if (cin.fail()) { cout << "������ ����� ������.\n"; clearCin(); break; }

                    cout << "������� ���� (4): ";
                    cin >> A >> B >> C >> D;
                    if (cin.fail()) { cout << "������ ����� �����.\n"; clearCin(); break; }

                    delete shape;
                    shape = new Quadrilateral<double>(a, b, c, d, A, B, C, D);
                    break;
                }
                case 3:
                    if (shape) shape->show();
                    else cout << "������� �������� ������.\n";
                    break;
                case 4:
                    if (shape) {
                        int idx;
                        double val;
                        cout << "������� ������ ������� (� 0) � ����� ��������: ";
                        cin >> idx >> val;
                        if (cin.fail()) {
                            cout << "������ �����.\n";
                            clearCin();
                            break;
                        }
                        shape->setSide(idx, val);
                    } else {
                        cout << "������� �������� ������.\n";
                    }   
                    break;
                case 5:
                    if (shape) {
                        int idx;
                        double val;
                        cout << "������� ������ ���� (� 0) � ����� ��������: ";
                        cin >> idx >> val;
                        if (cin.fail()) {
                            cout << "������ �����.\n";
                            clearCin();
                            break;
                        }
                        shape->setAngle(idx, val);
                    } else {
                        cout << "������� �������� ������.\n";
                    }
                    break;
                case 6:
                    if (shape) cout << "��������: " << shape->perimeter() << endl;
                    else cout << "������� �������� ������.\n";
                    break;
                case 7: {
                    auto* t = dynamic_cast<Triangle<double>*>(shape);
                    if (t) cout << "�������: " << t->area() << endl;
                    else cout << "��� �� �����������.\n";
                    break;
                }
                case 8:
                    if (shape) cout << (shape->isEqualSides() ? "������� �����.\n" : "������� �� �����.\n");
                    else cout << "������� �������� ������.\n";
                    break;
                case 9:
                    if (shape) cout << (shape->isEqualAngles() ? "���� �����.\n" : "���� �� �����.\n");
                    else cout << "������� �������� ������.\n";
                    break;
                case 10: {
                    auto* q = dynamic_cast<Quadrilateral<double>*>(shape);
                    if (q) cout << (q->isRectangle() ? "��� �������������.\n" : "��� �� �������������.\n");
                    else cout << "��� �� ���������������.\n";
                    break;
                }
                case 11: {
                    int n;
                    cout << "������� ���������� ������/����� ������: ";
                    cin >> n;
                    if (cin.fail() || n < 3) {
                        cout << "������ ����� ���������� ������ (�� ����� 3).\n";
                        clearCin();
                        break;
                    }
                    if (n == 3){
                            double a, b, c;
                    cout << "������� ������� ������������ (3): ";
                    cin >> a >> b >> c;
                    if (cin.fail()) {
                        cout << "������ ����� ������.\n";
                        clearCin();
                        break;
                    }

                    if (a + b <= c || a + c <= b || b + c <= a) {
                        cout << "������: ����� ������� �� �������� �����������.\n";
                        break;
                    }

                        delete shape;
                        shape = new Triangle<double>(a, b, c);
                    }else if (n == 4) {
                        double a, b, c, d, A, B, C, D;
                        cout << "������� 4 �������: ";
                        cin >> a >> b >> c >> d;
                        if (cin.fail()) { cout << "������ ����� ������.\n"; clearCin(); break; }
                        cout << "������� 4 ����: ";
                        cin >> A >> B >> C >> D;
                        if (cin.fail()) { cout << "������ ����� �����.\n"; clearCin(); break; }

                        delete shape;
                        shape = new Quadrilateral<double>(a, b, c, d, A, B, C, D);
                    } else {
                        vector<double> s(n), a(n);
                        cout << "������� " << n << " ������: ";
                        for (int i = 0; i < n; ++i) {
                            cin >> s[i];
                            if (cin.fail()) {
                                cout << "������ ����� �������.\n";
                                clearCin();
                                break;
                            }
                        }
                        cout << "������� " << n << " �����: ";
                        for (int i = 0; i < n; ++i) {
                            cin >> a[i];
                            if (cin.fail()) {
                                cout << "������ ����� ����.\n";
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
                    cout << "�����.\n";
                    break;
                default:
                    cout << "�������� �����.\n";
            }
        }
        catch (const exception& ex) {
            cout << "������: " << ex.what() << endl;
        }
    } while (choice != 0);
    delete shape;
    return 0;
}