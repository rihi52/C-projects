from tkinter import *
from tkinter import ttk

class Enemy:
    def __init__(self, name, ac, hp, init):
        self.name = name
        self.ac = ac
        self.hp = hp
        self.init = init
        
    def __str__(self) -> str:
        return f"{self.name}"

orc = Enemy("Orc", 13, 15, 11)
orog = Enemy("Orog", 18, 42, 11)
bandit = Enemy("Bandit", 12, 11, 11)
banditCaptain = Enemy("Bandit Captain", 15, 65, 13)
