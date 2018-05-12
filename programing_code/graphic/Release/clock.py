from turtle import *
from datetime import *
 
def Skip(step):
    penup()
    forward(step)
    pendown()
 
def mkHand(name, length):
    #注册Turtle形状，建立表针Turtle
    reset()  #清空当前窗口，并重置位置等信息为默认值
    Skip(-length*0.1)
    begin_poly()
    forward(length*1.1)
    end_poly()
    handForm = get_poly()
    register_shape(name, handForm) 
 
def Init():
    global secHand, minHand, hurHand, printer
    mode("logo")# 重置Turtle指向北
    #建立三个表针Turtle并初始化
    mkHand("secHand", 135)
    mkHand("minHand",  110)
    mkHand("hurHand", 90)
    secHand = Turtle()
    secHand.shape("secHand")
    minHand = Turtle()
    minHand.shape("minHand")
    hurHand = Turtle()
    hurHand.shape("hurHand")
    for hand in secHand, minHand, hurHand:
        hand.shapesize(1, 1, 3)
        hand.speed(0)
    #建立输出文字Turtle
    printer = Turtle()
    printer.hideturtle()
    printer.penup()
     
def SetupClock(radius):
    #建立表的外框
    reset()
    pensize(7)
    for i in range(60):
        Skip(radius)
        if i % 5 == 0:
            forward(20)
            Skip(-radius-20)
        else:
            dot(5)
            Skip(-radius)
        right(6)
         
def Week(t):    
    week = ["星期一", "星期二", "星期三",
            "星期四", "星期五", "星期六", "星期日"]
    return week[t.weekday()]
 
def Date(t):
    y = t.year
    m = t.month
    d = t.day
    return "%s %d %d" % (y, m, d)
 
def Tick():
    #绘制表针的动态显示
    t = datetime.today()
    second = t.second + t.microsecond*0.000001
    minute = t.minute + second/60.0
    hour = t.hour + minute/60.0
    secHand.setheading(6*second) #设置朝向，每秒转动6度
    minHand.setheading(6*minute)
    hurHand.setheading(30*hour)
     
    tracer(False)  #不显示绘制的过程，直接显示绘制结果
    printer.forward(65)
    printer.write(Week(t), align="center",
                  font=("Courier", 14, "bold"))
    printer.back(130)
    printer.write(Date(t), align="center",
                  font=("Courier", 14, "bold"))
    printer.back(50)

    printer.home()
    tracer(True)
 
    ontimer(Tick, 1000)#1000ms后继续调用tick
 
def main():
    tracer(False) #使多个绘制对象同时显示
    Init()
    SetupClock(160)
    tracer(True)
    Tick()
    mainloop()
      
      
main()
