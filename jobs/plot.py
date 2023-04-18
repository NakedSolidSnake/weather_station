import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('temperature.csv','r') as csvfile:
    plots = csv.reader(csvfile, delimiter = ';')
      
    for row in plots:
        x.append(row[2])
        y.append(row[1])
  
# plt.bar(x, y, color = 'g', width = 0.72, label = "Temperature")
# plt.bar(x, y, color = 'g', width = 0.72, label = "Temperature")
plt.plot(x, y, color = 'g', linestyle = 'solid', marker = 'o',label = "Temperature")
plt.xlabel('Time')
plt.ylabel('Value')
plt.title('Temperature')
plt.legend()
plt.show()