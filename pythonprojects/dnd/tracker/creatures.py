from tkinter import *
from tkinter import ttk

class Enemy:
    def __init__(self, name, ac, hp, initiative):
        self.name = name
        self.ac = ac
        self.hp = hp
        self.initiative = initiative
        
    def __str__(self) -> str:
        return f"{self.name}"

choices = [
    Enemy("Orc", 13, 15, 11),
    Enemy("Orog", 18, 42, 11),
    Enemy("Bandit", 12, 11, 11),
    Enemy("Bandit Captain", 15, 65, 13)]
