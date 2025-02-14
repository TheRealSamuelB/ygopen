/*
 * Copyright (c) 2021, Dylam De La Torre <dyxel04@gmail.com>
 *
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */
#ifndef YGOPEN_PROTO_DUEL_DATA_HPP
#define YGOPEN_PROTO_DUEL_DATA_HPP
// clang-format off
#include <duel_data.pb.h>
// clang-format on

#include <ygopen/duel/constants/location.hpp>
#include <ygopen/duel/constants_fwd.hpp>

namespace YGOpen::Proto::Duel
{

// Used to indicate that the place doesn't belong to an overlay.
constexpr int OSEQ_INVALID = -1;

// Check equivalence only of protobuf-exposed methods.
struct PlaceLess
{
	auto operator()(const Place& lhs, const Place& rhs) const noexcept -> bool
	{
		if(lhs.con() < rhs.con())
			return true;
		if(rhs.con() < lhs.con())
			return false;

		if(lhs.loc() < rhs.loc())
			return true;
		if(rhs.loc() < lhs.loc())
			return false;

		if(lhs.seq() < rhs.seq())
			return true;
		if(rhs.seq() < lhs.seq())
			return false;

		if(lhs.oseq() < rhs.oseq())
			return true;
		return false;
	}
};

inline auto get_con(const Place& place) noexcept -> auto
{
	return static_cast<YGOpen::Duel::Controller>(place.con());
}

inline auto get_loc(const Place& place) noexcept -> auto
{
	return static_cast<YGOpen::Duel::Location>(place.loc());
}

// See duel/constants/location.hpp `is_empty`.
inline auto is_empty(const Place& place) noexcept -> bool
{
	return is_empty(get_loc(place));
}

// See duel/constants/location.hpp `is_pile`.
inline auto is_pile(const Place& place) noexcept -> bool
{
	return is_pile(get_loc(place));
}

// See duel/constants/location.hpp `is_zone`.
inline auto is_zone(const Place& place) noexcept -> bool
{
	return is_zone(get_loc(place));
}

} // namespace YGOpen::Proto::Duel

#endif // YGOPEN_PROTO_DUEL_DATA_HPP
