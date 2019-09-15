void ft_write_resalt(int argc, char* argv[]);
char** ft_sort_params(int argc, char* argv[]);

int main(int argc, char* argv[])
{
    ft_write_resalt(argc, ft_sort_params(argc, argv));
    return 0;
}