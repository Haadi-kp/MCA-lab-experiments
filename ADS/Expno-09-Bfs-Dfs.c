#include <stdio.h>
#include <stdlib.h>
enum color
{
  White,
  Gray,
  Black
};
typedef struct list_node
{
  int index_of_item;
  struct list_node *next;
} list_node;

typedef struct node
{
  int data;
  enum color colr;
  int discovery_time;
  int finish_time;
  list_node *head;
} node;

typedef struct graph
{
  int number_of_vertices;
  node heads[];
} graph;
node *new_node(int data)
{
  node *z = malloc(sizeof(node));
  z->data = data;
  z->head = NULL;
  z->colr = White;
  z->discovery_time = 0;
  z->finish_time = 0;
  return z;
}

list_node *new_list_node(int item_index)
{
  list_node *z = malloc(sizeof(list_node));
  z->index_of_item = item_index;
  z->next = NULL;
  return z;
}

graph *new_graph(int number_of_vertices)
{
  graph *g = malloc(sizeof(graph) + (number_of_vertices * sizeof(node)));
  g->number_of_vertices = number_of_vertices;

  int i;
  for (i = 0; i < number_of_vertices; i++)
  {
    node *z = new_node(-1);
    g->heads[i] = *z;
  }
  return g;
}
void add_node_to_graph(graph *g, int data)
{
  node *z = new_node(data);
  int i;

  for (i = 0; i < g->number_of_vertices; i++)
  {
    if (g->heads[i].data < 0)
    {
      g->heads[i] = *z;
      break;
    }
  }
}

int in_graph_head_list(graph *g, int data)
{
  int i;
  for (i = 0; i < g->number_of_vertices; i++)
  {
    if (g->heads[i].data == data)
      return 1;
  }
  return 0;
}

void add_edge(graph *g, int source, int dest)
{
  if (!in_graph_head_list(g, source))
  {
    add_node_to_graph(g, source);
  }
  if (!in_graph_head_list(g, dest))
  {
    add_node_to_graph(g, dest);
  }

  int i, j;
  for (i = 0; i < g->number_of_vertices; i++)
  {
    if (g->heads[i].data == source)
    {

      int dest_index;
      for (j = 0; j < g->number_of_vertices; j++)
      {

        if (g->heads[j].data == dest)
        {
          dest_index = j;
          break;
        }
      }

      list_node *n = new_list_node(dest_index);
      if (g->heads[i].head == NULL)
      {
        g->heads[i].head = n;
      }
      else
      {
        list_node *temp;
        temp = g->heads[i].head;

        while (temp->next != NULL)
        {
          temp = temp->next;
        }
        temp->next = n;
      }
      break;
    }
  }
}

void print_graph(graph *g)
{
  int i;
  for (i = 0; i < g->number_of_vertices; i++)
  {
    list_node *temp;
    temp = g->heads[i].head;
    printf("%d\t", g->heads[i].data);
    while (temp != NULL)
    {
      printf("%d\t", g->heads[temp->index_of_item].data);

      temp = temp->next;
    }
    printf("\n");
  }
}
typedef struct queue_node
{
  node *n;
  struct queue_node *next;
} queue_node;

typedef struct queue
{
  int count;
  queue_node *front;
  queue_node *rear;
} queue;

int is_empty_queue(queue *q) { return !(q->count); }

void enqueue(queue *q, node *n)
{
  queue_node *new_queue_node;
  new_queue_node = malloc(sizeof(queue_node));
  new_queue_node->n = n;
  new_queue_node->next = NULL;
  if (!is_empty_queue(q))
  {
    q->rear->next = new_queue_node;
    q->rear = new_queue_node;
  }
  else
  {
    q->front = q->rear = new_queue_node;
  }
  q->count++;
}
queue_node *dequeue(queue *q)
{
  queue_node *tmp;
  tmp = q->front;
  q->front = q->front->next;
  q->count--;
  return tmp;
}

queue *make_queue()
{
  queue *q;
  q = malloc(sizeof(queue));
  q->count = 0;
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void print_queue(queue *q)
{
  queue_node *tmp;
  tmp = q->front;
  while (tmp != NULL)
  {
    printf("%d\t", tmp->n->data);
    tmp = tmp->next;
  }
  printf("\n");
}

void bfs(graph *g)
{
  node *s = &g->heads[0];
  int i;

  for (i = 0; i < g->number_of_vertices; i++)
  {

    g->heads[i].colr = White;
  }
  s->colr = Gray;

  queue *q = make_queue();
  enqueue(q, s);

  while (!is_empty_queue(q))
  {
    queue_node *u = dequeue(q);
    list_node *temp;
    temp = u->n->head;
    while (temp != NULL)
    {
      if (g->heads[temp->index_of_item].colr == White)
      {
        g->heads[temp->index_of_item].colr = Gray;
        enqueue(q, &g->heads[temp->index_of_item]);
      }
      temp = temp->next;
    }
    u->n->colr = Black;
    printf("%d\n", u->n->data);
  }
}

void dfs_visit(graph *g, node *u, int *time)
{
  u->colr = Gray;
  u->discovery_time = ++(*time);

  printf("Node %d discovered at time %d\n", u->data, u->discovery_time);

  list_node *temp = u->head;

  while (temp != NULL)
  {
    if (g->heads[temp->index_of_item].colr == White)
    {
      dfs_visit(g, &g->heads[temp->index_of_item], time);
    }
    temp = temp->next;
  }

  u->colr = Black;
  u->finish_time = ++(*time);
  printf("Node %d finished at time %d\n", u->data, u->finish_time);
}

void dfs_print(graph *g, node *u, int *time)
{
  u->colr = Gray;
  u->discovery_time = ++(*time);

  printf("%d\n", u->data);

  list_node *temp = u->head;

  while (temp != NULL)
  {
    if (g->heads[temp->index_of_item].colr == White)
    {
      dfs_print(g, &g->heads[temp->index_of_item], time);
    }
    temp = temp->next;
  }

  u->colr = Black;
  u->finish_time = ++(*time);
}

void dfs(graph *g)
{
  int time = 0;
  int i;
  for (i = 0; i < g->number_of_vertices; i++)
  {
    g->heads[i].colr = White;
  }
  for (i = 0; i < g->number_of_vertices; i++)
  {
    if (g->heads[i].colr == White)
    {
      dfs_visit(g, &g->heads[i], &time);
    }
  }
  printf("\n\nDFS traversal\n");
  for (i = 0; i < g->number_of_vertices; i++)
  {
    g->heads[i].colr = White;
  }
  for (i = 0; i < g->number_of_vertices; i++)
  {
    if (g->heads[i].colr == White)
    {
      dfs_print(g, &g->heads[i], &time);
    }
  }
}

typedef struct Stack
{
  int data;
  struct Stack *next;
} Stack;
Stack *createStackNode(int data)
{
  Stack *newNode = malloc(sizeof(Stack));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void topologicalSortUtil(graph *g, int v, int *visited, Stack **stack)
{
  visited[v] = 1;
  list_node *current = g->heads[v].head;
  while (current != NULL)
  {
    int adjacentVertex = current->index_of_item;
    if (!visited[adjacentVertex])
    {
      topologicalSortUtil(g, adjacentVertex, visited, stack);
    }
    current = current->next;
  }

  Stack *newNode = createStackNode(v);
  newNode->next = *stack;
  *stack = newNode;
}

void topologicalSort(graph *g)
{
  Stack *stack = NULL;

  int *visited = malloc(g->number_of_vertices * sizeof(int));
  for (int i = 0; i < g->number_of_vertices; i++)
  {
    visited[i] = 1;
  }
  for (int i = 0; i < g->number_of_vertices; i++)
  {

    if (!visited[i])
    {
      topologicalSortUtil(g, i, visited, &stack);
    }
  }

  while (stack != NULL)
  {
    printf("%d ", stack->data);
    Stack *temp = stack;
    stack = stack->next;
    free(temp);
  }

  free(visited);
}

int main()
{
  int s, d, n;
  printf("Enter size of graph: ");
  scanf("%d", &n);
  graph *g = new_graph(n);

  while (1)
  {
    printf("\nEnter starting vertex: ");
    scanf("%d", &s);
    printf("Enter destination vertex: ");
    scanf("%d", &d);
    add_edge(g, s, d);
    printf("\nType 0 0 to exit\n");
    if (s == 0 && d == 0)
      break;
  }
  printf("Graph Representation:\n");
  print_graph(g);

  printf("\nBFS Traversal:\n");
  bfs(g);
  printf("\nDFS Traversal:\n");
  dfs(g);

  printf("\nTopological Sort:\n");
  topologicalSort(g);

  free(g);

  return 0;
}
