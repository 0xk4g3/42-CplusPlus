
define BANNER

 ______  _____  ___  ___  ____  _____ ______      
|___  / |  _  | |  \/  | |  _ \|_   _|  ____|    
   / /  | | | | | .  . | | |_) | | | | |__       
  / /   | | | | | |\/| | |  _ <  | | |  __|      
./ /___ \ \_/ / | |  | | | |_) |_| |_| |____     
\_____/  \___/  \_|  |_/ |____/|_____|______|    
                                                  
        Made with love by: hbendjab     
endef
export BANNER

NAME		= zombie
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR		= .objfiles

FILES		= main Zombie newZombie randomChump

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))

#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

all: $(NAME)
	@printf "$(GREEN)- Zombie ready!$(RESET)\n"
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