import tkinter as tk
from tkinter import ttk
import sqlite3
import re

window=tk.Tk()
window.title("Read Kayako Ticket V0.0")

canvas1=tk.Canvas(window,width=1000,height=250)
canvas1.pack()

def SqlIDLookUp(IDlookUp):
    # SQL connection
    conn = sqlite3.connect(r"C:\Users\hirer\Documents\np++\databases\kayakoexport.db")
    cursor = conn.cursor()
    conn.text_factory = str
    sql = cursor.execute('SELECT "Case ID", "Requester Name", Subject, "Conversation Order Number", "Conversation Press Type & Serial Number" FROM tickets WHERE "Case ID"=?',(IDlookUp,))
    Namefetch = sql.fetchall()
    numRows = 0
    for rows in Namefetch:
        numRows +=1
    Subject = []
    if len(Namefetch) <= 0:
        idLabelReturn.config(text="Not a Name", fg="black", bg="red")
    for rows in range(numRows):        
        for i in range (5):
            Subject.append(Namefetch[rows][i])
        ticketList.insert("", tk.END, values =(Subject))
        Subject = []
    conn.close()

def SqlTicketLookUp(RequesterName):
    # SQL connection
    conn = sqlite3.connect(r"C:\Users\hirer\Documents\np++\databases\kayakoexport.db")
    cursor = conn.cursor()
    #conn.text_factory = str
    sql = cursor.execute('SELECT "Case ID", "Requester Name", Subject, "Conversation Order Number", "Conversation Press Type & Serial Number" FROM tickets WHERE "Requester Name"=?', (RequesterName,))
    Namefetch = sql.fetchall()
    numRows = 0
    for rows in Namefetch:
        numRows +=1
    Subject = []
    if len(Namefetch) <= 0:
        idLabelReturn.config(text="Not a Name", fg="black", bg="red")
    for rows in range(numRows):        
        for i in range (5):
            Subject.append(Namefetch[rows][i])
        ticketList.insert("", tk.END, values =(Subject))
        Subject = []
    conn.close()

def SqlContentsLookUp(IDcontents):
        # SQL connection
    conn = sqlite3.connect(r"C:\Users\hirer\Documents\np++\databases\kayakoexport.db")
    cursor = conn.cursor()
    #conn.text_factory = str
    sql = cursor.execute('SELECT Status FROM tickets WHERE "Case ID"=?', (IDcontents,))
    Namefetch = sql.fetchall()
    #if len(Namefetch) <= 0:
    #    idLabelReturn.config(text="Not a Name", fg="black", bg="red")
    #else:    
    #    idLabelNewWindow.config(text=Namefetch[0][0])
    conn.close()
    return Namefetch[0][0]

def OnClick():
    ticketList.delete(*ticketList.get_children())
    IDlookUp = idEntry.get()
    NameLookUp = idRequesterNameEntry.get()    
    if len(IDlookUp) <= 0 and len(NameLookUp) <= 0:
        idLabelReturn.config(text="Invalid Entry", fg="black", bg="red")
        return
    elif len(IDlookUp) > 0 and len(NameLookUp) <= 0:
        SqlIDLookUp(IDlookUp)
    elif len(IDlookUp) <= 0 and len(NameLookUp) > 0:
        SqlTicketLookUp(NameLookUp)
    else:
        idLabelReturn.config(text="Invalid Entry", fg="black", bg="red")
        return
    
def OpenDetails():
    curItem = ticketList.focus()
    myValues = ticketList.item(curItem, 'values')
    LookUp=myValues[0]
    newWindow= tk.Toplevel()
    statusText = SqlContentsLookUp(LookUp)
    StatusTextOutput = tk.Text(master=newWindow)
    StatusTextOutput.insert("1.0", statusText)
    StatusTextOutput.pack()
    StatusTextOutput.configure(state="disabled")
    #idLabelNewWindow = tk.Label(master=newWindow, text=statusText, fg="white", bg="black")
    #idLabelNewWindow.pack()    
    newWindow.title("New Window")

# Top label, ID entry, and button
frame1 = tk.Frame(window)
frame1.place(x=0, y=0)

# Requester name Search
frame2 = tk.Frame(window)
frame2.place(x=150, y=0)

# ID entry label, entry, and button
idLabelNew = tk.Label(master=frame1, text="New Ticket ID", fg="white", bg="black")
idLabelNew.pack()
idEntry = tk.Entry(master=frame1)
idEntry.pack()
button = tk.Button(master=frame1, text="Search", command=OnClick)
button.pack()

# Requester Name Input
idLabelRequesterName = tk.Label(master=frame2, text="Requester Name", fg="white", bg="black")
idLabelRequesterName.pack()
idRequesterNameEntry = tk.Entry(master=frame2)
idRequesterNameEntry.pack()
button2 = tk.Button(master=frame2, text="Open", command=OpenDetails)
button2.pack()

# Ticket List
cols = ("Ticket ID","Requester","Subject", "Order Number", "Press Type & Serial Number")
ticketList = ttk.Treeview(master=window, columns=cols, show="headings")
for col in cols:
    ticketList.heading(col, text=col)
ticketList.column("Ticket ID", width=75, anchor='center')
#ticketList.bind("<Double-Button-1>", OnDoubleClick())
ticketList.pack(fill=tk.X)

window.mainloop()