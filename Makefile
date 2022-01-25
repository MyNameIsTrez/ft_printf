# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/01/25 12:51:44 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a
LIBFT_PATH := libft/libft.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

MANDATORY_SOURCES :=

BONUS_SOURCES := bonus/src/ft_printf_bonus.c

FCLEANED_FILES := $(NAME)

################################################################################

ifdef USE_BONUS
SRC_DIR := bonus/src
OBJ_DIR := bonus/obj
SOURCES := $(BONUS_SOURCES)
else
SRC_DIR := mandatory/src
OBJ_DIR := mandatory/obj
SOURCES := $(MANDATORY_SOURCES)
endif

ifdef DEBUG
LIBS +=
HEADERS := tests.h
CFLAGS += -g3 -Wconversion
# CFLAGS += -fsanitize=address
FCLEANED_FILES += tester
endif

HEADERS := $(SOURCES:.c=.h)

################################################################################

OBJECT_PATHS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Sort removes duplicates
INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))

################################################################################

all: $(NAME)

$(NAME): $(OBJECT_PATHS) $(LIBFT_PATH)
	cp $(LIBFT_PATH) $(NAME)
	ar rs $(NAME) $(OBJECT_PATHS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_PATH):
	$(MAKE) -C $(dir $(LIBFT_PATH))

################################################################################

bonus:
	@$(MAKE) USE_BONUS=1 all

clean:
	rm -rf $(OBJ_DIR)/

fclean: clean
	rm -f $(FCLEANED_FILES)

re: fclean all

################################################################################

.PHONY: all bonus clean fclean re

################################################################################
