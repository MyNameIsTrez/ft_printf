# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    tester.mk                                          :+:    :+:             #
#                                                      +:+                     #
#    By: sbos <sbos@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/20 16:07:18 by sbos          #+#    #+#                  #
#    Updated: 2022/01/28 19:07:07 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

export DEBUG = 1

################################################################################

include Makefile

################################################################################

TESTER_NAME := tester

TESTED_SOURCES := libftprintf.a

TESTED_LIBS := libftprintf.a
LIBS := -lftprintf

LIBFT_PATH := libft

# TESTER_HEADERS := tests/tests.h $(LIBFT_PATH)/libft.h
TESTER_HEADERS := tests/tests.h bonus/src/get_type_strings/get_type_strings.h

TEST_DIR := tests

TEST_INCLUDES :=

################################################################################

# TESTER_SOURCES := $(wildcard $(TEST_DIR)/**.c) $(TESTER_NAME).c
TESTER_SOURCES := $(wildcard $(TEST_DIR)/*.c) $(wildcard $(TEST_DIR)/tests_get_type_strings/*.c) $(TESTER_NAME).c

TEST_INCLUDES += $(addprefix -I, $(sort $(dir $(TESTER_HEADERS))))

TEST_LIBS := $(addprefix -L, $(sort $(dir $(TESTED_LIBS))))

################################################################################

$(TESTER_NAME): bonus $(TESTER_HEADERS) $(TESTED_SOURCES) $(TESTER_SOURCES)
	$(CC) $(CFLAGS) $(TEST_INCLUDES) -g3 $(TESTER_SOURCES) $(TEST_LIBS) $(LIBS) -o $(TESTER_NAME)

################################################################################

.PHONY: $(TESTER_NAME)

################################################################################
