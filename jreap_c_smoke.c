#include <stdio.h>

#include "milstd3011/jreaplib_c.h"

int main(void)
{
    const char* csv = "49,1,0,17,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0";

    const char* decoded = jreap_decode_application_message_csv(csv, 0);
    if (decoded == NULL)
    {
        fprintf(stderr, "decode failed: null output\n");
        return 1;
    }

    puts(decoded);
    jreap_free_string(decoded);
    return 0;
}
