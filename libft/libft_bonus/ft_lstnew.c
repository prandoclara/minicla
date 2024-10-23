/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 12:21:36 by claprand          #+#    #+#             */
/*   Updated: 2024/04/09 13:28:55 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_lstlist allocates memory for a list list node and 
	initializes its content to the value passed as parameter, before
	setting its next node to NULL. 

	RESULT VALUE :
	The list list ode.
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/*
#include <stdio.h>
int main() 
{
	char *str = "Hello, world!";
	t_list *node_str = ft_lstlist(str);
	printf("%s\n", (char *)node_str->content);

	int num = 42;
	t_list *node_int = ft_lstlist(&num);
	printf("%d\n", *((int *)node_int->content));

	free(node_str);
	free(node_int);
	return 0;
}
*/