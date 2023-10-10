#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Nov 10 10:11:08 2021

@author: uli

based on https://en.wikipedia.org/wiki/LL_parser#Parser_implementation_in_Python
"""

# All constants are indexed from 0
TERM = 0
RULE = 1

# Terminals
T_LPAR = 0
T_RPAR = 1
T_A = 2
T_PLUS = 3
T_END = 4
T_INVALID = 5

# Non-Terminals
N_S = 0
N_F = 1

# Parse table
#            (     )  a     +   EOF   ERR
table = [[   1, None, 0, None, None, None], # S
         [None, None, 2, None, None, None]] # F

RULES = [ \
         # 0: S to F
         [(RULE, N_F)], \
         # 1: S to ( S + F )
         [(TERM, T_LPAR), (RULE, N_S), (TERM, T_PLUS), (RULE, N_F), (TERM, T_RPAR)], \
         # 2: F to a
         [(TERM, T_A)]]

stack = [(TERM, T_END), (RULE, N_S)]

def lexical_analysis(inputstring):
    tokens = []
    for c in inputstring:
        if c   == "+": tokens.append(T_PLUS)
        elif c == "(": tokens.append(T_LPAR)
        elif c == ")": tokens.append(T_RPAR)
        elif c == "a": tokens.append(T_A)
        else:
            print(f"syntax error: unknown symbol {c}")
            return
    tokens.append(T_END)
    return tokens

def syntactic_analysis(tokens):
    position = 0
    while len(stack) > 0:
        # stack is printed right to left!
        print(f"stack: {stack[::-1]}")
        (stype, svalue) = stack.pop()
        token = tokens[position]
        if stype == TERM:
            if svalue == token:
                position += 1
                print("pop", svalue)
                if token == T_END:
                    print("input accepted")
            else:
                print(f"syntax error: bad term at token {position}: {token}")
                return
        elif stype == RULE:
            print(f"token: {token}, variable: {svalue}")
            rule = table[svalue][token]
            if rule is None:
                print(f"syntax error: no rule to parse token {token} with variable {svalue}")
                return
            print("rule", rule)
            for r in reversed(RULES[rule]):
                stack.append(r)

#inputstring = "(a+a)"
#syntactic_analysis(lexical_analysis(inputstring))

