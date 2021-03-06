/*
 * The MIT License
 *
 * Copyright 2016 Eike Schumann <e-schumann@online.de>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/**
 * @File   singletonTest.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 24, 2016, 1:47 PM
 *
 * @Brief Brief description of singletonTest.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------

#include <memory>

// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------
#include <gtest/gtest.h>


// Include project headers
// -----------------------

// Include declaration header
// --------------------------
#include <singletonTest.h>


// Tests
// ---------------------------------------------------

/**
 * This test uses a trivial class that is CRTP-derived from 'singleton'.
 * Specialty: Due to the implementation of 'singleton' this class can not
 * be copied.
 */

TEST( singletonTest, simple01 ) {
   using namespace tuto::utl;

   int count{0};

   {
      count = test::constructor_test_class::instance().num_created();
      EXPECT_EQ( count, 1 );

      count = test::constructor_test_class::instance().num_created();
      EXPECT_EQ( count, 1 );

      count = test::constructor_test_class::instance().num_alive();
      EXPECT_EQ( count, 1 );

      test::constructor_test_class a;
      count = a.num_created();
      EXPECT_EQ( count, 2 );

      count = a.num_alive();
      EXPECT_EQ( count, 2 );

      {
         test::constructor_test_class a;
         count = a.num_created();
         EXPECT_EQ( count, 3 );

         count = a.num_alive();
         EXPECT_EQ( count, 3 );

         test::constructor_test_class b;
         count = b.num_created();
         EXPECT_EQ( count, 4 );

         count = b.num_alive();
         EXPECT_EQ( count, 4 );

         count = a.num_created();
         EXPECT_EQ( count, 4 );

         count = a.num_alive();
         EXPECT_EQ( count, 4 );
      }

      count = a.num_created();
      EXPECT_EQ( count, 4 );

      count = a.num_alive();
      EXPECT_EQ( count, 2 );

      {
         std::unique_ptr< test::constructor_test_class > p { new test::constructor_test_class };
         count = p->num_created();
         EXPECT_EQ( count, 5 );

         count = p->num_alive();
         EXPECT_EQ( count, 3 );
      }

      count = a.num_created();
      EXPECT_EQ( count, 5 );

      count = a.num_alive();
      EXPECT_EQ( count, 2 );

      test::constructor_test_class& d = test::constructor_test_class::instance();

      count = d.num_created();
      EXPECT_EQ( count, 5 );

      count = d.num_alive();
      EXPECT_EQ( count, 2 );
   }
   count = test::constructor_test_class::instance().num_created();
   EXPECT_EQ( count, 5 );

   count = test::constructor_test_class::instance().num_alive();
   EXPECT_EQ( count, 1 );
}

/**
 * This test uses a trivial class that is explicitly 'singletonized'.
 * Specialty: This allows 'non-singletonized' instances of the class
 * to be copied.
 */

TEST( singletonTest, simple02 ) {
   using namespace tuto::utl;

   int count{0};

   {
      count = singleton<test::constructor_test_class2>::instance().num_created();
      EXPECT_EQ( count, 1 );

      count = singleton<test::constructor_test_class2>::instance().num_created();
      EXPECT_EQ( count, 1 );

      count = singleton<test::constructor_test_class2>::instance().num_alive();
      EXPECT_EQ( count, 1 );

      test::constructor_test_class2 a;
      count = a.num_created();
      EXPECT_EQ( count, 2 );

      count = a.num_alive();
      EXPECT_EQ( count, 2 );

      {
         test::constructor_test_class2 a;
         count = a.num_created();
         EXPECT_EQ( count, 3 );

         count = a.num_alive();
         EXPECT_EQ( count, 3 );

         test::constructor_test_class2 b;
         count = b.num_created();
         EXPECT_EQ( count, 4 );

         count = b.num_alive();
         EXPECT_EQ( count, 4 );

         count = a.num_created();
         EXPECT_EQ( count, 4 );

         count = a.num_alive();
         EXPECT_EQ( count, 4 );
      }

      count = a.num_created();
      EXPECT_EQ( count, 4 );

      count = a.num_alive();
      EXPECT_EQ( count, 2 );

      {
         std::unique_ptr< test::constructor_test_class2 > p { new test::constructor_test_class2 };
         count = p->num_created();
         EXPECT_EQ( count, 5 );

         count = p->num_alive();
         EXPECT_EQ( count, 3 );
      }

      count = a.num_created();
      EXPECT_EQ( count, 5 );

      count = a.num_alive();
      EXPECT_EQ( count, 2 );

      test::constructor_test_class2 b ( a );
      count = b.num_created();
      EXPECT_EQ( count, 6 );

      count = b.num_alive();
      EXPECT_EQ( count, 3 );

      test::constructor_test_class2 c ( singleton< test::constructor_test_class2 >::instance() );
      count = c.num_created();
      EXPECT_EQ( count, 7 );

      count = c.num_alive();
      EXPECT_EQ( count, 4 );

      test::constructor_test_class2& d = singleton<test::constructor_test_class2>::instance();

      count = d.num_created();
      EXPECT_EQ( count, 7 );

      count = d.num_alive();
      EXPECT_EQ( count, 4 );
   }
   count = singleton<test::constructor_test_class2>::instance().num_created();
   EXPECT_EQ( count, 7 );

   count = singleton<test::constructor_test_class2>::instance().num_alive();
   EXPECT_EQ( count, 1 );
}

TEST( singletonTest, simple03 ) {
   using namespace tuto::utl;

   int count{0};

   {
      typedef test::multiple_constructors<1> test_class;

      count = test_class::instance().num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( test_class::instance().id(), 0 );
      EXPECT_TRUE( test_class::instance().name().empty() );
      EXPECT_EQ( test_class::instance().num_created(), 1 );
      EXPECT_EQ( test_class::instance().num_alive(), 1 );

      // This instance call does NOT initialize the field 'name' because being a singleton
      // the constructor is not called because there is already an instance existing from above
      // call. Effects like this made singletons an anti-pattern, I guess.
      // On the other hand this might be the effect one just wanted to achieve.
      // So: Use a singleton if you know what you do.
      // Changing state of the 'singletonized' object requires setters.
      test_class& instance = test_class::instance("wow");
      count = instance.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance.id(), 0 );
      EXPECT_TRUE( instance.name().empty() );
   }

   {
      typedef test::multiple_constructors<2> test_class;

      test_class& instance = test_class::instance("wow");
      count = instance.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance.id(), 0 );
      EXPECT_EQ( instance.name(), "wow" );
      count = instance.num_created();
      EXPECT_EQ( count, 1 );

      // This instance call does NOT initialize the field 'id' because being a singleton
      // the constructor is not called because there is already an instance existing from above
      // call. Effects like this made singletons an anti-pattern, I guess.
      // On the other hand this might be the effect one just wanted to achieve.
      // So: Use a singleton if you know what you do.
      // Changing state of the 'singletonized' object requires setters.

      test_class& instance2 = test_class::instance(25U);
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance2.id(), 0 );
      EXPECT_EQ( instance2.name(), "wow" );
      count = instance.num_created();
      EXPECT_EQ( count, 1 );
   }

   {
      typedef test::multiple_constructors<3> test_class;

      test_class& instance = test_class::instance("wow", 42U);
      count = instance.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance.id(), 42U );
      EXPECT_EQ( instance.name(), "wow" );
      count = instance.num_created();
      EXPECT_EQ( count, 1 );

      test_class& instance2 = test_class::instance();
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );
      EXPECT_EQ( instance2.id(), 42U );
      EXPECT_EQ( instance2.name(), "wow" );
      count = instance2.num_created();
      EXPECT_EQ( count, 1 );
   }
}

