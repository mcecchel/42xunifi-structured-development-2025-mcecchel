#include "filesystem.h"

static FSNode	*create_node(const char *name, int size, int is_folder)
{
	FSNode	*node;
	
	if (!name)
		return (NULL);
	node = malloc(sizeof(FSNode));
	if (!node)
		return (NULL);
	node->name = strdup(name);
	if (!node->name)
	{
		// free(node);
		return (NULL);
	}
	node->size = size;
	node->is_folder = is_folder;
	node->first_child = NULL;
	node->next_sibling = NULL;
	return (node);
}

FSNode	*create_file(const char *name, int size)
{
	if (size < 0)
		return (NULL);
	return (create_node(name, size, 0));
}

FSNode	*create_folder(const char *name)
{
	return	create_node(name, 0, 1);
}

void	add_child(FSNode *parent, FSNode *child)
{
	FSNode	*current;
	
	if (!parent || !child || !parent->is_folder)
		return;
	if (!parent->first_child)
	{
		parent->first_child = child;
		return;
	}
	current = parent->first_child;
	while (current->next_sibling)
		current = current->next_sibling;
	current->next_sibling = child;
}

FSNode	*get_children(const FSNode *parent)
{
	if (!parent || !parent->is_folder)
		return (NULL);
	return (parent->first_child);
}

FSNode	*get_sibling(const FSNode *node)
{
	if (!node)
		return (NULL);
	return (node->next_sibling);
}

// int main(void)
// {
// 	FSNode *root = create_folder("root");
// 	FSNode *file1 = create_file("file1.txt", 100);
// 	FSNode *file2 = create_file("file2.txt", 200);
// 	FSNode *subfolder = create_folder("subfolder");

// 	add_child(root, file1);
// 	add_child(root, file2);
// 	add_child(root, subfolder);
// 	FSNode *children = get_children(root);
// 	while (children)
// 	{
// 		printf("Child: %s with size: %d\n", children->name, children->size);
// 		children = get_sibling(children);
// 	}
// 	return (0);
// }