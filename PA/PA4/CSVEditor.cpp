#include "CSVEditor.hpp"

CSVEditor::CSVEditor(string &inputPath, string &rosterPath, string &outputPath, regex expr, int m)
{
	input.open(inputPath);
	roster.open(rosterPath);
	output.open(outputPath);
	regexPattern = expr;
	if (m == 0) 
	{	
		string line;
		while (getline(roster, line))
			++m;
	}
	hashTable = new HashTable<string>(m);
}

CSVEditor::~CSVEditor()
{
	delete hashTable;
}

void CSVEditor::readCSVToTable()
{
	string line;
	smatch match;
	while (getline(input, line))
	{
		regex_search(line, match, regexPattern);
		hashTable->insert(stoi(match.str(1)), match.str(2));
	}
	hashTable->showHash();
}

void CSVEditor::writeCSVToFile()
{
	string line;
	smatch match;
	while (getline(roster, line))
	{
		regex_search(line, match, regexPattern);
		string *search_result = hashTable->search(stoi(match.str(1)));
		line.erase(line.size() - 1);
		if (search_result != nullptr)
			output << line << *search_result << endl;
		else
			output << line << endl;
	}
	output.close();
}

std::tuple<int, int, double> CSVEditor::getStats()
{
	return std::make_tuple(hashTable->minChainLen(), hashTable->maxChainLen(), hashTable->averageChainLen());
}