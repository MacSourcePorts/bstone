/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#if !defined(BSTONE_SYS_WINDOW_SDL2_INCLUDED)
#define BSTONE_SYS_WINDOW_SDL2_INCLUDED

#include "bstone_sys_logger.h"
#include "bstone_sys_window.h"

namespace bstone {
namespace sys {

WindowUPtr make_sdl2_window(Logger& logger, const WindowInitParam& param);

} // namespace sys
} // namespace bstone

#endif // BSTONE_SYS_WINDOW_SDL2_INCLUDED
