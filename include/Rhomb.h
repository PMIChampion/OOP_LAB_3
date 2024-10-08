#pragma once
#include "Figure.h"
#include <cmath>

class Rhomb: public Figure
{
private:
    std::pair<double, double> points[4];
public:
    Rhomb(const std::pair<double, double>& v1, const std::pair<double, double>& v2,
    const std::pair<double, double>& v3, const std::pair<double, double>& v4);

    std::pair<double, double> Center_of_figure() const override;
    operator double() const override;
    Figure& operator=(const Figure& other) override;
    bool operator==(const Figure& other) const override;
    Rhomb(const Rhomb& other);
    Rhomb(Rhomb&& other) noexcept;
    Rhomb& operator=(const Rhomb& other);
    Rhomb& operator=(Rhomb&& other) noexcept;
protected:

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};