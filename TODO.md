# General
* Check that no forbidden functions are being used. Remove #includes accordingly as well.
* Add tests for strings.
* Run norminette on both printf and libft.
* Make all helper functions static and #include the individual C files in the tester.
* Only pass functions the part of the struct they need to access.
* Make sure that all my write() calls returning -1 are returned properly, including ones in ft_print-like functions in libft.
  This includes ft_putstr() and ft_putchar_fd() calls in this project.
* Change all "const type" to "type const" here and in libft.
* Let printf return -1 if write returns negative.
* Let printf return -1 if malloc returns NULL.
* Free all mallocs.

# Before evalling
* Check that no forbidden functions are being called (search all calls using '('?)
* Run ft_printf_test on a clone (and maybe another tester?)
