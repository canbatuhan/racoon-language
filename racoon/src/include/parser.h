#include <stdio.h>
#include "token.h"

#ifndef PARSER_H
#define PARSER_H

typedef struct num_node {
    token token;
} num_node;

num_node init_num_node(token);


typedef struct bin_op_node {
    token left_node;
    token operator_node;
    token right_node;
} bin_op_node;

bin_op_node init_bin_op_node(token, token, token);

typedef struct parser {
    token* tokens;
    int token_idx;
} parser;

parser init_parser(token*, int);
void move_to_next_node(parser*);
num_node factor(parser*);
bin_op_node term(parser*);
bin_op_node expression(parser*);

#endif