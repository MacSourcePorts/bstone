/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#if !defined(BSTONE_SYS_VIDEO_MGR_SDL2_INCLUDED)
#define BSTONE_SYS_VIDEO_MGR_SDL2_INCLUDED

#include "bstone_sys_video_mgr.h"

namespace bstone {
namespace sys {

VideoMgrUPtr make_sdl2_video_mgr(Logger& logger);

} // namespace sys
} // namespace bstone

#endif // BSTONE_SYS_VIDEO_MGR_SDL2_INCLUDED
