//
//  Copyright (c) 2012 Artyom Beilis (Tonkikh)
//  Copyright (c) 2019 Alexander Grund
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef BOOST_NOWIDE_CONFIG_HPP_INCLUDED
#define BOOST_NOWIDE_CONFIG_HPP_INCLUDED

/// @file

#include <boost/config.hpp>
#include <boost/nowide/replacement.hpp>

#if defined(BOOST_ALL_DYN_LINK) || defined(BOOST_NOWIDE_DYN_LINK)
#ifdef BOOST_NOWIDE_SOURCE
#define BOOST_NOWIDE_DECL BOOST_SYMBOL_EXPORT
#else
#define BOOST_NOWIDE_DECL BOOST_SYMBOL_IMPORT
#endif // BOOST_NOWIDE_SOURCE
#else
#define BOOST_NOWIDE_DECL
#endif // DYN_LINK

//
// Automatically link to the correct build variant where possible.
//
#if !defined(BOOST_ALL_NO_LIB) && !defined(BOOST_NOWIDE_NO_LIB) && !defined(BOOST_NOWIDE_SOURCE)
//
// Set the name of our library, this will get undef'ed by auto_link.hpp
// once it's done with it:
//
#define BOOST_LIB_NAME boost_nowide
//
// If we're importing code from a dll, then tell auto_link.hpp about it:
//
#if defined(BOOST_ALL_DYN_LINK) || defined(BOOST_NOWIDE_DYN_LINK)
#define BOOST_DYN_LINK
#endif
//
// And include the header that does the work:
//
#include <boost/config/auto_link.hpp>
#endif // auto-linking disabled

/// @def BOOST_NOWIDE_USE_FSTREAM_REPLACEMENTS
/// @brief Define to 1 to use internal classes from fstream.hpp
///
/// - On Non-Windows platforms: Define to 1 to use the same classes from header <fstream.hpp>
/// that are used on Windows.
/// - On Windows: No effect, always overwritten to 1
///
/// Affects boost::nowide::basic_filebuf,
/// boost::nowide::basic_ofstream, boost::nowide::basic_ifstream, boost::nowide::basic_fstream
#if defined(BOOST_WINDOWS)
#ifdef BOOST_NOWIDE_USE_FSTREAM_REPLACEMENTS
#undef BOOST_NOWIDE_USE_FSTREAM_REPLACEMENTS
#endif
#define BOOST_NOWIDE_USE_FSTREAM_REPLACEMENTS 1
#elif !defined(BOOST_NOWIDE_USE_FSTREAM_REPLACEMENTS)
#define BOOST_NOWIDE_USE_FSTREAM_REPLACEMENTS 0
#endif

#endif // boost/nowide/config.hpp
// vim: tabstop=4 expandtab shiftwidth=4 softtabstop=4
