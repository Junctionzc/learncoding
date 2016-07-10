class Queue():
     def __init__(self, max_elements):
         self.queue = []
         self.max_elements = max_elements
         
     def enqueue(self, element):
         if not self.is_full():
             self.queue.append(element)
             return "Element %s enqueue successed!" % (str(element))
         else:
             return "Queue is full!"
         
     def dequeue(self):
         if not self.is_empty():
             return self.queue.pop(0)
         else:
             return "Queue is empty!"
         
     def is_empty(self):
         if len(self.queue) == 0:
             return True
         else:
             return False
     
     def is_full(self):
         if len(self.queue) == self.max_elements:
             return True
         else:
             return False
         
if __name__ == '__main__':
    q = Queue(3)
    
    q.enqueue('1')
    q.enqueue('2')
    q.enqueue('3')
    q.enqueue('4')
    
    print q.dequeue()
    print q.dequeue()
    print q.dequeue()
    print q.dequeue()
    