/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2013-2022 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

#include <cassert>
#include <iterator>
#include "SDL.h"
#include "bstone_char_conv.h"
#include "bstone_exception.h"
#include "bstone_single_memory_pool.h"
#include "bstone_string_view.h"
#include "bstone_sys_logger.h"
#include "bstone_sys_sdl_audio_mgr.h"
#include "bstone_sys_sdl_event_mgr.h"
#include "bstone_sys_sdl_exception.h"
#include "bstone_sys_sdl_video_mgr.h"
#include "bstone_sys_system_mgr.h"

namespace bstone {
namespace sys {

namespace {

class SdlSystemMgr final : public SystemMgr
{
public:
	SdlSystemMgr(Logger& logger);
	SdlSystemMgr(const SdlSystemMgr&) = delete;
	SdlSystemMgr& operator=(const SdlSystemMgr&) = delete;
	~SdlSystemMgr() override;

	void* operator new(std::size_t size);
	void operator delete(void* ptr);

private:
	Logger& logger_;

private:
	AudioMgrUPtr do_make_audio_mgr() override;
	EventMgrUPtr do_make_event_mgr() override;
	VideoMgrUPtr do_make_video_mgr() override;

private:
	static MemoryResource& get_memory_resource();

	void log_version(const SDL_version& sdl_version, StringView version_name);
	void log_compiled_version();
	void log_linked_version();
	void log_versions();
	void log_info() noexcept;
};

// ==========================================================================

SdlSystemMgr::SdlSystemMgr(Logger& logger)
try
	:
	logger_{logger}
{
	logger_.log_information("<<< Start up SDL system manager.");

	log_versions();
	sdl_ensure_result(SDL_Init(0));

	logger_.log_information(">>> SDL system manager started up.");
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

SdlSystemMgr::~SdlSystemMgr()
{
	logger_.log_information("Shut down SDL system manager.");

	SDL_Quit();
}

void* SdlSystemMgr::operator new(std::size_t size)
try {
	return get_memory_resource().allocate(size);
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

void SdlSystemMgr::operator delete(void* ptr)
{
	get_memory_resource().deallocate(ptr);
}

AudioMgrUPtr SdlSystemMgr::do_make_audio_mgr()
{
	return make_sdl_audio_mgr(logger_);
}

EventMgrUPtr SdlSystemMgr::do_make_event_mgr()
{
	return make_sdl_event_mgr(logger_);
}

VideoMgrUPtr SdlSystemMgr::do_make_video_mgr()
{
	return make_sdl_video_mgr(logger_);
}

MemoryResource& SdlSystemMgr::get_memory_resource()
{
	static SingleMemoryPool<SdlSystemMgr> memory_pool{};

	return memory_pool;
}

void SdlSystemMgr::log_version(const SDL_version& sdl_version, StringView version_name)
{
	char major_chars[3];
	const auto major_size =
		to_chars(sdl_version.major, std::begin(major_chars), std::end(major_chars)) - major_chars;

	char minor_chars[3];
	const auto minor_size =
		to_chars(sdl_version.minor, std::begin(minor_chars), std::end(minor_chars)) - minor_chars;

	char patch_chars[3];
	const auto patch_size =
		to_chars(sdl_version.patch, std::begin(patch_chars), std::end(patch_chars)) - patch_chars;

	auto version_string = std::string{};
	version_string.reserve(32);
	version_string.append(version_name.get_data(), static_cast<std::size_t>(version_name.get_size()));
	version_string += " version: ";
	version_string.append(major_chars, static_cast<std::size_t>(major_size));
	version_string += '.';
	version_string.append(minor_chars, static_cast<std::size_t>(minor_size));
	version_string += '.';
	version_string.append(patch_chars, static_cast<std::size_t>(patch_size));

	logger_.log_information(version_string);
}

void SdlSystemMgr::log_compiled_version()
{
	auto sdl_version = SDL_version{};
	SDL_VERSION(&sdl_version);
	log_version(sdl_version, "Compiled");
}

void SdlSystemMgr::log_linked_version()
{
	auto sdl_version = SDL_version{};
	SDL_GetVersion(&sdl_version);
	log_version(sdl_version, "Linked");
}

void SdlSystemMgr::log_versions()
{
	log_compiled_version();
	log_linked_version();
}

void SdlSystemMgr::log_info() noexcept
try
{
	log_versions();
}
catch (...) {}

} // namespace

// ==========================================================================

SystemMgrUPtr make_system_mgr(Logger& logger)
try {
	return std::make_unique<SdlSystemMgr>(logger);
} BSTONE_END_FUNC_CATCH_ALL_THROW_NESTED

} // namespace sys
} // namespace bstone
