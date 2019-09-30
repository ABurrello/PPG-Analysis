import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
import matplotlib.animation as animation
import serial
from serial import Serial
import platform

print("Python version: " + platform.python_version())
print("matplotlib version: " + mpl.__version__)

fig, ax = plt.subplots()
#ax.set_xlabels("time[2ms]")
#ax.set_ylabels("ppg[LSB]")
line, = ax.plot(np.random.rand(1000),label="PPG signal")
ax.set_ylim(60000, 80000)
xdata, ydata = [0]*500, [0]*500
SerialIn = serial.Serial("/dev/ttyUSB1",9600)
xmin=0
xmax=500
x=0

def update(data):
    line.set_ydata(data)
    return line,

def run(data):
    global xdata, ydata
    x,y = data
    if (x == 0):
        xdata = [0]*500
        ydata = [0]*500
    del xdata[0]
    del ydata[0]
    xdata.append(x)
    ydata.append(y)
    line.set_data(xdata, ydata)
    return line,

def data_gen():
    global x
    while True:
        x += 1
        if x >= xmax-100:
            ax.set_xlim(x-xmax+100,x+100)


        try:
            inRaw = SerialIn.readline()
            inInt = int(inRaw)
        except:
            inInt = 0

        yield x, inInt

ani = animation.FuncAnimation(fig, run, data_gen, interval=0, blit=True)
plt.show()
