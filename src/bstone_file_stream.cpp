/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2023 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

// File stream.

#include "bstone_exception.h"
#include "bstone_file_stream.h"

namespace bstone {

FileStream::FileStream(const char* path, FileOpenFlags open_flags)
	:
	file_{path, open_flags}
{}

bool FileStream::try_open(const char* path, FileOpenFlags open_flags)
{
	return file_.try_open(path, open_flags);
}

void FileStream::open(const char* path, FileOpenFlags open_flags)
{
	file_.open(path, open_flags);
}

void FileStream::do_close() noexcept
{
	file_.close();
}

bool FileStream::do_is_open() const noexcept
{
	return file_.is_open();
}

std::intptr_t FileStream::do_read(void* buffer, std::intptr_t count)
{
	return file_.read(buffer, count);
}

std::intptr_t FileStream::do_write(const void* buffer, std::intptr_t count)
{
	return file_.write(buffer, count);
}

std::int64_t FileStream::do_seek(std::int64_t offset, StreamOrigin origin)
try {
	auto file_origin = FileOrigin::none;

	switch (origin)
	{
		case StreamOrigin::begin: file_origin = FileOrigin::begin; break;
		case StreamOrigin::current: file_origin = FileOrigin::current; break;
		case StreamOrigin::end: file_origin = FileOrigin::end; break;
		default: BSTONE_THROW_STATIC_SOURCE("Unknown origin.");
	}

	return file_.seek(offset, file_origin);
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

std::int64_t FileStream::do_get_size() const
{
	return file_.get_size();
}

void FileStream::do_set_size(std::int64_t size)
{
	file_.set_size(size);
}

void FileStream::do_flush()
{
	file_.flush();
}

} // namespace bstone
