/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2024 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

// Event manager.

#include "bstone_sys_event_mgr.h"

namespace bstone {
namespace sys {

bool EventMgr::poll_event(Event& e)
{
	return do_poll_event(e);
}

} // namespace sys
} // namespace bstone
