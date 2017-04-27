#pragma once
#include <string>
#include <vector>

using namespace std;
namespace parser
{
	class FileParser
	{
		public:
			FileParser(const string* propertyName, const string* defaultFile);
			string getValue(const string* target) const;
			string getValue(const char* c, int size) const;

		private:
			vector<string> readValues;
			

	};

}
