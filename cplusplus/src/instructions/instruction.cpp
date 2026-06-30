// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "enums/instructions.hpp"
#include "instructions/instruction.hpp"
#include "instructions/instruction_sh2.hpp"

// SYSTEM INCLUDES

#include <cstring>
#include <cstdlib>

using namespace catherine;

// THE FOLLOWING CONSTRUCTOR HELPS WITH A SPECIFIC OP
// FOCUSSES ON ACCESSING THE CURRENT WORD AND PC ADDRESS FOR EACH
//
// ALWAYS USE &this FOR ACCESSING THE REFERENCE ASSOCIATED WITH THE CLASS
CATH_INSTRUCTION_SH2::CATH_INSTRUCTION_SH2(U16 WORD, U32 PC) : CATH_INSTRUCTION() 
{
    std::memset(&this->INSTR, 0, sizeof(SH_INSTRUCTION));
    CATH_INSTRUCTION_INIT(&this->INSTR, WORD, PC);
    CATH_INSTRUCTION_PROCESS(&this->INSTR);
}

// NOW WE CAN FOCUS ON THE IMPLEMENTATION OF MAKING C++ WRAPPERS
// FOR THE C API LOGIC 

std::string CATH_INSTRUCTION::CATH_DISASSEMBLE_OPERANDS() const
{
    UNK SIZE = CATH_INSTRUCTION_DISASM_OPERAND(&this->INSTR, nullptr);
    std::string RESULT(SIZE + 1, '\0');

    CATH_INSTRUCTION_DISASM_OPERAND(&this->INSTR, RESULT.data());
    return RESULT;
}

std::string CATH_INSTRUCTION::CATH_DISASSEMBLE_INSTR() const
{
    UNK SIZE = CATH_INSTRUCTION_GET_SIZE(&this->INSTR);
    std::string RESULT(SIZE, '\0');

    CATH_INSTRUCTION_DISASM_INSTR(&this->INSTR, RESULT.data());

    return RESULT;
}

std::string CATH_INSTRUCTION::CATH_DISASSEMBLE() const
{
    UNK SIZE = CATH_INSTRUCTION_GET_SIZE(&this->INSTR);
    std::string RESULT(SIZE + 1, '\0');

    CATH_INSTRUCTION_DISASM(&this->INSTR, RESULT.data());
    return RESULT;
}
