#include "Trapecy.h"
//Пусть точки ромба задаются по часовой стрелке.
Trapecy::Trapecy(const std::pair<double, double>& v1, const std::pair<double, double>& v2,
    const std::pair<double, double>& v3, const std::pair<double, double>& v4){
        points[0] = v1;
        points[1] = v2;
        points[2] = v3;
        points[3] = v4;
}

std::pair<double, double> Trapecy::Center_of_figure() const{
    double x = 0, y = 0;
    for (int i = 0; i < 4; ++i){
        x += points[i].first;
        y += points[i].second;

    }
    return {x / 4, y / 4};
}

Trapecy::operator double() const {
    double a = std::sqrt(std::pow(points[0].first - points[3].first, 2) +
                         std::pow(points[0].second - points[3].second, 2));
    double b = std::sqrt(std::pow(points[1].first - points[2].first, 2) +
                         std::pow(points[1].second - points[2].second, 2));

    double h = std::abs(points[0].second - points[2].second);
    return (a + b) / 2.0 * h;
}

Figure& Trapecy::operator=(const Figure& other) {
    const Trapecy* p = dynamic_cast<const Trapecy*>(&other);
    if (p){
        for (int i = 0; i < 4; ++i){
            points[i] = p -> points[i];
        }
    } else {
        throw std::invalid_argument("Рыбы к рыбам, а ромбы к ромбам");
    }
    return *this;
}

void Trapecy::read(std::istream& is) {
    for (int i = 0; i < 4; ++i){
        is  >> points[i].first >> points[i].second;
    }
}

Trapecy::Trapecy(const Trapecy& other) {
    std::copy(std::begin(other.points), std::end(other.points), std::begin(points));
}

// Конструктор перемещения
Trapecy::Trapecy(Trapecy&& other) noexcept {
    std::move(std::begin(other.points), std::end(other.points), std::begin(points));
}

// Оператор копирующего присваивания
Trapecy& Trapecy::operator=(const Trapecy& other) {
    if (this != &other) {
        std::copy(std::begin(other.points), std::end(other.points), std::begin(points));
    }
    return *this;
}

// Оператор перемещающего присваивания
Trapecy& Trapecy::operator=(Trapecy&& other) noexcept {
    if (this != &other) {
        std::move(std::begin(other.points), std::end(other.points), std::begin(points));
    }
    return *this;
}

void Trapecy::print(std::ostream& os) const{
    for (int i = 0; i < 4; ++i){
        os << points[i].first << points[i].second << " | ";
    }
}

bool Trapecy::operator==(const Figure &other) const{
    const Trapecy* p = dynamic_cast<const Trapecy*>(&other);
    if (p){
        for (int i = 0; i < 4; ++i){
            if (points[i] == p -> points[i]){
                continue;
            }else{
                return false;
            }
        }
    }
    return true;
}