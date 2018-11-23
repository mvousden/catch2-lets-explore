#define CATCH_CONFIG_MAIN  // Catch will provide an entry point for this
                           // translation unit.
#include "apple_pie.hpp"
#include "catch.hpp"

TEST_CASE("Pies can be burned", "[ApplePie]") {
    ApplePie myPie;
    myPie.bake();
    myPie.bake();
    REQUIRE(myPie.isBurned() == true);
}

TEST_CASE("Burned pies are inedible", "[ApplePie]") {
    ApplePie myPie;
    myPie.bake();
    myPie.bake();
    REQUIRE(myPie.eat() == 1);
}

TEST_CASE("Badly written tests don't stop other tests", "[CatchForSanity]") {
    ApplePie myPie;
    myPie.bake();
    myPie.bake();
    REQUIRE(myPie.eat() == 0);
}

TEST_CASE("Pies can be cooked correctly", "[ApplePie]") {
    ApplePie myPie;
    myPie.fill();
    myPie.bake();
    REQUIRE(myPie.eat() == 0);
}
