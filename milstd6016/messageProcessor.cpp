#include "messageProcessorValueMeaning.h"

#include <sstream>

#include "messageLibrary.h"

namespace milstd6016 {

namespace {

std::string FormatValueMeaning(const ValueMeaning& value)
{
	std::ostringstream builder;
	builder << "DFI " << value.dfi << ", DUI " << value.dui;
	if (!value.duiName.empty())
	{
		builder << " (" << value.duiName << ")";
	}
	builder << '\n';
	builder << "BIT_CODE: " << value.bitCode << '\n';
	builder << "DATA_ITEM: " << value.dataItem;
	if (!value.applicability.empty())
	{
		builder << '\n' << "APPLICABILITY: " << value.applicability;
	}
	if (!value.explanation.empty())
	{
		builder << '\n' << "EXPLANATION: " << value.explanation;
	}
	return builder.str();
}

}

std::string DescribeValueMeaning(int dfi, int dui, const std::string& bitCode, bool resolveRanges)
{
	ValueMeaning value;
	const bool found = resolveRanges
		? TryResolveValueMeaning(dfi, dui, bitCode, value)
		: TryGetValueMeaning(dfi, dui, bitCode, value);

	if (!found)
	{
		std::ostringstream builder;
		builder << "No MIL-STD-6016 value meaning found for DFI " << dfi
				<< ", DUI " << dui
				<< ", BIT_CODE '" << bitCode << "'.";

		const std::string sourcePath = GetCatalogSourcePath();
		if (sourcePath.empty())
		{
			builder << " Catalog file was not found.";
		}
		return builder.str();
	}

	return FormatValueMeaning(value);
}

std::string DescribeAllValueMeanings(int dfi, int dui)
{
	const std::vector<ValueMeaning> values = GetValueMeanings(dfi, dui);
	if (values.empty())
	{
		std::ostringstream builder;
		builder << "No MIL-STD-6016 entries found for DFI " << dfi << ", DUI " << dui << ".";
		const std::string sourcePath = GetCatalogSourcePath();
		if (sourcePath.empty())
		{
			builder << " Catalog file was not found.";
		}
		return builder.str();
	}

	std::ostringstream builder;
	for (std::size_t index = 0; index < values.size(); ++index)
	{
		if (index != 0)
		{
			builder << "\n\n";
		}
		builder << FormatValueMeaning(values[index]);
	}

	return builder.str();
}

}
