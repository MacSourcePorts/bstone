#include <algorithm>
#include <iterator>
#include <utility>

#include "bstone_file.h"
#include "bstone_file_stream.h"
#include "bstone_tester.h"

namespace {

auto tester = bstone::Tester{};

// ==========================================================================

// explicit FileStream(const char*, FileOpenFlags)
void test_9iuvd5h9gzjbt351()
{
	auto is_failed = false;
	auto is_open = false;

	try
	{
		const auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open);
}

// ==========================================================================

// explicit FileStream(const char*, FileOpenFlags)
// Invalid flags.
void test_cz3bzq9ia1144mgd()
{
	auto is_failed = false;

	try
	{
		const auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::none};
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(is_failed);
}

// ==========================================================================

// explicit FileStream(const char*)
void test_gj50q07ijq9uhdu2()
{
	auto is_created = false;
	auto is_opened = false;

	try
	{
		const auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_created = file.is_open();
	}
	catch (...) {}

	try
	{
		const auto file = bstone::FileStream{"test.data"};
		is_opened = file.is_open();
	}
	catch (...) {}

	tester.check(is_created && is_opened);
}

// ==========================================================================

// FileStream(FileStream&&) noexcept
void test_87hjc768xmbd1t34()
{
	auto file_1 = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
	const auto is_open_1 = file_1.is_open();
	auto file_2 = std::move(file_1);
	const auto is_open_2 = file_2.is_open();

	tester.check(is_open_1 && is_open_2);
}

// ==========================================================================

// FileStream& operator=(FileStream&&) noexcept
void test_5mmf4qysfrd2fonu()
{
	auto file_1 = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
	auto file_2 = bstone::FileStream{};
	const auto is_open_1 = file_1.is_open();
	file_2 = std::move(file_1);
	const auto is_open_2 = file_2.is_open();

	tester.check(is_open_1 && is_open_2);
}

// ==========================================================================

// bool try_open(const char*, FileOpenFlags)
void test_fwl347iyu5349iee()
{
	auto stream = bstone::FileStream{};

	const auto result_1 = stream.try_open("test.data", bstone::FileOpenFlags::create);
	const auto is_valid_1 = result_1;

	const auto result_2 = stream.is_open();
	const auto is_valid_2 = result_2;

	const auto is_valid =
		is_valid_1 &&
		is_valid_2 &&
		true;

	tester.check(is_valid);
}

// ==========================================================================

// bool try_open(const char*, FileOpenFlags) noexcept
// Invalid flags.
void test_4hi9u7tj6ugr8kmy()
{
	auto stream = bstone::FileStream{};
	auto is_failed = false;

	try
	{
		const auto result = stream.try_open("test.data", bstone::FileOpenFlags::none);
		static_cast<void>(result);
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(is_failed);
}

// ==========================================================================

// bool try_open(const char*) noexcept
void test_n5pmd6moj0vqsnqn()
{
	{
		const auto stream = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
	}

	auto stream = bstone::FileStream{};

	const auto result_1 = stream.try_open("test.data");
	const auto is_valid_1 = result_1;

	const auto result_2 = stream.is_open();
	const auto is_valid_2 = result_2;

	const auto is_valid =
		is_valid_1 &&
		is_valid_2 &&
		true;

	tester.check(is_valid);
}

// ==========================================================================

// void open(const char*, FileOpenFlags)
void test_3h64grd141dr6atb()
{
	auto is_failed = false;
	auto is_open = false;

	try
	{
		auto file = bstone::FileStream{};
		file.open("test.data", bstone::FileOpenFlags::create);
		is_open = file.is_open();
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open);
}

// ==========================================================================

// void open(const char*, FileOpenFlags)
// Invalid flags.
void test_bfq3co9j1znbbjim()
{
	auto is_failed = false;

	try
	{
		auto file = bstone::FileStream{};
		file.open("test.data", bstone::FileOpenFlags::none);
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(is_failed);
}

// ==========================================================================

// void open(const char*)
void test_fs8htsia07pw47ps()
{
	auto is_created = false;
	auto is_opened = false;

	try
	{
		const auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_created = file.is_open();
	}
	catch (...) {}

	try
	{
		auto file = bstone::FileStream{};
		file.open("test.data");
		is_opened = file.is_open();
	}
	catch (...) {}

	tester.check(is_created && is_opened);
}

// ==========================================================================

// void close() noexcept
void test_wrbmfiq7r9t2bjfi()
{
	auto is_failed = false;
	auto is_created = false;
	auto is_closed = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_created = file.is_open();
		file.close();
		is_closed = !file.is_open();
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_created && is_closed);
}

// ==========================================================================

// is_open() const noexcept
void test_n0q8fvihwy1v2klm()
{
	auto is_failed = false;
	auto is_open = false;

	try
	{
		const auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open);
}

// ==========================================================================

// std::intptr_t read(void*, std::intptr_t)
// std::intptr_t write(const void*, std::intptr_t)
void test_s4ldcda38dhh06px()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_zero_size = false;
	auto is_written = false;
	auto is_set_position = false;
	auto is_read = false;
	auto is_equal = false;

	try
	{
		constexpr auto byte_count = 4;
		const unsigned char ref_bytes[byte_count] = {0x11, 0x44, 0x22, 0x33};

		unsigned char bytes[byte_count] = {};

		auto file = bstone::FileStream
		{
			"test.data",
			bstone::FileOpenFlags::create | bstone::FileOpenFlags::truncate | bstone::FileOpenFlags::read
		};

		is_open = file.is_open();
		is_zero_size = file.get_size() == 0;
		is_written = file.write(ref_bytes + 0, 2) == 2 && file.write(ref_bytes + 2, 2) == 2;
		is_set_position = file.seek(0, bstone::StreamOrigin::begin) == 0;
		is_read = file.read(bytes + 0, 2) == 2 && file.read(bytes + 2, 2) == 2;
		is_equal = std::equal(std::cbegin(bytes), std::cend(bytes), ref_bytes);
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_zero_size && is_written && is_set_position && is_read && is_equal);
}

// ==========================================================================

// void read_exact(void*, std::intptr_t)
// void write_exact(const void*, std::intptr_t)
void test_xv0g17przcyh3w4p()
{
	auto is_open = false;
	auto is_zero_size = false;
	auto is_set_position = false;
	auto is_equal = false;

	constexpr auto byte_count = 4;
	const unsigned char ref_bytes[byte_count] = {0x11, 0x44, 0x22, 0x33};

	unsigned char bytes[byte_count] = {};

	auto file = bstone::FileStream
	{
		"test.data",
		bstone::FileOpenFlags::create | bstone::FileOpenFlags::truncate | bstone::FileOpenFlags::read
	};

	is_open = file.is_open();
	is_zero_size = file.get_size() == 0;
	file.write_exact(ref_bytes + 0, 2);
	file.write_exact(ref_bytes + 2, 2);
	is_set_position = file.seek(0, bstone::StreamOrigin::begin) == 0;
	file.read_exact(bytes + 0, 2);
	file.read_exact(bytes + 2, 2);
	is_equal = std::equal(std::cbegin(bytes), std::cend(bytes), ref_bytes);

	tester.check(is_open && is_zero_size && is_set_position && is_equal);
}

// ==========================================================================

// void read_exact(void*, std::intptr_t)
// Failed.
void test_kms3o2eisp359ubi()
{
	auto is_open = false;
	auto is_zero_size = false;

	auto file = bstone::FileStream
	{
		"test.data",
		bstone::FileOpenFlags::create | bstone::FileOpenFlags::truncate | bstone::FileOpenFlags::read
	};

	is_open = file.is_open();
	is_zero_size = file.get_size() == 0;

	auto is_failed = false;

	try
	{
		auto buffer = '\0';
		file.read_exact(&buffer, 1);
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(is_open && is_zero_size && is_failed);
}

// ==========================================================================

// std::int64_t seek(std::int64_t, StreamOrigin)
void test_qfmcpsx4dy9jrgwi()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_set_position_1 = false;
	auto is_set_position_2 = false;
	auto is_set_position_3 = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
		file.set_size(100);
		is_set_position_1 = file.seek(0, bstone::StreamOrigin::end) == 100;
		is_set_position_2 = file.seek(10, bstone::StreamOrigin::begin) == 10;
		is_set_position_3 = file.seek(-5, bstone::StreamOrigin::current) == 5;
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_set_position_1 && is_set_position_2 && is_set_position_3);
}

// ==========================================================================

// std::int64_t skip(std::int64_t)
void test_gmx97qp03xosymdn()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_set_position_1 = false;
	auto is_set_position_2 = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
		file.set_size(100);
		is_set_position_1 = file.seek(0, bstone::StreamOrigin::end) == 100;
		is_set_position_2 = file.skip(-5) == 95;
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_set_position_1 && is_set_position_2);
}

// ==========================================================================

// std::int64_t get_position()
void test_n9h6bhuu066frk7i()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_set_position_1 = false;
	auto is_set_position_2 = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
		is_set_position_1 = file.seek(42, bstone::StreamOrigin::begin) == 42;
		is_set_position_2 = file.get_position() == 42;
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_set_position_1 && is_set_position_2);
}

// ==========================================================================

// void set_position(std::int64_t)
void test_j7d9qfbvnl7p0fdh()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_set_position = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
		file.set_position(42);
		is_set_position = file.seek(0, bstone::StreamOrigin::current) == 42;
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_set_position);
}

// ==========================================================================

// std::int64_t get_size() const
void test_jvs8f0vrf44bei94()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_valid_size_1 = false;
	auto is_valid_size_2 = false;

	try
	{
		const char buffer = '\0';
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create | bstone::FileOpenFlags::truncate};
		is_open = file.is_open();
		is_valid_size_1 = file.get_size() == 0;
		file.seek(99, bstone::StreamOrigin::begin);
		file.write(&buffer, 1);
		is_valid_size_2 = file.get_size() == 100;
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_valid_size_1 && is_valid_size_2);
}

// ==========================================================================

// void set_size(std::int64_t)
void test_apnc1tdy41tuubu6()
{
	auto is_failed = false;
	auto is_open = false;
	auto is_valid_size_1 = false;
	auto is_valid_size_2 = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create | bstone::FileOpenFlags::truncate};
		is_open = file.is_open();
		is_valid_size_1 = file.get_size() == 0;
		file.set_size(100);
		is_valid_size_2 = file.get_size() == 100;
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open && is_valid_size_1 && is_valid_size_2);
}

// ==========================================================================

// void flush()
void test_2o69zbx04pa7rsz4()
{
	auto is_failed = false;
	auto is_open = false;

	try
	{
		auto file = bstone::FileStream{"test.data", bstone::FileOpenFlags::create};
		is_open = file.is_open();
		file.flush();
	}
	catch (...)
	{
		is_failed = true;
	}

	tester.check(!is_failed && is_open);
}

// ==========================================================================

class Registrator
{
public:
	Registrator()
	{
		register_file_stream();
		register_try_open();
		register_open();
		register_close();
		register_is_open();
		register_read_write();
		register_read_exact_write_exact();
		register_seek();
		register_skip();
		register_get_position();
		register_set_position();
		register_get_size();
		register_set_size();
		register_flush();
	}

private:
	void register_file_stream()
	{
		tester.register_test("FileStream#9iuvd5h9gzjbt351", test_9iuvd5h9gzjbt351);
		tester.register_test("FileStream#cz3bzq9ia1144mgd", test_cz3bzq9ia1144mgd);
		tester.register_test("FileStream#gj50q07ijq9uhdu2", test_gj50q07ijq9uhdu2);
		tester.register_test("FileStream#87hjc768xmbd1t34", test_87hjc768xmbd1t34);
		tester.register_test("FileStream#5mmf4qysfrd2fonu", test_5mmf4qysfrd2fonu);
	}

	void register_try_open()
	{
		tester.register_test("FileStream#fwl347iyu5349iee", test_fwl347iyu5349iee);
		tester.register_test("FileStream#4hi9u7tj6ugr8kmy", test_4hi9u7tj6ugr8kmy);
		tester.register_test("FileStream#n5pmd6moj0vqsnqn", test_n5pmd6moj0vqsnqn);
	}

	void register_open()
	{
		tester.register_test("FileStream#3h64grd141dr6atb", test_3h64grd141dr6atb);
		tester.register_test("FileStream#bfq3co9j1znbbjim", test_bfq3co9j1znbbjim);
		tester.register_test("FileStream#fs8htsia07pw47ps", test_fs8htsia07pw47ps);
	}

	void register_close()
	{
		tester.register_test("FileStream#wrbmfiq7r9t2bjfi", test_wrbmfiq7r9t2bjfi);
	}

	void register_is_open()
	{
		tester.register_test("FileStream#n0q8fvihwy1v2klm", test_n0q8fvihwy1v2klm);
	}

	void register_read_write()
	{
		tester.register_test("FileStream#s4ldcda38dhh06px", test_s4ldcda38dhh06px);
	}

	void register_read_exact_write_exact()
	{
		tester.register_test("FileStream#xv0g17przcyh3w4p", test_xv0g17przcyh3w4p);
		tester.register_test("FileStream#kms3o2eisp359ubi", test_kms3o2eisp359ubi);
	}

	void register_seek()
	{
		tester.register_test("FileStream#qfmcpsx4dy9jrgwi", test_qfmcpsx4dy9jrgwi);
	}

	void register_skip()
	{
		tester.register_test("FileStream#gmx97qp03xosymdn", test_gmx97qp03xosymdn);
	}

	void register_get_position()
	{
		tester.register_test("FileStream#n9h6bhuu066frk7i", test_n9h6bhuu066frk7i);
	}

	void register_set_position()
	{
		tester.register_test("FileStream#j7d9qfbvnl7p0fdh", test_j7d9qfbvnl7p0fdh);
	}

	void register_get_size()
	{
		tester.register_test("FileStream#jvs8f0vrf44bei94", test_jvs8f0vrf44bei94);
	}

	void register_set_size()
	{
		tester.register_test("FileStream#apnc1tdy41tuubu6", test_apnc1tdy41tuubu6);
	}

	void register_flush()
	{
		tester.register_test("FileStream#2o69zbx04pa7rsz4", test_2o69zbx04pa7rsz4);
	}
};

auto registrator = Registrator{};

} // namespace
