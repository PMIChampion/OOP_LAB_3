#include "Figure.h"

std::ostream& operator<<(std::ostream& os, const Figure& figure){
    figure.print(os);
    return os;
}
std::istream& operator>>(std::istream& is, Figure& figure){
    figure.read(is);
    return is;
}
Figure& Figure::operator=(const Figure& other){
    return *this;
}