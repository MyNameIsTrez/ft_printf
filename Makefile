# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: trez <trez@student.codam.nl>                 +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/10 13:54:36 by trez          #+#    #+#                  #
#    Updated: 2022/01/20 15:15:36 by sbos          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

################################################################################

NAME := libftprintf.a

CC := cc

CFLAGS := -Wall -Wextra -Werror

MANDATORY_SOURCES :=

BONUS_SOURCES := bonus/src/ft_printf_bonus.c

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

HEADERS := $(SOURCES:.c=.h)

################################################################################

OBJECT_PATHS := $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:.c=.o))

# Sort removes duplicates
INCLUDES := $(addprefix -I, $(sort $(dir $(HEADERS))))

################################################################################

all: $(NAME)

$(NAME): $(OBJECT_PATHS)
	echo $(USE_BONUS)
	ar rcs $(NAME) $(OBJECT_PATHS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
