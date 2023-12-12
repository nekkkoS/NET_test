#include <iostream>
#include <cmath>

struct Point {
    int x;
    int y;
};

// Считаем расстояние от А до B
int calculateDistance(const Point& A, const Point& B) {
    int dx = B.x - A.x;
    int dy = B.y - A.y;
    return std::sqrt(dx * dx + dy * dy);
}

// Вычисляем косинус получевшегося прямоугольника
double calculateCos(const Point& A, const Point& B) {
    int dx = B.x - A.x;
    int distance = calculateDistance(A, B);
    return static_cast<double>(dx) / distance;
}

void calculatePositions(const Point& A, const Point& B, int acceleration, int limit, int initialSpeed) {
    int distance = calculateDistance(A, B);
    int position = 0;
    double cosA = calculateCos(A, B);

    std::cout << "{ " << A.x << "; " << A.y << " }\n";

    // Определяем расстояние, за которое достигается максимальная скорость
    int maxSpeedDistance = (limit - initialSpeed) / acceleration;

    for (int time = 1; position < distance; ++time) {
        if (position + maxSpeedDistance >= distance) {
            initialSpeed -= acceleration;
        } else {
            initialSpeed += acceleration;
            if (initialSpeed > limit) {
                initialSpeed = limit;
            }
        }

        position += initialSpeed;

        int dx = position * cosA;
        int dy = std::sqrt(position * position - dx * dx);

        int x = A.x + ((B.x > A.x) ? dx : -dx);
        int y = A.y + ((B.y > A.y) ? dy : -dy);

        // Добавим проверку для точки B левее и ниже точки A
        if ((B.x < A.x && B.y > A.y) || (B.x < A.x && B.y < A.y)) {
            x = A.x - std::abs(dx);
        }

        std::cout << "{ " << x << "; " << y << " }\n";
    }
}

int main() {
    // Тест
    Point A = {-10,15};
    Point B = {23,41};
    int acceleration = 1;
    int limit = 5;
    int initialSpeed = 0;

    std::cout << "Test:\n";
    calculatePositions(A, B, acceleration, limit, initialSpeed);

    // Пример 1
    Point A1 = {-10, 10};
    Point B1 = {10, -10};
    int acceleration1 = 1;
    int limit1 = 5;
    int initialSpeed1 = 0;

    std::cout << std::endl << "Example 1:\n";
    calculatePositions(A1, B1, acceleration1, limit1, initialSpeed1);

    // Пример 2
    Point A2 = {-10, -10};
    Point B2 = {10, 10};
    int acceleration2 = 1;
    int limit2 = 5;
    int initialSpeed2 = 0;

    std::cout << "\nExample 2:\n";
    calculatePositions(A2, B2, acceleration2, limit2, initialSpeed2);

    // Пример 3
    Point A3 = {10, 10};
    Point B3 = {-10, -10};
    int acceleration3 = 1;
    int limit3 = 5;
    int initialSpeed3 = 0;

    std::cout << "\nExample 3:\n";
    calculatePositions(A3, B3, acceleration3, limit3, initialSpeed3);

    // Пример 4
    Point A4 = {10, -10};
    Point B4 = {-10, 10};
    int acceleration4 = 1;
    int limit4 = 5;
    int initialSpeed4 = 0;

    std::cout << "\nExample 4:\n";
    calculatePositions(A4, B4, acceleration4, limit4, initialSpeed4);

    return 0;
}
