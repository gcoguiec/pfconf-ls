#include <stdio.h>
#include <ctype.h>

#include "tree_sitter/parser.h"

// enum TokenType {
// };

// static void advance(TSLexer *lexer) { lexer->advance(lexer, false); }

void *tree_sitter_pfconf_external_scanner_create() {
    return NULL;
}

void tree_sitter_pfconf_external_scanner_destroy(void *p) {}

void tree_sitter_pfconf_external_scanner_reset(void *p) {}

unsigned tree_sitter_pfconf_external_scanner_serialize(void *p, char *buffer) {
    return 0;
}

void tree_sitter_pfconf_external_scanner_deserialize(
    void *p,
    const char *b,
    unsigned n
) {}

bool tree_sitter_pfconf_external_scanner_scan(
    void *payload,
    TSLexer *lexer,
    const bool *valid_symbols
) {
    return false;
}
