OUTPUT_ARCH( "riscv" )

ENTRY( _start )

MEMORY
{
  flash (rxai!w) : ORIGIN = 0x80, LENGTH = 1M
}

_start = 0x80;

PHDRS
{
  flash PT_LOAD;
  ram_init PT_LOAD;
  ram PT_NULL;
}

SECTIONS
{
  .text           :
  {
    *(.text .text.*)
  } >flash AT>flash :flash

}
