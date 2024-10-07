#include "Rhomb.h"
//Пусть точки ромба задаются по часовой стрелке.
Rhomb::Rhomb(const std::pair<double, double>& v1, const std::pair<double, double>& v2,
    const std::pair<double, double>& v3, const std::pair<double, double>& v4){
        points[0] = v1;
        points[1] = v2;
        points[2] = v3;
        points[3] = v4;
}

std::pair<double, double> Rhomb::Center_of_figure() const{
    double x = 0, y = 0;
    for (int i = 0; i < 4; ++i){
        x += points[i].first;
        y += points[i].second;

    }
    return {x / 4, y / 4};
}

Rhomb::operator double() const {
    double d1 = std::sqrt(std::pow(points[0].first - points[2].first, 2) +
                          std::pow(points[0].second - points[2].second, 2));
    double d2 = std::sqrt(std::pow(points[1].first - points[3].first, 2) +
                          std::pow(points[1].second - points[3].second, 2));
    
    return (d1 * d2) / 2.0;
}

Figure& Rhomb::operator=(const Figure& other) {
    const Rhomb* p = dynamic_cast<const Rhomb*>(&other);
    if (p){
        for (int i = 0; i < 4; ++i){
            points[i] = p -> points[i];
        }
    } else {
        throw std::invalid_argument("Рыбы к рыбам, а ромбы к ромбам");
    }
    return *this;
}

void Rhomb::read(std::istream& is) {
    for (int i = 0; i < 4; ++i){
        is  >> points[i].first >> points[i].second;
    }
}

void Rhomb::print(std::ostream& os) const{
    for (int i = 0; i < 4; ++i){
        os << points[i].first << points[i].second << " | ";
    }
}

bool Rhomb::operator==(const Figure &other) const{
    const Rhomb* p = dynamic_cast<const Rhomb*>(&other);
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