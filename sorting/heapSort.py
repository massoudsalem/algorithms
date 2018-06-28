# This heap sort algorithm is written by Moh.Massoud in 25Jan18
class minHeap:
    def __init__(self,list=[]):
        self.heap=[]
        for i in list:
            self.insertNode(i)
    def __str__(self):
        return "{}".format(self.heap)
    def size(self):
        return len(self.heap) if len(self.heap) else print("The heap doesn't contain any elements.")
    def top(self):
        return self.heap[0] if len(self.heap) else print("The heap doesn't contain any elements.")
    def getLeftChild(self,node):
        child=2*node+1
        return child if child<len(self.heap) else -1
    def getRightChild(self,node):
        child=2*node+2
        return child if child<len(self.heap) else -1
    def getParent(self,node):
        return int((node-1)/2) if node!=0 else -1
    def reHeapUp(self,node):
        parent=self.getParent(node)
        if node == 0 or self.heap[parent]<self.heap[node]:
            return
        self.heap[parent],self.heap[node]=self.heap[node],self.heap[parent]
        self.reHeapUp(parent)
    def reHeapDown(self,node):
        minChild=self.getLeftChild(node)
        if minChild==-1:
            return
        rightChild=self.getRightChild(node)
        if self.heap[minChild]>self.heap[rightChild]:
            minChild=rightChild
        if self.heap[node]>self.heap[minChild]:
            self.heap[minChild], self.heap[node] = self.heap[node], self.heap[minChild]
            self.reHeapDown(minChild)
    def insertNode(self,node):
        self.heap.append(node)
        self.reHeapUp(self.size()-1)
    def removeTop(self):
        if self.size()!=0:
            self.heap[0]=self.heap[-1]
            self.heap.pop()
            self.reHeapDown(0)
class maxHeap:
    def __init__(self,list=[]):
        self.heap=[]
        for i in list:
            self.insertNode(i)
    def __str__(self):
        return "{}".format(self.heap)
    def size(self):
        return len(self.heap) if len(self.heap) else print("The heap doesn't contain any elements.")
    def top(self):
        return self.heap[0] if len(self.heap) else print("The heap doesn't contain any elements.")
    def getLeftChild(self,node):
        child=2*node+1
        return child if child<len(self.heap) else -1
    def getRightChild(self,node):
        child=2*node+2
        return child if child<len(self.heap) else -1
    def getParent(self,node):
        return int((node-1)/2) if node!=0 else -1
    def reHeapUp(self,node):
        parent=self.getParent(node)
        if node == 0 or self.heap[parent]>self.heap[node]:
            return
        self.heap[parent],self.heap[node]=self.heap[node],self.heap[parent]
        self.reHeapUp(parent)
    def reHeapDown(self,node):
        maxChild=self.getLeftChild(node)
        if maxChild==-1:
            return
        rightChild=self.getRightChild(node)
        if self.heap[maxChild]<self.heap[rightChild]:
            maxChild=rightChild
        if self.heap[node]<self.heap[maxChild]:
            self.heap[maxChild], self.heap[node] = self.heap[node], self.heap[maxChild]
            self.reHeapDown(maxChild)
    def insertNode(self,node):
        self.heap.append(node)
        self.reHeapUp(self.size()-1)
    def removeTop(self):
        if self.size()!=0:
            self.heap[0]=self.heap[-1]
            self.heap.pop()
            self.reHeapDown(0)

def heapSort(list,Max=False):
    if Max:
        heap=minHeap(list)
    else:
        heap=maxHeap(list)
    for i in range(len(list)):
        list[i]=heap.top()
        heap.removeTop()


x=[43,355,4234,23,43]
print(x)
heapSort(x)
print(x)
heapSort(x,1)
print(x)