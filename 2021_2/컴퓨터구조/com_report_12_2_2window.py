import tkinter as tk
from tkinter import *
from tkinter import messagebox
from tkinter import scrolledtext
import com_report_12_2 as cr_12



win = Tk()
win.geometry("")
win.option_add("*Font","굴림 15")
win.title("비복원나눗셈알고리즘")



def main():
    def get_attribute():

        bit=int((ent0.get()))
        a=int((ent1.get()))
        b=int((ent2.get()))
        # c="0"*(2*len(a))
        # a_= ("0"*len(a))+a
        # b_=b+"0"
        global result
        first=str(a)+"%"+str(b)+"\n\n"
        result=first+cr_12.main2(bit,a,b)
        def createNewWindow():
            newWindow =tk.Toplevel(win)
            newWindow.title("비복원 나눗셈 결과")
            newWindow.resizable(width=False, height=False)
            log_text=scrolledtext.ScrolledText(newWindow)
            log_text.config(font=("굴림", 15))
            log_text.insert(END,result)
            log_text.configure(state='disabled')
            log_text.pack()
        createNewWindow()
                
    label0 = Label(win)
    label0.configure(text="출력할 몫의 비트수를 입력하시오")
    label0.pack()
    ent0=Entry(win)
    ent0.pack()

    label1 = Label(win)
    label1.configure(text="피제수를 입력하시오(10진수)")
    label1.pack()
    ent1 = Entry(win)
    ent1.pack()

    label2 = Label(win)
    label2.configure(text="제수를 입력하시오(10진수)")
    label2.pack()
    ent2 = Entry(win)
    ent2.pack()

        
    btn=Button(win)
    btn.config(text="계산")
    btn.config(command=get_attribute)

    btn.pack()
    
    
main()

win.mainloop()