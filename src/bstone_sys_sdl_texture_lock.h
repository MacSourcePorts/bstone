/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2023 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#if !defined(BSTONE_SYS_SDL_TEXTURE_LOCK_INCLUDED)
#define BSTONE_SYS_SDL_TEXTURE_LOCK_INCLUDED

#include "bstone_sys_r2_rect.h"
#include "bstone_sys_sdl_texture.h"
#include "bstone_sys_texture_lock.h"

struct SDL_Texture;

namespace bstone {
namespace sys {

TextureLockUPtr make_sdl_texture_lock(SDL_Texture& sdl_texture, const R2Rect* rect);

} // namespace sys
} // namespace bstone

#endif // BSTONE_SYS_SDL_TEXTURE_LOCK_INCLUDED
