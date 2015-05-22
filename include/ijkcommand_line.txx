/// \file ijkcommand_line.txx
/// templates for command line options.
/// Version 0.1.0

/*
  IJK: Isosurface Jeneration Kode
  Copyright (C) 2012 Rephael Wenger

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public License
  (LGPL) as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _IJKCOMMAND_LINE_
#define _IJKCOMMAND_LINE_

#include <iostream>
#include <vector>

#include "ijk.txx"
#include "ijkstring.txx"

namespace IJK {

  // forward declarations
  inline void throw_error_on_missing_argument
  (const int iarg, const int argc, char **argv, IJK::ERROR & error);

  // **************************************************
  // GET ARGUMENT OPTIONS
  // **************************************************

  /// Get integer argument argv[iarg+1].
  inline int get_arg_int(const int iarg, const int argc, char **argv,
                         IJK::ERROR & error)
  {
    throw_error_on_missing_argument(iarg, argc, argv, error);

    int x;
    if (!IJK::string2val(argv[iarg+1], x)) {
      error.AddMessage("Error in argument for option: ", argv[iarg], "");
      error.AddMessage
        ("Non-integer character in string: ", argv[iarg+1], "");
      throw error;
    }

    return(x);
  }


  /// Get string argument argv[iarg+1] and convert to list of arguments.
  template <typename ETYPE>
  inline void get_arg_multiple_arguments
  (const int iarg, const int argc, char **argv,
   std::vector<ETYPE> & v, IJK::ERROR & error)
  {
    throw_error_on_missing_argument(iarg, argc, argv, error);

    if (!IJK::string2vector(argv[iarg+1], v)) {
      error.AddMessage("Error in argument for option: ", argv[iarg], ".");
      error.AddMessage("Non-numeric character in string: ", argv[iarg+1], ".");
      throw error;
    }
  }

  // **************************************************
  // CHECK NUMBER OF ARGUMENTS
  // **************************************************

  inline void throw_error_on_missing_argument
  (const int iarg, const int argc, char **argv, IJK::ERROR & error)
  {
    if (iarg+1 >= argc) { 
      error.AddMessage
        ("Usage error. Missing argument for option ", argv[iarg],
         " and missing file name.");
      throw error;
    }
  }



}

#endif
