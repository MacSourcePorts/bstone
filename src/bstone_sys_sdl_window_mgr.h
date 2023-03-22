/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#if !defined(BSTONE_SYS_SDL_WINDOW_MGR_INCLUDED)
#define BSTONE_SYS_SDL_WINDOW_MGR_INCLUDED

#include "bstone_sys_logger.h"
#include "bstone_sys_window_mgr.h"

namespace bstone {
namespace sys {

WindowMgrUPtr make_sdl_window_mgr(Logger& logger);

} // namespace sys
} // namespace bstone

#endif // BSTONE_SYS_SDL_WINDOW_MGR_INCLUDED
