#include <stdio.h>
#include <stdlib.h>

#include "iq.h"
#include "graph.h"

il *bfs(graph *g, unsigned int start_key)
{
  il *reached = NULL;
  iq *q = iq_new();
  if (start_key>=g->n_vertices) {
    fprintf(stderr,"bfs: no such vertex (%u)\n",start_key);
    exit(1);
  }
  enqueue(q,start_key);
  while (q->n>0) {
    int curr = dequeue(q);
    if (g->vs[curr]->done)
      continue;
    g->vs[curr]->done = 1;
    reached = il_append(reached,il_singleton(curr));
    il *neighbors = g->es[curr];
    while (neighbors) {
      int n = neighbors->n;
      enqueue(q,n);
      neighbors = neighbors->next;
    }
  }
  return reached;
}

int main(int argc, char *argv[])
{
  graph *g = sample_graph(0);
  if (argc>1)
    g = sample_graph(atoi(argv[1]));

  printf("--- graph ---\n");
  graph_show(g);
  putchar('\n');

  printf("--- breadth-first search ---\n");
  il *ns = bfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  return 0;
}
