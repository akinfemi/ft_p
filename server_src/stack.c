/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akinfemi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 20:02:29 by akinfemi          #+#    #+#             */
/*   Updated: 2018/01/20 20:02:31 by akinfemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftp.h"

t_item  *new_node (char *word) {
	t_item *item = malloc(sizeof(*item));
	item->word = word;
	item->next = NULL;
	return (item);
}

t_stack *stackInit(void)
{
    t_stack *new_stack = malloc(sizeof(*new_stack));
    if (!new_stack)
        return (NULL);
    new_stack->item = NULL;
    new_stack->size = 0;
    return (new_stack);
}

void	push(t_stack *stack, char *word)
{
    t_item *new_item = NULL;

    if (!stack || !word)
        return ;
    new_item = new_node(word);
    if (!stack->item)
        stack->item = new_item;
    else
    {
        new_item->next = stack->item;
        stack->item = new_item;
    }
    stack->size++;
}

void	*pop(t_stack *stack)
{
    t_item	*top = NULL;
    
    if (!stack || !stack->item)
        return (0);
    top = stack->item;
    stack->item = stack->item->next; 
    stack->size--;
    return (top);
}