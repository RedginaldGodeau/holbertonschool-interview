#include "binary_trees.h"
#include <stdlib.h>

/**
 * find_insertion_parent - Finds the parent where new node should be inserted
 * @root: Pointer to the root node
 *
 * Return: Pointer to the parent node, or NULL if tree is empty
 */
heap_t *find_insertion_parent(heap_t *root) {
  heap_t *queue[1024];
  int front = 0, rear = 0;

  if (!root)
    return (NULL);

  queue[rear++] = root;

  while (front < rear) {
    heap_t *current = queue[front++];

    if (!current->left || !current->right)
      return (current);

    if (current->left)
      queue[rear++] = current->left;
    if (current->right)
      queue[rear++] = current->right;
  }

  return (NULL);
}

/**
 * swap_with_parent - Swaps a node with its parent
 * @root: Double pointer to the root node
 * @node: Pointer to the node to swap
 */
void swap_with_parent(heap_t **root, heap_t *node) {
  heap_t *parent = node->parent;
  heap_t *grandparent;
  int is_left;

  if (!parent)
    return;

  grandparent = parent->parent;
  is_left = (parent->left == node);

  /* Save node's children */
  heap_t *node_left = node->left;
  heap_t *node_right = node->right;
  heap_t *parent_other_child = is_left ? parent->right : parent->left;

  /* Update root if needed */
  if (!grandparent)
    *root = node;

  /* Update grandparent's child pointer */
  if (grandparent) {
    if (grandparent->left == parent)
      grandparent->left = node;
    else
      grandparent->right = node;
  }

  /* Update node's parent */
  node->parent = grandparent;

  /* Reconstruct the tree */
  if (is_left) {
    /* Node was left child */
    node->left = parent;
    node->right = parent_other_child;

    if (node->right)
      node->right->parent = node;

    parent->parent = node;
    parent->left = node_left;
    parent->right = node_right;

    if (parent->left)
      parent->left->parent = parent;
    if (parent->right)
      parent->right->parent = parent;
  } else {
    /* Node was right child */
    node->left = parent_other_child;
    node->right = parent;

    if (node->left)
      node->left->parent = node;

    parent->parent = node;
    parent->left = node_left;
    parent->right = node_right;

    if (parent->left)
      parent->left->parent = parent;
    if (parent->right)
      parent->right->parent = parent;
  }
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node of the Heap
 * @value: Value to store in the node to be inserted
 *
 * Return: Pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value) {
  heap_t *new_node, *parent;

  if (!root)
    return (NULL);

  /* Create new node */
  new_node = binary_tree_node(NULL, value);
  if (!new_node)
    return (NULL);

  /* If tree is empty */
  if (!*root) {
    *root = new_node;
    return (new_node);
  }

  /* Find parent for insertion */
  parent = find_insertion_parent(*root);
  if (!parent) {
    free(new_node);
    return (NULL);
  }

  /* Insert new node */
  if (!parent->left)
    parent->left = new_node;
  else
    parent->right = new_node;
  new_node->parent = parent;

  /* Heapify up */
  while (new_node->parent && new_node->n > new_node->parent->n) {
    swap_with_parent(root, new_node);
  }

  return (new_node);
}