// 020-TestCase-2.cpp
// Source: https://github.com/catchorg/Catch2/blob/master/examples/020-TestCase-2.cpp

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "../naive.h"
#include "../hash.h"

TEST_CASE("Constructor", "[multi-file:2]"){
  string text = "dsfh kjadadfssfkjhadskjfh akjsdadfshfkjadshfkjasdfeidadfso adshkj fkjadshf kkjdadfsadsfah fkjladsf uaesbkjdfm, a";
  string pattern = "dadfs";
  vector<int> expected_result = {8, 30, 52, 78};
  vector<int> naive_result = search_pattern_naive(text, pattern);
  vector<int> hash_result = search_pattern_hash(text, pattern);
  REQUIRE( naive_result == hash_result );
  REQUIRE( naive_result ==  expected_result);
}
