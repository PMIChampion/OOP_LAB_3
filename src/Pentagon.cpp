#include "Pentagon.h"

Pentagon::Pentagon(const std::pair<double, double>& v1, const std::pair<double, double>& v2,
    const std::pair<double, double>& v3, const std::pair<double, double>& v4,
    const std::pair<double, double>& v5){
        points[0] = v1;
        points[1] = v2;
        points[2] = v3;
        points[3] = v4;
        points[4] = v5;
}

Pentagon::Pentagon(const Pentagon& other) {
    std::copy(std::begin(other.points), std::end(other.points), std::begin(points));
}

// Конструктор перемещения
Pentagon::Pentagon(Pentagon&& other) noexcept {
    std::move(std::begin(other.points), std::end(other.points), std::begin(points));
}

// Оператор копирующего присваивания
Pentagon& Pentagon::operator=(const Pentagon& other) {
    if (this != &other) {
        std::copy(std::begin(other.points), std::end(other.points), std::begin(points));
    }
    return *this;
}

// Оператор перемещающего присваивания
Pentagon& Pentagon::operator=(Pentagon&& other) noexcept {
    if (this != &other) {
        std::move(std::begin(other.points), std::end(other.points), std::begin(points));
    }
    return *this;
}
std::pair<double, double> Pentagon::Center_of_figure() const{
    double x = 0, y = 0;
    for (int i = 0; i < 5; ++i){
        x += points[i].first;
        y += points[i].second;

    }
    return {x / 5, y / 5};
}

Pentagon::operator double() const {
    double side = std::sqrt(std::pow(points[0].first - points[1].first, 2) +
                            std::pow(points[0].second - points[1].second, 2));
    return (5.0 / 4.0) * side * side * (1.0 / std::tan(M_PI / 5));
}

Figure& Pentagon::operator=(const Figure& other) {
    const Pentagon* p = dynamic_cast<const Pentagon*>(&other);
    if (p){
        for (int i = 0; i < 5; ++i){
            points[i] = p -> points[i];
        }
    } else {
        throw std::invalid_argument("Рыбы к рыбам, а пентагоны к пентагонам");
    }
    return *this;
}

void Pentagon::read(std::istream& is) {
    for (int i = 0; i < 5; ++i){
        is  >> points[i].first >> points[i].second;
    }
}

void Pentagon::print(std::ostream& os) const{
    for (int i = 0; i < 5; ++i){
        os << points[i].first << points[i].second << " | ";
    }
}

bool Pentagon::operator==(const Figure &other) const{
    const Pentagon* p = dynamic_cast<const Pentagon*>(&other);
    if (p){
        for (int i = 0; i < 5; ++i){
            if (points[i] == p -> points[i]){
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
}


