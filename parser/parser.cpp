#include "parser.h"
#include <fstream>
#include <iostream>

using namespace parser;

FileParser::FileParser(const string* propertyName) : readValues()
{
	fstream fs;
	string l;
	
	fs.open(propertyName->c_str(), fstream::in);	
	if (!fs.good())
	{
		cerr << *propertyName << " file does not exist\n";
		return;
	}
	
	getline(fs, l);
	while (l.size() > 0)
	{

		size_t a(l.find('='));	
		if (a == string::npos)
			continue;

		readValues.push_back(l.substr(0, a));
		readValues.push_back(l.substr(a+1, l.size()));

		getline(fs, l);
	}
	fs.close();

}

string FileParser::getValue(const string* target) const
{
	string s(*target);
	for (unsigned int a = 0; a < readValues.size(); a = a + 2)
	{
		if (s == readValues[a])
		{
			return readValues[a+1];
		}
	}
	s = "Not Found";
	return s;
}

string FileParser::getValue(const char* c, int size) const
{
	string s(c, size);
	return getValue(&s);
}
