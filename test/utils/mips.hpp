#ifndef mips_hpp
#define mu0_hpp

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <map>
#include <utility>
#include <iomanip>
#include <bitset>
#include <fstream>

using namespace std;

// Assembly

// Returns true if the s is a valid MIPS instruction OPCODE
bool mips_is_instruction(const string &s);

// Return true if the s is a valid label declaration
bool mips_is_label_decl(const string &s);

// Return true if the s represents data ( a decimal integer constant)
bool mips_is_data(const string &s);

// Returns r, i, j depending on the instruction 's' argument in the function
char mips_instruction_type(const string &s);

// Returns corresponding opcode of MIPS assembly instruction 's'
uint16_t mips_instr_to_opcode(const string &s);

// Returns corresponding function code of a r-type MIPS instruction 's'
uint16_t mips_r_instr_to_fncode(const string &s);

// Returns the hex string of uint16_t 'x'
string to_hex8(uint32_t x);

string to_hex1(unsigned char x);

// Returns a vector words in sentence 's'
vector<string> string_break(string s);

// Returns a pair of opname and operands from a word 'w'
pair<string, string> sep_word (string s);

// Returns a vector of words seperated by comas 's'
vector<string> opr_break(string s);

// Returns a pair of strings 'rs' and 'offset' from a string in the form of 'offset(rs)'
pair<string, string> addr_break(string s);

// Returns true if instruction 's' is a memory access instruction
bool mips_is_mem_acc_instr(const string &s);

// Output_Filter

// returns the output line broken down with colon :
pair<string, string> get_address (string s);


#endif
