#pragma once

#include "automaton.hh"

bool is_determinist(const Automaton&);

Automaton determinize(const Automaton&);
