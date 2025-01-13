# =======================================
# Main Variables - Variables / Values
# =======================================

CC		= cc
CFLAGS 	= -Wall -Werror -Wextra
NAME 	= fdf.out

# =======================================
# Main Directories - Paths
# =======================================

SRCS 	= fdf.c
OBJS 	= $(SRCS:.c=.o)

SRC_D	= srcs/
OBJ_D	= objs/
INC_D	= -Iincludes \
		  -ILibft/includes

# =======================================
# Objets Files
# =======================================

.PHONY:a ll
all :
	$(MAKE) -C Libft/
	$(MAKE) $(NAME)

OBJS	:= $(addprefix $(OBJ_D), $(OBJS))
SRCS	:= $(addprefix $(SRC_D), $(SRCS))

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INC_D) $(OBJS) Libft/libft.a -o $(NAME)

$(OBJ_D)%.o: $(SRC_D)%.c $(OBJ_D)
	$(CC) $(CFLAGS) $(INC_D) -c $< -o $@

.PHONY: clean
clean:
	$(MAKE) clean -C Libft/
	rm -rf $(OBJ_D)

.PHONY: fclean
fclean:	clean
	$(MAKE) fclean -C Libft/ 
	rm -f $(NAME)

.PHONY: re
re: fclean all
	$(MAKE) fclean -C Libft/

.PHONY: debug
debug: $(OBJS)
	$(MAKE) -C Libft/
	$(CC) -Wall -Wextra $(INC_D) $(OBJS) -o $(NAME)

$(OBJ_D):
	mkdir -p $(OBJ_D)