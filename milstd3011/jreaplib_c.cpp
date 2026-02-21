#include "jreaplib_c.h"

#include "jreaplib.h"

#include <cstdlib>
#include <cstring>
#include <new>
#include <string>

namespace {

const char* DuplicateCString(const std::string& value)
{
    char* buffer = static_cast<char*>(std::malloc(value.size() + 1));
    if (buffer == nullptr)
    {
        return nullptr;
    }

    std::memcpy(buffer, value.c_str(), value.size() + 1);
    return buffer;
}

}

extern "C" const char* jreap_decode_application_message_csv(const char* csv_bytes, int strict_abml)
{
    try
    {
        const std::string input = (csv_bytes == nullptr) ? std::string() : std::string(csv_bytes);
        const std::string output = jreap::DecodeApplicationMessageCsv(input, strict_abml != 0);
        return DuplicateCString(output);
    }
    catch (const std::bad_alloc&)
    {
        return nullptr;
    }
    catch (...)
    {
        return DuplicateCString("jreaplib error: decode failed");
    }
}

extern "C" void jreap_free_string(const char* value)
{
    std::free(const_cast<char*>(value));
}
