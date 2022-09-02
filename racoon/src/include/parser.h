#include <stdio.h>
#include "token.h"

#ifndef PARSER_H
#define PARSER_H

typedef struct num_node {
    token token;
} num_node;

num_node init_num_node(token);

typedef struct bin_op_node {
    num_node left_node;
    token operator_token;
    num_node right_node;
} bin_op_node;

bin_op_node init_bin_op_node(num_node, token, num_node);

typedef struct parser {
    token* tokens;
    int token_idx;
} parser;

parser init_parser(token*);
void move_to_next_token(parser*);
num_node factor(parser*);
bin_op_node term(parser*);
bin_op_node expression(parser*);

#endif