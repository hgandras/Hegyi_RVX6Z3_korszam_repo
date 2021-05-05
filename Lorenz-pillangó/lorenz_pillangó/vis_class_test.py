import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import csv
import mpl_toolkits.mplot3d.axes3d as d3




class Visualize:


    


    def __init__(self,data,dim=2,plane=None,colors=[]):
        self.plane=plane
        self.dim=dim
        self.fig=plt.figure()
        self.colors=colors
        if self.dim==2:
            self.axs=plt.axes()
        if self.dim==3:
            self.axs=d3.Axes3D(self.fig)
        self.data=data
        self.lines=[self.axs.plot(dat[:,0][0],dat[:,1][0],dat[:,2][0],lw=1)[0] for count,dat in enumerate(self.data)]
        self.xdata,self.ydata,self.zdata=[[None] for h in range(len(data))],[[None] for h in range(len(data))],[[None] for h in range(len(data))]


    def init(self):
        for line in self.lines:
            line.set_data([],[])
        return self.lines
        
    def points(self,i):
        if self.dim==2:
            for count,dat in enumerate(self.data):
                self.xdata[count].append(dat[:,0][i])
                self.ydata[count].append(dat[:,1][i])
                self.zdata[count].append(dat[:,2][i])

            if self.plane=='xy':
                for c,line in enumerate(self.lines): 
                    line.set_data(self.xdata[c],self.ydata[c]) 
            if self.plane=='xz':
                for c,line in enumerate(self.lines): 
                    line.set_data(self.xdata[c],self.zdata[c]) 
            if self.plane=='yz':
                for c,line in enumerate(self.lines): 
                    line.set_data(self.ydata[c],self.zdata[c]) 
            

        if self.dim==3:
            for adat,line in zip(self.data,self.lines): 
                line.set_data(adat[:,0][:i],adat[:,1][:i])
                line.set_3d_properties(adat[:,2][:i])


        return self.lines

    def draw(self):
        if self.dim==2:
            anim=FuncAnimation(self.fig,self.points,frames=len(self.data[0][:,0]),init_func=self.init,blit=True,interval=1)
        if self.dim==3:
            anim=FuncAnimation(self.fig,self.points,frames=len(self.data[0][:,0]),init_func=self.init,blit=False,interval=1,cache_frame_data=True)
        plt.show()











