/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2023 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

// Stream primitive.

#include "bstone_exception.h"
#include "bstone_stream.h"

namespace bstone {

void Stream::close() noexcept
{
	do_close();
}

bool Stream::is_open() const noexcept
{
	return do_is_open();
}

std::intptr_t Stream::read(void* buffer, std::intptr_t count)
{
	return do_read(buffer, count);
}

void Stream::read_exact(void* buffer, std::intptr_t count)
{
	if (read(buffer, count) != count)
	{
		BSTONE_THROW_STATIC_SOURCE("Data underflow.");
	}
}

std::intptr_t Stream::write(const void* buffer, std::intptr_t count)
{
	return do_write(buffer, count);
}

void Stream::write_exact(const void* buffer, std::intptr_t count)
{
	if (write(buffer, count) != count)
	{
		BSTONE_THROW_STATIC_SOURCE("Data overflow.");
	}
}

std::int64_t Stream::seek(std::int64_t offset, StreamOrigin origin)
{
	return do_seek(offset, origin);
}

std::int64_t Stream::skip(std::int64_t delta)
{
	return seek(delta, StreamOrigin::current);
}

std::int64_t Stream::get_position()
{
	return skip(0);
}

void Stream::set_position(std::int64_t position)
{
	seek(position, StreamOrigin::begin);
}

std::int64_t Stream::get_size() const
{
	return do_get_size();
}

void Stream::set_size(std::int64_t size)
{
	do_set_size(size);
}

void Stream::flush()
{
	do_flush();
}

} // namespace bstone
