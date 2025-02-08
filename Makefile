CMD = cc
CFLAGS = -Wall -Wextra -Werror -I. -g #-fsanitize=address,undefined

TARGET_LIBFTA = libft.a
TARGET_PRINTF = libftprintf.a
TARGET_PROGRM = push_swap

SRC_LIBFTA = \
	ft_libft/ft_atoi.c\
	ft_libft/ft_bzero.c\
	ft_libft/ft_calloc.c\
	ft_libft/ft_isalnum.c\
	ft_libft/ft_isalpha.c\
	ft_libft/ft_isascii.c\
	ft_libft/ft_isdigit.c\
	ft_libft/ft_isprint.c\
	ft_libft/ft_itoa.c\
	ft_libft/ft_memchr.c\
	ft_libft/ft_memcmp.c\
	ft_libft/ft_memcpy.c\
	ft_libft/ft_memmove.c\
	ft_libft/ft_memset.c\
	ft_libft/ft_putchar_fd.c\
	ft_libft/ft_putendl_fd.c\
	ft_libft/ft_putnbr_fd.c\
	ft_libft/ft_putstr_fd.c\
	ft_libft/ft_split.c\
	ft_libft/ft_strchr.c\
	ft_libft/ft_strdup.c\
	ft_libft/ft_striteri.c\
	ft_libft/ft_strjoin.c\
	ft_libft/ft_strlcat.c\
	ft_libft/ft_strlcpy.c\
	ft_libft/ft_strlen.c\
	ft_libft/ft_strmapi.c\
	ft_libft/ft_strncmp.c\
	ft_libft/ft_strnstr.c\
	ft_libft/ft_strrchr.c\
	ft_libft/ft_strtrim.c\
	ft_libft/ft_substr.c\
	ft_libft/ft_tolower.c\
	ft_libft/ft_toupper.c

SRC_PRINTF = \
	ft_libft/ft_printf/ft_helper.c\
	ft_libft/ft_printf/ft_pointer.c\
	ft_libft/ft_printf/ft_putnbr_base.c\
	ft_libft/ft_printf/ft_printf.c

SRC_PROGRM = \
	ft_actions_a.c\
	ft_actions_b.c\
	ft_actions_both.c\
	ft_atol.c\
	ft_guide_list_helper.c\
	ft_guide_list.c\
	ft_list.c\
	ft_parse_arg.c\
	ft_parse_help.c\
	ft_sort_comp.c\
	ft_sort_easy.c\
	ft_sort_help.c\
	ft_sort.c\
	ft_stack.c\
	ft_stk_ops.c\
	ft_utils.c\
	push_swap.c\

OBJ_LIBFTA = $(SRC_LIBFTA:.c=.o)
OBJ_PRINTF = $(SRC_PRINTF:.c=.o)
OBJ_PROGRM = $(SRC_PROGRM:.c=.o)

HEADER = ft_printf.h libft.h ft_stack.h

all : $(TARGET_LIBFTA) $(TARGET_PRINTF) $(TARGET_PROGRM)

$(TARGET_LIBFTA) : $(OBJ_LIBFTA) $(OBJ_PRINTF)
	ar rcs $(TARGET_LIBFTA) $(OBJ_LIBFTA) $(OBJ_PRINTF)

$(TARGET_PRINTF) : $(OBJ_PRINTF) $(TARGET_LIBFTA)
	ar rcs $(TARGET_PRINTF) $(OBJ_PRINTF) $(TARGET_LIBFTA)

$(TARGET_PROGRM) : $(OBJ_PROGRM) $(TARGET_PRINTF) $(TARGET_LIBFTA)
	$(CMD) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CMD) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ_LIBFTA) $(OBJ_PRINTF) $(OBJ_PROGRM)

fclean : clean
	rm -rf $(TARGET_LIBFTA) $(TARGET_PRINTF) $(TARGET_PROGRM)

re : fclean all

.PHONY: all clean fclean re
