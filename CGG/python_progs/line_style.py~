# write a program in Python to draw a line with different line styles(thick,Thin,Dotted)

#!/user/bin/python

from Tkinter import *

canvas = Canvas(width=800, height=800, bg='white',borderwidth=5,relief='raised') #To create canvas
canvas.pack(expand=YES, fill=BOTH) 

canvas.create_text(370,100,text="Ouptput of a prog in Python to draw a line with different line styles(Thick,Dashed,Dotted)",fill="black",font=("Arial","13"))#to dispaly the text on canvas
										
canvas.create_line(30,100,80,200,fill="blue",dash=(14,4))
              #dash=(9,4) produces alternating 14-pixel dashes separated by 4-pixel gaps.Produces a dashed line.

canvas.create_line(200,200,300,300,fill="green",dash=(1,1))#Produces a dotted line.

canvas.create_line(20,20,80,80,fill="violet",width=20)#Produces a thick line.

mainloop() #Exit from Tkinter


