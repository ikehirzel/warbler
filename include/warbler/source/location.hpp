#ifndef WARBLER_SOURCE_LOCATION_HPP
#define WARBLER_SOURCE_LOCATION_HPP

#include <warbler/util/primitive.hpp>

namespace warbler::source
{
	class Location
	{
	private:

		usize _pos;
		usize _length;

	public:

		Location(usize pos, usize length);

		Location operator+(const Location& other);

		usize pos() const { return _pos; }
		usize length() const { return _length; }
	};
}

#endif