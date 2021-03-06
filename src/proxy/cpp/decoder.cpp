/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * @File   decoder.cpp
 * @Author Eike Schumann <e-schumann@online.de>
 *
 * (c) Copyright 2016 by Eike Schumann
 *
 * Created on December 26, 2016, 10:25 AM
 *
 * @Brief Brief description of decoder.cpp.
 *
 * Description:
 */

// Include STL headers (e.g. vector, string, etc...)
// -------------------------------------------------


// Include system headers (e.g. dlfcn.h, etc ...)
// ----------------------------------------------


// Include external headers (e.g. from Boost, etc ...)
// ---------------------------------------------------


// Include project headers
// -----------------------
#include <parser_interface.h>

// Include declaration header
// --------------------------
#include <decoder.h>

tuto::decoder::decoder( parser_interface* parser ) : parser_{parser} {
}

tuto::pt::ptree tuto::decoder::decode( std::string const& data ) const {
   return parser_->parse(data);
 }