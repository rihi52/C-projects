import tkinter as tk
from tkinter import ttk
import sqlite3

window=tk.Tk()
window.title("Read Kayako Ticket V0.0")
window.minsize(width=1020, height=300)

#canvas1=tk.Canvas(window,width=1000,height=250)
#canvas1.pack()

def SqlIDLookUp(IDlookUp):
    # SQL connection
    conn = sqlite3.connect(r"kayakoexport.db")
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
        ticketList.insert("", tk.END, values =(Subject), tags = ('evenrow',))
        Subject = []
    conn.close()

def SqlTicketLookUp(RequesterName):
    # SQL connection
    conn = sqlite3.connect(r"kayakoexport.db")
    cursor = conn.cursor()
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
        if rows % 2 == 0:
            ticketList.insert("", tk.END, values =(Subject), tags = ('evenrow',))
        else:
            ticketList.insert("", tk.END, values =(Subject), tags = ('oddrow',))
        Subject = []
    conn.close()

def SqlContentsLookUp(IDcontents):
        # SQL connection
    conn = sqlite3.connect(r"kayakoexport.db")
    cursor = conn.cursor()
    sql = cursor.execute('SELECT Status FROM tickets WHERE "Case ID"=?', (IDcontents,))
    Namefetch = sql.fetchall()
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
    contentsText = SqlContentsLookUp(LookUp)
    contentsTextOutput = tk.Text(master=newWindow)
    contentsTextOutput.insert("1.0", contentsText)
    contentsTextOutput.pack()
    contentsTextOutput.configure(state="disabled")   
    newWindow.title("New Window")

#### Frames ####
# ID Search
frame1 = tk.Frame(window)
frame1.grid(row=0,column=0)

# Requester name Search
frame2 = tk.Frame(window)
frame2.grid(row=0,column=1)

# Buttons
frame3 = tk.Frame(window)
frame3.grid(row=0,column=2)

# Treeview
frame4 = tk.Frame(window)
frame4.grid(row=1,column=0, columnspan=3, rowspan=5)

#### Widgets ####
# ID entry label and entry
idLabelNew = tk.Label(master=frame1, relief='raised', text="New Ticket ID", fg="white", bg="black")
idLabelNew.pack(side='top')
idEntry = tk.Entry(master=frame1)
idEntry.pack(side='top')

# Search Button
button = tk.Button(master=frame3, text="Search", command=OnClick)
button.pack(side='top')

# Requester Name Input
idLabelRequesterName = tk.Label(master=frame2, text="Requester Name", relief='raised', fg="white", bg="black")
idLabelRequesterName.pack()
idRequesterNameEntry = tk.Entry(master=frame2)
idRequesterNameEntry.pack()

# Open Details Button
button2 = tk.Button(master=frame3, text="Open", command=OpenDetails)
button2.pack()

# Ticket List
cols = ("Ticket ID","Requester", "Subject", "Order Number", "Press Type & Serial Number")
ticketList = ttk.Treeview(master=frame4, columns=cols, show="headings", selectmode ='browse')
ticketList.tag_configure('evenrow', background='light blue')
ticketList.tag_configure('oddrow', background='white')
for col in cols:
    ticketList.heading(col, text=col)
ticketList.column("Ticket ID", width=100, stretch='YES', anchor='center')
ticketList.column("Requester", width=100, stretch='YES', anchor='center')
ticketList.column("Order Number", width=100, stretch='YES', anchor='center')
ticketList.column("Press Type & Serial Number", width=500, stretch='YES', anchor='center')
ticketList.pack(side='left', fill='y')

verscrlbar = ttk.Scrollbar(master=frame4, orient="vertical", command = ticketList.yview)
verscrlbar.pack(side='right', fill='y')

ticketList.configure(yscrollcommand = verscrlbar.set)

window.mainloop()