//
// Created by Janus Bo Andersen on 18/9/19.
//

#include "catch2/catch.hpp"
#include "answer.h"

TEST_CASE("1: The answer should be 42") {
    REQUIRE(theAnswer() == 42);
}

TEST_CASE("2: Life, the universe and everything", "[42][theAnswer]") {
    REQUIRE(theAnswer() == 54);
}