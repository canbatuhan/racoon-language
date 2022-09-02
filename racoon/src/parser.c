#include <stdio.h>
#include "include/parser.h"

num_node init_num_node(token token) {
    num_node new_num_node;
    new_num_node.token = token;
    return new_num_node;
}

bin_op_node init_bin_op_node(num_node left, token operator, num_node right) {
    bin_op_node new_bin_op_node;
    new_bin_op_node.left_node = left;
    new_bin_op_node.operator_token = operator;
    new_bin_op_node.right_node = right;
    return new_bin_op_node;
}

parser init_parser(token* tokens) {
    parser new_parser;
    new_parser.tokens = tokens;
    new_parser.token_idx = 0;
}

void move_to_next_token(parser* parser_ptr) {
    parser_ptr->token_idx++;
    //...
}