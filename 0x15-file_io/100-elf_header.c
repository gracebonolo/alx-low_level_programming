#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void print_error(char *msg, int status)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(status);
}

void print_elf_header_info(Elf64_Ehdr *header)
{
	printf("  Magic:   ");
	for (int i = 0; i < EI_NIDENT; ++i)
		printf("%02x ", header->e_ident[i]);
	printf("\n");

	printf("  Class:                             %s\n", header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
	printf("  Data:                              %s\n", header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");
	printf("  Version:                           %d (current)\n", header->e_ident[EI_VERSION]);
	printf("  OS/ABI:                            %d\n", header->e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);

	printf("  Type:                              %d\n", header->e_type);
	printf("  Entry point address:               %llx\n", (unsigned long long)header->e_entry);
	printf("  Start of program headers:          %lld (bytes into file)\n", (long long)header->e_phoff);
	printf("  Start of section headers:          %lld (bytes into file)\n", (long long)header->e_shoff);
	printf("  Flags:                             %x\n", header->e_flags);
	printf("  Size of this header:               %d (bytes)\n", header->e_ehsize);
	printf("  Size of program headers:           %d (bytes)\n", header->e_phentsize);
	printf("  Number of program headers:         %d\n", header->e_phnum);
	printf("  Size of section headers:           %d (bytes)\n", header->e_shentsize);
	printf("  Number of section headers:         %d\n", header->e_shnum);
	printf("  Section header string table index: %d\n", header->e_shstrndx);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		print_error("Usage: elf_header elf_filename", 98);

	int fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Could not open file", 98);

	Elf64_Ehdr header;
	ssize_t read_result = read(fd, &header, sizeof(header));
	if (read_result == -1)
		print_error("Error: Could not read from file", 98);

	if (read_result != sizeof(header) || header.e_ident[EI_MAG0] != ELFMAG0 || header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 || header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Error: Not an ELF file", 98);

	print_elf_header_info(&header);

	close(fd);

	return (0);
}

