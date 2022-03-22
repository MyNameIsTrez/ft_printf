# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    tester.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/20 16:07:18 by sbos          #+#    #+#                  #    Updated: 2022/03/01 18:14:56 by sbos          ########   odam.nl          #
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

TESTER_LIBS := ./libmassert/libmassert.a ./libftprintf.a

TESTER := tester

TESTER_HEADERS :=											\
	$(HEADERS)												\
	tests/tests_get_type_strings/test_get_type_strings.h	\
	$(TESTS_DIR)/tests.h									\
	$(MASSERT_DIR)/massert.h

################################################################################

TESTER_SOURCES := $(wildcard $(TESTS_DIR)/*.c) $(wildcard $(TESTS_DIR)/**/*.c)
TESTER_OBJECTS := $(addprefix $(TESTS_OBJ_DIR)/,$(TESTER_SOURCES:.c=.o))

TESTER_INCLUDES := $(sort $(addprefix -I, $(dir $(TESTER_HEADERS))))

TESTER_LIB_FLAGS := $(sort $(addprefix -L,$(dir $(TESTER_LIBS)))) $(sort $(patsubst lib%,-l%,$(basename $(notdir $(TESTER_LIBS)))))

################################################################################

$(TESTER): bonus $(MASSERT_DIR)/libmassert.a $(TESTER_OBJECTS)
	$(CC) $(CFLAGS) $(TESTER_INCLUDES) -g3 $(TESTER_OBJECTS) $(TESTER_LIB_FLAGS) -o $(TESTER)

$(TESTS_OBJ_DIR)/%.o: %.c $(TESTER_HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -Wno-format $(TESTER_INCLUDES) -c $< -o $@

################################################################################

$(MASSERT_DIR)/libmassert.a:
	@$(MAKE) -C $(MASSERT_DIR)

.PHONY: $(MASSERT_DIR)/libmassert.a

################################################################################

fclean_tester: fclean
	rm -rf $(TESTS_OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(MASSERT_DIR) fclean

re_tester: fclean_tester $(TESTER)

.PHONY: fclean_tester re_tester

################################################################################
