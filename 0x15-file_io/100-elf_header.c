#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool is_elf(const unsigned char *e_ident);
void check_elf(unsigned char *e_ident);
void check_magic(unsigned char *e_ident);
void check_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
*is_elf - a C function that checks if a file is an ELF file.
*@e_ident: pointer to an array containing ELF magic numbers.
*
* Return: 0,1,2 or 3
**/

bool is_elf(const unsigned char *e_ident)
{
	return (e_ident[0] == 0x7f && e_ident[1] == 'E' &&
			e_ident[2] == 'L' && e_ident[3] == 'F');
}

/**
*check_elf - a C function that prints error message if a file is an ELF file.
*@e_ident: pointer to an array containing ELF magic numbers.
*Description: This function checks if the given file is an ELF file by
*verifying if its magic numbers are correct. If the file is not an ELF file,
*the function prints an error message to the standard error output and exits
*the program with a status code of 98.
**/

void check_elf(unsigned char *e_ident)
{
	if (!is_elf(e_ident))
	{
		dprintf(STDERR_FILENO, "Error: This is not an ELF file\n");
		exit(98);
	}
}



/**
 * check_magic - a C function that prints magic numbers of an ELF header
 * @e_ident: pointer to array containing ELF magic numbers
 *
 * Return: magic number
 **/

void check_magic(unsigned char *e_ident)
{
	int index = 0;

	printf("  Magic:   ");
	while (index < EI_NIDENT)
	{
		printf("%02x", e_ident[index]);
		if (index == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
		index++;
	}
}


/**
 * check_class - a C function that prints class of ELF header
 * @e_ident: pointer to array containing ELF class
 *
 * Return: class
 **/

void check_class(unsigned char *e_ident)
{
	const char *class_str;
	unsigned char class = e_ident[EI_CLASS];

	switch (class)
	{
		case ELFCLASSNONE:
			class_str = "none";
			break;
		case ELFCLASS32:
			class_str = "ELF32";
			break;
		case ELFCLASS64:
			class_str = "ELF64";
			break;
		default:
			printf("<unknown: %x>\n", class);
			return;
	}

	printf("  Class:                             %s\n", class_str);
}


/**
 * print_data - a C function that prints data of ELF header.
 * @e_ident: pointer to array of ELF class.
 *
 * Return: data
 **/

void print_data(unsigned char *e_ident)
{
	const char *data_str;
	unsigned char data = e_ident[EI_DATA];

	switch (data)
	{
		case ELFDATANONE:
			data_str = "none";
			break;
		case ELFDATA2LSB:
			data_str = "2's complement, little endian";
			break;
		case ELFDATA2MSB:
			data_str = "2's complement, big endian";
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_DATA]);
			return;
	}

	printf("  Data:                              %s\n", data_str);
}


/**
 * print_version - a C function that prints version of ELF header
 * @e_ident: pointer to array containing ELF version.
 *
 * Return: version
 **/

void print_version(unsigned char *e_ident)
{
	int version = e_ident[EI_VERSION];

	printf("  Version:                           %d", version);

	switch (version)
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}


/**
 * print_osabi - a c function that print the OSABI of ELF header
 * @e_ident: pointer to array containing ELF version
 *
 * Return: osabi
 **/

void print_osabi(unsigned char *e_ident)
{
	int osabi = e_ident[EI_OSABI];

	printf("  OS/ABI:                            ");

	switch (osabi)
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", osabi);
			break;
	}
}


/**
 * print_abi_ver - a C function that prints ABI version of ELF header
 * @e_ident: pointer to array of ELF ABI version
 *
 * Return: ABI version
 **/

void print_abi_ver(unsigned char *e_ident)
{
	unsigned char abi_ver = e_ident[EI_ABIVERSION];

	printf("  ABI Version:                       %d\n", abi_ver);
}


/**
 * print_elf_type - a C function that print ELF header type
 * @e_type: elf type
 * @e_ident: pointer to array of ELF class
 *
 * Return: Type
 **/

void print_elf_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}

	printf("  Type:                              ");

	if (e_type == ET_NONE)
	{
		printf("NONE (None)\n");
	}
	else if (e_type == ET_REL)
	{
		printf("REL (Relocatable file)\n");
	}
	else if (e_type == ET_EXEC)
	{
		printf("EXEC (Executable file)\n");
	}
	else if (e_type == ET_DYN)
	{
		printf("DYN (Shared object file)\n");
	}
	else if (e_type == ET_CORE)
	{
		printf("CORE (Core file)\n");
	}
	else
	{
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}


/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}


/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	check_magic(header->e_ident);
	check_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi_ver(header->e_ident);
	print_elf_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}

