# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgomez-p <sgomez-p@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 14:27:09 by sgomez-p          #+#    #+#              #
#    Updated: 2023/02/20 16:25:19 by sgomez-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CCLIENT		= client.c
OCLIENT	=	${CCLIENT:.c=.o}

CSERVER		= server.c
OSERVER	=	${CSERVER:.c=.o}

CLIBFT		= \
			libft/lib/ft_atoi.c libft/lib/ft_bzero.c libft/lib/ft_calloc.c \
			libft/lib/ft_isalnum.c libft/lib/ft_isalpha.c libft/lib/ft_isascii.c \
			libft/lib/ft_isdigit.c libft/lib/ft_isprint.c libft/lib/ft_memchr.c \
			libft/lib/ft_memcmp.c libft/lib/ft_memcpy.c libft/lib/ft_memmove.c \
			libft/lib/ft_memset.c libft/lib/ft_strchr.c libft/lib/ft_strdup.c \
			libft/lib/ft_strlcat.c libft/lib/ft_strlcpy.c libft/lib/ft_strlen.c \
			libft/lib/ft_strncmp.c libft/lib/ft_strnstr.c libft/lib/ft_strrchr.c \
			libft/lib/ft_tolower.c libft/lib/ft_toupper.c libft/lib/ft_substr.c \
			libft/lib/ft_strjoin.c libft/lib/ft_strtrim.c libft/lib/ft_putchar_fd.c \
			libft/lib/ft_putstr_fd.c libft/lib/ft_putendl_fd.c libft/lib/ft_putnbr_fd.c \
			libft/lib/ft_itoa.c libft/lib/ft_strmapi.c libft/lib/ft_striteri.c \
			libft/lib/ft_split.c libft/lib/ft_lstnew_bonus.c \
			libft/lib/ft_lstadd_front_bonus.c libft/lib/ft_lstsize_bonus.c \
			libft/lib/ft_lstlast_bonus.c libft/lib/ft_lstadd_back_bonus.c \
			libft/lib/ft_lstdelone_bonus.c libft/lib/ft_lstclear_bonus.c \
			libft/lib/ft_lstiter_bonus.c libft/lib/ft_lstmap_bonus.c \

OLIBFT	=	${CLIBFT:.c=.o}

CPRINTF		= \
			libft/printf/ft_printf_hexlow.c libft/printf/ft_printf_hexup.c \
			libft/printf/ft_printf_int.c libft/printf/ft_printf_str.c \
			libft/printf/ft_printf_unsigned_int.c libft/printf/ft_printf_void_hex.c \
			libft/printf/check_format.c libft/printf/ft_printf_per.c \
			libft/printf/utils.c \

OPRINTF	=	${CPRINTF:.c=.o}

CGNL		= \
			libft/gnl/get_next_line.c libft/gnl/get_next_line_utils.c \
			libft/gnl/get_next_line_bonus.c libft/gnl/get_next_line_utils_bonus.c
OGNL	=	${CGNL:.c=.o}

###############################################################################
#                                              SETTINGS                       #
###############################################################################
SERVER = server
CLIENT = client

NLIBRARY= libft.a

CC = clang
CFLAGS = -Wall -Werror -Wextra
OPGRAFIC = -lmlx -framework OpenGL -framework AppKit
FSANITIZE = -fsanitize=address -g

AR = ar
ARFLAGS = -rcs
RM = rm -f

LIBFT = $(OLIBFT) $(OPRINTF) $(OGNL)

###############################################################################

ifdef WITH_BONUS
	OBJS_CLIENT = ${OCLIENTB}
	OBJS_SERVER = ${OSERVERB}
else
	OBJS_CLIENT = ${OCLIENT}
	OBJS_SERVER = ${OSERVER}
endif
all: ${CLIENT} ${SERVER}

${CLIENT}: ${NLIBRARY} ${OBJS_CLIENT}
	@${CC} ${CFLAGS} $^ ${NLIBRARY} ${FSANITIZE} -o $@
	@echo "Created ${CLIENT}."

${SERVER}: ${NLIBRARY} ${OBJS_SERVER}
	@${CC} ${CFLAGS} $^ ${NLIBRARY} ${FSANITIZE} -o $@
	@echo "Created ${SERVER}."

$(NLIBRARY): $(LIBFT)
	@$(AR) $(ARFLAGS) $@ $^
	@echo "Created LIBFT."

bonus:
	@make WITH_BONUS=1

git: fclean
	@echo "\t${BIPurple}>>Push To Git<<${NoColor}"
	@git add . ;
	@git remote -v | cut -d " " -f 1 | uniq
	@read -p "Name the commit: " commit ;\
	git commit -m "$$commit" ;\
	git push origin master ;

normi:
	@echo "${BICyan}>>Check Files with ${BIRed}ERROR${BICyan} norminette<<${NoColor}"
	@norminette -R CheckForbiddenSourceHeader | grep Error! | grep -v tester

.c.o:
	@${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

###############################################################################
clean:
		@${RM} ${OSERVER} ${OSERVERB} ${OCLIENT} ${OCLIENTB} ${LIBFT}
		@echo "Delete .o."

fclean: clean
		@${RM} ${NLIBRARY} ${SERVER} ${CLIENT}
		@echo "Delete libft.a, client and server."

bre:	fclean
	@make WITH_BONUS=1

re: fclean all