section .data
    hello_message db "Hello, Holberton", 10, 0 ; "Hello, Holberton" followed by a new line character (10) and a null terminator (0)
    format db "%s", 0

section .text
    extern printf

global main
main:
    ; Prepare the arguments for printf
    mov rdi, format   ; First argument: format string
    mov rsi, hello_message ; Second argument: address of the hello_message string
    xor rax, rax     ; Clear RAX register (set to 0) to indicate no floating-point arguments
    call printf

    ; Exit the program
    mov rax, 60      ; syscall number for exit
    xor rdi, rdi     ; status = 0
    syscall

