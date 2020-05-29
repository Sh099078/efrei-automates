#pragma once

#include "automaton.hh"

bool is_determinist(Automaton);

Automaton determinize(Automaton);
