

define BANNER
    ____                          _   
  / ___|___  _ ____   _____ _ __| |_ 
 | |   / _ \| '_ \ \ / / _ \ '__| __|
 | |__| (_) | | | \ V /  __/ |  | |_ 
  \____\___/|_| |_|\_/ \___|_|   \__|
                                     
    Made with love by: hbendjab     
endef

export BANNER

NAME		= Convert
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98 
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main  ScalarConverter Converter TheChecker 
SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)
	@printf "$(GREEN)- Bureaucrat ready!$(RESET)\n"
	@echo "$$BANNER"

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) -o $(NAME)
	@printf "$(CURSIVE)- Compiled with $(FLAGS) -$(RESET)\n"

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf "$(YELLOW)- Object files cleaned!$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@printf "$(YELLOW)- Executable cleaned!$(RESET)\n"
	

re: fclean all

.PHONY: all clean fclean re
