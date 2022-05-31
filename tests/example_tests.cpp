#include "catch2/catch_test_macros.hpp"
#include "example.hpp"

TEST_CASE("addition") {
    REQUIRE(example::addition(1, 1) == 2);
}
