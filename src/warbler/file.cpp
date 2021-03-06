#include <warbler/file.hpp>

#include <warbler/util/file.hpp>

#include <cassert>

namespace warbler
{
	File::File(String&& filename, String&& src, Array<usize>&& line_lengths) :
	_filename(filename),
	_src(src),
	_line_lengths(line_lengths)
	{}

	static Array<usize> get_line_lengths(const String& src)
	{
		Array<usize> line_lengths;
		auto estimated_line_count = src.size() / 80 + 1;
		usize last_start_of_line = 0;

		line_lengths.reserve(estimated_line_count);

		for (usize i = 0; i < src.size(); ++i)
		{
			if (src[i] == '\n')
			{
				auto line_length = i - last_start_of_line + 1;

				line_lengths.push_back(line_length);
				last_start_of_line = i + 1;
			}
		}

		return line_lengths;
	}

	Result<File> File::read(const String& filepath)
	{
		auto res = read_file(filepath);

		if (!res)
			return {};

		String src(res.unwrap());
		auto line_lengths = get_line_lengths(src);

		return File(String(filepath), std::move(src), std::move(line_lengths));
	}

	File File::from(const char *name, const char *text)
	{
		assert(name != nullptr);
		assert(text != nullptr);
		
		String source(text);
		auto line_lengths = get_line_lengths(source);

		return File(String(name), std::move(source), std::move(line_lengths));
	}

	usize File::get_line(usize pos) const
	{
		usize line = 0;

		for (const auto& length : _line_lengths)
		{
			if (pos >= length)
			{
				line += 1;
				pos -= length;
			}
		}

		return line;
	}
	
	usize File::get_col(const usize start_pos) const
	{
		usize pos = start_pos;

		while (true)
		{
			if (pos == 0 || _src[pos - 1] == '\n')
				break;

			pos -= 1;
		}

		return start_pos - pos;
	}

	String File::get_text(usize pos, usize length) const
	{		
		assert(pos + length < _src.size());

		return String(&_src[pos], length);
	}
}