#include "parser.h"
#include <fstream>
#include <iostream>

using namespace parser;

void createFile(const string* propertyName, const string* defaultFile)
{
	ofstream file(propertyName->c_str());
	if (!file)
		return;

	file << *defaultFile << std::endl;
	file.close();
}

FileParser::FileParser(const string* propertyName, const string* defaultFile) : readValues()
{
	fstream fs;
	fstream f2;
	string l;
	fstream* p(&fs);
	
	fs.open(propertyName->c_str(), fstream::in);	
	if (!fs.good())
	{
		fs.close();
		cerr << *propertyName << " file does not exist\n";
		createFile(propertyName, defaultFile);

		f2.open(propertyName->c_str(), fstream::in);
		if (!f2.good())
		{
			cerr << "and could not be created\n";
			return;
		}
		p = &f2;
	}
	
	getline(*p, l);
	while (l.size() > 0)
	{

		size_t a(l.find('='));	
		if (a == string::npos)
			continue;

		readValues.push_back(l.substr(0, a));
		readValues.push_back(l.substr(a+1, l.size()));

		getline(*p, l);
	}
	p->close();

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
