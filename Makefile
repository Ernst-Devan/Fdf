# =======================================
# Main Variables - Variables / Values
# =======================================

CC		= cc
CCFLAGS ?= -Wall -Werror -Wextra -Ofast
DEBUG	= -g
NAME 	= fdf

# =======================================
# Main Directories - Paths
# =======================================

SRC_FILES	?=	fdf.c 				\
		  		draw.c				\
		  		window.c			\
		  		error.c				\
		  		init.c				\
		  		utils.c				\
		  		parsing.c			\
		  		vector.c			\
		  		bresenham.c			\
		  		keys.c				\
		  		rotation.c			\
		  		join.c

SRC_BONUS	=	fdf_bonus.c 		\
		  		draw_bonus.c		\
		  		window_bonus.c		\
		  		error_bonus.c		\
		  		parsing_bonus.c		\
		  		init_bonus.c		\
		  		utils_bonus.c		\
		  		vector_bonus.c		\
		  		bresenham_bonus.c	\
		  		keys_bonus.c	\
		  		rotation_bonus.c	\
		  		join_bonus.c

OBJS 	= $(SRC_FILES:.c=.o)

SRC_DIR		?= srcs/basic/
SRC_DIR_BONUS = srcs/bonus/

OBJ_D		= objs/
INC_D		= -Iincludes 		\
			-ILibft/includes 	\
			-Iminilibx-linux	\

# =======================================
# Decoration Text - Colors
# =======================================

red    	= 	/bin/echo -e "\x1b[31m$1\x1b[0m"
green  	= 	/bin/echo -e "\x1b[32m$1\x1b[0m"
yellow 	= 	/bin/echo -e "\x1b[33m$1\x1b[0m"
blue   	= 	/bin/echo -e "\x1b[34m$1\x1b[0m"
magenta = 	/bin/echo -e "\x1b[35m$1\x1b[0m"
cyan   	= 	/bin/echo -e "\x1b[36m$1\x1b[0m"

# =======================================
# Objets Files
# =======================================

.PHONY:all
all :
	$(MAKE) -C Libft/
	$(MAKE) -C minilibx-linux
	$(MAKE) $(NAME)

OBJS		:= $(addprefix $(OBJ_D), $(OBJS))
SRC_FILES	:= $(addprefix $(SRC_DIR), $(SRC_FILES))

$(NAME): $(OBJS)
	@$(CC) $(INC_D) $(OBJS) Libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_D)%.o: $(SRC_DIR)%.c $(OBJ_D)
	@$(CC) $(CCFLAGS) $(INC_D) -g3 -c $< -o $@

.PHONY: bonus
bonus:
	$(MAKE) SRC_FILES="$(SRC_BONUS)" SRC_DIR="$(SRC_DIR_BONUS)"

.PHONY: debug
debug:
	$(MAKE) CCFLAGS=$(DEBUG)

.PHONY: clean
clean:
	$(MAKE) clean -C minilibx-linux
	$(MAKE) clean -C Libft/
	rm -rf $(OBJ_D)

.PHONY: fclean
fclean:	clean
	$(MAKE) fclean -C Libft/ 
	rm -f $(NAME)

.PHONY: re
re: fclean all
	$(MAKE) re -C minilibx-linux
	$(MAKE) fclean -C Libft/

.PHONY: norminette
norminette:
	watch norminette $(SRC_DIR) $(INC_D)

$(OBJ_D):
	mkdir -p $(OBJ_D)