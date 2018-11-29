#include <stdio.h>
#include <stdlib.h>

#include "is.h"
#include "graph.h"

il *dfs(graph *g, unsigned int start_key)
{
  il *reached = NULL;
  is *s = is_new();
  if (start_key>=g->n_vertices) {
    fprintf(stderr,"dfs: no such vertex (%u)\n",start_key);
    exit(1);
  }
  push(s,start_key);
  while (s->ns!=NULL) {
    int curr = pop(s);
    if (g->vs[curr]->done)
      continue;
    reached = il_append(reached,il_singleton(curr));
    g->vs[curr]->done = 1;
    il *neighbors = g->es[curr];
    while (neighbors) {
      int n = neighbors->n;
      push(s,n);
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

  printf("--- depth-first search ---\n");
  il *ns = dfs(g,0);
  graph_show_labels(g,ns);
  putchar('\n');

  return 0;
}
