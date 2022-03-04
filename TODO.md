# General
* Let printf return -1 if write returns NULL.
* Use the leaks program.
* Add tests for every combination of flags.
* Remove reference to bonus in filenames.
* Add comments saying what is used from includes.
* Don't initialize things to const when it can be confusing to others.
* CHECK IF THERE IS ANY ft_empty_str_assign_fail or ft_str_assign_fail CALL
  THAT HAS A FIRST ARGUMENT THAT DOESN'T START WITH A &

# Before evalling
* Fix all TODOs.
* Check that no forbidden functions are being called (search all calls using '('?)
* Run ft_printf_test on a clone (and maybe another tester?)
* UNCAPITALIZE STATIC (and remove from header)
* Run norminette on both printf and libft.

# At some later point
* Try to figure out the exact rules for multi-line variable tabbing, cause it isn't always 2!
  Then once I know how that works, consider applying those same rules to multi-line function argument tabbing.
* Consistently use && on the line *before* or *at the start of* the line of a second argument.
* Consider using *bool* to show that an error occurred, instead of ssize_t.
* Make sure all ssize_t are included from <sys/types.h>

These use malloc:
ft_char_to_str|ft_lstnew|ft_calloc|ft_split_str|ft_split|ft_substr|pft_get_char|ft_lst_new_back|ft_lst_new_front|ft_lstmap|ft_stralloc|ft_str_replace|ft_strtrim|pft_get_string|pft_parse_argument|ft_nbr_to_str|ft_unsigned_nbr_to_str|ft_chr_repeat|ft_rejoin_split|ft_str_repeat|ft_strdup|ft_strjoin|ft_strmapi|ft_print_fd|ft_strtrim_whitespace|ft_printf|ft_itoa|pft_get_decimal|pft_get_hex_lower|pft_get_pointer|pft_get_unsigned|pft_fill_parts|ft_empty_str|pft_get_percent|ft_print|pft_get_hex_upper

These use write:
ft_print_fd|ft_print|ft_put_substr_fd|ft_put_substr|pft_utils|ft_putchar_fd|ft_putchar|ft_putendl_fd|ft_putendl|ft_putnbr_fd|ft_putnbr|ft_putstr_fd|ft_putstr|pft_putstr|pft_putchr|pft_put_substr|ft_printf
