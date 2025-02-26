# =======================================
# Main Variables - Variables / Values
# =======================================

CC		= cc
CCFLAGS ?= -Wall -Werror -Wextra -Ofast
CPPFLAGS = -MMD -MP $(INC_D)
DEBUG	= -g
NAME 	= fdf
MOD		= 0
INC_D		= -Iincludes 		\
			-ILibft/includes 	\
			-Iminilibx-linux	\

# =======================================
# Main Directories - Paths
# =======================================

GLOBAL_FILES	?=	fdf.c				\
		  			error.c				\
		  			utils.c				\
		  			parsing.c			\
		  			vector.c			\
		  			join.c

MANDATORY_FILES =	bresenham.c			\
					draw.c				\
					init.c				\
					keys.c				\
					window.c			\

BONUS_FILES		=	bresenham_bonus.c	\
					draw_bonus.c		\
					init_bonus.c		\
					keys_bonus.c		\
					rotation_bonus.c	\
					window_bonus.c


SRC_DIR			= srcs/basic/
SRC_DIR_BONUS	= srcs/bonus/

OBJ_D		= objs/

# =======================================
# Switch Between Mandatory And Bonus - Colors
# =======================================

ifeq ($(MOD),0)
	GLOBAL_FILES+= $(MANDATORY_FILES)
else
	GLOBAL_FILES+= $(BONUS_FILES)
endif

# =======================================
#  Adding Path
# =======================================

OBJS 			= $(GLOBAL_FILES:.c=.o)
DEPS			= $(GLOBAL_FILES:.c=.d)
DEPS			:= $(addprefix $(OBJ_D), $(DEPS))
OBJS			:= $(addprefix $(OBJ_D), $(OBJS))
BONUS_FILES		:= $(addprefix $(SRC_DIR_BONUS), $(BONUS_FILES))
GLOBAL_FILES	:= $(addprefix $(SRC_DIRS), $(GLOBAL_FILES))
MANDATORY_FILES	:= $(addprefix $(SRC_DIRS), $(MANDATORY_FILES))

# =======================================
#  Mandatory Command
# =======================================

.PHONY:all
all :
	$(MAKE) -C Libft/
	$(MAKE) -C minilibx-linux
	$(MAKE) $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) Libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -lz -o $(NAME)

$(OBJ_D)%.o: $(SRC_DIR)%.c | $(OBJ_D)
	@$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_D)%.o: $(SRC_DIR_BONUS)%.c | $(OBJ_D)
	@$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

.PHONY: bonus
bonus:
	$(MAKE) MOD=1

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

$(OBJ_D):
	mkdir -p $(OBJ_D)

-include $(DEPS)

# =======================================
#  Custom Command
# =======================================

.PHONY: debug
debug:
	$(MAKE) CCFLAGS=$(DEBUG)

.PHONY: norminette
norminette:
	watch norminette $(SRC_DIRS) $(INC_D)