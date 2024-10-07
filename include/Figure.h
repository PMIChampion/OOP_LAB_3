// Вычисление геом центра
// Перегрузим std::ostream для вывода координат вершин
// Чтение фигур из стандартных потоко
// Double - вычисление площади

#pragma once
#include <iostream>
#include <string>
#include <utility>

class Figure
{
public:
    virtual std::pair<double, double> Center_of_figure() const = 0;
    virtual operator double() const = 0;
    virtual Figure& operator=(const Figure& other);
    virtual bool operator==(const Figure& other) const = 0;
    virtual ~Figure() {}

    friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
    friend std::istream& operator>>(std::istream& is, Figure& figure);
protected:
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0; 
};