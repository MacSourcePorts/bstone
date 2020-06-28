/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2020 Boris I. Bendovsky (bibendovsky@hotmail.com)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the
Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/


#include "jm_cio.h"


// ----------------------------------------------------------------------------
//
// PTR/PTR COMPRESSION ROUTINES
//
//
// ----------------------------------------------------------------------------

// ---------------------------------------------------------------------------
// CIO_WritePtr()  -- Outputs data to a particular ptr type
//
//      PtrType MUST be of type DEST_TYPE.
//
// NOTE : For PtrTypes DEST_MEM a ZERO (0) is always returned.
//
// ---------------------------------------------------------------------------
void CIO_WritePtr(
	std::uint8_t*& buffer,
	std::uint8_t value)
{
	*buffer++ = value;
}

// ---------------------------------------------------------------------------
// CIO_ReadPtr()  -- Reads data from a particular ptr type
//
//      PtrType MUST be of type SRC_TYPE.
//
// RETURNS :
//              The char read in or EOF for SRC_FFILE type of reads.
//
//
// ---------------------------------------------------------------------------
std::uint8_t CIO_ReadPtr(
	const std::uint8_t*& buffer)
{
	return *(buffer++);
}
