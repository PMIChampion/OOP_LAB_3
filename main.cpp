#include <iostream>
#include <vector>
#include "Rhomb.h"
#include "Trapecy.h"
#include "Pentagon.h"

int main() {
    // Создание объекта ромба
    Rhomb* my_rhomb = new Rhomb({0, 0}, {0, 0}, {0, 0}, {0, 0});
    std::cout << "Введите координаты 4 вершин ромба по часовой стрелке : x1 y1 x2 y2 x3 y3 x4 y4)" << std::endl;
    std::cin >> *my_rhomb;  

    // Вывод информации о ромбе
    std::cout << "Ромб:\n" << *my_rhomb << std::endl;
    std::cout << "Площадь ромба: " << double(*my_rhomb) << std::endl;
//==================================================================================================================
    // Создание обьекта трапеции
    Trapecy* my_trapecy = new Trapecy({0, 0}, {0, 0}, {0, 0}, {0, 0});
    std::cout << "Введите координаты 4 вершин трапеции по часовой стрелке : x1 y1 x2 y2 x3 y3 x4 y4)" << std::endl;
    std::cin >> *my_trapecy;  

    // Вывод информации о трапеции
    std::cout << "Трапеция:\n" << *my_trapecy << std::endl;
    std::cout << "Площадь трапеции: " << double(*my_trapecy) << std::endl;
//==================================================================================================================
    // Создание обьекта пятиугольник
    Pentagon* my_pentagon = new Pentagon({0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0});
    std::cout << "Введите координаты 5 вершин пятиугольника по часовой стрелке : x1 y1 x2 y2 x3 y3 x4 y4)" << std::endl;
    std::cin >> *my_pentagon;  

    // Вывод информации о пятиугольнике
    std::cout << "Пятиугольник:\n" << *my_pentagon << std::endl;
    std::cout << "Площадь пятиугольника: " << double(*my_pentagon) << std::endl;
//==================================================================================================================
//==================================================================================================================
//==================================================================================================================

    // Теперь продемонстрируем полиморфизм.
    std::cout << "Теперь все помещается в массив и вызывается снова:" << std::endl;
    std::vector<Figure*> figures;
    figures.push_back(my_pentagon);
    figures.push_back(my_trapecy);
    figures.push_back(my_rhomb);

    for (const auto& figure : figures) {
        std::cout << *figure << std::endl;
        
        std::cout << "Площадь: " << double(*figure) << std::endl;
        
        auto center = figure->Center_of_figure();
        std::cout << "Геометрический центр: (" << center.first << ", " << center.second << ")" << std::endl;
    }

    return 0;
}

