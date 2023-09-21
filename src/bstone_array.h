/*
BStone: Unofficial source port of Blake Stone: Aliens of Gold and Blake Stone: Planet Strike
Copyright (c) 2023 Boris I. Bendovsky (bibendovsky@hotmail.com) and Contributors
SPDX-License-Identifier: MIT
*/

// A container that encapsulates fixed size array.

#if !defined(BSTONE_ARRAY_INCLUDED)
#define BSTONE_ARRAY_INCLUDED

#include <cassert>

#include <memory>
#include <type_traits>
#include <utility>

#include "bstone_int.h"
#include "bstone_utility.h"

namespace bstone {

namespace detail {

template<typename TArg1, typename ...TArgs>
struct ArrayFirstType
{
	using Type = TArg1;
};


template<typename TItem, typename ...TArgs>
using ArrayVarArgPolicy =
	std::enable_if_t<
		std::is_convertible<
			typename detail::ArrayFirstType<TArgs...>::Type,
			TItem
		>::value,
	int>;

} // namespace detail

// ==========================================================================

template<typename TItem, IntP TSize>
class Array
{
public:
	using Item = TItem;

public:
	Array() = default;
	constexpr Array(const Array& rhs);
	constexpr explicit Array(const Item (&rhs)[TSize]);

	template<typename ...TArgs, detail::ArrayVarArgPolicy<Item, TArgs...> = 0>
	constexpr explicit Array(TArgs&& ...args)
		:
		items_{std::forward<TArgs>(args)...}
	{}

	constexpr Array& operator=(const Array& rhs);

	constexpr const Item* get_data() const noexcept;
	constexpr Item* get_data() noexcept;

	constexpr IntP get_size() const noexcept;
	constexpr bool is_empty() const noexcept;

	constexpr const Item* begin() const noexcept;
	constexpr Item* begin() noexcept;
	constexpr const Item* end() const noexcept;
	constexpr Item* end() noexcept;

	constexpr const Item* cbegin() const noexcept;
	constexpr const Item* cend() const noexcept;

	constexpr void fill(const Item& value);

	constexpr const Item& operator[](IntP index) const;
	constexpr Item& operator[](IntP index);

	constexpr void swap(Array& rhs) noexcept(
		noexcept(bstone::swop(std::declval<Item&>(), std::declval<Item&>())));

private:
	using Items = Item[TSize];

private:
	Items items_{};

private:
	constexpr void copy_items(const Items& src_items, Items& dst_items);
};

// --------------------------------------------------------------------------

template<typename TItem, IntP TSize>
constexpr Array<TItem, TSize>::Array(const Array& rhs)
{
	copy_items(rhs.items_, items_);
}

template<typename TItem, IntP TSize>
constexpr Array<TItem, TSize>::Array(const Item (&rhs)[TSize])
{
	copy_items(rhs, items_);
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::operator=(const Array& rhs) -> Array&
{
	assert(std::addressof(rhs) != this);
	copy_items(rhs.items_, items_);
	return *this;
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::get_data() const noexcept -> const Item*
{
	return items_;
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::get_data() noexcept -> Item*
{
	return const_cast<Item*>(bstone::as_const(*this).get_data());
}

template<typename TItem, IntP TSize>
constexpr IntP Array<TItem, TSize>::get_size() const noexcept
{
	return TSize;
}

template<typename TItem, IntP TSize>
constexpr bool Array<TItem, TSize>::is_empty() const noexcept
{
	return get_size() == 0;
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::begin() const noexcept -> const Item*
{
	return get_data();
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::begin() noexcept -> Item*
{
	return const_cast<Item*>(bstone::as_const(*this).begin());
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::end() const noexcept -> const Item*
{
	return get_data() + get_size();
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::end() noexcept -> Item*
{
	return const_cast<Item*>(bstone::as_const(*this).end());
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::cbegin() const noexcept -> const Item*
{
	return get_data();
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::cend() const noexcept -> const Item*
{
	return get_data() + get_size();
}

template<typename TItem, IntP TSize>
constexpr void Array<TItem, TSize>::fill(const Item& value)
{
	for (auto& item : items_)
	{
		item = value;
	}
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::operator[](IntP index) const -> const Item&
{
	assert(index >= 0 && index < get_size());
	return items_[index];
}

template<typename TItem, IntP TSize>
constexpr auto Array<TItem, TSize>::operator[](IntP index) -> Item&
{
	return const_cast<Item&>(bstone::as_const(*this).operator[](index));
}

template<typename TItem, IntP TSize>
constexpr void Array<TItem, TSize>::swap(Array& rhs) noexcept(
	noexcept(bstone::swop(std::declval<Item&>(), std::declval<Item&>())))
{
	for (auto i = IntP{}; i < TSize; ++i)
	{
		bstone::swop(items_[i], rhs.items_[i]);
	}
}

template<typename TItem, IntP TSize>
constexpr void Array<TItem, TSize>::copy_items(const Items& src_items, Items& dst_items)
{
	for (auto i = decltype(TSize){}; i < TSize; ++i)
	{
		dst_items[i] = src_items[i];
	}
}

// ==========================================================================

template<typename TItem>
class Array<TItem, 0>
{
public:
	using Item = TItem;

public:
	Array() = default;

	constexpr const Item* get_data() const noexcept;
	constexpr Item* get_data() noexcept;

	constexpr IntP get_size() const noexcept;
	constexpr bool is_empty() const noexcept;

	constexpr const Item* begin() const noexcept;
	constexpr Item* begin() noexcept;
	constexpr const Item* end() const noexcept;
	constexpr Item* end() noexcept;

	constexpr const Item* cbegin() const noexcept;
	constexpr const Item* cend() const noexcept;

private:
	Item item_{};
};

// --------------------------------------------------------------------------

template<typename TItem>
constexpr auto Array<TItem, 0>::get_data() const noexcept -> const Item*
{
	return &item_;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::get_data() noexcept -> Item*
{
	return const_cast<Item*>(bstone::as_const(*this).get_data());
}

template<typename TItem>
constexpr IntP Array<TItem, 0>::get_size() const noexcept
{
	return 0;
}

template<typename TItem>
constexpr bool Array<TItem, 0>::is_empty() const noexcept
{
	return true;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::begin() const noexcept -> const Item*
{
	return &item_;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::begin() noexcept -> Item*
{
	return &item_;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::end() const noexcept -> const Item*
{
	return &item_;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::end() noexcept -> Item*
{
	return &item_;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::cbegin() const noexcept -> const Item*
{
	return &item_;
}

template<typename TItem>
constexpr auto Array<TItem, 0>::cend() const noexcept -> const Item*
{
	return &item_;
}

// ==========================================================================

template<typename TItem, IntP TSize>
inline constexpr bool operator==(const Array<TItem, TSize>& lhs, const Array<TItem, TSize>& rhs)
{
	for (auto i = decltype(TSize){}; i < TSize; ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}

	return true;
}

template<typename TItem, IntP TSize>
inline constexpr bool operator!=(const Array<TItem, TSize>& lhs, const Array<TItem, TSize>& rhs)
{
	return !(lhs == rhs);
}

} // namespace bstone

#endif // BSTONE_ARRAY_INCLUDED
