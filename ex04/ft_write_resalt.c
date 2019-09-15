void ft_putchar(char c);

void ft_write_resalt(int argc, char* argv[])
{
    for(int line_print = 1; line_print < argc; line_print++)
    {
        for(int tmp_int = 0; argv[line_print][tmp_int] != 0; tmp_int++)
            ft_putchar(argv[line_print][tmp_int]);

        ft_putchar('\n');
    }
}