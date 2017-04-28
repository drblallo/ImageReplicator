#include "globalsettings.h"
#include "globaldefines.h"
#include "parser/parser.h"
#include <iostream>

GlobalSettings* GlobalSettings::settings(NULL);

GlobalSettings* GlobalSettings::getSettings()
{
	if (!settings)
	{
		string s(PARSER_FILE);
		string d(DEFAULT_FILE);
		parser::FileParser parser(&s, &d);
		settings = new GlobalSettings(&parser);
		
	}
	return settings;
}

GlobalSettings::GlobalSettings() :
		treshHold(40),
		scala(2),
		dropped(1),
		depth(0.4f),
		generatorion_divisor(1000),
		red_clear(0.0f),
		green_clear(0.02f),
		blue_clear(0.05f),
		alpha_clear(0.0f),
		black_and_white(0),
		blot_quantity(10),
		blot_scale_x(50),
		blot_scale_y(50),
		blot_enabled(1),
		file_name("image.jpg")
{

}

GlobalSettings::GlobalSettings(parser::FileParser* parser)
{
	try
	{
		string t(FILE_NAME);
		file_name = parser->getValue(&t);		
		
		t = TRESH_STRING;
		treshHold = std::stoi(parser->getValue(&t));	

		t = SCALA_STRING;
		scala = std::stoi(parser->getValue(&t));

		t = DROPPED_STRING;
		dropped = std::stoi(parser->getValue(&t));
		
		t = DEPTH_STRING;
		depth = std::stof(parser->getValue(&t));

		t = GENERATION_DIVISOR_STRING;
		generatorion_divisor = std::stoi(parser->getValue(&t));

		t = RED_CLEAR_STRING;
		red_clear = std::stof(parser->getValue(&t));

		t = GREEN_CLEAR_STRING;
		green_clear = std::stof(parser->getValue(&t));

		t = BLUE_CLEAR_STRING;
		blue_clear = std::stof(parser->getValue(&t));

		t = ALPHA_CLEAR_STRING;
		alpha_clear = std::stof(parser->getValue(&t));

		t = BLACK_AND_WHITE_STRING;
		black_and_white = std::stof(parser->getValue(&t));

		t = BLOT_QUANTITY_STRING;
		blot_quantity = std::stoi(parser->getValue(&t));

		t = BLOT_ENABLE_STRING;
		blot_enabled = std::stoi(parser->getValue(&t));

		t = BLOT_SCALE_X_STRING;
		blot_scale_x = std::stof(parser->getValue(&t));

		t = BLOT_SCALE_Y_STRING;
		blot_scale_y = std::stof(parser->getValue(&t));
	}
	catch(std::exception)
	{
		std::cerr << "setting file malformated, using default setting" << std::endl;
	}
}
