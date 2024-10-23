/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claprand <claprand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:08:22 by claprand          #+#    #+#             */
/*   Updated: 2024/04/09 11:08:23 by claprand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	DESCRIPTION :
	The function ft_lstlast finds the last node in a given list.

	RETURN VALUE :
	The last node of a list.
		[.]->[.]->[.]->[LAST]->[NULL]
*/

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst-> next)
		lst = lst-> next;
	return (lst);
}

/*
#include <stdio.h>
int main(void)
{
	char s[] = "hello";
	t_list *phrase;
	
	phrase = ft_lstnew((char *)s);
	ft_lstadd_front(&phrase, ft_lstnew("Salut"));
	ft_lstadd_front(&phrase, ft_lstnew("Bjr"));
	printf("%s\n", (char *)ft_lstlast(phrase)->content);
	printf("---------\n");
	t_list  *tmp = phrase;
	while (tmp)
	{
		 printf("%s\n", (char *)tmp->content);
		 phrase = phrase->next;
	}
	
}
*/