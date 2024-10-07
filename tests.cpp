#include <gtest/gtest.h>
#include "Rhomb.h"
#include "Pentagon.h"
#include "Trapecy.h"

TEST(RhombTests, CenterOfFigure) {
    Rhomb rhomb({0, 4}, {4, 0}, {0, -4}, {-4, 0});
    auto center = rhomb.Center_of_figure();
    EXPECT_EQ(center.first, 0);
    EXPECT_EQ(center.second, 0);
}

TEST(RhombTests, AreaOfRhomb) {
    Rhomb rhomb({0, 4}, {4, 0}, {0, -4}, {-4, 0});
    double area = double(rhomb);
    EXPECT_NEAR(area, 32, 0.0001); 
}

TEST(RhombTests, RhombEquality) {
    Rhomb rhomb1({0, 4}, {4, 0}, {0, -4}, {-4, 0});
    Rhomb rhomb2({0, 4}, {4, 0}, {0, -4}, {-4, 0});
    Rhomb rhomb3({0, 3}, {3, 0}, {0, -3}, {-3, 0});

    EXPECT_TRUE(rhomb1.operator==(rhomb2));
    EXPECT_FALSE(rhomb1.operator==(rhomb3));  
}


TEST(PentagonTests, AreaOfPentagon) {
    Pentagon pentagon({0, 0}, {2, 0}, {3, 2}, {1, 3}, {-1, 1});
    double area = double(pentagon);
    EXPECT_NEAR(area, 6.88191, 0.0001);  
}

TEST(PentagonTests, CenterOfPentagon) {
    Pentagon pentagon({0, 0}, {2, 0}, {3, 2}, {1, 3}, {-1, 1});
    auto center = pentagon.Center_of_figure();
    EXPECT_NEAR(center.first, 1.0, 0.01); 
    EXPECT_NEAR(center.second, 1.2, 0.01);
}

// Тест для трапеции на площадь
TEST(TrapecyTests, AreaOfTrapecy) {
    Trapecy trapecy({0, 0}, {1, 3}, {3, 3}, {4, 0});
    double area = double(trapecy);
    EXPECT_NEAR(area, 9, 0.0001);
}

// Тест для геометрического центра трапеции
TEST(TrapecyTests, CenterOfTrapecy) {
    Trapecy trapecy({0, 0}, {4, 0}, {3, 3}, {1, 3});
    auto center = trapecy.Center_of_figure();
    EXPECT_NEAR(center.first, 2.0, 0.01);
    EXPECT_NEAR(center.second, 1.5, 0.01);
}

