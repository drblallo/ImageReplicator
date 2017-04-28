#pragma once
#include <string>

namespace parser
{
	class FileParser;
}
class GlobalSettings
{
	public:
		static GlobalSettings* getSettings();
		int treshHold;
		int scala;
		int dropped;
		float depth;
		int generatorion_divisor;
		float red_clear;
		float green_clear;
		float blue_clear;
		float alpha_clear;
		int black_and_white;
		int blot_quantity;
		float blot_scale_x;
		float blot_scale_y;
		int blot_enabled;
		std::string file_name;

	private:
		GlobalSettings();
		GlobalSettings(parser::FileParser* parser);
		static GlobalSettings* settings;

};
