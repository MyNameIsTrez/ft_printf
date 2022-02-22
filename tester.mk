# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    tester.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/20 16:07:18 by sbos          #+#    #+#                  #
#    Updated: 2022/02/22 15:39:44 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

export DEBUG = 1

################################################################################

include Makefile

################################################################################

TESTS_DIR := tests
TESTS_OBJ_DIR := obj_tests

MASSERT_DIR := libmassert

TESTER := tester
TESTER_HEADERS :=											\
	src/ft_printf_bonus.h									\
	src/get_type_strings/get_type_strings.h					\
	tests/tests_get_type_strings/test_get_type_strings.h	\
	$(TESTS_DIR)/tests.h									\
	$(MASSERT_DIR)/massert.h
TESTER_LIBS := -L$(MASSERT_DIR) -lmassert -L. -lftprintf

################################################################################

TESTER_SOURCES := $(wildcard $(TESTS_DIR)/*.c) $(wildcard $(TESTS_DIR)/**/*.c)
TESTER_OBJECTS := $(patsubst $(TESTS_DIR)/%,$(TESTS_OBJ_DIR)/%,$(TESTER_SOURCES:.c=.o))

TESTER_INCLUDES := $(sort $(addprefix -I, $(dir $(TESTER_HEADERS))))

################################################################################

$(TESTER): bonus $(MASSERT_DIR)/libmassert.a $(TESTER_OBJECTS)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -g3 $(TESTER_OBJECTS) $(TESTER_LIBS) -o $(TESTER)

$(TESTS_OBJ_DIR)/%.o: $(TESTS_DIR)/%.c $(TESTER_HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -c $< -o $@

################################################################################

$(MASSERT_DIR)/libmassert.a:
	$(MAKE) -C $(MASSERT_DIR)

.PHONY: $(MASSERT_DIR)/libmassert.a

################################################################################

fclean_tester: fclean
	rm -rf $(TESTS_OBJ_DIR)
	rm -f $(TESTER)

re_tester: fclean_tester $(TESTER)

.PHONY: fclean_tester re_tester

################################################################################
