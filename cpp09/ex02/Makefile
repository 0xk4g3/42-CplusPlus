

define BANNER
 _____   ___   ____   ___           ____   ___   __ __  ____   _____  ___   ____  
|     | /   \ |    \ |   \         |    | /   \ |  |  ||    \ / ___/ /   \ |    \ 
|   __||     ||  D  )|    \  _____ |__  ||     ||  |  ||  _  (   \_ |     ||  _  |
|  |_  |  O  ||    / |  D  ||     |__|  ||  O  ||  _  ||  |  |\__  ||  O  ||  |  |
|   _] |     ||    \ |     ||_____/  |  ||     ||  |  ||  |  |/  \ ||     ||  |  |
|  |   |     ||  .  \|     |      \  `  ||     ||  |  ||  |  |\    ||     ||  |  |
|__|    \___/ |__|\_||_____|       \____j \___/ |__|__||__|__| \___| \___/ |__|__|
                                                                                                                                   

  Made with love by: hbendjab     
endef

export BANNER

NAME		= PmergeMe
CC	        = c++
FLAGS		= -Wall -Wextra -Werror -O3 -std=c++98 
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main PmergeMe 
SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)
	@printf "$(GREEN)- Ford-Johnson ready!$(RESET)\n"
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
