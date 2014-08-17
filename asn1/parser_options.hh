#ifndef __ASN1_PARSER_OPTIONS_HH
#define __ASN1_PARSER_OPTIONS_HH

#include "asn1/data.hh"

namespace asn1 {

/**
 * Form of ASN.1 encoding.
 */
enum Encoding {
    BER,
    DER
};

/**
 * Parser options structure; used in order to make passing options to the
 * nested parsers easier.
 */
struct ParserOptions {
    /**
     * Encoding type (DER or BER).
     */
    Encoding encoding;

    /**
     * Enable or disable UTF-8 string validation.  It is enabled by default,
     * but some certificates in the wild which we might want to parse contain
     * invalid UTF-8.
     */
    bool validate_utf8 = true;

    /**
     * T.61 is the defined format for TeletexString; however, in reality most
     * consumers of X.509 certificates treat it as Latin-1.
     */
    bool treat_teletex_as_latin1 = false;
};

}

#endif  /* __ASN1_PARSER_OPTIONS_HH */
