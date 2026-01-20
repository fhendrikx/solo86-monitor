ENTRY(start)
OUTPUT_FORMAT(binary)

SECTIONS {
    .text : {
        *(.start);

        . = ALIGN(4);

        *(.text);
        *(.text.*);

        . = ALIGN(4);

        rodata_start = . ;
        *(.rodata*);
        rodata_end = . ;
    }

    .data : {
        data_start = . ;
        *(.data*);
        data_end = . ;

        . = ALIGN(4);

        bss_start = . ;
        *(.bss*);
        *(COMMON);
        bss_end = . ;
    }

    _end = . ;

    /DISCARD/ : {
        *(.comment);
        *(.eh_frame);
        *(.note*);
    }
}
