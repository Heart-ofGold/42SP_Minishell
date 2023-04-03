################################################################################
##                               42 PUSH SWAP                                 ##
################################################################################

#static library's name
NAME =		minishell

#colors
RESET 			:= \033[0m
GREEN			=	\e[32m
CYAN  			:= \33[1;36m
YELLOW			=	\e[033m
BLUE			=	\e[34m
WHITE			=	\e[00m

#printing
LOG   			:= printf "[$(GREEN)PROJECT_INFO$(RESET)] %s\n"
LOG_SUC			:= printf "[$(CYAN)COMPILING_INFO$(RESET)] %s\n"

################################################################################
##                                DIRECTORIES                                 ##
################################################################################

#scr functions
MANDATORY_FILES =	pearl/main.c \
					pearl/signal_utils.c \
					errors/pearl_error.c \
					cmd/cmd_path.c \
					cmd/executor.c \
					builtin/ft_echo.c \
					builtin/ft_cd.c \
					builtin/ft_pwd.c \
					builtin/ft_export.c \
					builtin/ft_unset.c \
					builtin/ft_env.c \
					builtin/ft_exit.c \
					lexer/lexer.c \
					lexer/token.c \
					lexer/utils_lexer.c \
					parser/parser.c \
					parser/utils_parser.c \
					../0_tests/tests.c \

#directories
OBJPATH =			temps
MANDATORY_PATH =	sources
LIBFT_PATH =		./libft
LIBFT =				$(LIBFT_PATH)/libft.a

#header to libft.h
INCLUDE =	-I ./ -I $(LIBFT_PATH)

################################################################################
##                                 COMPILATION                                ##
################################################################################

#compiling
CC =	gcc
FLAGS =	-Wall -Werror -Wextra -g3
GDB =	gdb
VAL =	valgrind --leak-check=full --track-origins=yes
## --trace-children=yes --track-fds=yes

# clean
RM =		-rm -f
RM_DIR =	rm -rf

#tranform into .o
OBJ_MANDATORY = $(MANDATORY_FILES:%.c=$(OBJPATH)/%.o)

#compiling bar
NUMBER_OF_FILES	=	$(words $(MANDATORY_FILES))
PROGRESS			=	0

################################################################################
##                                    RULES                                   ##
################################################################################

#make
all: $(OBJPATH) $(NAME)

#make bonus
bonus: $(OBJPATH) $(B_NAME)

##folder for temporary objects
$(OBJPATH):
		@$(LOG) "Creating objects directory..."
		@mkdir -p $(OBJPATH)

##make libft
$(LIBFT):
		@make -C $(LIBFT_PATH) --no-print-directory

##rule name - make minishell
$(NAME): $(LIBFT)  $(OBJ_MANDATORY)
		@cc $(FLAGS) -o $(NAME) $(OBJ_MANDATORY) $(LIBFT) -lreadline
		@$(LOG_SUC) "$(NAME) succesfully compiled!"

##compile MANDATORY
$(OBJPATH)/%.o: $(MANDATORY_PATH)/%.c $(HEADER)
		@mkdir -p $(dir $@)
		@cc $(FLAGS) -c $< -o $@ $(INCLUDE)
		@echo -n "$(YELLOW)Compiling ${NAME} $(WHITE)$$(( $(PROGRESS) * 100 / $(NUMBER_OF_FILES)))%\r"
		$(eval PROGRESS=$(shell echo $$(($(PROGRESS)+1))))

#make mem -> mcheck
mem:
		$(VAL) ./$(NAME)


#make clean -> remove objects
clean:
		@make clean -C $(LIBFT_PATH) --no-print-directory
		@$(LOG) "Removing objects..."
		@$(RM) $(OBJ_MANDATORY)

#make fclean -> remove all
fclean: clean
		@make fclean -C $(LIBFT_PATH) --no-print-directory
		@$(LOG) "Removing executable..."
		@$(RM) $(NAME) $(B_NAME)
		@$(RM_DIR) $(OBJPATH)
		@$(LOG_SUC) "Cleaned project!"

#make re -> clear all and recompliles
re:		fclean all
		@$(LOG_SUC) "Recompiled succesfully!"

##avoids double inclusion
.PHONY: all clean fclean re bonus

#make git m="message" -> commit to git
git:
		git add .
		git commit -m "$(m)"
		git push

norm:
		clear
		@norminette ${addprefix ${MANDATORY_PATH}/, ${MANDATORY_FILES}} | grep -v "OK!" || echo "All files ok!"

norm_CI:
		norminette ${addprefix ${MANDATORY_PATH}/, ${MANDATORY_FILES}}
