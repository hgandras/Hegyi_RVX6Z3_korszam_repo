import csv
import matplotlib.pyplot as plt
from vis_class_test import Visualize
import numpy as np


def get_data(file_name):
    with open(file_name) as f:
        reader=csv.reader(f)
        data=np.array(list(reader))

    data=data.astype(float)
    return data

data1=get_data('output1.txt')
data2=get_data('output2.txt')
data3=get_data('output_ro1.txt')
data4=get_data('output_ro14.txt')

data=[data1,data2]

valami=Visualize(data,dim=3,plane='xz')

valami.axs.set_xlim3d(-10,15)
valami.axs.set_ylim3d(-10,30)
valami.axs.set_zlim3d(-20,30)

valami.axs.set_xlabel('X',size=15)
valami.axs.set_ylabel('Y',size=15)
valami.axs.set_zlabel('Z',size=15)


valami.draw()