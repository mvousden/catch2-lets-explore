#include "apple_pie.hpp"
#include <iostream>

int main(int argc, char** argv) {
    ApplePie myPie;
    myPie.fill();
    myPie.bake();
    return myPie.eat();
}
