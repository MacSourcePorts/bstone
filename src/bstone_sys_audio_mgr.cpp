/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2024 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

// Audio manager.

#include "bstone_sys_audio_mgr.h"

namespace bstone {
namespace sys {

PollingAudioDeviceUPtr AudioMgr::make_polling_audio_device(const PollingAudioDeviceOpenParam& param)
{
	return do_make_polling_audio_device(param);
}

} // namespace sys
} // namespace bstone
