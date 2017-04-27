#include "globalsettings.h"
#include "globaldefines.h"
#include "parser/parser.h"

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

GlobalSettings::GlobalSettings()
{

}

GlobalSettings::GlobalSettings(parser::FileParser* parser)
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
}
