import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv
import mpl_toolkits.mplot3d.axes3d as d3

def get_data(file_name):
    with open(file_name) as f:
        reader=csv.reader(f)
        data=np.array(list(reader))

    data=data.astype(float)
    return data

data1=get_data('output1.txt')
data2=get_data('output2.txt')

fig=plt.figure()
axs = d3.Axes3D(fig)

axs.set_xlim3d([-50, 50])
axs.set_xlabel('X')

axs.set_ylim3d([-30, 30])
axs.set_ylabel('Y')

axs.set_zlim3d([-10, 55])
axs.set_zlabel('Z')


frames=len(data1[:,0])

data=[data1,data2]


lines = [axs.plot(dat[:,0][0],dat[:,1][0],dat[:,2][0])[0] for dat in data]


def points(i,data,lines):
    for adat,line in zip(data,lines): 
        line.set_data(adat[:,0][:i],adat[:,1][:i])
        line.set_3d_properties(adat[:,2][:i])
    return lines


ani = FuncAnimation(fig, points, frames=frames,fargs=(data,lines), blit=False,interval=1,cache_frame_data=True)

plt.show()
