
class Graph{
    
    
public:

    int numeroDeNodos;
    int numeroDeAristas;
    linkedList<nodeGraph> nodos;
    linkedList<Edge> edges;

    Graph(){
    
        nodos = new linkedList<nodeGraph>;
        edges = new linkedList<Edge>;
        
    }

    int anadirNodo(int valor, int weight){
        nodeGraph<T> *nuevoNodo = new nodeGraph<int>;
        nuevoNodo->valor = valor;
        nuevoNodo->cost = weight;
        nodos.insertarFinal(nuevoNodo);
         numeroDeNodos++;
        return 0;
    }

    int anadirArista(int peso,int inicio, int destino){
        NodeGraph*<T> inicioNodo = nodos.obtenerValor(inicio);
        NodeGraph*<T> finNodo = nodos.obtenerValor(destino);
        Edge* edge = new Edge(peso,numeroDeAristas,inicioNodo,finNodo);
        inicioNodo->edges.añadirFinal(edge);
        edges.insertarFinal(edge);
        numeroDeAristas++;
        return 0;
    }
    
    // The main function that calulates distances of shortest paths from src to all 
    // vertices. It is a O(ELogV) function 
    void dijkstra(struct Graph* graph, int src){ 
        int V = graph->V;// Get the number of vertices in graph 
        int dist[V];      // dist values used to pick minimum weight edge in cut 
    
        // minHeap represents set E 
        struct MinHeap* minHeap = createMinHeap(V); 
    
        // Initialize min heap with all vertices. dist value of all vertices  
        for (int v = 0; v < V; ++v){ 
            dist[v] = INT_MAX; 
            minHeap->array[v] = newMinHeapNode(v, dist[v]); 
            minHeap->pos[v] = v; 
        } 
    
        // Make dist value of src vertex as 0 so that it is extracted first 
        minHeap->array[src] = newMinHeapNode(src, dist[src]); 
        minHeap->pos[src]   = src; 
        dist[src] = 0; 
        decreaseKey(minHeap, src, dist[src]); 
    
        // Initially size of min heap is equal to V 
        minHeap->size = V; 
    
        // In the followin loop, min heap contains all nodes 
        // whose shortest distance is not yet finalized. 
        while (!isEmpty(minHeap)) 
        { 
            // Extract the vertex with minimum distance value 
            struct MinHeapNode* minHeapNode = extractMin(minHeap); 
            int u = minHeapNode->v; // Store the extracted vertex number 
    
            // Traverse through all adjacent vertices of u (the extracted 
            // vertex) and update their distance values 
            struct AdjListNode* pCrawl = graph->array[u].head; 
            while (pCrawl != NULL) 
            { 
                int v = pCrawl->dest; 
    
                // If shortest distance to v is not finalized yet, and distance to v 
                // through u is less than its previously calculated distance 
                if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&  
                                            pCrawl->weight + dist[u] < dist[v]) 
                { 
                    dist[v] = dist[u] + pCrawl->weight; 
    
                    // update distance value in min heap also 
                    decreaseKey(minHeap, v, dist[v]); 
                } 
                pCrawl = pCrawl->next; 
            } 
        }    
  
        // print the calculated shortest distances 
        printArr(dist, V); 
    }    
}

