/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filesystem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianna <marianna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 13:35:23 by mcecchel          #+#    #+#             */
/*   Updated: 2025/06/17 18:10:46 by marianna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filesystem.h"

FSNode	*create_file(const char *name, int size)
{
	FSNode	*file;

	file = malloc(sizeof(FSNode));
	if (!file)
		return (NULL);
	file->name = strdup(name);
	if (!file->name)
	{
		// free(file);
		return (NULL);
	}
	file->size = size;
	file->is_folder = 0;
	file->first_child = NULL;
	file->next_sibling = NULL;
	return (file);
}

FSNode	*create_folder(const char *name)
{
	FSNode	*folder;

	folder = malloc(sizeof(FSNode));
	if (!folder)
		return (NULL);
	folder->name = strdup(name);
	if (!folder->name)
	{
		// free(folder);
		return (NULL);
	}
	folder->size = 0;
	folder->is_folder = 1;
	folder->first_child = NULL;
	folder->next_sibling = NULL;
	return (folder);
}

void	add_child(FSNode *parent, FSNode *child)
{
	if (!parent || !child || !parent->is_folder)
		return;
	child->next_sibling = NULL;
	if (!parent->first_child)
		parent->first_child = child;
	else
	{
		FSNode *current;
		current = parent->first_child;
		while (current->next_sibling)
			current = current->next_sibling;
		current->next_sibling = child;
	}
}

FSNode *get_children(const FSNode *parent)
{
	if (!parent || !parent->is_folder)
		return (NULL);
	return (parent->first_child);
}

FSNode *get_sibling(const FSNode *node)
{
	if (!node || !node->next_sibling)
		return (NULL);
	return (node->next_sibling);
}

int main()
{
	FSNode *root = create_folder("root");
	FSNode *file1 = create_file("file1.txt", 100);
	FSNode *file2 = create_file("file2.txt", 200);
	FSNode *subfolder = create_folder("subfolder");

	add_child(root, file1);
	add_child(root, file2);
	add_child(root, subfolder);
	FSNode *children = get_children(root);
	while (children)
	{
		printf("Child: %s\n", children->name);
		children = get_sibling(children);
	}
	return (0);
}