# General
* Check that no forbidden functions are being used. Remove #includes accordingly as well.
* Add tests for strings.
* Run norminette on both printf and libft.
* Make all helper functions static and #include the individual C files in the tester.
* Only pass functions the part of the struct they need to access.
* Make sure that all my write() calls returning -1 are returned properly, including ones in ft_print-like functions in libft.
  This includes ft_putstr() and ft_putchar_fd() calls in this project.
* Change all "const type" to "type const" here and in libft.
* Use ft_str_repeat() instead of ft_stralloc(pad_len); ft_memset(pad, ' ', pad_len);
* Let printf return -1 if write returns negative.
* Let printf return -1 if malloc returns NULL.
* Free all mallocs.
* Make conversion->options.type an enum instead of a char.

# Before evalling
* Check that no forbidden functions are being called (search all calls using '('?)
