#include "apple_pie.hpp"
#include <iostream>

ApplePie::ApplePie() {
    filled = false;
    baked = false;
    burned = false;
}

int ApplePie::fill() {
    // Returns 0 if it could be filled, and 1 otherwise.
    std::cout << "Filling the pie...\n";
    if (filled) {
        std::cout << "[ApplePie] Can't fill any more!\n";
        return 1;
    }
    else if (baked) {
        std::cout << "[ApplePie] It's too hot to fill now!\n";
        return 1;
    }
    else {
        std::cout << "[ApplePie] Pie has now been filled.\n";
        filled = true;
        return 0;
    }
}

void ApplePie::bake() {
    std::cout << "Baking the pie...\n";
    if (baked) {
        std::cout << "[ApplePie] I smell smoke...\n";
        burned = true;
    }
    else {
        std::cout << "[ApplePie] Smells good!\n";
    }
    baked = true;
}

int ApplePie::eat() {
    // Returns 0 if it tastes good, and 1 otherwise.
    std::cout << "Eating the pie...\n";
    if (burned) {
        std::cout << "[ApplePie] Tastes like charcoal...\n";
        return 1;
    }
    else if (filled and baked) {
        std::cout << "[ApplePie] Delicious!\n";
        return 0;
    }
    else if (baked) {
        std::cout << "[ApplePie] Pastry is good, but there was no filling.\n";
        return 1;
    }
    else {
        std::cout << "[ApplePie] The pastry is raw!\n";
        return 1;
    }
}
