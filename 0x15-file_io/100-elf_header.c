#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <stdlib.h>

void print_error(const char *message)
{
	fprintf(stderr, "Error: %s\n", message);
	exit(98);
}

void print_elf_header_info(Elf64_Ehdr *elf_header)
{
	printf("Magic: %02x %02x %02x %02x\n",
	       elf_header->e_ident[EI_MAG0],
	       elf_header->e_ident[EI_MAG1],
	       elf_header->e_ident[EI_MAG2],
	       elf_header->e_ident[EI_MAG3]);

	printf("Class: %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");

	printf("Data: %s\n", elf_header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" : "2's complement, big endian");

	printf("Version: %d\n", elf_header->e_ident[EI_VERSION]);

	printf("OS/ABI: %s\n", elf_header->e_ident[EI_OSABI] == ELFOSABI_SYSV ? "UNIX - System V" : "Others");

	printf("ABI Version: %d\n", elf_header->e_ident[EI_ABIVERSION]);

	printf("Type: 0x%x\n", elf_header->e_type);

	printf("Entry point address: 0x%lx\n", (unsigned long)elf_header->e_entry);

	printf("Format: %s\n", elf_header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "ELF32");
}

int main(int argc, char *argv[])
{
	const char *filename;
	int fd;
	Elf64_Ehdr elf_header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Failed to open the file.");

	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
		print_error("Failed to read ELF header.");

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
	    elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	    elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	    elf_header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file.");

	print_elf_header_info(&elf_header);

	close(fd);
	return (0);
}

