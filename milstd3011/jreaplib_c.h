#ifndef JREAPLIB_C_H_
#define JREAPLIB_C_H_

#ifdef __cplusplus
extern "C" {
#endif

const char* jreap_decode_application_message_csv(const char* csv_bytes, int strict_abml);

void jreap_free_string(const char* value);

#ifdef __cplusplus
}
#endif

#endif
