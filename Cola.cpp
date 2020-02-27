#include "nodoCola.hpp" 
  
class Cola { 
    int size;      // Number of heap nodes present currently 
    int capacity;  // Capacity of min heap 
    int *pos;     // This is needed for decreaseKey() 
    linkedList<nodoCola> listaElementos; 
    
    public:
  
        Cola (int capacity) { 
            struct Cola* minHeap = new Cola;
            minHeap->pos = (int *)malloc(capacity * sizeof(int)); 
            minHeap->size = 0; 
            minHeap->capacity = capacity; 
            minHeap->listaElementos = new linkedList<nodoCola>; 
            return minHeap; 
        }

        // A utility function to create a new Min Heap Node 
        nodoCola* añadirNodoCola(T valor, int dist) { 
            struct nodoCola* minHeapNode = new nodoCola;
            minHeapNode->valor = valor; 
            minHeapNode->dist = dist; 
            return minHeapNode; 
        } 
        
        // A utility function to swap two nodes of min heap. Needed for min heapify 
        void swapNodos(struct nodoCola** desde, struct nodoCola** hasta){ 
            struct nodoCola* tmp = *desde; 
            *desde = *hasta; 
            *hasta = *tmp; 
        } 
        
        // A standard function to heapify at given idx REVISAR REVISAR REVISAR
        // This function also updates position of nodes when they are swapped. 
        // Position is needed for decreaseKey() 
        void minHeapify(struct Cola* minHeap, int idx) //REVISAR
        { 
            int smallest, left, right; 
            smallest = idx; 
            left = 2 * idx + 1; 
            right = 2 * idx + 2; 
        
            if (left < minHeap->size && 
                minHeap->array[left]->dist < minHeap->array[smallest]->dist ) 
            smallest = left; 
        
            if (right < minHeap->size && 
                minHeap->array[right]->dist < minHeap->array[smallest]->dist ) 
            smallest = right; 
        
            if (smallest != idx) 
            { 
                // The nodes to be swapped in min heap 
                nodoCola *smallestNode = minHeap->array[smallest]; 
                nodoCola *idxNode = minHeap->array[idx]; 
        
                // Swap positions 
                minHeap->pos[smallestNode->valor] = idx; 
                minHeap->pos[idxNode->valor] = smallest; 
        
                // Swap nodes 
                swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]); 
        
                minHeapify(minHeap, smallest); 
            } 
        } 
        
        // A utility function to check if the given minHeap is ampty or not 
        int isEmpty(struct Cola* minHeap) 
        { 
            return minHeap->size == 0; 
        } 
        
        // Standard function to extract minimum node from heap 
        struct nodoCola* extractMin(struct Cola* minHeap) { //REVISAR 
            if (isEmpty(minHeap)) 
                return NULL; 
        
            // Store the root node 
            struct nodoCola* root = minHeap->array[0]; 
        
            // Replace root node with last node 
            struct nodoCola* lastNode = minHeap->array[minHeap->size - 1]; 
            minHeap->array[0] = lastNode; 
        
            // Update position of last node 
            minHeap->pos[root->valor] = minHeap->size-1; 
            minHeap->pos[lastNode->valor] = 0; 
        
            // Reduce heap size and heapify root 
            --minHeap->size; 
            minHeapify(minHeap, 0); 
        
            return root; 
        } 
        
        // Function to decreasy dist value of a given vertex valor. This function 
        // uses pos[] of min heap to get the current index of node in min heap 
        void decreaseKey(struct Cola* minHeap, int valor, int dist){ //REVISAR
            // Get the index of valor in  heap array 
            int i = minHeap->pos[valor]; 
        
            // Get the node and update its dist value 
            minHeap->array[i]->dist = dist; 
        
            // Travel up while the complete tree is not hepified. 
            // This is a O(Logn) loop 
            while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist) 
            { 
                // Swap this node with its parent 
                minHeap->pos[minHeap->array[i]->valor] = (i-1)/2; 
                minHeap->pos[minHeap->array[(i-1)/2]->valor] = i; 
                swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]); 
        
                // move to parent index 
                i = (i - 1) / 2; 
            } 
        } 
        
        // A utility function to check if a given vertex 
        // 'valor' is in min heap or not 
        bool isInMinHeap(struct Cola *minHeap, int valor) 
        { 
        if (minHeap->pos[valor] < minHeap->size){ 
            return true; 
        }
        return false; 
        } 
        
        // A utility function used to print the solution 
        void printArr(int dist[], int n) 
        { 
            printf("Vertex   Distance from Source\n"); 
            for (int i = 0; i < n; ++i) 
                printf("%d \t\t %d\n", i, dist[i]); 
        } 

}
