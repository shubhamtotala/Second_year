# Write a Python program to draw simple polygons(Square,Rectangle,Triangle) using mouse click event

#!/usr/bin/python

from Tkinter import *

canvas = Canvas(width=800, height=800, bg='white')
#canvas.pack(expand=YES, fill=BOTH)      
 
canvas.create_text(400,300,text="Output of a Python program to draw simple polygons(Square,Rectangle,Triangle)using mouse click event", fill='black',font=("arial","15"))       

class Handler:
     rectangle on mouse click event
	     def_init_(self, canvas):
	        self.canvas = canvas
		canvas.bind("<Button-1>", self.xaxix)
		canvas.bind("<ButtonRelease-1>", self.create)
        
    	    def xaxis(self, event):
		self.x1, self.y1 = (event.x - 1),(event.y - 1)  
    
            def yaxis(self, event):
		self.x2, self.y2 = (event.x + 1),(event.y + 1)  
	
            def create(self, event):
		self.yaxis(event)
		self.canvas.create_rectangle
        
(self.x1,self.y1,self.x2,self.y2,fill='yellow')
	
   canvas.config(cursor='cross')
   canvas.pack(expand=YES, fill=BOTH)      
Handler(canvas)
mainloop()
 
