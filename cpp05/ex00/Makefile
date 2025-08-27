

define BANNER
  ____                                            _   
 |  _ \                                          | |  
 | |_) |_   _ _ __ ___  __ _ _   _  ___ _ __ __ _| |_ 
 |  _ <| | | | '__/ _ \/ _` | | | |/ __| '__/ _` | __|
 | |_) | |_| | | |  __/ (_| | |_| | (__| | | (_| | |_ 
 |____/ \__,_|_|  \___|\__,_|\__,_|\___|_|  \__,_|\__|
                                                      
                                                      
                                                                                               
        Made with love by: hbendjab     
endef

export BANNER

NAME		= Bureaucrat
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main Bureaucrat

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
