#ifndef MILSTD6016_MESSAGELIBRARY_H_
#define MILSTD6016_MESSAGELIBRARY_H_

#include <string>
#include <vector>

namespace milstd6016 {

struct DfiDuiCombo
{
	int dfi = 0;
	int dui = 0;
	std::string duiName;
};

struct ValueMeaning
{
	int dfi = 0;
	int dui = 0;
	std::string duiName;
	std::string bitCode;
	std::string dataItem;
	std::string explanation;
	std::string applicability;
};

std::vector<DfiDuiCombo> GetDfiDuiCombos();

std::vector<ValueMeaning> GetValueMeanings(int dfi, int dui);

bool TryGetValueMeaning(int dfi, int dui, const std::string& bitCode, ValueMeaning& result);

bool TryResolveValueMeaning(int dfi, int dui, const std::string& bitCode, ValueMeaning& result);

std::string GetCatalogSourcePath();

}

#endif
