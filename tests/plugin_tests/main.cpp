#include <cstdlib>
#include <iostream>
#include <boost/test/included/unit_test.hpp>

extern uint32_t CALIBRAE_TESTING_GENESIS_TIMESTAMP;

boost::unit_test::test_suite* init_unit_test_suite(int argc, char* argv[]) {
   std::srand(time(NULL));
   std::cout << "Random number generator seeded to " << time(NULL) << std::endl;
   const char* genesis_timestamp_str = getenv("CALIBRAE_TESTING_GENESIS_TIMESTAMP");
   if( genesis_timestamp_str != nullptr )
   {
      CALIBRAE_TESTING_GENESIS_TIMESTAMP = std::stoul( genesis_timestamp_str );
   }
   std::cout << "CALIBRAE_TESTING_GENESIS_TIMESTAMP is " << CALIBRAE_TESTING_GENESIS_TIMESTAMP << std::endl;
   return nullptr;
}
