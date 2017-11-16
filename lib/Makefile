# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aakin-al <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/01 10:11:56 by aakin-al          #+#    #+#              #
#    Updated: 2017/09/01 14:27:59 by aakin-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

CFLAGS = -Wall -Wextra -Werror -I includes/

LIBFT =		btree_add_node.c\
			btree_apply_inorder.c\
			btree_apply_postorder.c\
			btree_apply_preorder.c\
			btree_create_node.c\
			ft_atoi.c\
			ft_bzero.c\
            ft_isalnum.c\
            ft_isalpha.c\
            ft_isascii.c\
            ft_isdigit.c\
            ft_isprint.c\
            ft_itoa.c\
            ft_lstadd.c\
            ft_lstappend.c\
            ft_lstdel.c\
            ft_lstdelone.c\
            ft_lstiter.c\
            ft_lstmap.c\
            ft_lstnew.c\
            ft_memalloc.c\
            ft_memccpy.c\
            ft_memchr.c\
            ft_memcmp.c\
            ft_memcpy.c\
            ft_memdel.c\
            ft_memmove.c\
            ft_memset.c\
            ft_putchar.c\
            ft_putchar_fd.c\
            ft_putendl.c\
            ft_putendl_fd.c\
            ft_putnbr.c\
            ft_putnbr_fd.c\
            ft_putstr.c\
            ft_putstr_fd.c\
            ft_strcat.c\
            ft_strchr.c\
            ft_strclr.c\
            ft_strcmp.c\
            ft_strcpy.c\
            ft_strdel.c\
            ft_strdup.c\
            ft_strequ.c\
            ft_striter.c\
            ft_striteri.c\
            ft_strjoin.c\
            ft_strlcat.c\
            ft_strlen.c\
            ft_strmap.c\
            ft_strncat.c\
            ft_strncmp.c\
            ft_strncpy.c\
            ft_strndup.c\
            ft_strnequ.c\
            ft_strnew.c\
            ft_strnstr.c\
            ft_strrchr.c\
            ft_strsplit.c\
            ft_strsplitlist.c\
            ft_strstr.c\
            ft_strsub.c\
            ft_strtrim.c\
            ft_sqrt.c\
			ft_strtolower.c\
            ft_tolower.c\
            ft_toupper.c\
            ft_itoa_base.c\
            ft_itoa_bin.c\
            ft_itoa_upper_base.c\
            ft_imaxtoa.c\
			ft_atomax.c \
            ft_bin_to_dec.c \
            ft_pow.c \
		ft_abs.c \
		ft_isnum.c \
        ft_lstsort.c
            
FT_PRINTF = ft_build.c\
            ft_is.c\
            ft_is2.c\
            ft_parse.c\
            ft_set.c\
            ft_conv.c\
            ft_str.c\
            ft_handle.c\
            ft_handle_2.c\
            ft_handle_extra.c\
            ft_printf.c

GET_NEXT_LINE = get_next_line.c

FILES = $(addprefix libft/, $(LIBFT)) \
		$(addprefix get_next_line/, $(GET_NEXT_LINE)) \
		$(addprefix ft_printf/, $(FT_PRINTF))

OBJ = $(FILES:.c=.o)

.PHONY = all fclean clean re 

all: $(NAME)

$(OBJ):%.o: %.c
	@gcc -c $(CFLAGS) $< -o $@

$(NAME): $(FILES) $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "lib.a created"

clean:
	@rm -f $(OBJ)
	@echo "Object files removed"

fclean: clean
	@rm -f $(NAME)
	@echo "lib.a removed"

re: fclean all
