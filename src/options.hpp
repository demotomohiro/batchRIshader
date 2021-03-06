#pragma once

#include <string>
#include "gl_common.hpp"

struct render_info
{
	GLsizei output_w;
	GLsizei output_h;
	GLsizei num_tile_x;
	GLsizei num_tile_y;
	GLsizei super_sampling_level;

	render_info::render_info():
		output_w(1280),	output_h(720),
		num_tile_x(4),	num_tile_y(4),
		super_sampling_level(3)
	{
	}

	GLsizei get_super_sampling_width() const
	{
		assert(super_sampling_level < 31);

		return 1 << super_sampling_level;
	}

	GLsizei get_tile_width() const
	{
		assert(output_w % num_tile_x == 0);

		return output_w / num_tile_x;
	}

	GLsizei get_tile_height() const
	{
		assert(output_h % num_tile_y == 0);

		return output_h / num_tile_y;
	}

	GLsizei get_draw_w() const
	{
		return get_tile_width() * get_super_sampling_width();
	}

	GLsizei get_draw_h() const
	{
		return get_tile_height() * get_super_sampling_width();
	}
};

struct options
{
	options(int argc, char* argv[]);

	bool		is_render;
	int			ret_code;
	std::string	source_file;
	render_info	rinfo;
};

