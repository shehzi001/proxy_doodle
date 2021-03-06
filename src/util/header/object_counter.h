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
 * @File   object_counter.h
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 24, 2016, 5:49 PM
 *
 * @Brief Brief description of file.
 *
 * Description:
 */


// Create a comment in the ELF object file structure for
// error tracing reasons.
// -----------------------------------------------------

#if defined( __unix__ ) || defined( __unix )
#ident "@(#) object_counter 2016-12-24 17:49:48 Eike Schumann"
#endif


// Ensure that only a C++ compiler tries to compile this file to avoid
// some 'interesting' error messages from C compilers
// ---------------------------------------------------------------------

#if !defined( __cplusplus )
#error The file __FILE__ requires to be compiled by a C++ compiler!
#endif


// Include guard to avoid multiple inclusion
// -----------------------------------------
#ifndef OBJECT_COUNTER_H
#define OBJECT_COUNTER_H

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------


// Include project headers
// -----------------------


// Synopsis/Namespace interface:
// This section lists the classes, functions and types provided by this
// file as well as forward declaration of classes, functions and types
// provided by custom components.
// --------------------------------------------------------------------
namespace tuto { namespace utl {
  template < typename T > struct object_counter;
}}

// Declarations of the class interfaces
// ------------------------------------

template < typename T > struct tuto::utl::object_counter {
  static int created;
  static int alive;
  object_counter();
  object_counter( object_counter const& );

  int const& num_created() const;
  int const& num_alive() const;

protected:
  ~object_counter();
};

// Definition of (inlined) methods and functions ( most likely template related ).
// ------------------------------------------------------------------------------

template < typename T > tuto::utl::object_counter<T>::object_counter() {
  ++created;
  ++alive;
}

template < typename T > tuto::utl::object_counter<T>::object_counter( object_counter const& ) {
  ++created;
  ++alive;
}

template < typename T > tuto::utl::object_counter<T>::~object_counter() {
  --alive;
}

template < typename T > inline int const& tuto::utl::object_counter<T>::num_created() const {
  return created;
}

template < typename T > inline int const& tuto::utl::object_counter<T>::num_alive() const {
  return alive;
}

template < typename T > int tuto::utl::object_counter<T>::created(0);
template < typename T > int tuto::utl::object_counter<T>::alive(0);

#endif /* OBJECT_COUNTER_H */