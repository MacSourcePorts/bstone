/*
BStone: A Source port of
Blake Stone: Aliens of Gold and Blake Stone: Planet Strike

Copyright (c) 1992-2013 Apogee Entertainment, LLC
Copyright (c) 2013-2021 Boris I. Bendovsky (bibendovsky@hotmail.com)

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

#include "bstone_audio_mixer_validator.h"
#include "bstone_exception.h"

namespace bstone
{

namespace
{

class AudioMixerValidatorException : public Exception
{
public:
	explicit AudioMixerValidatorException(const char* message) noexcept
		:
		Exception{"AUDIO_MIXER_VALIDATOR", message}
	{
	}
}; // AudioMixerValidatorException

} // namespace

// ==========================================================================

void AudioMixerValidator::validate_gain(double gain)
try
{
	if (gain < audio_mixer_min_gain || gain > audio_mixer_max_gain)
	{
		fail("Gain out of range.");
	}
}
catch (...)
{
	fail_nested(__func__);
}

[[noreturn]] void AudioMixerValidator::fail(const char* message)
{
	throw AudioMixerValidatorException{message};
}

[[noreturn]] void AudioMixerValidator::fail_nested(const char* message)
{
	std::throw_with_nested(AudioMixerValidatorException{message});
}

} // bstone