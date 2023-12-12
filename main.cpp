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
            initialSpeed = std::min(initialSpeed, limit);
        }

        position += initialSpeed;

        int x = position * cosA;
        int y = std::sqrt(position * position - x * x);

        std::cout << "{ " << A.x + x << "; " << A.y + y << " }\n";
    }

}

int main() {
    Point A = {-10, 15};
    Point B = {23, 41};
    int acceleration = 1;
    int limit = 5;
    int initialSpeed = 0;

    calculatePositions(A, B, acceleration, limit, initialSpeed);

    return 0;
}
