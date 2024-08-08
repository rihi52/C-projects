import tkinter as tk
from tkinter import ttk
from creatures import *

root=tk.Tk()
root.title("Combat Tracker V0.0")
root.minsize(width=800, height=400)

canvas1=tk.Canvas(master= root, highlightthickness=0)
canvas1.grid(column= 0, row= 0)

canvas2=tk.Canvas(master =root, highlightthickness=0)
canvas2.grid(row= 0, column= 1)

choiceNames = []
choiceQuantity = []
choiceButtons = []
choiceHp = []
choiceInitiative = []
choiceAc = []
chosenCreatures = []
rowCount = 0
rowCount2 = 0

def get_quantity(x):
    global rowCount2
    global chosenCreatures
    rowCount2 += 1
    qty = choiceQuantity[x].get()
    chosenCreatures.append(tk.Label(master=canvas2, text=f'{qty} {choices[x].name}', justify='left', anchor= W))
    chosenCreatures[-1].grid(sticky = W, row= rowCount2, column=0, columnspan=1, rowspan=1,pady=5)
    return
    
for _ in range(len(choices)):
    colCount = 0    
    choiceNames.append(tk.Label(master=canvas1, text=choices[_].name))
    choiceNames[_].grid(row=rowCount,column=colCount, columnspan=1, rowspan=1,pady=(5, 2))
    colCount += 1
    choiceHp.append(tk.Label(master=canvas1, text=f'HP: {choices[_].hp}'))
    choiceHp[_].grid(row=rowCount,column=colCount, columnspan=1, rowspan=1,pady=(5, 2))
    colCount += 1
    choiceInitiative.append(tk.Label(master=canvas1, text=f'Init: {choices[_].initiative}'))
    choiceInitiative[_].grid(row=rowCount,column=colCount, columnspan=1, rowspan=1,pady=(5, 2))
    colCount += 1
    choiceAc.append(tk.Label(master=canvas1, text=f'AC: {choices[_].ac}'))
    choiceAc[_].grid(row=rowCount,column=colCount, columnspan=1, rowspan=1,pady=(5, 2))
    colCount += 1
    choiceQuantity.append(tk.Entry(master=canvas1, width=5))
    choiceQuantity[_].grid(row=rowCount,column=colCount, columnspan=1, rowspan=1,pady=(5, 2)) 
    colCount += 1
    choiceButtons.append(tk.Button(master=canvas1, command=lambda _=_: get_quantity(_), text='Add', width=10))
    choiceButtons[_].grid(row=rowCount, column=colCount, columnspan=1, rowspan=1,pady=(5, 2))
    rowCount += 1

print(rowCount)
root.mainloop()