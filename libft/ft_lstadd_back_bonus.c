/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 18:39:12 by cciapett          #+#    #+#             */
/*   Updated: 2025/01/09 15:40:47 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new);

// int	main(void)
// {	
// 	t_list	*node1 = malloc(sizeof(t_list));
// 	t_list	*node2 = malloc(sizeof(t_list));
// 	t_list	*node3 = malloc(sizeof(t_list));
// 	t_list	*node4 = malloc(sizeof(t_list));
// 	t_list	*head;

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = NULL;
// 	node1->content = (void *)"10";
// 	node2->content = (void *)"20";
// 	node3->content = (void *)"30";
// 	node4->content = (void *)"40";
// 	node4->next = NULL;

// 	head = node1; // Salva la testa della lista
// 	ft_lstadd_back(&head, node4); // Aggiungi node4 alla lista
// 	while (head != NULL)
// 	{
// 		printf("%s\n", (char *)(head->content));
// 		head = head->next;
// 	}
// 	return (0);
// }


void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *temp;
	if (!lst || !new)
		return ;
	if (*lst != NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp -> next != NULL)
	{
		temp = temp -> next;
	}
	temp -> next = new;
}