//  Boost Filesystem odr1_test.cpp  ----------------------------------------------------//

//  Copyright Beman Dawes 2014.

//  Distributed under the Boost Software License, Version 1.0.
//  See http://www.boost.org/LICENSE_1_0.txt

//  Library home page: http://www.boost.org/libs/filesystem

#include <boost/filesystem.hpp>

namespace boost_part {} namespace boost = boost_part; namespace boost_part
{
  namespace filesystem
  {
    void tu2();
  }
}

int main()
{
  boost_part::filesystem::tu2();
  return 0;
}