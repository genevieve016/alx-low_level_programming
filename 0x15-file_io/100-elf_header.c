#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_info(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - checks if a file is an ELF file
 * @e_ident: pointer to an array containing the ELF magic numbers
 *
 * desc: If the file is not an ELF file - exit code 98
 */

void check_elf(unsigned char *e_ident)
{
        int index;

        for (index = 0; index < 4; index++)
        {
                if (e_ident[index] != 127 &&
                    e_ident[index] != 'E' &&
                    e_ident[index] != 'L' &&
                    e_ident[index] != 'F')
                {
                        dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
                        exit(98);
                }
        }
}

/**
 * print_info - prints the header information of an ELF file
 * @e_ident: pointer to an array containing the ELF magic numbers
 *
 * desc: prints the magic number, class, data encoding, version, OS/ABI,
 *       ABI version and type of an ELF file
 */

void print_info(unsigned char *e_ident)
{
        printf("ELF Header:\n");
        print_magic(e_ident);
        print_class(e_ident);
        print_data(e_ident);
        print_version(e_ident);
        print_abi(e_ident);
        print_osabi(e_ident);
        printf(" Type:                               ");
        print_type(ET_EXEC, e_ident);
        printf(" Entry point address:                 ");
        print_entry(0, e_ident);
}

/**
 * print_type - prints the type of an ELF header
 * @e_type: type of ELF
 * @e_ident: pointer to an array containing the ELF class
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
        if (e_ident[EI_DATA] == ELFDATA2MSB)
                e_type = ((e_type >> 8) & 0xFF) | ((e_type << 8) & 0xFF00);

        switch (e_type)
        {
        case ET_NONE:
                printf("NONE (No file type)\n");
                break;
        case ET_REL:
                printf("REL (Relocatable file)\n");
                break;
        case ET_EXEC:
                printf("EXEC (Executable file)\n");
                break;
        case ET_DYN:
                printf("DYN (Shared object file)\n");
                break;
        case ET_CORE:
                printf("CORE (Core file)\n");
                break;
        default:
                printf("<unknown: %x>\n", e_type);
        }
}

/**
 * print_entry - prints the entry point address of an ELF header
 * @e_entry: entry point address
 * @e_ident: pointer to an array containing the ELF class
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf(" Entry point address: 0x%x\n",
	(unsigned int)e_entry);
	else if (e_ident[EI_CLASS] == ELFCLASS64)
		printf(" Entry point address: 0x%lx\n", e_entry);
	else
		printf(" Entry point address: <unknown>\n");
}

/**

close_elf - closes an ELF file descriptor
@elf: ELF file descriptor
desc: If there's an error with closing the file, exit code 100
*/
void close_elf(int elf)
{
if (close(elf) == -1)
{
dprintf(STDERR_FILENO, "Error: Cannot close ELF file descriptor\n");
exit(100);
}
}

int main(int argc, char **argv)
{
int elf, count;
unsigned char e_ident[EI_NIDENT];
Elf32_Ehdr e_hdr32;
Elf64_Ehdr e_hdr64;
    if (argc != 2)
    {
            dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
            exit(97);
    }

    elf = open(argv[1], O_RDONLY);

    if (elf == -1)
    {
            dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
            exit(98);
    }

    count = read(elf, e_ident, EI_NIDENT);

    if (count == -1)
    {
            dprintf(STDERR_FILENO, "Error: Cannot read file %s\n", argv[1]);
            exit(98);
    }

    check_elf(e_ident);

    lseek(elf, (off_t)0, SEEK_SET);

    count = read(elf, &e_hdr32, sizeof(e_hdr32));

    if (count != sizeof(e_hdr32))
    {
            close_elf(elf);
            dprintf(STDERR_FILENO, "Error: Invalid ELF header size\n");
            exit(98);
    }

    if (e_hdr32.e_ident[EI_CLASS] == ELFCLASS32)
    {
            print_magic(e_hdr32.e_ident);
            print_class(e_hdr32.e_ident);
            print_data(e_hdr32.e_ident);
            print_version(e_hdr32.e_ident);
            print_osabi(e_hdr32.e_ident);
            print_abi(e_hdr32.e_ident);
            print_type(e_hdr32.e_type, e_hdr32.e_ident);
            print_entry(e_hdr32.e_entry, e_hdr32.e_ident);
    }
    else if (e_hdr32.e_ident[EI_CLASS] == ELFCLASS64)
    {
            lseek(elf, (off_t)0, SEEK_SET);

            count = read(elf, &e_hdr64, sizeof(e_hdr64));

            if (count != sizeof(e_hdr64))
            {
                    close_elf(elf);
                    dprintf(STDERR_FILENO, "Error: Invalid ELF header size\n");
                    exit(98);
            }

            print_magic(e_hdr64.e_ident);
            print_class(e_hdr64.e_ident);
            print_data(e_hdr64.e_ident);
            print_version(e_hdr64.e_ident);
            print_osabi(e_hdr64.e_ident);
            print_abi(e_hdr64.e_ident);
            print_type(e_hdr64.e_type, e_hdr64.e_ident);
            print_entry(e_hdr64.e_entry, e_hdr64.e_ident);
    }
        free(header);
        close_elf(o);
        return (0);
