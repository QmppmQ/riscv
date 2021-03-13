// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vtop__Syms.h"
#include "Vtop.h"
#include "Vtop_top.h"
#include "Vtop_ram__A14.h"
#include "Vtop___024unit.h"
#include "Vtop_dp_ram__A14.h"

// FUNCTIONS
Vtop__Syms::Vtop__Syms(Vtop* topp, const char* namep)
	// Setup locals
	: __Vm_namep(namep)
	, __Vm_activity(false)
	, __Vm_didInit(false)
	// Setup submodule names
	, TOP__top                       (Verilated::catName(topp->name(),"top"))
	, TOP__top__ram_i                (Verilated::catName(topp->name(),"top.ram_i"))
	, TOP__top__ram_i__dp_ram_i      (Verilated::catName(topp->name(),"top.ram_i.dp_ram_i"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->top                       = &TOP__top;
    TOPp->top->ram_i                = &TOP__top__ram_i;
    TOPp->top->ram_i->dp_ram_i      = &TOP__top__ram_i__dp_ram_i;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__top.__Vconfigure(this, true);
    TOP__top__ram_i.__Vconfigure(this, true);
    TOP__top__ram_i__dp_ram_i.__Vconfigure(this, true);
    // Setup export functions
    for (int __Vfinal=0; __Vfinal<2; __Vfinal++) {
    }
}
