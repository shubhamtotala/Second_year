# Write a Python program to draw simple polygons(Square,Rectangle,Triangle)

#!/usr/bin/python

from Tkinter import *

canvas = Canvas(width=800, height=800, bg='white')
canvas.pack(expand=YES, fill=BOTH)      
 
canvas.create_text(400,300,text="Output of a Python program to draw simple polygons(Square,Rectangle,Triangle)", fill='black',font=("arial","15"))       

canvas.create_rectangle(100, 150, 20, 25, width=3, fill='white')
        
canvas.create_rectangle(200, 100, 125, 25, width=3, fill='white')

canvas.create_oval(300, 100, 220, 20, width=3, fill='white')      
        
canvas.create_line(400, 120, 320, 120, width=3, fill='black') 

canvas.create_line(400, 120, 360, 50, width=3, fill='black') 

canvas.create_line(360, 50, 320, 120, width=3, fill='black') 


mainloop()  
     
