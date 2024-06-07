import tkinter as tk
import sqlite3

window=tk.Tk()
window.title("Read Kayako Ticket V0.0")

canvas1=tk.Canvas(window,width=1000,height=250)
canvas1.pack()

def SqlIDLookUp(IDlookUp):
    # SQL connection
    conn = sqlite3.connect(r"C:\Users\hirer\Documents\np++\databases\kayakoexport.db")
    cursor = conn.cursor()
    conn.text_factory = str
    sql = 'SELECT Subject FROM tickets WHERE "Case ID" = "{}"'.format(IDlookUp)
    IDfetch = cursor.execute(sql).fetchall()
    if len(IDfetch) <= 0:
        idLabelReturn.config(text="Not a Ticket", fg="black", bg="red")
    else:
        Subject = IDfetch[0][0]
        conn.close()
        idLabelReturn.config(text=Subject, bg="white")
    
def SqlNameLookUp(IDlookUp):
    # SQL connection
    conn = sqlite3.connect(r"C:\Users\hirer\Documents\np++\databases\kayakoexport.db")
    cursor = conn.cursor()
    conn.text_factory = str
    sql = 'SELECT "Requester Name" FROM tickets WHERE "Case ID" = "{}"'.format(IDlookUp)
    Namefetch = cursor.execute(sql).fetchall()
    if len(Namefetch) <= 0:
        idLabelNameReturn.config(text=" ")
    else:
        Subject = Namefetch[0][0]
        conn.close()
        idLabelNameReturn.config(text=Subject)

def SqlTicketLookUp(RequesterName):
    # SQL connection
    conn = sqlite3.connect(r"C:\Users\hirer\Documents\np++\databases\kayakoexport.db")
    cursor = conn.cursor()
    conn.text_factory = str
    sql = 'SELECT "Case ID", "Requester Name", Subject FROM tickets WHERE "Requester Name" = "{}" LIMIT 1'.format(RequesterName)
    Namefetch = cursor.execute(sql).fetchall()
    Subject = []
    if len(Namefetch) <= 0:
        idLabelReturn.config(text="Not a Name", fg="black", bg="red")
    else:
        for i in range(3):
            Subject.append(Namefetch[0][i])
        #subjectVar = tk.StringVar(Subject)
        conn.close()
        ticketList.insert(tk.END, Subject)
        #choices.append(Subject)

def OnClick():
    IDlookUp = idEntry.get()
    NameLookUp = idRequesterNameEntry.get()
    
    if len(IDlookUp) <= 0 and len(NameLookUp) <= 0:
        idLabelReturn.config(text="Invalid Entry", fg="black", bg="red")
        return
    elif len(IDlookUp) > 0 and len(NameLookUp) <= 0:
        SqlIDLookUp(IDlookUp)
        SqlNameLookUp(IDlookUp)
    elif len(IDlookUp) <= 0 and len(NameLookUp) > 0:
        SqlTicketLookUp(NameLookUp)
    else:
        idLabelReturn.config(text="Invalid Entry", fg="black", bg="red")
        return

# Top label, ID entry, and button
frame1 = tk.Frame(window)
frame1.place(x=0, y=0)

# Subject Label
frame2 = tk.Frame(window, relief=tk.RAISED)
frame2.place(x=0, y=75)

# Subject return
frame3 = tk.Frame(window, bg="white")
frame3.place(x=0, y=90)

# Requester Name label
frame4 = tk.Frame(window)
frame4.place(x=0, y=115)

# Requester name return
frame5 = tk.Frame(window)
frame5.place(x=0, y=130)

# Requester name Search
frame6 = tk.Frame(window)
frame6.place(x=150, y=0)

# ID entry label, entry, and button
idLabelNew = tk.Label(master=frame1, text="New Ticket ID", fg="white", bg="black")
idLabelNew.pack()
idEntry = tk.Entry(master=frame1)
idEntry.pack()
button = tk.Button(master=frame1, text="Search", command=OnClick)
button.pack()

# Requester Name Input
idLabelRequesterName = tk.Label(master=frame6, text="Requester Name", fg="white", bg="black")
idLabelRequesterName.pack()
idRequesterNameEntry = tk.Entry(master=frame6)
idRequesterNameEntry.pack()

# Subject header and label return
idLabelSubject = tk.Label(master=frame2, text="Subject")
idLabelSubject.pack()
idLabelReturn = tk.Label(master=frame3)
idLabelReturn.pack()

# Requester name header and label return
idLabelName = tk.Label(master=frame4, text="Requester")
idLabelName.pack()
idLabelNameReturn = tk.Label(master=frame5)
idLabelNameReturn.pack()

# Ticket List
choices = []
choicesvar = tk.StringVar(value=choices)
ticketList = tk.Listbox(master=window, height=15, listvariable=choicesvar)
ticketList.pack(fill=tk.X)

window.mainloop()