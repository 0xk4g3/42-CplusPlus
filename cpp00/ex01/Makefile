
YELLOW = \033[33m
GREEN = \033[32m
RED = \033[31m
BLUE = \033[34m
RESET = \033[0m

NAME = PhoneBook
CC = c++
SRC = PhoneBook.cpp  Contact.cpp main.cpp
FLAGS = -Wall -Wextra -Werror -std=c++98
OBJ = ${SRC:.cpp=.o}

all: ${NAME} banner

${NAME}: ${OBJ}
	@echo "$(GREEN)🔨 Compiling...$(RESET)"
	@${CC} ${FLAGS} ${OBJ} -o $@
	@echo "$(GREEN)✅ PhoneBook is ready!$(RESET)"

%.o: %.cpp
	@echo "$(BLUE)🔄 Building $<...$(RESET)"
	@${CC} ${FLAGS} -c $< -o $@

clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	@rm -f ${OBJ}
	@echo "$(GREEN)✨ Object files cleaned!$(RESET)"

fclean: clean
	@echo "$(RED)🗑️  Removing program...$(RESET)"
	@rm -f ${NAME}
	@echo "$(GREEN)✨ All cleaned!$(RESET)"

re: fclean all

banner:
	@echo "$(YELLOW)██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗$(RESET)"
	@echo "$(YELLOW)██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝$(RESET)"
	@echo "$(YELLOW)██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ $(RESET)"
	@echo "$(YELLOW)██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ $(RESET)"
	@echo "$(YELLOW)██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗$(RESET)"
	@echo "$(YELLOW)╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝$(RESET)"
	@echo "$(GREEN)                    Made with love by:$(BLUE) hbendjab$(RESET)"

.PHONY: all clean fclean re banner