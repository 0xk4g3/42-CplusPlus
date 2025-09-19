

define BANNER
  _________            .__       .__  .__                
 /   _____/ ___________|__|____  |  | |__|_______ ____   
 \_____  \_/ __ \_  __ \  \__  \ |  | |  \___   // __ \  
 /        \  ___/|  | \/  |/ __ \|  |_|  |/    /\  ___/  
/_______  /\___  >__|  |__(____  /____/__/_____ \\___  > 
        \/     \/              \/              \/    \/  
                                     
    Made with love by: hbendjab     
endef

export BANNER

NAME		= Serialize
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98 
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main Serialize 
SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)
	@printf "$(GREEN)- Serialize ready!$(RESET)\n"
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
