import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv
import mpl_toolkits.mplot3d.axes3d 

def get_data(file_name):
    with open(file_name) as f:
        reader=csv.reader(f)
        data=np.array(list(reader))

    data=data.astype(float)
    return data

data1=get_data('output1.txt')
data2=get_data('output2.txt')

fig=plt.figure()
axs = plt.axes(xlim=(-20,30),ylim=(-10,60))


xdata1, ydata1 = [], []
xdata2,ydata2=[], []
im, = axs.plot([], [])

frames=len(data1[:,0])

colors=["orange","red"]


lines = []
for index in range(2):
    lobj = axs.plot([],[],lw=2,color=colors[index])[0]
    lines.append(lobj)


def init():
    for line in lines:
        line.set_data([],[])
    return lines


def points(i):
    xdata1.append(data1[:,0][i])
    ydata1.append(data1[:,2][i])

    xdata2.append(data2[:,0][i])
    ydata2.append(data2[:,2][i])


    xlist=[xdata1,xdata2]
    ylist=[ydata1,ydata2]

    for c,line in enumerate(lines): 
        line.set_data(xlist[c],ylist[c])

    return lines


ani = FuncAnimation(fig, points, frames=frames,init_func=init, blit=True,interval=1)

plt.show()
